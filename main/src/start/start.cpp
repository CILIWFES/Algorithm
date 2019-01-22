
#include "algorithm/neuralNetworks/ConnectedModule.h"


int main() {
    int trainInt=100;
    vector<vector<double>*>* trainDatas=new vector<vector<double>*>(0);
    trainDatas->reserve(2*trainInt);
    vector<vector<double>*>* trainAnswers=new vector<vector<double>*>(0);
    trainAnswers->reserve(2*trainInt);

    for(int i=-trainInt;i<trainInt;i++){

        for(int j=-trainInt;j<trainInt;j++){
            trainDatas->push_back(new vector<double>{i*1.0,j*1.0});
            trainAnswers->push_back(new vector<double>{sin(i*j)});
        }
    }


    unsigned inp_hid_out[]={2,10,10,8,1};
    auto trainTemp = fullyConnected::makeSet(*trainDatas, *trainAnswers);
    delete trainDatas;
    delete trainAnswers;

    int randRange[]={-10,10};
    auto fullyConnected=fullyConnected::makeFullyConnected(10000, 0.1,inp_hid_out,5,trainTemp,randRange,0);

    auto* temp=new vector<double>({8,9});
    shared_ptr<vector<double>> ret(fullyConnected->prediction(*temp));
    cout<<"prediction \t";
    for(unsigned i=0;i<ret->size();i++){
        if(i==ret->size()-1){
            cout<<ret->at(i)<<"\t"<<sin(temp->at(0)*temp->at(1))<<endl;
        }else{
            cout<<ret->at(i)<<"\t";
        }
    }
    delete temp;
    return 0;
}
