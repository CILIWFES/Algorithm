//
// Created by ZC on 2019/1/1.
//

#include"algorithm/neuralNetworks/ConnectedModule.h"
#include "algorithm/neuralNetworks/class/NeuronHidden.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"

struct {
    //增长倍率
    int growthRate=2;
    //结束倍率
    int endRate=10000;
    //初始值
    double initialValue=0;
    //增长因子
    double growthFactor=2;
    //展示次数
    int showTime=20;
}info;

FullyConnected::FullyConnected(unsigned inp_hid_out[], unsigned hid_Cnt[], int randRange[]){
    //记录数据
    unsigned inputCnts=inp_hid_out[0];
    unsigned hiddenCnts=inp_hid_out[1];
    unsigned outputCnts=inp_hid_out[2];
    //记录权重
    unsigned weightCnt = inputCnts;
    this->intPut.reset(new vector<NeuronInput>(inputCnts));
    this->hidden.reset(new vector<vector<NeuronHidden>>(hiddenCnts));
    this->outPut.reset(new vector<NeuronOutput>(outputCnts));

    //初始化神经网络(层数(具体个数))
    for (unsigned i = 0; i < hidden->size(); ++i) {
        hidden->at(i) = vector<NeuronHidden>(hid_Cnt[i]);
        vector<NeuronHidden>& item=hidden->at(i);
        //手动初始化
        for (unsigned  j = 0; j < hid_Cnt[i]; j++) {
            item.at(j)= NeuronHidden(weightCnt, randRange);
        }
        //下一个权重
        weightCnt = item.size();
    }

    //赋值给神经网络输出层
    for (auto &i : *outPut) {
        i = NeuronOutput(weightCnt, randRange);
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
    shared_ptr<vector<double>> slop( new vector<double>(trainingSet.trainAnswers->size()));
    //set.trainAnswers.size()必须与误差尺寸相等
    //计算初始斜率
    for (unsigned  i = 0; i < trainingSet.trainAnswers->size(); i++) {
        double prediction = trainingSet.prediction->at(i);
        //负的输出-标出
        double reduce = -(prediction-trainingSet.trainAnswers->at(i));
        ret += reduce * reduce*0.5;
        //输出层误差斜率
        slop->at(i) = (reduce) *this->outPut->at(i).conversionDerivative(prediction);
    }
    ret /= trainingSet.trainAnswers->size();
    //传入输出层
    shared_ptr<vector<vector<double>>> oldW (this->tarinLayer_Out(*this->outPut, *slop,hiddenOutPut.at(hiddenOutPut.size()-1), rate));
    //重置slop
    slop.reset(this->calculationWeight(this->hidden->at(this->hidden->size()-1),*slop, *oldW,hiddenOutPut.at(hiddenOutPut.size()-1)));

    for (unsigned  i = hiddenOutPut.size() - 1; i >= 1; i--) {
        //上一层输出
        auto &historicalTemp=hiddenOutPut.at(i - 1);
        oldW .reset(this->tarinLayer(this->hidden->at(i), *slop, historicalTemp, rate));
        slop.reset(this->calculationWeight(this->hidden->at(i-1),*slop, *oldW, historicalTemp));
    }

    this->tarinLayer(this->hidden->at(0), *slop, *trainingSet.trainDatas, rate);

    return ret;
}


vector<double>* FullyConnected::calculationWeight(vector<NeuronHidden> &beforNeurons,vector<double> &slop, vector<vector<double>> &oldW, vector<double> &lastOutput) {
    //构建上一神经元斜率
    vector<double>* temp =new vector<double>(lastOutput.size());
    //以当前斜率与旧权重,构建上个全重
    for (unsigned i = 0; i < slop.size(); i++) {
        double item = slop.at(i);
        auto tempW = oldW.at(i);
        for (unsigned j = 0; j < tempW.size(); j++) {
            temp->at(j) += item * tempW.at(j);
        }
    }
    for (unsigned i = 0; i < temp->size(); i++) {
        temp->at(i) *=beforNeurons.at(i).conversionDerivative(lastOutput.at(i));
    }
    return temp;
}



vector<double>* FullyConnected:: prediction(vector<double> &dataSet){
    //深度复制
    shared_ptr<vector<double>> val(this->predictionLayer_Input(*this->intPut, dataSet));

    for (unsigned layer = 0; layer < this->hidden->size(); layer++) {
        //输入隐层
        //获取隐层数值
        val.reset(this->predictionLayer(this->hidden->at(layer), *val));
    }
    //获取输出层
    return this->predictionLayer_Output(*this->outPut, *val);
}


vector<double>* FullyConnected::predictionLayer(vector<NeuronHidden> &neurons, vector<double> &inputDatas){
    vector<double>* rets(new vector<double>(neurons.size()));
    for (unsigned i = 0; i < neurons.size(); i++) {
        auto &item = neurons.at(i);
        double val = item.calculate(inputDatas);
        rets->at(i) = item.conversion(val);
    }
    return rets;
}

vector<double>* FullyConnected::predictionLayer_Output(vector<NeuronOutput> &neurons, vector<double> &inputDatas){
    vector<double>* rets(new vector<double>(neurons.size()));
    for (unsigned i = 0; i < neurons.size(); i++) {
        auto &item = neurons.at(i);
        double val = item.calculate(inputDatas);
        rets->at(i) = item.conversion(val);
    }
    return rets;
}
vector<double>* FullyConnected::predictionLayer_Input(vector<NeuronInput> &neurons, vector<double> &inputDatas){
    vector<double>* rets(new vector<double>(neurons.size()));
    for (unsigned i = 0; i < neurons.size(); i++) {
        auto &item = neurons.at(i);
        double val = item.calculate(inputDatas.at(i));
        rets->at(i) = item.conversion(val);
    }
    return rets;
}


vector<vector<double>>* FullyConnected::predictionByTrain(TrainingSet &tarinSet){
    vector<vector<double>>* ret(new vector<vector<double>>(this->hidden->size()));
    shared_ptr<vector<double>> val(this->predictionLayer_Input(*this->intPut, *tarinSet.trainDatas));


    for (unsigned layer = 0; layer < this->hidden->size(); layer++) {
        //输入隐层
        //获取隐层数值
        val.reset(this->predictionLayer(this->hidden->at(layer), *val));
        //深度复制
        ret->at(layer) =*val;
    }
    val.reset(this->predictionLayer_Output(*this->outPut, *val));
    tarinSet.prediction.reset(new vector<double>(*val));
    return ret;
}

vector<vector<double>>* FullyConnected::tarinLayer(vector<NeuronHidden> &neurons,vector<double> &slop, vector<double>&lastIntput,double rate){
    //记录神经元的旧权重
    vector<vector<double>>* ret(new vector<vector<double>>(neurons.size()));

    for (unsigned i = 0; i < slop.size(); i++) {
        auto& item = neurons.at(i);
        //获取旧权重
        ret->at(i) = item.correct(lastIntput, slop.at(i), rate);
    }
    return ret;
}

vector<vector<double>>* FullyConnected::tarinLayer_Out(vector<NeuronOutput> &neurons,vector<double> &slop, vector<double>&lastIntput,double rate){
    //记录神经元的旧权重
    vector<vector<double>>* ret(new vector<vector<double>>(neurons.size()));

    for (unsigned i = 0; i < slop.size(); i++) {
        auto& item = neurons.at(i);
        //获取旧权重
        ret->at(i) = item.correct(lastIntput, slop.at(i), rate);
    }
    return ret;
}

double FullyConnected::singleTraining(TrainingSet &trainSet,double rate){
    shared_ptr<vector<vector<double>>> hiddenOutput(this->predictionByTrain(trainSet));
    double error=this->trainByPrediction(*hiddenOutput,trainSet,rate);
    return error;
}

double FullyConnected::multipleTraining(vector<TrainingSet> &trainSets,double rate){
    double error=0;
    shared_ptr<vector<vector<double>>> hiddenOutput(new vector<vector<double>>(this->hidden->size()));
    shared_ptr<TrainingSet> tempTrain (new TrainingSet());
    int size=trainSets.size();
    for(unsigned i=0;i<size;i++){
        auto& trainSet = trainSets.at(i);
        shared_ptr<vector<vector<double>>> tempOutput(this->predictionByTrain(trainSet));
        this->mergeTrainSet(*tempTrain, trainSet,size);
        this->mergeOutput(*hiddenOutput,*tempOutput,size);
    }
    error=this->trainByPrediction(*hiddenOutput,*tempTrain,rate);

    return error;
}

double FullyConnected::startTrain(vector<TrainingSet> &trainSets, int times, double rate, int modelCheck=0){
    double startRate=rate;
    unsigned nowTime=0;
    double  error=0;
    int  showTime=times/info.showTime;
    do {
        error=0;
        if(modelCheck==0){
            for(unsigned i=0;i<trainSets.size();i++){
                auto& trainSet = trainSets.at(i);
                //单次训练
                error+=this->singleTraining(trainSet,rate);
            }
            error/=trainSets.size();
        }else{
            error=this->multipleTraining(trainSets,rate);
        }

        nowTime++;
        if ((nowTime - 1) % showTime == 0) {
            if(nowTime==1){
                info.initialValue = error;
            }
            if(error!=0){
                //当前倍率
                int magnification=info.initialValue/error/info.growthRate;
                if(magnification>=1 && magnification<info.endRate){
                    rate=magnification*info.growthFactor*startRate;
                }
            }
            cout<<"No:\t"<<nowTime<<"\ttraining,AverageError is :\t"<<error<<endl;
        }
    } while (times>=nowTime);
    return error;
}

TrainingSet& FullyConnected::mergeTrainSet(TrainingSet& collect,TrainingSet& oldTrain,int divisor){
    if(collect.trainAnswers== nullptr ){
        collect.trainDatas.reset(new vector<double>(oldTrain.trainDatas->size(),0.0));
        collect.trainAnswers.reset(new vector<double>(oldTrain.trainAnswers->size(),0.0));
        collect.prediction.reset(new vector<double>(oldTrain.prediction->size(),0.0));
    }
    for(unsigned i=0;i<oldTrain.trainDatas->size();i++){
        collect.trainDatas->at(i) += oldTrain.trainDatas->at(i)/divisor;
    }
    for(unsigned i=0;i<oldTrain.trainAnswers->size();i++){
        collect.trainAnswers->at(i) += oldTrain.trainAnswers->at(i)/divisor;
        collect.prediction->at(i) += oldTrain.prediction->at(i)/divisor;
    }
    return collect;
}
vector<vector<double>>& FullyConnected::mergeOutput(vector<vector<double>>& collect,vector<vector<double>>& oldOutPut,int divisor){
    if(collect.size()==0){
        collect.resize(oldOutPut.size());
    }
    for(unsigned i = 0;i<oldOutPut.size();i++){
        vector<double>& itemC=collect.at(i);
        vector<double>& itemO=oldOutPut.at(i);
        if(itemC.size()==0){
            itemC.resize(itemO.size(),0);
        }
        for (unsigned j = 0; j < itemO.size(); j++) {
            itemC.at(j) = itemO.at(j) / divisor;
        }
    }
    return collect;
}
FullyConnected::~FullyConnected() {
}
