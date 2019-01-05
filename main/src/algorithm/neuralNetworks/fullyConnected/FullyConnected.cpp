//
// Created by ZC on 2019/1/1.
//

#include"algorithm/neuralNetworks/class/connectedMod.h"
#include "algorithm/neuralNetworks/class/Neurons.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"


FullyConnected::FullyConnected(unsigned inp_hid_out[], unsigned hid_Cnt[], int randRange){
    //记录数据
    unsigned inputCnts=inp_hid_out[0];
    unsigned hiddenCnts=inp_hid_out[1];
    unsigned outputCnts=inp_hid_out[2];
    //记录权重
    unsigned weightCnt = inputCnts;
    this->hidden.reset(new vector<vector<Neurons>>(hiddenCnts));
    this->outPut.reset(new vector<Neurons>(outputCnts));

    //初始化神经网络(层数(具体个数))
    for (unsigned i = 0; i < hidden->size(); ++i) {
        hidden->at(i) = vector<Neurons>(hid_Cnt[i]);
        vector<Neurons>& item=hidden->at(i);
        //手动初始化
        for (unsigned  j = 0; j < hid_Cnt[i]; j++) {
            item.at(j)= Neurons(weightCnt, randRange);
        }
        //下一个权重
        weightCnt = item.size();
    }

    //赋值给神经网络输出层
    for (auto &i : *outPut) {
        i = Neurons(weightCnt, randRange);
    }

}

/**
 * 开始训练
 * @param vec 历史各层输出
 * @return
 */
double FullyConnected::trainByPrediction(vector<vector<double>> &hiddenOutPut, TrainingSet &trainingSet, double rate){
    double ret = 0;
    //先计算起始斜率
    shared_ptr<vector<double>> slop( new vector<double>(trainingSet.trainAnswer->size()));
    //set.trainAnswer.size()必须与误差相等
    for (unsigned  i = 0; i < trainingSet.trainAnswer->size(); i++) {
        double prediction = trainingSet.prediction->at(i);
        //负的输出-标出
        double reduce = -(prediction-trainingSet.trainAnswer->at(i));
        ret += reduce * reduce*0.5;
        //输出层误差斜率
        slop->at(i) = (reduce) * prediction * (1 - prediction);
    }
    ret /= trainingSet.trainAnswer->size();
    //传入输出层
    shared_ptr<vector<vector<double>>> oldW (this->tarinLayer(*this->outPut, *slop,hiddenOutPut.at(hiddenOutPut.size()-1), rate));
    //重置slop
    slop.reset(&this->calculationWeight(*slop, *oldW,hiddenOutPut.at(hiddenOutPut.size()-1)));

    for (unsigned  i = hiddenOutPut.size() - 1; i >= 1; i--) {
        //历史权重
        //上一层输出
        auto &historicalTemp=hiddenOutPut.at(i - 1);
        oldW = this->tarinLayer(this->hidden->at(i), *slop, historicalTemp, rate);
        slop.reset(&this->calculationWeight(*slop, *oldW, historicalTemp));
    }

    this->tarinLayer(this->hidden->at(0), *slop, *trainingSet.trainDatas, rate);

    return ret;
}


vector<double>& FullyConnected::calculationWeight(vector<double> &slop, vector<vector<double>> &oldW, vector<double> &lastOutput) {
    //构建上一神经元斜率
    vector<double>& temp =*new vector<double>(lastOutput.size());
    //以当前斜率与旧权重,构建上个全重
    for (unsigned i = 0; i < slop.size(); i++) {
        double item = slop.at(i);
        auto tempW = oldW.at(i);
        for (unsigned j = 0; j < tempW.size(); j++) {
            temp.at(j) += item * tempW.at(j);
        }
    }
    //signmod
    for (unsigned i = 0; i < temp.size(); i++) {
        temp.at(i) *= lastOutput.at(i) * (1 - lastOutput.at(i));
    }
    return temp;
}



shared_ptr<vector<double>> FullyConnected::prediction(vector<double> &dataSet){
    //深度复制
    shared_ptr<vector<double>> val(new vector<double>(dataSet));

    for (int layer = 0; layer < this->hidden->size(); layer++) {
        //输入隐层
        //获取隐层数值
        val = this->predictionLayer(this->hidden->at(layer), *val);
    }
    //获取输出层
    return this->predictionLayer(*this->outPut, *val);
}


shared_ptr<vector<double>> FullyConnected::predictionLayer(vector<Neurons> &neurons, vector<double> &inputDatas){
    shared_ptr<vector<double>> rets(new vector<double>(neurons.size()));
    for (unsigned i = 0; i < neurons.size(); i++) {
        Neurons &item = neurons.at(i);
        double val = item.calculate(inputDatas);
        rets->at(i) = item.conversion(val);
    }
    return rets;
}


shared_ptr<vector<vector<double>>> FullyConnected::predictionByTrain(TrainingSet &tarinSet){
    shared_ptr<vector<vector<double>>> ret(new vector<vector<double>>(this->hidden->size()));
    shared_ptr<vector<double>> val (new vector<double>(*tarinSet.trainDatas));

    for (unsigned layer = 0; layer < this->hidden->size(); layer++) {
        //输入隐层
        //获取隐层数值
        val=this->predictionLayer(this->hidden->at(layer), *val);
        //深度复制
        ret->at(layer) =*val;
    }
    val = this->predictionLayer(*this->outPut, *val);
    tarinSet.prediction.reset(new vector<double>(*val));
    return ret;
}


shared_ptr<vector<vector<double>>> FullyConnected::tarinLayer(vector<Neurons> &neurons,vector<double> &slop, vector<double>&lastIntput,double rate){
    //记录神经元的旧权重
    shared_ptr<vector<vector<double>>> ret(new vector<vector<double>>(neurons.size()));

    for (unsigned i = 0; i < slop.size(); i++) {
        auto& item = neurons.at(i);
        //获取旧权重
        ret->at(i) = item.correct(lastIntput, slop.at(i), rate);
    }
    return ret;
}
double FullyConnected::startTrain(vector<TrainingSet> &trainSets, int times, double rate, int modelCheck=0){
    unsigned nowTime=0;
    double  error=0;
    int  showTime=times/20;
    do {
        error=0l;
        for(unsigned i=0;i<trainSets.size();i++){
            auto& trainSet = trainSets.at(i);
            auto hiddOutput=this->predictionByTrain(trainSet);
            error+=this->trainByPrediction(*hiddOutput,trainSet,rate);
        }
        nowTime++;
        if ((nowTime - 1) % showTime == 0) {
            cout<<"No:\t"<<nowTime<<"\ttraining,AverageError is :\t"<<error/trainSets.size()<<endl;
        }
    } while (times >nowTime);
    return error;
}
FullyConnected::~FullyConnected() {

}
