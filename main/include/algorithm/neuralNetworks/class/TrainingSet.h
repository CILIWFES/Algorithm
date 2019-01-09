//
// Created by ZC on 2019/1/1.
//

#pragma once

#include <vector>
#include <memory>


using std::vector, std::shared_ptr, std::move, std::make_shared;

class TrainingSet {
public:
    TrainingSet();
    /**
     * 传入训练数据与训练答案
     * @param trainDatas  训练数据
     * @param trainAnswers 训练答案
     */
    TrainingSet(vector<double> *trainDatas, vector<double> *trainAnswers);

    TrainingSet &operator=(TrainingSet &&trainingSet);
    TrainingSet &operator=(TrainingSet &trainingSet);

    TrainingSet(TrainingSet &&trainingSet);



    shared_ptr<vector<double>> trainDatas;

    shared_ptr<vector<double>> trainAnswers;

    shared_ptr<vector<double>> prediction;

    ~TrainingSet();
};
