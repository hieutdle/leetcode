#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

cd "$PROJECT_ROOT"

if [ ! -f "compile_commands.json" ]; then
    echo "Error: compile_commands.json not found."
    echo "Run: xmake project -k compile_commands"
    exit 1
fi

find src tests \( -name "*.cc" -o -name "*.cpp" \) | while read -r file; do
    echo "Linting: $file"
    # Only check headers in src/ and tests/ directories, exclude system headers
    # Filter out system header warnings and the "X warnings generated" summary
    clang-tidy \
        -p . \
        -header-filter='^(src|tests)/.*' \
        -extra-arg=-w \
        "$file" 2>&1 | grep -v -E "^(/usr|/Library|/Applications|/System)" | grep -v "warnings generated" || true
done

echo "Linting complete!"
