//
// Created by ZC on 2018/12/31.
//

#ifndef ALGORITHM_NEURONS_H
#define ALGORITHM_NEURONS_H

#include "algorithm/neuralNetworks/class/neurons.h"
#include <vector>
#include <ctime>


//声明静态变量
std::default_random_engine Neurons::myRand(time(nullptr));    // 将种子值设置为时间
long long   Neurons::maxRand = std::default_random_engine::max();
double   Neurons::e = 2.71828182846;

/**
 * 自动生成权重与范围
 * @param weights
 * @param range
 */
Neurons::Neurons(unsigned long long int weights, int range) : weights(*new vector<double>(weights)) {

    long long rand1 = 0;
    long long rand2 = 0;
    for (double &weight : this->weights) {
        rand1 = this->myRand();
        rand2 = this->myRand();
        weight = (rand1 % (2 * range) - range) + rand2 * 1.0 / maxRand / range;
    }
    this->bias = (rand1 % (2 * range) - range) + rand2 * 1.0 / maxRand / range;
}

/**
 * 计算单元
 * @param vals
 * @return
 */
double Neurons::calculate(vector<double> &vals) {
    double val = this->bias;
    for (double &weight : this->weights) {
        val += weight;
    }
    return val;
}

/**
 * 挤压函数
 * @param val
 * @return
 */
double Neurons::conversion(double val) {
    return 1.0 / (1 + pow(e, -val));

}

/**
 * 修正函数
 * @param lastVal 上一个真实值
 * @param slope   下一个神经元往回传递的更新斜率g_j
 * @param rate    学习率
 * @return
 */
vector<double> &Neurons::correct(double lastVal, vector<double> &slope, double rate) {
    //复制原始数组
    vector<double> &saveW = *new vector<double>(this->weights);
    for (unsigned long long i = 0; i < slope.size(); ++i) {
        double changeVal = rate * slope.at(i);
        this->weights.at(i) -= changeVal * lastVal;
        this->bias -= changeVal;
    }
    return saveW;
}


Neurons::~Neurons() {
    delete &this->weights;
}

#endif //ALGORITHM_NEURONS_H
