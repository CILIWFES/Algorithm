#include "algorithm/neuralNetworks/class/TrainingSet.h"
#include <iostream>

TrainingSet::TrainingSet(vector<double>*trainDatas, vector<double>*trainAnswers){
    this->trainDatas.reset(trainDatas);
    this->trainAnswers.reset(trainAnswers);
    this->prediction.reset(new vector<double>(this->trainAnswers->size()));

}

TrainingSet& TrainingSet::operator= (TrainingSet& trainingSet){
    this->trainDatas=trainingSet.trainDatas;
    this->trainAnswers=trainingSet.trainAnswers;
    this->prediction=trainingSet.prediction;
    return *this;
}

TrainingSet& TrainingSet::operator= (TrainingSet&& trainingSet){
    this->trainDatas=move(trainingSet.trainDatas);
    this->trainAnswers=move(trainingSet.trainAnswers);
    this->prediction=move(trainingSet.prediction);
    return *this;
}

TrainingSet::TrainingSet(TrainingSet&& trainingSet){
    this->trainDatas=move(trainingSet.trainDatas);
    this->trainAnswers=move(trainingSet.trainAnswers);
    this->prediction=move(trainingSet.prediction);
}

TrainingSet::TrainingSet(){

}

TrainingSet::~TrainingSet() {
}
