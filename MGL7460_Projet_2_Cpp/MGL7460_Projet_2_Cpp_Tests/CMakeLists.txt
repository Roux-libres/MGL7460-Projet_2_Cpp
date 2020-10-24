cmake_minimum_required (VERSION 3.8)
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)
add_executable(test1 test.cpp)
target_link_libraries(test1 ${GTEST_BOTH_LIBRARIES})
add_test(test-1 test1)
