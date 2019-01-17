#pragma once

#include "Neuron.h"


class NeuronOutput:public Neuron{
public:
    NeuronOutput();
    /**
    * 拷贝构造
    * @param other
    */
    NeuronOutput(const NeuronOutput& other);
    /**
     * 生成神经网络
     * @param weightCnts  权重参数数量
     * @param range    生成随机数范围
     */
    NeuronOutput(unsigned weightCnts, int range[]);

    /**
    * 正向传播,传递该神经元计算值
    * @param vals 上一层参数
    * @return 计算完成的值
    */
    double calculate(vector<double>& vals);
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
    NeuronOutput& operator=(const NeuronOutput& other);

    ~NeuronOutput();

};

