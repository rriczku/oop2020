cmake_minimum_required(VERSION 3.16)

project(project)

add_library(calculator STATIC src/Calculator.cpp)
target_include_directories(calculator PUBLIC include)
target_include_directories(calculator PUBLIC src)

add_executable(runner src/main.cpp)
target_link_libraries(runner PUBLIC calculator)
add_subdirectory(tests CMakeLists.txt)
add_test(tests tests)
