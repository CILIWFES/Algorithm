cmake_minimum_required(VERSION 3.13)
project(Algorithm)

set(CMAKE_CXX_STANDARD 17)
include_directories(tools/eigen)

INCLUDE_DIRECTORIES(main/include)
add_executable(Algorithm
        main/src/start/start.cpp
        main/src/module/performance/time/TimePoint.cpp
        main/src/algorithm/neuralnetworks/fullyconnected/FullyConnectedNeuralNetwork.cpp
        main/src/base/base.cpp
        main/include/base.h
        main/src/module/configuration/Configuration.cpp
        main/src/module/IO/IOSupport.cpp )