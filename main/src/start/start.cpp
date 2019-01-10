
#include "algorithm/neuralNetworks/ConnectedModule.h"


int main() {
    int trainInt=6;
    vector<vector<double>*>* trainDatas=new vector<vector<double>*>(0);
    trainDatas->reserve(trainInt*2*trainInt*2);
    vector<vector<double>*>* trainAnswers=new vector<vector<double>*>(0);
    trainAnswers->reserve(trainInt*2*trainInt*2);

    for(int i=-trainInt;i<trainInt;i++){

        for(int j=-trainInt;j<trainInt;j++){
            trainDatas->push_back(new vector<double>{i*1.0,j*1.0});
            trainAnswers->push_back(new vector<double>{1.0 / (1 + pow(e, -1.0*(4*i+j)))});
        }
    }



    unsigned inp_hid_out[]={2,1,1};
    unsigned hid_Cnt[]={1};
    auto trainTemp = fullyConnected::makeSet(*trainDatas, *trainAnswers);
    delete trainDatas;
    delete trainAnswers;

    int randRange[]={-4,4};
    auto fullyConnected=fullyConnected::makeFullyConnected(10000, 0.001,inp_hid_out,hid_Cnt,trainTemp,randRange,0);

    auto* temp=new vector<double>({4,1});
    shared_ptr<vector<double>> ret(fullyConnected->prediction(*temp));
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
