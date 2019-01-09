#include"algorithm/neuralNetworks/connectedModule.h"
#include "algorithm/neuralNetworks/class/Neurons.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"

namespace fullyConnected {

    vector<TrainingSet>* makeSet(){
        vector<TrainingSet> *sets = new vector<TrainingSet>(
                {
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({1,1})),shared_ptr<vector<double>>(new vector<double>({1}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({3,3})),shared_ptr<vector<double>>(new vector<double>({1}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({2,2})),shared_ptr<vector<double>>(new vector<double>({1}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({1,0})),shared_ptr<vector<double>>(new vector<double>({0}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({8,7})),shared_ptr<vector<double>>(new vector<double>({0}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({0,0})),shared_ptr<vector<double>>(new vector<double>({1}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({0,1})),shared_ptr<vector<double>>(new vector<double>({0}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({2,1})),shared_ptr<vector<double>>(new vector<double>({0}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({1,2})),shared_ptr<vector<double>>(new vector<double>({0}))),
                    TrainingSet(shared_ptr<vector<double>>(new vector<double>({2,3})),shared_ptr<vector<double>>(new vector<double>({0})))
                }
                );

        return sets;
    }

    shared_ptr<FullyConnected> makeFullyConnected(int times,double rate) {
        unsigned inp_hid_out[]={2,1,1};
        unsigned hid_Cnt[]={2};
        shared_ptr<FullyConnected> fullyConnected(new FullyConnected(inp_hid_out,hid_Cnt,2));
        shared_ptr<vector<TrainingSet>> sets(makeSet());
        double error=fullyConnected->startTrain(*sets,times,rate,0);
        return fullyConnected;
    }
}
