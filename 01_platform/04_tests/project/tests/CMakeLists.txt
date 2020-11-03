cmake_minimum_required(VERSION 3.16)

project(project)

add_executable(tests src/CalculatorTest.cpp)

target_include_directories(tests PRIVATE ../include)
target_link_directories(tests PRIVATE ../../googletest/build/lib)
target_include_directories(tests PRIVATE ../../googletest/googletest/include)
target_link_libraries(tests gtest gtest_main pthread calculator)
