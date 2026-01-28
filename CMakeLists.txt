cmake_minimum_required(VERSION 4.2.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For clang-tidy.

set(CMAKE_CXX_STANDARD 23) # Compile as C++23.
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
set(TWO_POINTERS_DIR ${PROJECT_SOURCE_DIR}/src/two-pointers)
set(SLIDING_WINDOW_DIR ${PROJECT_SOURCE_DIR}/src/sliding-window)
set(STACK_DIR ${PROJECT_SOURCE_DIR}/src/stack)
set(BINARY_SEARCH_DIR ${PROJECT_SOURCE_DIR}/src/binary-search)
set(LINKED_LIST_DIR ${PROJECT_SOURCE_DIR}/src/linked-list)
set(TREES_DIR ${PROJECT_SOURCE_DIR}/src/trees)
set(BACKTRACKING_DIR ${PROJECT_SOURCE_DIR}/src/backtracking)
set(HEAP_PRIORITY_QUEUE_DIR ${PROJECT_SOURCE_DIR}/src/heap-priority-queue)
set(TRIES_DIR ${PROJECT_SOURCE_DIR}/src/tries)
set(GRAPHS_DIR ${PROJECT_SOURCE_DIR}/src/graphs)
set(ADVANCED_GRAPHS_DIR ${PROJECT_SOURCE_DIR}/src/advanced-graphs)
set(ONE_D_DYNAMIC_PROGRAMMING_DIR ${PROJECT_SOURCE_DIR}/src/1d-dynamic-programming)
set(TWO_D_DYNAMIC_PROGRAMMING_DIR ${PROJECT_SOURCE_DIR}/src/2d-dynamic-programming)


include_directories(${ARRAYS_HASHING_DIR})
include_directories(${TWO_POINTERS_DIR})
include_directories(${SLIDING_WINDOW_DIR})
include_directories(${STACK_DIR})
include_directories(${BINARY_SEARCH_DIR})
include_directories(${LINKED_LIST_DIR})
include_directories(${TREES_DIR})
include_directories(${BACKTRACKING_DIR})
include_directories(${HEAP_PRIORITY_QUEUE_DIR})
include_directories(${TRIES_DIR})
include_directories(${GRAPHS_DIR})
include_directories(${ADVANCED_GRAPHS_DIR})
include_directories(${ONE_D_DYNAMIC_PROGRAMMING_DIR})
include_directories(${TWO_D_DYNAMIC_PROGRAMMING_DIR})
include_directories(BEFORE src) # This is needed for gtest.

enable_testing()

add_subdirectory(third_party)
add_subdirectory(test)
