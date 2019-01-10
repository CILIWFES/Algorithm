#pragma once

#include <vector>
#include <ctime>
#include <random>
#include <memory>
#include "TrainingSet.h"

#define e 2.71828182846
using std::vector, std::shared_ptr;

class Neuron {
public:
    Neuron();

    /**
    * 拷贝构造
    * @param other
    */
    Neuron(const Neuron &other);

    /**
     * 生成神经网络
     * @param weightCnts  权重参数数量
     * @param range    生成随机数范围
     */
    Neuron(unsigned weightCnts, int range[]);

    /**
     * 赋值拷贝
     * @param other
     * @return
     */
    Neuron &operator=(const Neuron &other);


    /**
    * 正向传播,传递该神经元计算值
    * @param vals 上一层参数
    * @return 计算完成的值
    */
    virtual double calculate(vector<double> &vals) = 0;

    /**
     * 挤压函数
     * @param val 当前层计算值
     * @return 挤压返回值
     */
    virtual double conversion(double val) = 0;

    /**
     * 挤压函数求导
     * @param val
     * @return
     */
    virtual double conversionDerivative(double val) = 0;

    /**
     * 修正函数
     * @param lastInput 当前层正向预测输入值
     * @param slope   反向更新斜率g_j -∂Ek/∂(y'),Ek=1/2*(y'-y)^2
     * @param rate    学习因子
     * @return
     */
    virtual vector<double> correct(vector<double> &lastInput, double slope, double rate) = 0;

    ~Neuron();

protected:
    double bias;
    shared_ptr<vector<double>> weights;
    static std::default_random_engine myRand;
};


