cmake_minimum_required(VERSION 3.16)

project(project)

add_library(utils
        include/Calculator.h
        include/factory/executor/AcousticCpuCore.h
        include/factory/executor/AcousticCudaCore.h
        include/factory/executor/AnisotropicCpuCore.h
        include/factory/executor/AnisotropicCudaCore.h
        include/factory/executor/CpuCoreFactory.h
        include/factory/executor/CudaCoreFactory.h
        include/factory/executor/CoreFactory.h
        include/factory/executor/Core.h
        include/factory/executor/Demo.h
        include/factory/executor/ElasticCpuCore.h
        include/factory/executor/ElasticCudaCore.h
        include/factory/gui/ButtonGnomeWidget.h
        include/factory/gui/ButtonKdeWidget.h
        include/factory/gui/CheckBoxGnomeWidget.h
        include/factory/gui/CheckBoxKdeWidget.h
        include/factory/gui/Demo.h
        include/factory/gui/GnomeWidgetFactory.h
        include/factory/gui/KdeWidgetFactory.h
        include/factory/gui/ListGnomeWidget.h
        include/factory/gui/ListKdeWidget.h
        include/factory/gui/Widget.h
        include/factory/gui/WidgetFactory.h
        include/observer/Acceleration.h
        include/observer/Displacement.h
        include/observer/Observable.h
        include/observer/Observer.h
        include/observer/Speed.h
        src/factory/executor/AcousticCpuCore.cpp
        src/factory/executor/AcousticCudaCore.cpp
        src/factory/executor/AnisotropicCpuCore.cpp
        src/factory/executor/AnisotropicCudaCore.cpp
        src/factory/executor/CpuCoreFactory.cpp
        src/factory/executor/CudaCoreFactory.cpp
        src/factory/executor/Demo.cpp
        src/factory/executor/ElasticCpuCore.cpp
        src/factory/executor/ElasticCudaCore.cpp
        src/factory/gui/ButtonGnomeWidget.cpp
        src/factory/gui/ButtonKdeWidget.cpp
        src/factory/gui/CheckBoxGnomeWidget.cpp
        src/factory/gui/CheckBoxKdeWidget.cpp
        src/factory/gui/Demo.cpp
        src/factory/gui/GnomeWidgetFactory.cpp
        src/factory/gui/KdeWidgetFactory.cpp
        src/factory/gui/ListGnomeWidget.cpp
        src/factory/gui/ListKdeWidget.cpp
        src/observer/Acceleration.cpp
        src/observer/Displacement.cpp
        src/observer/Observable.cpp
        src/observer/Speed.cpp
        src/Calculator.cpp)

target_include_directories(utils PUBLIC include)

add_executable(runner src/main.cpp)
target_link_libraries(runner PRIVATE utils)

add_subdirectory(tests)
