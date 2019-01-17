//
// Created by ZC on 2019/1/10.
//

#include "algorithm/neuralNetworks/class/Neuron.h"
//
// Created by ZC on 2018/12/31.
//



#include "algorithm/neuralNetworks/class/Neuron.h"
#include <vector>
#include <ctime>
#include <iostream>

//声明静态变量
std::default_random_engine Neuron::myRand(time(nullptr));    // 将种子值设置为时间
Neuron::Neuron():weights(nullptr){};

Neuron::Neuron(const Neuron& other):weights(new vector<double>(*other.weights.get())){
    this->bias=other.bias;
};
Neuron&  Neuron::operator =(const Neuron& other){
    this->bias=other.bias;
    this->weights.reset(new vector<double>(*other.weights));
    return *this;
};
Neuron::Neuron(unsigned weightCnts, int range[]):weights(new vector<double>(weightCnts))  {
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

Neuron::~Neuron() {

}