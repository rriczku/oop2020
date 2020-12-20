cmake_minimum_required(VERSION 3.16)

project(project)

add_library(utils
        include/Point.h
        include/Space.h
        include/Time.h
        include/Universe.h
        include/Observer.h
        src/Universe.cpp src/ObserverImpl.cpp src/SpaceImpl.cpp src/TimeImpl.cpp include/TimeImpl.h)

target_include_directories(utils PUBLIC include)

add_executable(runner src/main.cpp include/SpaceImpl.h include/ObserverImpl.h include/TimeImpl.h)
target_link_libraries(runner PRIVATE utils)

add_subdirectory(tests)
