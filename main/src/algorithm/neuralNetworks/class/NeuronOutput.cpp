//
// Created by ZC on 2018/12/31.
//

#ifndef ALGORITHM_NEURONS_H
#define ALGORITHM_NEURONS_H

#include "algorithm/neuralNetworks/class/NeuronOutput.h"
#include <vector>
#include <ctime>
#include <iostream>

//声明静态变量
NeuronOutput::NeuronOutput():Neuron(){};

NeuronOutput::NeuronOutput(const NeuronOutput& other):Neuron(other){};

NeuronOutput&  NeuronOutput::operator =(const NeuronOutput& other){
    this->bias=other.bias;
    this->weights.reset(new vector<double>(*other.weights));
    return *this;
};
NeuronOutput::NeuronOutput(unsigned weightCnts, int range[]):Neuron(weightCnts,range)  {}


double NeuronOutput::calculate(vector<double>& vals) {
    double val = this->bias;
    for (unsigned i=0;i<vals.size();i++) {
        val += this->weights->at(i)*vals.at(i);
    }
    return val;
}


double NeuronOutput::conversion(double val) {
    return 1.0 / (1 + pow(e, -val/10000));
}
double NeuronOutput::conversionDerivative(double val) {
    return (val/10000)*(1-val/10000);
}
vector<double> NeuronOutput::correct(vector<double>& lastInput, double slope, double rate) {
    //复制原始数组
    vector<double> saveW(vector<double>(*this->weights));
    //根据△w+=slope*lastVal
    for (unsigned i = 0; i < weights->size(); ++i) {
        double changeVal = rate * slope;
        this->weights->at(i) += changeVal * lastInput.at(i);
        this->bias += changeVal;
    }

    return saveW;
}


NeuronOutput::~NeuronOutput() {

}

#endif //ALGORITHM_NEURONS_H
