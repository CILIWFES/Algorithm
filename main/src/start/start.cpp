
#include "algorithm/neuralNetworks/ConnectedModule.h"


int main() {
    int trainInt=10;
    vector<vector<double>*>* trainDatas=new vector<vector<double>*>(0);
    trainDatas->reserve(2*trainInt*2*trainInt);
    vector<vector<double>*>* trainAnswers=new vector<vector<double>*>(0);
    trainAnswers->reserve(2*trainInt*2*trainInt);

    for(double i=-trainInt;i<trainInt;i+=1){

        for(double j=-trainInt;j<trainInt;j+=1){
            trainDatas->push_back(new vector<double>{i*1.0,j*1.0});
            trainAnswers->push_back(new vector<double>{i>=0?(j>=0?1.0:0.0):(j<0?1.0:0.0)});
        }
    }
//    trainDatas->push_back(new vector<double>{0,1});
//    trainDatas->push_back(new vector<double>{1,0});
//    trainDatas->push_back(new vector<double>{1,1});
//    trainDatas->push_back(new vector<double>{0,0});
//    trainAnswers->push_back(new vector<double>{0});
//    trainAnswers->push_back(new vector<double>{0});
//    trainAnswers->push_back(new vector<double>{1});
//    trainAnswers->push_back(new vector<double>{1});



    unsigned inp_hid_out[]={2,4,2,1};
    auto trainTemp = fullyConnected::makeSet(*trainDatas, *trainAnswers);
    delete trainDatas;
    delete trainAnswers;

    int randRange[]={-2,2};
    auto fullyConnected=fullyConnected::makeFullyConnected(5000, 1,inp_hid_out,4,trainTemp,randRange,0);

    auto* temp=new vector<double>({-8,5});
    shared_ptr<vector<double>> ret(fullyConnected->prediction(*temp));
    cout<<"prediction \t";
    for(unsigned i=0;i<ret->size();i++){
        if(i==ret->size()-1){
            cout<<ret->at(i)<<"\t"<<(temp->at(0)>=0?( temp->at(1)>=0?1.0:0.0):( temp->at(1)<0?1.0:0.0)) <<endl;
        }else{
            cout<<ret->at(i)<<"\t";
        }
    }

    temp=new vector<double>({-6,-1});
    shared_ptr<vector<double>> ret1(fullyConnected->prediction(*temp));
    cout<<"prediction \t";
    for(unsigned i=0;i<ret1->size();i++){
        if(i==ret1->size()-1){
            cout<<ret1->at(i)<<"\t"<<(temp->at(0)>=0?( temp->at(1)>=0?1.0:0.0):( temp->at(1)<0?1.0:0.0)) <<endl;
        }else{
            cout<<ret1->at(i)<<"\t";
        }
    }
    delete temp;
    return 0;
}
