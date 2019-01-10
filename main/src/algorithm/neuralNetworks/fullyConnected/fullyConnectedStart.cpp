
#include "algorithm/neuralNetworks/ConnectedModule.h"

namespace fullyConnected {

    shared_ptr<FullyConnected> makeFullyConnected(int times,double rate,unsigned inp_hid_out[],unsigned hid_Cnt[],vector<TrainingSet> *trainDatas,int randRange[],int checkModel) {
        shared_ptr<FullyConnected> fullyConnected(new FullyConnected(inp_hid_out,hid_Cnt,randRange));
        shared_ptr<vector<TrainingSet>> sets(trainDatas);
        fullyConnected->startTrain(*sets,times,rate,checkModel);
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
