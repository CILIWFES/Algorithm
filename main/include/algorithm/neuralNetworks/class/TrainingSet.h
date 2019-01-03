//
// Created by ZC on 2019/1/1.
//

#pragma once

#include <vector>
#include <memory>


using std::vector,std::shared_ptr;

class TrainingSet {
public:
    /**
     * 传入训练数据与训练答案
     * @param trainDatas  训练数据
     * @param trainAnswer 训练答案
     */
    TrainingSet(shared_ptr<vector<double>>&trainDatas, shared_ptr<vector<double>>&trainAnswer);

    shared_ptr<vector<double>> trainDatas;
    shared_ptr<vector<double>> trainAnswer;
    shared_ptr<vector<double>> prediction;

    ~TrainingSet();
};
