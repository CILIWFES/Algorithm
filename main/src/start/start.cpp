
#include "algorithm/neuralNetworks/ConnectedModule.h"


int main() {
    unsigned trainInt=7;
    vector<vector<double>>* trainDatas=new vector<vector<double>>(0);
    trainDatas->reserve(trainInt);
    vector<vector<double>>* trainAnswers=new vector<vector<double>>(0);
    trainAnswers->reserve(trainInt);

    trainDatas->push_back(vector<double>{1,2});
    trainAnswers->push_back(vector<double>{0});

    trainDatas->push_back(vector<double>{5,4});
    trainAnswers->push_back(vector<double>{0});

    trainDatas->push_back(vector<double>{2,3});
    trainAnswers->push_back(vector<double>{0});

    trainDatas->push_back(vector<double>{5,6});
    trainAnswers->push_back(vector<double>{0});
    trainDatas->push_back(vector<double>{8,7});
    trainAnswers->push_back(vector<double>{0});

    trainDatas->push_back(vector<double>{2,2});
    trainAnswers->push_back(vector<double>{1});

    trainDatas->push_back(vector<double>{5,5});
    trainAnswers->push_back(vector<double>{1});

    trainDatas->push_back(vector<double>{1,1});
    trainAnswers->push_back(vector<double>{1});

    fullyConnected::makeSet(trainDatas,trainAnswers);
//
//    auto fullyConnected=fullyConnected::makeFullyConnected(1000, 0.1,trainDatas,trainAnswers);
//    auto* temp=new vector<double>({8,7});
//    auto ret=fullyConnected->prediction(*temp);
//    cout<<"prediction \t";
//    for(unsigned i=0;i<ret->size();i++){
//        if(i==ret->size()-1){
//            cout<<ret->at(i)<<endl;
//        }else{
//            cout<<ret->at(i)<<"\t";
//        }
//    }
//    delete temp;
    return 0;
}
