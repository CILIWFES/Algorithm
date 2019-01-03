#include"algorithm/neuralNetworks/class/connectedMod.h"
#include "algorithm/neuralNetworks/class/Neurons.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"
#include <iostream>

using namespace std;
namespace fullyConnected {
    vector<TrainingSet>& makeSet(){
        vector<TrainingSet> &sets = *new vector<TrainingSet>(
                { * new TrainingSet(*new vector<double>({1,1}),*new vector<double>({1})),
                  * new TrainingSet(*new vector<double>({0.78,1}),*new vector<double>({0})),
                  * new TrainingSet(*new vector<double>({0.4,1}),*new vector<double>({0})),
                  * new TrainingSet(*new vector<double>({0.89,0}),*new vector<double>({0})),
                  * new TrainingSet(*new vector<double>({1,1}),*new vector<double>({1})),
                  * new TrainingSet(*new vector<double>({1,0}),*new vector<double>({0})),
                  * new TrainingSet(*new vector<double>({0.5,0}),*new vector<double>({0})),
                  * new TrainingSet(*new vector<double>({0,0.4}),*new vector<double>({0})),
                  * new TrainingSet(*new vector<double>({0,0.1}),*new vector<double>({0}))
                }
                );

        return sets;
    }
    int start(int times) {
        int nowTime = 0;
        double range=0.0001;
        FullyConnected* fullyConnected=new FullyConnected(2,1,1,{1},1);
        vector<TrainingSet>& sets=makeSet();
        do {
            for(unsigned i=0;i<sets.size();i++){
                auto temp=fullyConnected->predictionByTrain(sets.at(i));
                double rr=fullyConnected->trainNetWork(*temp,sets.at(i),range);
                cout << rr << endl;

            }
            nowTime++;
        } while (times >nowTime);
        delete fullyConnected;
        return 4;
    }
}
