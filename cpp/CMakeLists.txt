cmake_minimum_required(VERSION 3.16)
project(LeetCode)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

# We override the default flags here so you can use `assert()` in RelWithDebInfo builds.
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g3 -gdwarf-4 -fno-omit-frame-pointer" CACHE STRING "" FORCE)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type specified. Defaulting to Debug.
                    Use cmake `-DCMAKE_BUILD_TYPE=Release ..` to build an optimized version.")
endif()

if (CMAKE_BUILD_TYPE MATCHES Release)
  message(STATUS "Building an optimized release version.")
  add_compile_options(-O3)
endif ()

set(TASK_SOURCES
    "src/two_sum.cpp"
)

add_library(algorithms SHARED ${TASK_SOURCES})
target_include_directories(algorithms PUBLIC ${CMAKE_HOME_DIRECTORY}/include)

enable_testing()
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.13.0
)

set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(basic_test test/basic.cpp)
add_test(basic_test basic_test)
target_link_libraries(basic_test algorithms gtest gmock)
