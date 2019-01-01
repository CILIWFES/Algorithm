#pragma once

#include "algorithm/neuralNetworks/class/Neurons.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"

class FullyConnected {
public:
    FullyConnected(int inputCnts,int hiddenCnts,int outputCnts,vector<unsigned long long int> hidden_W,int randRange);
    void prediction(vector<double>& set);
    vector<vector<double>> predictionByTrain(TrainingSet& set);

    ~FullyConnected();
private:
    int inputCnts;
    int hiddenCnts;
    int outputCnts;
    vector<vector<Neurons>>& hidden;
    vector<Neurons>& outPut;

};