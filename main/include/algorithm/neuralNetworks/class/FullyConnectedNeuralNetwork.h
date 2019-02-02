#pragma once

#include "../base.h"

//static enum NeuronType{inputLayer=0,hiddenLayer,outputLayer};

class FullyConnectedNeuralNetwork {
public:
    /**
     * 神经元类型
     */

    /**
     * 生成神经网络
     * @param inp_hid_out 输出层个数-隐藏层1个数-2个数-3个数-...n个数-输出层个数
     * @param totalFloors 总层数
     * @param mean 平均数
     * @param standardDeviation 标志差
     */
    FullyConnectedNeuralNetwork(unsigned int inp_hid_out[],unsigned int totalFloors, double mean,double standardDeviation);

protected:
    shared_ptr<vector<MatrixXd>> layerNeuronWeights;

    /**
     * 转化函数
     * @param array 输出值
     * @sign neuronType 神经元标志
     */
    void conversion(VectorXd& outPut, short neuronType);
    /**
     * 转化函数导数
     * @param outPut
     * @param neuronType
     */
    void conversionDerivative(VectorXd& outPut, short neuronType);

    /**
     * 输入至输出的前馈计算
     * @param input
     * @return
     */
    vector<VectorXd>* feedforwardCalculation(VectorXd input);

    /**
     * 现实预测
     * @param input
     * @return
     */
    VectorXd prediction(VectorXd input);

    /**
     * 反向训练
     * @param layerNeuronOutputs
     * @param rate
     * @return
     */
    double reverseTraining(vector<VectorXd>& layerNeuronOutputs, double rate);

    /**
     * 随机引擎
     * @param mean
     * @param standardDeviation
     * @return
     */
    auto random_engine(double mean,double standardDeviation);
};
