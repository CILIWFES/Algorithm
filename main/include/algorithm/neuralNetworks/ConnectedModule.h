#pragma once

#include "algorithm/neuralNetworks/class/FullyConnected.h"
#include<iostream>
using  std::cout,std::endl;

namespace fullyConnected {
    shared_ptr<FullyConnected> makeFullyConnected(int times,double rate,unsigned inp_hid_out[],unsigned hid_Cnt[],vector<TrainingSet> *trainDatas);
    vector<TrainingSet>* makeSet(vector<vector<double>*>* trainDatas,vector<vector<double>*>* trainAnswers);
}