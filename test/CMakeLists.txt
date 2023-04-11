cmake_minimum_required(VERSION 3.8)

project(test)

#add_subdirectory(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test test.cpp)

target_link_libraries(test gtest gtest_main)