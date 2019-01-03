#include "algorithm/neuralNetworks/class/TrainingSet.h"

TrainingSet::TrainingSet(shared_ptr<vector<double>>&trainDatas, shared_ptr<vector<double>>&trainAnswer){
    this->trainDatas = trainDatas;
    this->trainAnswer = trainAnswer;
    this->prediction.reset(new vector<double>(trainAnswer->size()));
}
TrainingSet::~TrainingSet() {
    delete &this->trainDatas;
    delete &this->trainAnswer;
    delete &this->prediction;
}
