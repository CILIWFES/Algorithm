
#include "algorithm/neuralNetworks/ConnectedModule.h"


int main() {
    unsigned trainInt=7;
    vector<vector<double>*>* trainDatas=new vector<vector<double>*>(0);
    trainDatas->reserve(trainInt);
    vector<vector<double>*>* trainAnswers=new vector<vector<double>*>(0);
    trainAnswers->reserve(trainInt);

    trainDatas->push_back(new vector<double>{0,-1});
    trainAnswers->push_back(new vector<double>{0});

    trainDatas->push_back(new vector<double>{-1,1});
    trainAnswers->push_back(new vector<double>{0});

    trainDatas->push_back(new vector<double>{-1,-1});
    trainAnswers->push_back(new vector<double>{1});

    trainDatas->push_back(new vector<double>{1,-1});
    trainAnswers->push_back(new vector<double>{0});

    trainDatas->push_back(new vector<double>{0,0});
    trainAnswers->push_back(new vector<double>{1});

    trainDatas->push_back(new vector<double>{0,1});
    trainAnswers->push_back(new vector<double>{0});

    trainDatas->push_back(new vector<double>{1,1});
    trainAnswers->push_back(new vector<double>{1});

    trainDatas->push_back(new vector<double>{1,0});
    trainAnswers->push_back(new vector<double>{0});

    unsigned inp_hid_out[]={2,2,1};
    unsigned hid_Cnt[]={2,2};
    auto trainTemp = fullyConnected::makeSet(trainDatas, trainAnswers);
    auto fullyConnected=fullyConnected::makeFullyConnected(10000, 0.1,inp_hid_out,hid_Cnt,trainTemp);
    delete trainDatas;
    auto* temp=new vector<double>({1,1});
    auto ret=fullyConnected->prediction(*temp);
    cout<<"prediction \t";
    for(unsigned i=0;i<ret->size();i++){
        if(i==ret->size()-1){
            cout<<ret->at(i)<<endl;
        }else{
            cout<<ret->at(i)<<"\t";
        }
    }
    delete temp;
    return 0;
}
