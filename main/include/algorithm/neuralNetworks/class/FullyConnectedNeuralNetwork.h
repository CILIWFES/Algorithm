#pragma once

#include "../base.h"

//static enum NeuronType{inputLayer=0,hiddenLayer,outputLayer};
//全连接打印次数
unsigned int NUMBEROFPRINTS = 10;
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
    FullyConnectedNeuralNetwork(unsigned int inp_hid_out[], unsigned int totalFloors, double mean,
                                double standardDeviation);

    /**
    * 开始预测
    * @param input
    * @return
    */
    VectorXd prediction(VectorXd &inputData);

    /**
     * 开始训练
     * @param trainData 训练数据
     * @param answer    训练标准答案
     * @param train_model    训练模式
     * @param times     训练次数
     * @param rate      学习率
     * @return 最后一批误差
     */
    VectorXd train(vector<VectorXd>& trainData,vector<VectorXd>& answer,int train_model, unsigned int times,double rate);


protected:
    vector<MatrixXd> layerNeuronWeights;

    /**
     * 转化函数
     * @param array 输出值
     * @sign neuronType 神经元标志
     */
    void conversion(VectorXd &outPut);

    /**
     * 转化函数导数
     * @param outPut
     * @param neuronType
     */
    VectorXd conversionDerivative(VectorXd &outPut);

    /**
     * 输入至输出的前馈计算
     * @param input
     * @return
     */
    vector<VectorXd> feedforwardCalculation(VectorXd &trainDate);

    /**
     * 反向训练
     * @param layerNeuronOutputs
     * @param errorDerivative 误差导数
     * @param rate
     * @return
     */
    void reverseTraining(vector<VectorXd> &layerNeuronOutputs, VectorXd& errorDerivative, double rate);

    /**
     * 随机引擎
     * @param mean
     * @param standardDeviation
     * @return
     */
    auto random_engine(double mean, double standardDeviation);

    /**
     * 获取误差
     * @param outPut
     * @param answer
     * @return
     */
    VectorXd calculationError(VectorXd output,VectorXd answer);

    /**
     * 计算误差导数
     * @param outPut
     * @param answer
     * @return
     */
    VectorXd calculatedErrorDerivative(VectorXd output,VectorXd answer);

private:


};
