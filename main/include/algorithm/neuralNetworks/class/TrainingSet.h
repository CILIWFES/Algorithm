//
// Created by ZC on 2019/1/1.
//

#ifndef ALGORITHM_TRAININGSET_H
#define ALGORITHM_TRAININGSET_H

#include <vector>
using std::vector;
class TrainingSet{
public:
    TrainingSet(vector<double>& trainDatas,vector<double>& trainAnswer);
    vector<double>& trainDatas;
    vector<double>& trainAnswer;
    vector<double>& prediction;
    ~TrainingSet();

};

#endif //ALGORITHM_TRAININGSET_H
