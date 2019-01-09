#include "algorithm/neuralNetworks/class/TrainingSet.h"
#include <iostream>

TrainingSet::TrainingSet(vector<double>*trainDatas, vector<double>*trainAnswers){
    this->trainDatas.reset(trainDatas);
    this->trainAnswers.reset(trainAnswers);
    this->prediction.reset(new vector<double>(this->trainAnswers->size()));

}

TrainingSet& TrainingSet::operator= (TrainingSet&& trainingSet){
    this->trainDatas=trainingSet.trainDatas;
    std::cout<<"ssss"<<&(this->trainDatas)<<"!!!"<<this->trainDatas.get()<<"~~"<<this->trainDatas.use_count()<<"~~"<<std::endl;
    std::cout<<"ssss"<<&(trainingSet.trainDatas)<<"!!!"<<trainingSet.trainDatas.get()<<"~~"<<trainingSet.trainDatas.use_count()<<"~~"<<std::endl;
    this->trainAnswers=trainingSet.trainAnswers;
    this->prediction=trainingSet.prediction;
    return *this;
}

TrainingSet& TrainingSet::operator= (TrainingSet& trainingSet){
    this->trainDatas=trainingSet.trainDatas;
    std::cout<<"&~~~"<<&(this->trainDatas)<<"!!!"<<this->trainDatas.get()<<"~~"<<this->trainDatas.use_count()<<"~~"<<std::endl;
    std::cout<<"&~~~"<<&(trainingSet.trainDatas)<<"!!!"<<trainingSet.trainDatas.get()<<"~~"<<trainingSet.trainDatas.use_count()<<"~~"<<std::endl;
    this->trainAnswers=trainingSet.trainAnswers;
    this->prediction=trainingSet.prediction;
    return *this;
}

TrainingSet::TrainingSet(TrainingSet&& trainingSet){
    this->trainDatas=trainingSet.trainDatas;
    this->trainAnswers=trainingSet.trainAnswers;
    this->prediction=trainingSet.prediction;
}

TrainingSet::TrainingSet(){

}

TrainingSet::~TrainingSet() {
    std::cout<<"using~"<<this->trainDatas.use_count()<<"--"<<this->trainDatas.get()<<std::endl;
}
