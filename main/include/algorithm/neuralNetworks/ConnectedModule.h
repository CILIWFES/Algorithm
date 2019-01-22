#pragma once

#include "algorithm/neuralNetworks/class/FullyConnected.h"
#include<iostream>
using  std::cout,std::endl;

namespace fullyConnected {
    /**
     * 构造全连接神经元并训练
     * @param times 训练次数
     * @param rate 学习率
     * @param inp_hid_out 输入神经元个数-隐藏层1个数-隐藏层2个数-******隐藏层n个数-输出神经元个数
     * @param totalFloors 层数
     * @param trainDatas 训练集
     * @param randRange 权重生成范围
     * @param trainModel 训练模式
     * @return
     */
    shared_ptr<FullyConnected> makeFullyConnected(int times,double rate,unsigned inp_hid_out[],unsigned totalFloors,vector<TrainingSet> *trainDatas,int randRange[],int trainModel);

    vector<TrainingSet>* makeSet(vector<vector<double>*>& trainDatas,vector<vector<double>*>& trainAnswers);
}