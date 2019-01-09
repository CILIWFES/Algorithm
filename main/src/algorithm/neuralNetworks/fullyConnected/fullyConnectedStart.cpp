
#include "algorithm/neuralNetworks/ConnectedModule.h"

namespace fullyConnected {

    shared_ptr<FullyConnected> makeFullyConnected(int times,double rate,vector<vector<double>>* trainDatas,vector<vector<double>>* trainAnswers) {
        makeSet(trainDatas,trainAnswers);
//        unsigned inp_hid_out[]={2,2,1};
//        unsigned hid_Cnt[]={2,2};
//        shared_ptr<FullyConnected> fullyConnected(new FullyConnected(inp_hid_out,hid_Cnt,2));
//        shared_ptr<vector<TrainingSet>> sets=move(makeSet(trainDatas,trainAnswers));
//
//        fullyConnected->startTrain(*sets,times,rate,0);
        return nullptr;
    }

    shared_ptr<vector<TrainingSet>> makeSet(vector<vector<double>>* trainDatas,vector<vector<double>>* trainAnswers){
        if (trainDatas->size() != trainAnswers->size()) {
            throw "数量不一致";
        }
        shared_ptr<vector<TrainingSet>> sets(new vector<TrainingSet>(trainAnswers->size()));
        for (unsigned i = 0; i < trainAnswers->size(); i++) {
            auto trainData=&(trainDatas->at(i));
            auto trainAnswer=&(trainAnswers->at(i));
            sets->at(i)=TrainingSet(trainData, trainAnswer);
        }
        return nullptr;
    }

}
