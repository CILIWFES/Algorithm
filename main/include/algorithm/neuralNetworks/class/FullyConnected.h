#pragma once

#include "algorithm/neuralNetworks/class/Neurons.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"


class FullyConnected {
public:

    FullyConnected(unsigned inp_hid_out[], unsigned hid_Cnt[], int randRange[]);

    /**
     * 神经网络预测,并返回预测向量
     * @param dataSet 输入向量
     * @return  输出向量
     */
    vector<double>* prediction(vector<double> &dataSet);

    /**
     * 开始训练
     * @param trainSets 训练集
     * @param times 训练次数
     * @param rate 学习率
     * @param modelCheck 模型选择
     * @return 最后一次的误差
     */
    double startTrain(vector<TrainingSet> &trainSets, int times, double rate, int modelCheck);

    ~FullyConnected();

protected:
    /**
    * 通过隐藏层输出,进行训练
    * @param hiddenOutPut 隐藏层输出
    * @param trainingSet     训练集合(输入向量,真实向量,模型预计)
    * @param rate         学习因子
    * @return 误差率
    */
    double trainByPrediction(vector<vector<double>>& hiddenOutPut, TrainingSet &trainingSet, double rate);

    /**
     * 预测训练向量并返回隐藏层挤压后的输出参数
     * @param tarinSet
     * @return  隐藏层挤压输出
     */
    vector<vector<double>>* predictionByTrain(TrainingSet &tarinSet);

    /**
     * 逐层训练
     * @param slop 斜率
     * @param lastOutput  当前神经元挤压输出
     * @return 下一个斜率
     */
    vector<vector<double>>* tarinLayer(vector<Neurons> &neurons,vector<double> &slop, vector<double>&lastIntput ,double rate);


    /**
     * 逐层预测
     * @param neurons 神经元数组
     * @param inputDatas  输入向量
     * @return 当前神经元挤压输出
     */
    vector<double>* predictionLayer(vector<Neurons> &neurons, vector<double> &inputDatas);

private:

    /**
     * 计算当前层的权值
     * @param beforNeurons  上一层神经元
     * @param slop  当前斜率
     * @param oldW  当前旧权值
     * @param lastOutput 当前神经元的输出
     * @return
     */
    vector<double>* calculationWeight(vector<Neurons>& beforNeurons,vector<double> &slop, vector<vector<double>> &oldW, vector<double> &lastOutput);

    /**
     * 二维隐藏层指针
     */
    shared_ptr<vector<vector<Neurons>>> hidden;

    /**
     * 一维输出层指针
     */
    shared_ptr<vector<Neurons>> outPut;

};
