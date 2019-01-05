#pragma once

#include "algorithm/neuralNetworks/class/FullyConnected.h"
#include<iostream>
using  std::cout,std::endl;

namespace fullyConnected {
    shared_ptr<FullyConnected> makeFullyConnected(int times,double rate);
}