//
// Created by ZC on 2019/1/1.
//

#include"algorithm/neuralNetworks/class/connectedMod.h"
#include "algorithm/neuralNetworks/class/Neurons.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"
#include <iostream>

FullyConnected::FullyConnected(int inputCnts,int hiddenCnts,int outputCnts,vector<unsigned long long int> hidden_W,int randRange):
hidden(*new vector<vector<Neurons>>(hidden_W.size())),outPut(*new vector<Neurons>(outputCnts)){
    //记录数据
    this->inputCnts=inputCnts;
    this->hiddenCnts=hiddenCnts;
    this->outputCnts=outputCnts;
    //记录权重
    unsigned long long int weights=inputCnts;
    //初始化神经网络(层数(具体个数))
    for (unsigned long long int  i= 0; i < hidden.size(); ++i) {
        hidden.at(i)=vector<Neurons>(hidden_W.at(i));
        //手动初始化
        for(unsigned long long int j=0;j<hidden_W.at(i);j++){
            hidden.at(i).at(j)=Neurons(weights,randRange);
        }
        //记录最后一个权重
        weights=hidden_W.at(i);
    }

    //赋值给神经网络输出层
    for(unsigned long long int i=0;i<outPut.size();i++){
        outPut.at(i)=Neurons(weights,randRange);
    }

}
void FullyConnected::prediction(vector<double>& set){
    for(int layer=0;layer<this->hidden.size();layer++){

    }
}
vector<double>& FullyConnected::calculateLayer(vector<Neurons>&vec,vector<double>& input){
    vector<double>& rets=*new vector<double>(vec.size());

    for(unsigned long long i=0;i<vec.size();i++){
        Neurons item = vec.at(i);
        double val=item.calculate(input);
        rets.at(i)=val;
    }

    return rets;
}
vector<vector<double>> FullyConnected::predictionByTrain(TrainingSet& set){
    return vector<vector<double>>();
}
FullyConnected::~FullyConnected(){
    delete &hidden;
    delete &outPut;
}
