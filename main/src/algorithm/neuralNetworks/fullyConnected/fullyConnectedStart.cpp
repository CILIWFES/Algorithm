
#include "algorithm/neuralNetworks/ConnectedModule.h"

namespace fullyConnected {

    shared_ptr<FullyConnected> makeFullyConnected(int times,double rate,unsigned inp_hid_out[],unsigned totalFloors,vector<TrainingSet> *trainDatas,int randRange[],int trainModel) {
        shared_ptr<FullyConnected> fullyConnected(new FullyConnected(inp_hid_out,totalFloors,randRange));
        shared_ptr<vector<TrainingSet>> sets(trainDatas);
        fullyConnected->startTrain(*sets,times,rate,trainModel);
        return fullyConnected;
    }

    vector<TrainingSet>* makeSet(vector<vector<double>*>& trainDatas,vector<vector<double>*>& trainAnswers){
        if (trainDatas.size() != trainAnswers.size()) {
            throw "数量不一致";
        }
        vector<TrainingSet>* sets=new vector<TrainingSet>(trainAnswers.size());
        for (unsigned i = 0; i < trainAnswers.size(); i++) {
            sets->at(i)= move(TrainingSet(trainDatas.at(i), trainAnswers.at(i)));
        }
        return sets;
    }

}
