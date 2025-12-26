#!/bin/bash

exitcode=0

# Run cpplint. Excluded checks:
#  - legal/copyright: We do not include copyright information in our source files.
#  - runtime/references: We prefer references to pointers in most cases.
#  - build/(c++11|c++17): cpplint complains about headers that are "unapproved" by Google devs (see https://github.com/google/styleguide/issues/194).
#  - readability/nolint: cpplint complains about excluded clang-tidy categories, which we widely use.
#  - readability/inheritance: cpplint complains about "override final" as being redundant, but it is not.
#  - whitespace/braces: Does not work with {} initialization (see https://github.com/cpplint/cpplint/issues/204#issuecomment-1146769949).
#  - build/include_subdir: Does not work well with our structure of using lib, test, and third_party directories.
find src \( -iname "*.cc" -o -iname "*.h" \) -print0 | parallel --null --no-notice -j 100% --nice 17 /usr/bin/env python3 ./third_party/cpplint/cpplint.py --verbose=0 --extensions=h,cc --counting=detailed --filter=-legal/copyright,-runtime/references,-build/c++11,-build/c++17,-readability/nolint,-readability/inheritance,-whitespace/braces,-build/include_subdir --linelength=120 {} 2\>\&1 \| grep -v \'\^Done processing\' \| grep -v \'\^Total errors found: 0\' \; test \${PIPESTATUS[0]} -eq 0
let "exitcode |= $?"
#                             /------------------ runs in parallel -------------------\
# Conceptual: find | parallel python cpplint \| grep -v \| test \${PIPESTATUS[0]} -eq 0
#             ^      ^        ^                 ^          ^
#             |      |        |                 |          |
#             |      |        |                 |          Get the return code of the first pipeline item (here: cpplint)
#             |      |        |                 Removes the prints for files without errors
#             |      |        Regular call of cpplint with options
#             |      Runs the following in parallel
#             Finds all .cc and .h files, separated by \0

# All disabled tests should have an issue number
output=$(grep -rHn 'DISABLED_' test | grep -v '#[0-9]\+' | sed 's/^\([a-zA-Z/._]*:[0-9]*\).*/\1  Disabled tests should be documented with their issue number (e.g. \/* #123 *\/)/')
if [ ! -z "$output" ]; then
  echo "$output"
  exitcode=1
fi

# Gtest's TEST() should not be used. Use TEST_F() instead. This might require additional test classes but ensures that state is cleaned up properly.
output=$(grep -rHn '^TEST(' test | sed 's/^\([a-zA-Z/._]*:[0-9]*\).*/\1  TEST() should not be used as it does not clean up global state (e.g., the Hyrise singleton)./')
if [ ! -z "$output" ]; then
  echo "$output"
  exitcode=1
fi

# The singleton pattern should not be manually implemented
output=$(grep -rHn 'static[^:]*instance;' --exclude singleton.h src | sed 's/^\([a-zA-Z/._]*:[0-9]*\).*/\1  Singletons should not be implemented manually. Have a look at src\/lib\/utils\/singleton.h/')
if [ ! -z "$output" ]; then
  echo "$output"
  exitcode=1
fi

# Tests should not include any type of random behavior, see #1321.
output=$(grep -rHEn '#include <random>|std::random|std::[a-z_]+_engine|std::[a-z_]+_distribution' test | grep -v std::random_access_iterator_tag | sed 's/^\([a-zA-Z/._]*:[0-9]*\).*/\1  Tests should not include any type of random behavior, see #1321./')
if [ ! -z "$output" ]; then
  echo "$output"
  exitcode=1
fi

# Check for included cc files. You would think that this is not necessary, but history proves you wrong.
regex='#include .*\.cc'
namecheck=$(find src \( -iname "*.cc" -o -iname "*.h" \) -print0 | xargs -0 grep -rHn "$regex" | grep -v NOLINT)
let "exitcode |= ! $?"
while IFS= read -r line
do
  if [ ! -z "$line" ]; then
    echo $line | sed 's/^\([a-zA-Z/._]*:[0-9]*\).*/Include of cc file:/' | tr '\n' ' '
    echo $line | sed 's/\(:[^:]*:\)/\1 /'
  fi
done <<< "$namecheck"

# # Check that all cc and h files in src/ are listed in the corresponding CMakeLists.txt
# for dir in src/*
# do
#   for file in $(find $dir -name *.cc -o -name *.h)
#   do
#     if grep $(basename $file) $dir/CMakeLists.txt | grep -v '#' > /dev/null
#     then
#       continue
#     else
#       echo $file not found in $dir/CMakeLists.txt
#       exitcode=1
#     fi
#   done
# done

# Check for Windows-style line endings
output=$(find src -type f -exec dos2unix -ic {} +)
if [[ ${output} ]]; then
  for file in ${output}
  do
    echo "Windows-style file ending: $file"
  done
  exitcode=1
fi

unamestr=$(uname)
if [[ "$unamestr" == 'Darwin' ]]; then
    LLVM_PREFIX=$(brew --prefix llvm)
    clang_tidy="$LLVM_PREFIX/bin/clang-tidy"
    SDK=$(xcrun --sdk macosx --show-sdk-path)
    RES=$(clang++ -print-resource-dir)
    
    # macOS-specific extra args - force color output
    lint_cmd="$clang_tidy --use-color -p ./build {} -- -isysroot $SDK -resource-dir=$RES"
elif [[ "$unamestr" == 'Linux' ]]; then
    lint_cmd="clang-tidy --use-color -p ./build {}"
fi

dirs="src|test"

if [ "${1}" = "all" ]; then
    find src test -iname "*.cc" -o -iname "*.h" -o -iname "*.ipp" | parallel "${lint_cmd}"
elif [ "$1" = "modified" ]; then
    # Run on all changed as well as untracked cc/h files, as compared to the current HEAD. Skip deleted files.
    { git diff --diff-filter=d --name-only & git ls-files --others --exclude-standard; } | grep -E "^src.*\.[chi]pp$" | parallel "${lint_cmd}"
elif [ "$1" = "staged" ]; then
    # Run on all files that are staged to be committed.
    git diff --diff-filter=d --cached --name-only | grep -E "^src.*\.[chi]pp$" | parallel "${lint_cmd}"
else
    # Run on all changed as well as untracked cc/h files, as compared to the current master. Skip deleted files.
    { git diff --diff-filter=d --name-only master & git ls-files --others --exclude-standard; } | grep -E "^($dirs).*\.[chi]pp$" | parallel --color "${lint_cmd}"
fi

exit $exitcode
