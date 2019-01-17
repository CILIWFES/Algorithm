
#include "algorithm/neuralNetworks/ConnectedModule.h"


int main() {
    int trainInt=10;
    vector<vector<double>*>* trainDatas=new vector<vector<double>*>(0);
    trainDatas->reserve(trainInt*2*trainInt*2);
    vector<vector<double>*>* trainAnswers=new vector<vector<double>*>(0);
    trainAnswers->reserve(trainInt*2*trainInt*2);

    for(int i=-trainInt;i<trainInt;i++){

        for(int j=-trainInt;j<trainInt;j++){
            trainDatas->push_back(new vector<double>{i*1.0,j*1.0});
            trainAnswers->push_back(new vector<double>{1.0 / (1 + pow(e, -(1.0*(4*i+j))/10000))});
        }
    }



    unsigned inp_hid_out[]={2,1,1};
    unsigned hid_Cnt[]={2};
    auto trainTemp = fullyConnected::makeSet(*trainDatas, *trainAnswers);
    delete trainDatas;
    delete trainAnswers;

    int randRange[]={-3,3};
    auto fullyConnected=fullyConnected::makeFullyConnected(100, 0.1,inp_hid_out,hid_Cnt,trainTemp,randRange,1);

    auto* temp=new vector<double>({3,9});
    shared_ptr<vector<double>> ret(fullyConnected->prediction(*temp));
    cout<<"prediction \t";
    for(unsigned i=0;i<ret->size();i++){
        if(i==ret->size()-1){
            cout<<ret->at(i)<<"\t"<<1.0 / (1 + pow(e, -(4* temp->at(0)+temp->at(1))/10000))<<endl;
        }else{
            cout<<ret->at(i)<<"\t";
        }
    }
    delete temp;
    return 0;
}
