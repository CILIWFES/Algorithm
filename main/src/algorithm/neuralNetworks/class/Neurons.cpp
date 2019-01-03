//
// Created by ZC on 2018/12/31.
//

#ifndef ALGORITHM_NEURONS_H
#define ALGORITHM_NEURONS_H

#include "algorithm/neuralNetworks/class/Neurons.h"
#include <vector>
#include <ctime>

//声明静态变量
std::default_random_engine Neurons::myRand(time(nullptr));    // 将种子值设置为时间

Neurons::Neurons(unsigned weights, int range) : weights(new vector<double>(weights)) {
    long long rand1 = 0;
    long long rand2 = 0;
    long maxRand = std::default_random_engine::max();
    for (double &weight : *this->weights) {
        //整数部分
        rand1 = myRand();
        //小数部分
        rand2 = myRand();
        weight = (rand1 % (2 * range) - range);
        weight += weight < 0 ? -rand2 * 1.0 / maxRand / range : rand2 * 1.0 / maxRand / range;
    }
    rand1 = myRand();
    rand2 = myRand();
    this->bias = (rand1 % (2 * range) - range);
    this->bias += this->bias < 0 ? -rand2 * 1.0 / maxRand / range : rand2 * 1.0 / maxRand / range;
}


double Neurons::calculate(shared_ptr<vector<double>> vals) {
    double val = this->bias;
    for (double &weight : *this->weights) {
        val += weight;
    }
    return val;
}


double Neurons::conversion(double val) {
    return 1.0 / (1 + pow(e, -val));

}


shared_ptr<vector<double>> Neurons::correct(double lastInput, double slope, double rate) {
    //复制原始数组
    shared_ptr<vector<double>> saveW(new vector<double>(*this->weights));
    //根据△w+=slope*lastVal
    for (unsigned long long i = 0; i < weights.size(); ++i) {
        double changeVal = rate * slope;
        this->weights->at(i) -= changeVal * lastInput;
        this->bias -= changeVal;
    }

    return saveW;
}


Neurons::~Neurons() {
    delete &weights;
}

#endif //ALGORITHM_NEURONS_H
