cmake_minimum_required(VERSION 4.2.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For clang-tidy.

set(CMAKE_CXX_STANDARD 20) # Compile as C++20.
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Require C++23 support.
set(CMAKE_CXX_EXTENSIONS OFF)

project(leetcode-cpp
  VERSION 0.1.0
  DESCRIPTION "LeetCode solutions in C++"
  LANGUAGES C CXX)

# Output directory.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Includes.
set(ARRAYS_HASHING_DIR ${PROJECT_SOURCE_DIR}/src/arrays-hashing)

include_directories(${ARRAYS_HASHING_DIR})
include_directories(BEFORE src) # This is needed for gtest.

enable_testing()

add_subdirectory(third_party)
add_subdirectory(test)
