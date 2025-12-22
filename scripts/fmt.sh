#!/bin/bash

# Format C++ source files using clang-format

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

cd "$PROJECT_ROOT"

# Find all C++ source files
find src tests -name "*.cc" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" | while read -r file; do
    echo "Formatting: $file"
    clang-format -i "$file"
done

echo "Formatting complete!"
