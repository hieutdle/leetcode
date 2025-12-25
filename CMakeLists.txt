cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For clang-tidy.

set(CMAKE_CXX_STANDARD 23) # Compile as C++23.
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Require C++23 support.

project(leetcode-cpp
  VERSION 0.1.0
  DESCRIPTION "LeetCode solutions in C++"
  LANGUAGES C CXX)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(extern)