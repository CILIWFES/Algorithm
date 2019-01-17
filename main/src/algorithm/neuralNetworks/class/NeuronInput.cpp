//
// Created by ZC on 2018/12/31.
//

#ifndef ALGORITHM_NEURONS_H
#define ALGORITHM_NEURONS_H

#include "algorithm/neuralNetworks/class/NeuronInput.h"
#include <vector>
#include <ctime>
#include <iostream>

//声明静态变量
NeuronInput::NeuronInput():Neuron(){};




double NeuronInput::calculate(vector<double>& vals) {
    double val = this->bias;
    for (unsigned i=0;i<vals.size();i++) {
        val += this->weights->at(i)*vals.at(i);
    }
    return val;
}
double NeuronInput::calculate(double val) {
    return val;
}


double NeuronInput::conversion(double val) {
    return val;
}
double NeuronInput::conversionDerivative(double val) {
    return 1;
}

vector<double> NeuronInput::correct(vector<double>& lastInput, double slope, double rate) {

    return vector<double>(0);
}


NeuronInput::~NeuronInput() {

}

#endif //ALGORITHM_NEURONS_H
