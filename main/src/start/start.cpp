#include <iostream>
#include <string>
#include<memory>
#include "algorithm/neuralNetworks/connectedModule.h"


int main() {

    auto fullyConnected=fullyConnected::makeFullyConnected(1000, 0.1);
    auto* temp=new vector<double>({8,7});
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
