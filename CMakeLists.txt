cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For clang-tidy.

set(CMAKE_CXX_STANDARD 23) # Compile as C++23.
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Require C++23 support.

project(leetcode-cpp
        VERSION 0.1.0
        DESCRIPTION "LeetCode solutions in C++"
        LANGUAGES C CXX)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)