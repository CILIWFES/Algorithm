//
// Created by ZC on 2019/1/1.
//

#include "algorithm/neuralNetworks/class/TrainingSet.h"
TrainingSet::TrainingSet(vector<double>& trainDatas,vector<double>& trainAnswer):trainDatas(trainDatas),trainAnswer(trainAnswer),prediction(*new vector<double>(trainAnswer.size(), 0)){};
TrainingSet::~TrainingSet() {
    delete &this->trainDatas;
    delete &this->trainAnswer;
    delete &this->prediction;
}