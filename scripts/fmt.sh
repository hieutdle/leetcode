#!/bin/bash

unamestr=$(uname)
if [[ "$unamestr" == 'Darwin' ]]; then
	clang_format="$(brew --prefix llvm)/bin/clang-format"
	format_cmd="$clang_format -i -style=file '{}'"
elif [[ "$unamestr" == 'Linux' ]]; then
	format_cmd="clang-format -i -style=file '{}'"
fi

dirs="src|test"

if [ "${1}" = "all" ]; then
    find src test -iname "*.cc" -o -iname "*.h" -o -iname "*.ipp" | xargs -I{} sh -c "${format_cmd}"
elif [ "$1" = "modified" ]; then
    # Run on all changed as well as untracked cc/h files, as compared to the current HEAD. Skip deleted files.
    { git diff --diff-filter=d --name-only & git ls-files --others --exclude-standard; } | grep -E "^src.*\.[chi]pp$" | xargs -I{} sh -c "${format_cmd}"
elif [ "$1" = "staged" ]; then
    # Run on all files that are staged to be committed.
    git diff --diff-filter=d --cached --name-only | grep -E "^src.*\.[chi]pp$" | xargs -I{} sh -c "${format_cmd}"
else
    # Run on all changed as well as untracked cc/h files, as compared to the current master. Skip deleted files.
    { git diff --diff-filter=d --name-only master & git ls-files --others --exclude-standard; } | grep -E "^($dirs).*\.[chi]pp$" | xargs -I{} sh -c "${format_cmd}"
fi