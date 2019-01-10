//
// Created by ZC on 2018/12/31.
//

#ifndef ALGORITHM_NEURONS_H
#define ALGORITHM_NEURONS_H

#include "algorithm/neuralNetworks/class/Neurons.h"
#include <vector>
#include <ctime>
#include <iostream>

//声明静态变量
std::default_random_engine Neurons::myRand(time(nullptr));    // 将种子值设置为时间
Neurons::Neurons():weights(nullptr){};

Neurons::Neurons(const Neurons& other):weights(new vector<double>(*other.weights.get())){
    this->bias=other.bias;
};
Neurons&  Neurons::operator =(const Neurons& other){
    this->bias=other.bias;
    this->weights.reset(new vector<double>(*other.weights));
    return *this;
};
Neurons::Neurons(unsigned weightCnts, int range[]):weights(new vector<double>(weightCnts))  {
    int range1 = range[0];
    int range2 = range[1]-1;
    int scope=range2-range1;

    long long rand1 = 0;
    long long rand2 = 0;
    for (unsigned i=0;i<weightCnts;i++) {
        //整数部分
        rand1 = myRand();
        //小数部分
        rand2 = myRand();
        if(scope==0){
            this->weights->at(i) = (rand2%(10000+1))/10000.0;
        }else{
            this->weights->at(i) = (rand1 % scope+range1)+(rand2%(10000+1))/10000.0;
        }
    }
    rand1 = myRand();
    rand2 = myRand();
    if(scope==0){
        this->bias = (rand2%(10000+1))/10000.0;
    }else{
        this->bias = (rand1 % scope+range1)+(rand2%(10000+1))/10000.0;
    }
}


double Neurons::calculate(vector<double>& vals) {
    double val = this->bias;
    for (unsigned i=0;i<vals.size();i++) {
        val += this->weights->at(i)*vals.at(i);
    }
    return val;
}


double Neurons::conversion(double val) {
    return 1.0 / (1 + pow(e, -val));
}
double Neurons::conversionDerivative(double val) {
    return val*(1-val);
}

vector<double> Neurons::correct(vector<double>& lastInput, double slope, double rate) {
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


Neurons::~Neurons() {

}

#endif //ALGORITHM_NEURONS_H
