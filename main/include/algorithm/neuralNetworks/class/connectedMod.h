#pragma once

#include "algorithm/neuralNetworks/class/Neurons.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"

class FullyConnected {
public:
    FullyConnected(int inp_hid_out[3], int hidW_Cnt[], int randRange);

    /**
     * 神经网络预测,并返回预测向量
     * @param dataSet 输入向量
     * @return  输出向量
     */
    shared_ptr<vector<double>> prediction(shared_ptr<vector<double>> &dataSet);

    /**
     * 开始训练
     * @param trainSets 训练集
     * @param times 训练次数
     * @param rate 学习率
     * @param modelCheck 模型选择
     * @return 最后一次的误差
     */
    double startTrain(shared_ptr<vector<vector<TrainingSet>>> &trainSets, int times, int rate, int modelCheck);

    ~FullyConnected();

protected:
    /**
    * 通过隐藏层输出,进行训练
    * @param hiddenOutPut 隐藏层输出
    * @param tarinSet     训练集合(输入向量,真实向量,模型预计)
    * @param rate         学习因子
    * @return 误差率
    */
    double trainByPrediction(shared_ptr<vector<vector<double>>> &hiddenOutPut, TrainingSet &tarinSet, double rate);

    /**
     * 预测训练向量并返回隐藏层挤压后的输出参数
     * @param tarinSet
     * @return  隐藏层挤压输出
     */
    shared_ptr<vector<vector<double>>> predictionByTrain(TrainingSet &tarinSet);

    /**
     * 逐层训练
     * @param slop 斜率
     * @param lastOutput  当前神经元挤压输出
     * @return 下一个斜率
     */
    shared_ptr<vector<double>> tarinLayer(shared_ptr<vector<double>> &slop, shared_ptr<vector<double>> &lastOutput);


    /**
     * 逐层预测
     * @param neurons 神经元数组
     * @param inputDatas  输入向量
     * @return 当前神经元挤压输出
     */
    shared_ptr<vector<double>>
    predictionLayer(shared_ptr<vector<Neurons>> &neurons, shared_ptr<vector<vector<double>>> &inputDatas);

private:

    /**
     * 二维隐藏层指针
     */
    shared_ptr<vector<vector<Neurons>>> hidden;
    /**
     * 一维输出层指针
     */
    shared_ptr<vector<Neurons>> outPut;

};

namespace fullyConnected {
    int start(int times);
}