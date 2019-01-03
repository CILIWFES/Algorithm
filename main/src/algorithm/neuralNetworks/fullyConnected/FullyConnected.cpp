//
// Created by ZC on 2019/1/1.
//

#include"algorithm/neuralNetworks/class/connectedMod.h"
#include "algorithm/neuralNetworks/class/Neurons.h"
#include "algorithm/neuralNetworks/class/TrainingSet.h"


/**
 *
 * @param inputCnts
 * @param hiddenCnts
 * @param outputCnts
 * @param hidden_W
 * @param randRange
 */
FullyConnected::FullyConnected(int inputCnts, int hiddenCnts, int outputCnts, vector<unsigned long long int> hidden_W,
                               int randRange) :
        hidden(*new vector<vector<Neurons>>(hidden_W.size())), outPut(*new vector<Neurons>(outputCnts)) {
    //记录数据
    this->inputCnts = inputCnts;
    this->hiddenCnts = hiddenCnts;
    this->outputCnts = outputCnts;
    //记录权重
    unsigned long long int weights = inputCnts;
    //初始化神经网络(层数(具体个数))
    for (unsigned long long int i = 0; i < hidden.size(); ++i) {
        hidden.at(i) = vector<Neurons>(hidden_W.at(i));
        //手动初始化
        for (unsigned long long int j = 0; j < hidden_W.at(i); j++) {
            hidden.at(i).at(j) = Neurons(weights, randRange);
        }
        //记录最后一个权重
        weights = hidden_W.at(i);
    }

    //赋值给神经网络输出层
    for (unsigned long long int i = 0; i < outPut.size(); i++) {
        outPut.at(i) = Neurons(weights, randRange);
    }

}

/**
 * 开始训练
 * @param vec 历史各层输出
 * @return
 */
double FullyConnected::trainNetWork(vector<vector<double>> &historicalOutput, TrainingSet &set, double rate) {
    double ret = 0;
    //先计算起始斜率
    vector<double> slop = vector<double>(set.trainAnswer.size());
    //set.trainAnswer.size()必须与误差相等
    for (unsigned long long i = 0; i < set.trainAnswer.size(); i++) {
        double prediction = set.prediction.at(i);
        //负的输出-标出
        double reduce = -(prediction-set.trainAnswer.at(i));
        ret += reduce * reduce;
        //输出层误差斜率
        slop.at(i) = (reduce) * prediction * (1 - prediction);
    }
    ret /= set.trainAnswer.size();
    //传入输出层
    vector<vector<double>> *oldW = this->tarinLayer(this->outPut, slop,
                                                    historicalOutput.at(historicalOutput.size() - 1), rate);
    slop = this->collectW(slop, *oldW, historicalOutput.at(historicalOutput.size() - 1));
    delete oldW;

    for (unsigned long long i = historicalOutput.size() - 1; i >= 1; i--) {
        //历史权重
        auto &historicalTemp = historicalOutput.at(i - 1);
        oldW = this->tarinLayer(this->hidden.at(i), slop, historicalTemp, rate);
        slop = this->collectW(slop, *oldW, historicalTemp);
        delete oldW;

    }

    this->tarinLayer(this->outPut, slop, set.trainDatas, rate);

    delete &historicalOutput;
    return ret;
}

/**
 * 累加权重
 * @param slop 当前斜率
 * @param w    历史权重
 * @return
 */
vector<double> FullyConnected::collectW(vector<double> &slop, vector<vector<double>> &w, vector<double> &lastVal) {
    //构建上一神经元斜率
    vector<double> temp = vector<double>(w.at(0).size());
    //以当前斜率与旧权重,构建上个全重
    for (unsigned i = 0; i < slop.size(); i++) {
        double item = slop.at(i);
        auto tempW = w.at(i);
        for (unsigned long long j = 0; j < tempW.size(); j++) {
            temp.at(j) += item * tempW.at(j);
        }
    }
    //signmod
    for (unsigned long long i = 0; i < temp.size(); i++) {
        temp.at(i) *= lastVal.at(i) * (1 - lastVal.at(i));
    }
    return temp;
}


/**
 * 预测
 * @param set
 * @return 输出向量
 */
vector<double> FullyConnected::prediction(vector<double> &set) {
    vector<double> val = set;
    for (int layer = 0; layer < this->hidden.size(); layer++) {
        //输入隐层
        //获取隐层数值
        val = this->calculateLayer(hidden.at(layer), val);
    }
    return this->calculateLayer(outPut, val);
}

/**
 * 逐层计算
 * @param vec
 * @param input
 * @return
 */
vector<double> FullyConnected::calculateLayer(vector<Neurons> &vec, vector<double> &input) {
    vector<double> rets = vector<double>(vec.size());

    for (unsigned long long i = 0; i < vec.size(); i++) {
        Neurons &item = vec.at(i);
        double val = item.calculate(input);
        rets.at(i) = item.conversion(val);
    }
    return rets;
}

/**
 *
 * @param set
 * @return
 */
vector<vector<double>> *FullyConnected::predictionByTrain(TrainingSet &set) {
    vector<double> val = set.trainDatas;
    vector<vector<double>> *ret = new vector<vector<double>>(this->hidden.size());
    for (int layer = 0; layer < this->hidden.size(); layer++) {
        //输入隐层
        //获取隐层数值
        val = this->calculateLayer(hidden.at(layer), val);
        ret->at(layer) = val;
    }
    val = this->calculateLayer(outPut, val);
    set.prediction.clear();
    set.prediction.assign(val.begin(), val.end());
    return ret;
}

/**
 * 单层训练,获取当前斜率,上一层的输入
 * @param vec     当前层神经元
 * @param slop    当层斜率
 * @param lastVal 上层输入
 * @param rate    学习率
 * @return 旧权重
 */
vector<vector<double>> *
FullyConnected::tarinLayer(vector<Neurons> &vec, vector<double> &slop, vector<double> &lastVal, double rate) {
    //记录神经元的旧权重
    vector<vector<double>> *ret = new vector<vector<double>>(vec.size());
    for (unsigned long long i = 0; i < vec.size(); i++) {
        auto item = vec.at(i);
        //获取旧权重
        ret->at(i) = item.correct(lastVal.at(i), slop.at(i), rate);
    }
    return ret;
}

FullyConnected::~FullyConnected() {
    delete &hidden;
    delete &outPut;
}
