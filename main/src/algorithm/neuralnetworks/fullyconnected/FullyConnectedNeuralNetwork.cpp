
#include <algorithm/neuralNetworks/FullyConnectedNeuralNetwork.h>

//全连接打印次数
unsigned int NUMBEROFPRINTS = 10;

auto FullyConnectedNeuralNetwork::random_engine(double mean, double standardDeviation) {
    static auto closure = [mean, standardDeviation](double dump) {
        return random_evenly_distributed(mean, standardDeviation);
    };
    return closure;
}

FullyConnectedNeuralNetwork::FullyConnectedNeuralNetwork(unsigned int* inp_hid_out, unsigned int totalFloors,
                                                         double startNum, double endNum) {
    if (totalFloors <= 1) {
        throw "请输入尺寸大于1";
    }
    //Generating closure
    auto random = this->random_engine(startNum, endNum);

    //set the neuron list capacity
    this->layerNeuronWeights.reserve(totalFloors);

    //Random input matrix weight
    this->layerNeuronWeights.emplace_back(MatrixXd(inp_hid_out[0], inp_hid_out[0]));
    this->layerNeuronWeights.at(0).setIdentity();

    //Generating RandomMatrix
    for (unsigned int i = 1; i < totalFloors; i++) {
        //Generating matrix and randomize
        this->layerNeuronWeights.emplace_back(MatrixXd(inp_hid_out[i], inp_hid_out[i - 1]).unaryExpr(random));
    }
}

void FullyConnectedNeuralNetwork::conversion(VectorXd &outPut) {
    outPut.array() = (1 / (1 + pow(E, -outPut.array())));
}

VectorXd FullyConnectedNeuralNetwork::conversionDerivative(VectorXd &outPut) {
    auto derivative = outPut.array() * (1 - outPut.array());
    return derivative;
}

vector<VectorXd> FullyConnectedNeuralNetwork::feedforwardCalculation(VectorXd &trainDate) {
    vector<VectorXd> recording(0);
    recording.reserve(this->layerNeuronWeights.size());
    VectorXd lastOutput(trainDate);

    for (unsigned int i = 0; i < this->layerNeuronWeights.size(); ++i) {
        auto &item = this->layerNeuronWeights.at(i);
        lastOutput = (item * lastOutput).transpose();
        if (i != 0)this->conversion(lastOutput);
        recording.emplace_back(lastOutput);
    }
    return recording;
}

VectorXd FullyConnectedNeuralNetwork::prediction(VectorXd &input) {
    VectorXd lastOutput = input;
    for (unsigned int i = 0; i < this->layerNeuronWeights.size(); ++i) {
        auto &item = this->layerNeuronWeights.at(i);
        lastOutput = (item * lastOutput).transpose();
        if (i != 0)this->conversion(lastOutput);
    }
    return lastOutput;
}

VectorXd FullyConnectedNeuralNetwork::train(vector<VectorXd> &trainData, vector<VectorXd> &answer, int train_model,
                                            unsigned int times, double rate) {
    if (trainData.size() != answer.size()) {
        throw "训练集大小与训练答案大小不一致";
    }

    /**前期准备**/
    long long trainSize = trainData.size();
    unsigned int nowTimes = 0;
    long long  outLayers = this->layerNeuronWeights.back().rows();
    //使用输出层神经元个数来初始化向量
    VectorXd errRate = VectorXd(outLayers);

    /**批量训练准备**/
    //批量训练参数,平均输出
    vector<VectorXd> avgOut(0);
    //批量训练参数,平均误差导数
    VectorXd avg_errD(0);
    //批量训练初始化
    if (train_model == 2) {
        unsigned long long layerSize = this->layerNeuronWeights.size();
        avgOut.reserve(layerSize);
        for (unsigned int i = 0; i < layerSize; i++) {
            //输出尺寸=下一神经元个数,输出层便为自身神经元尺寸
            auto &item = this->layerNeuronWeights.at(i);
            avgOut.emplace_back(VectorXd(item.rows()));
        }
        avg_errD = VectorXd(outLayers);
    }

    /**主流程**/
    do {
        /**清除标记**/
        //批量训练清0
        if (train_model == 2) {
            avg_errD.setZero();
            for (auto &item:avgOut) item.setZero();
        }

        /**开始前馈**/
        for (unsigned int i = 0; i < trainSize; ++i) {
            //前馈计算
            auto out = this->feedforwardCalculation(trainData.at(i));
            //计算误差
            VectorXd err = this->calculationError(out.back(), answer.at(i));
            //计算误差导数
            VectorXd errD = this->calculatedErrorDerivative(out.back(), answer.at(i));

            //记录误差
            if (nowTimes % (times / NUMBEROFPRINTS) == 0) errRate += err / trainSize;

            /**模式分支**/
            if (train_model == 1) {
                /**单次训练**/
                this->reverseTraining(out, errD, rate);
            } else if (train_model == 2) {
                //计算批量训练参数
                avg_errD += errD / trainSize;

                for (unsigned int layOut = 0; layOut < out.size(); layOut++) {
                    avgOut.at(layOut) += out.at(layOut) / trainSize;
                }
            }
        }
        /**批量训练位置**/
        if (train_model == 2) this->reverseTraining(avgOut, avg_errD, rate);
        //打印进程
        if (nowTimes % (times / NUMBEROFPRINTS) == 0) {
            cout << "numberOfTimes:\t" << nowTimes + 1 << "\t avg_errorRate:\t" << errRate << endl;
            errRate.setZero();
        };
        nowTimes++;
    } while (times > nowTimes);
    return errRate;
}

void FullyConnectedNeuralNetwork::reverseTraining(vector<VectorXd> &layerNeuronOutputs, VectorXd &errorDerivative,
                                                  double rate) {
    VectorXd derivative = errorDerivative;
    
    //无需训练输入层
    for (unsigned  long long i = layerNeuronOutputs.size() - 1; i >= 1; i--) {
        MatrixXd &weight = this->layerNeuronWeights.at(i);
        VectorXd &lastOutput = layerNeuronOutputs.at(i);
        //---计算输出层修正值
        //计算当前神经层修正系数 eh=last_eh/err * c(f(x))'
        derivative = derivative.cwiseProduct(this->conversionDerivative(lastOutput));
        //获取输入值 x
        VectorXd &lastIntput = layerNeuronOutputs.at(i - 1);
        //计算权重修改值 △w=η*eh*x
        MatrixXd changeVal = rate * (derivative * (lastIntput.transpose()));
        //---计算上一层修正系数 befor_eh(beforlayer_no_* c(f(x)))=∑w(layer)*eh(layer)
        if (i != 1) derivative = (weight.transpose() * derivative).transpose();
        //修改当前权重
        weight += changeVal;
    }
}

VectorXd FullyConnectedNeuralNetwork::calculationError(VectorXd output, VectorXd answer) {
    return pow(answer.array() - output.array(), 2) / 2.0;
}

VectorXd FullyConnectedNeuralNetwork::calculatedErrorDerivative(VectorXd output, VectorXd answer) {
    return answer - output;
}


string FullyConnectedNeuralNetwork::getSerialization() {
    return string();
}
//
//FullyConnectedNeuralNetwork* FullyConnectedNeuralNetwork::Serialization(string serialization) {
//    return FullyConnectedNeuralNetwork(nullptr, 0, 0, 0);
//}
