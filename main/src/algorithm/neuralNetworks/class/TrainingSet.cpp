#include <utility>

#include "algorithm/neuralNetworks/class/TrainingSet.h"
#include <iostream>

TrainingSet::TrainingSet(shared_ptr<vector<double>>trainDatas, shared_ptr<vector<double>>trainAnswer){
    this->trainDatas = std::move(trainDatas);
    this->trainAnswer = std::move(trainAnswer);
    this->prediction.reset(new vector<double>(this->trainAnswer->size()));
}


TrainingSet::~TrainingSet() {

}
