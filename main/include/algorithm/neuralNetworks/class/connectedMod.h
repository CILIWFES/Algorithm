#pragma once

#include "algorithm/neuralNetworks/class/Neurons.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"

class FullyConnected {
public:
    FullyConnected(int inputCnts,int hiddenCnts,int outputCnts,vector<unsigned long long int> hidden_W,int randRange);

    ~FullyConnected();
    vector<double> prediction(vector<double>& set);

    double trainNetWork(vector<vector<double>>& vec,TrainingSet& set,double rate);
    vector<vector<double>>* predictionByTrain(TrainingSet& set);


protected:
    vector<double> collectW(vector<double>& slop,vector<vector<double>>& w,vector<double>&lastVal);
    vector<vector<double>>* tarinLayer(vector<Neurons>&vec,vector<double>& slop,vector<double>& lastval,double rate);
    vector<double> calculateLayer(vector<Neurons>&vec,vector<double>& input);

private:
    int inputCnts;
    int hiddenCnts;
    int outputCnts;
    vector<vector<Neurons>>& hidden;
    vector<Neurons>& outPut;

};
namespace fullyConnected {
    int start(int times);
}