cmake_minimum_required(VERSION 3.16)

project(project)

add_executable(tests main.cpp)
target_include_directories(tests PRIVATE ../googletest/googletest/include)
target_link_directories(tests PRIVATE ../googletest/build/lib)
target_link_libraries(tests PRIVATE gtest gtest_main pthread)