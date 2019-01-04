#include"algorithm/neuralNetworks/class/connectedMod.h"
#include "algorithm/neuralNetworks/class/Neurons.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"
#include <iostream>

using namespace std;
namespace fullyConnected {
    vector<TrainingSet>* makeSet(){
        vector<TrainingSet> *sets = new vector<TrainingSet>(
                {
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({1,1})),shared_ptr<vector<double>>(new vector<double>({1}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({1,0})),shared_ptr<vector<double>>(new vector<double>({1}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({0,1})),shared_ptr<vector<double>>(new vector<double>({1}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({0,0})),shared_ptr<vector<double>>(new vector<double>({0})))
                }
                );

        return sets;
    }
    double start(int times,double rate) {
        unsigned inp_hid_out[]={2,1,1};
        unsigned hid_Cnt[]={1};
        shared_ptr<FullyConnected> fullyConnected(new FullyConnected(inp_hid_out,hid_Cnt,1));
        shared_ptr<vector<TrainingSet>> sets(makeSet());
        double error=fullyConnected->startTrain(*sets,1000,rate,0);
        return error;
    }
}
