
#include "algorithm/neuralNetworks/ConnectedModule.h"


int main() {
    int trainInt=1;
    vector<vector<double>*>* trainDatas=new vector<vector<double>*>(0);
    trainDatas->reserve(2*trainInt*100);
    vector<vector<double>*>* trainAnswers=new vector<vector<double>*>(0);
    trainAnswers->reserve(2*trainInt*100);

    for(double i=-trainInt;i<trainInt;i+=0.1){

        for(double j=-trainInt;j<trainInt;j+=0.1){
            trainDatas->push_back(new vector<double>{i*1.0,j*1.0});
            trainAnswers->push_back(new vector<double>{i>=0?(j>=0?1.0:0.0):(j<0?1.0:0.0)});
        }
    }

    unsigned inp_hid_out[]={2,2,1};
    auto trainTemp = fullyConnected::makeSet(*trainDatas, *trainAnswers);
    delete trainDatas;
    delete trainAnswers;

    int randRange[]={-2,2};
    auto fullyConnected=fullyConnected::makeFullyConnected(10000, 1,inp_hid_out,3,trainTemp,randRange,0);

    auto* temp=new vector<double>({1,1});
    shared_ptr<vector<double>> ret(fullyConnected->prediction(*temp));
    cout<<"prediction \t";
    for(unsigned i=0;i<ret->size();i++){
        if(i==ret->size()-1){
            cout<<ret->at(i)<<"\t"<<(sin(temp->at(0)*temp->at(1))>0?1.0:0.0) <<endl;
        }else{
            cout<<ret->at(i)<<"\t";
        }
    }
    delete temp;
    return 0;
}
