#pragma once

#include "algorithm/neuralNetworks/class/NeuronHidden.h"
#include "algorithm/neuralNetworks/class/NeuronInput.h"
#include "algorithm/neuralNetworks/class/NeuronOutput.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"


class FullyConnected {
public:
    /**
     * 生成神经元
     * @param inp_hid_out 输出层个数-隐藏层1个数-2个数-3个数-...n个数-输出层个数
     * @param totalFloors 总层数
     * @param randRange 权重范围
     */
    FullyConnected(unsigned inp_hid_out[],unsigned totalFloors, int randRange[]);

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

    /**
     * 单独训练
     * @param trainSet 预测训练集
     * @param rate 学习率
     * @return
     */
    double singleTraining(TrainingSet &trainSet,double rate);
    /**
     * 批量预测
     * @param trainSets 预测训练集合
     * @param rate 学习率
     * @return
     */
    double multipleTraining(vector<TrainingSet> &trainSets,double rate);

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
     * @param neurons 输出神经元
     * @param slop 斜率
     * @param lastOutput  当前神经元挤压输出
     * @return 下一个斜率
     */
    vector<vector<double>>* tarinLayer(vector<NeuronHidden> &neurons,vector<double> &slop, vector<double>&lastIntput ,double rate);
    /**
     * 训练输出层
     * @param neurons 输出神经元
     * @param slop 斜率
     * @param lastOutput 当前神经元挤压输出
     * @param rate
     * @return
     */
    vector<vector<double>>* tarinLayer_Out(vector<NeuronOutput> &neurons,vector<double> &slop, vector<double>&lastOutput ,double rate);


    /**
     * 逐层预测
     * @param neurons 神经元数组
     * @param inputDatas  输入向量
     * @return 当前神经元挤压输出
     */
    vector<double>* predictionLayer(vector<NeuronHidden> &neurons, vector<double> &inputDatas);
    /**
     * 预测输出层
     * @param neurons 神经元数组
     * @param inputDatas 输入数据
     * @return
     */
    vector<double>* predictionLayer_Output(vector<NeuronOutput> &neurons, vector<double> &inputDatas);
    /**
     * 输入层预测
     * @param neurons 神经元数组
     * @param inputDatas 输入数据
     * @return
     */
    vector<double>* predictionLayer_Input(vector<NeuronInput> &neurons, vector<double> &inputDatas);

private:

    /**
     * 合并训练集
     * @param collect 已合并数据
     * @param old 待合并数据
     * @param divisor 总数据量
     * @return
     */
    TrainingSet& mergeTrainSet(TrainingSet& collect,TrainingSet& old,int divisor);

    /**
     * 合并输出元素
     * @param collect 已合并输出数据
     * @param oldOutPut 待合并输出数据
     * @param divisor 总数据量
     * @return
     */
    vector<vector<double>>& mergeOutput(vector<vector<double>>& collect,vector<vector<double>>& oldOutPut,int divisor);
    /**
     * 计算当前层的权值
     * @param beforNeurons  上一层神经元
     * @param slop  当前斜率
     * @param oldW  当前旧权值
     * @param lastOutput 当前神经元的输出
     * @return
     */
    vector<double>* calculationWeight(vector<NeuronHidden>& beforNeurons,vector<double> &slop, vector<vector<double>> &oldW, vector<double> &lastOutput);

    /**
     * 二维隐藏层指针
     */
    shared_ptr<vector<vector<NeuronHidden>>> hidden;

    /**
     * 一维输出层指针
     */
    shared_ptr<vector<NeuronOutput>> outPut;
    /**
     * 一维输出层指针
     */
    shared_ptr<vector<NeuronInput>> intPut;

};
