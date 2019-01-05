cmake_minimum_required(VERSION 3.13)
project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(main/include)

add_executable(Algorithm
        main/src/start/start.cpp
        main/src/module/performance/time/TimePoint.cpp
        main/src/algorithm/neuralNetworks/class/Neurons.cpp
        main/src/algorithm/neuralNetworks/fullyConnected/FullyConnected.cpp
        main/src/algorithm/neuralNetworks/class/TrainingSet.cpp
        main/src/algorithm/neuralNetworks/fullyConnected/fullyConnectedStart.cpp
        )