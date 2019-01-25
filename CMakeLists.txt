cmake_minimum_required(VERSION 3.13)
project(Algorithm)

set(CMAKE_CXX_STANDARD 17)
include_directories(tools/eigen)

INCLUDE_DIRECTORIES(main/include)
add_executable(Algorithm
        main/src/start/start.cpp
        main/src/module/performance/time/TimePoint.cpp
        main/src/algorithm/neuralNetworks/class/NeuronHidden.cpp
        main/src/algorithm/neuralNetworks/fullyConnected/FullyConnected.cpp
        main/src/algorithm/neuralNetworks/class/TrainingSet.cpp
        main/src/algorithm/neuralNetworks/fullyConnected/fullyConnectedStart.cpp
        main/src/algorithm/neuralNetworks/class/Neuron.cpp
        main/src/algorithm/neuralNetworks/class/NeuronOutput.cpp
        main/src/algorithm/neuralNetworks/class/NeuronInput.cpp
        )