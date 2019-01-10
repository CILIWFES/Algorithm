//
// Created by ZC on 2018/12/31.
//

#ifndef ALGORITHM_NEURONS_H
#define ALGORITHM_NEURONS_H

#include "algorithm/neuralNetworks/class/NeuronHidden.h"
#include <vector>
#include <ctime>
#include <iostream>

//声明静态变量
NeuronHidden::NeuronHidden():Neuron(){};

NeuronHidden::NeuronHidden(const NeuronHidden& other):Neuron(other){};

NeuronHidden&  NeuronHidden::operator =(const NeuronHidden& other){
    this->bias=other.bias;
    this->weights.reset(new vector<double>(*other.weights));
    return *this;
};
NeuronHidden::NeuronHidden(unsigned weightCnts, int range[]):Neuron(weightCnts,range)  {

}


double NeuronHidden::calculate(vector<double>& vals) {
    double val = this->bias;
    for (unsigned i=0;i<vals.size();i++) {
        val += this->weights->at(i)*vals.at(i);
    }
    return val;
}


double NeuronHidden::conversion(double val) {
    return 1.0 / (1 + pow(e, -val));
}
double NeuronHidden::conversionDerivative(double val) {
    return val*(1-val);
}

vector<double> NeuronHidden::correct(vector<double>& lastInput, double slope, double rate) {
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


NeuronHidden::~NeuronHidden() {

}

#endif //ALGORITHM_NEURONS_H
