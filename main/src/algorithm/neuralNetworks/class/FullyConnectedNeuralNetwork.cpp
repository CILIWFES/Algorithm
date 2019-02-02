//
// Created by ZC on 2019/1/29.
//


#include "algorithm/neuralNetworks/class/FullyConnectedNeuralNetwork.h"

auto FullyConnectedNeuralNetwork::random_engine(double mean,double standardDeviation) {
    auto closure=[mean,standardDeviation](double dump){
        return generate_random(mean, standardDeviation);
    };
    return closure;
}

FullyConnectedNeuralNetwork::FullyConnectedNeuralNetwork(unsigned int inp_hid_out[],unsigned int totalFloors, double mean,double standardDeviation) {
    if(totalFloors<=1){
        throw "请输入尺寸大于1";
    }
    auto random = this->random_engine(mean,standardDeviation);
    unsigned int inputSize = inp_hid_out[0];
    unsigned int outputSize = inp_hid_out[totalFloors-1];
    this->layerNeuronWeights->reserve(totalFloors);
    for(unsigned int i=1;i<totalFloors-1;i++){
        this->layerNeuronWeights->at(i - 1) = MatrixXd(inp_hid_out[i - 1], inp_hid_out[i]).unaryExpr(random);
    }
}

void FullyConnectedNeuralNetwork::conversion(VectorXd &outPut, short neuronType) {

}

void FullyConnectedNeuralNetwork::conversionDerivative(VectorXd &outPut, short neuronType) {

}

vector<VectorXd> *FullyConnectedNeuralNetwork::feedforwardCalculation(VectorXd input) {
    return nullptr;
}

VectorXd FullyConnectedNeuralNetwork::prediction(VectorXd input) {
    return Eigen::VectorXd();
}

double FullyConnectedNeuralNetwork::reverseTraining(vector<VectorXd> &layerNeuronOutputs, double rate) {
    return 0;
}
