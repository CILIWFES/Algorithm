//
// Created by ZC on 2019/1/29.
//

#pragma once

#include "../base.h"

class FullyConnectedNeuralNetwork {
public:
    static enum NeuronType{inputLayer,hiddenLayer,outputLayer};
    /**
     * 生成神经网络
     * @param inp_hid_out 输出层个数-隐藏层1个数-2个数-3个数-...n个数-输出层个数
     * @param totalFloors 总层数
     * @param randRange 权重范围 {a~b}
     */
    FullyConnectedNeuralNetwork(unsigned int inp_hid_out[],unsigned int totalFloors, int randRange[]);


protected:
    shared_ptr<vector<MatrixXd>> layerNeuronWeights;
    sh|ared_ptr<vector<ArrayXd>> layerNeuronOutputs;
    /**
     * 转化方法
     * @param array 输出值
     * @sign neuronType 神经元标志
     */
    void conversion(ArrayXd& array, short neuronType);

    /**
     * 输入至输出的前馈计算
     */
    void feedforwardCalculation();
      /**
       * 反向训练
       */
};
