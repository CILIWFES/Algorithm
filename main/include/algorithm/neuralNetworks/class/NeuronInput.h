#pragma once

#include "Neuron.h"


class NeuronInput:public Neuron{
public:
    NeuronInput();

    /**
    * 正向传播,传递该神经元计算值
    * @param vals 上一层参数
    * @return 计算完成的值
    */
    double calculate(vector<double>& vals);
    double calculate(double val);
    /**
     * 挤压函数
     * @param val 当前层计算值
     * @return 挤压返回值
     */
    double conversion(double val);
    /**
     * 挤压函数求导
     * @param val
     * @return
     */
    double conversionDerivative(double val);
    /**
     * 修正函数
     * @param lastInput 当前层正向预测输入值
     * @param slope   反向更新斜率g_j -∂Ek/∂(y'),Ek=1/2*(y'-y)^2
     * @param rate    学习因子
     * @return
     */
    vector<double> correct(vector<double>&  lastInput, double slope, double rate);
    /**
     * 赋值拷贝
     * @param other
     * @return
     */
    NeuronInput& operator=(const NeuronInput& other);

    ~NeuronInput();

};

