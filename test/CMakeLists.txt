include(GoogleTest)

file(GLOB_RECURSE LEETCODE_TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*/*test.cc")

# #####################################################################################################################
# MAKE TARGETS
# #####################################################################################################################

# #########################################
# "make check-tests"
# #########################################
add_custom_target(build-tests COMMAND ${CMAKE_CTEST_COMMAND} --show-only)
add_custom_target(check-tests COMMAND ${CMAKE_CTEST_COMMAND} --verbose)

# #########################################
# "make XYZ_test"
# #########################################
foreach (leetcode_test_source ${LEETCODE_TEST_SOURCES})
    # Create a human readable name.
    get_filename_component(leetcode_test_filename ${leetcode_test_source} NAME)
    string(REPLACE ".cc" "" leetcode_test_name ${leetcode_test_filename})

    # Add the test target separately and as part of "make check-tests".
    add_executable(${leetcode_test_name} EXCLUDE_FROM_ALL ${leetcode_test_source})
    add_dependencies(build-tests ${leetcode_test_name})
    add_dependencies(check-tests ${leetcode_test_name})

    gtest_discover_tests(${leetcode_test_name}
            EXTRA_ARGS
            --gtest_output=xml:${CMAKE_BINARY_DIR}/test/${leetcode_test_name}.xml
            --gtest_catch_exceptions=0
            DISCOVERY_TIMEOUT 120
            PROPERTIES
            TIMEOUT 120
            )

    target_link_libraries(${leetcode_test_name} gtest gmock_main)

    # Set test target properties and dependencies.
    set_target_properties(${leetcode_test_name}
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
            COMMAND ${leetcode_test_name}
            )
endforeach ()
