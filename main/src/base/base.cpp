#include "algorithm\neuralNetworks\base.h"
//定义全局变量
TimePoint timePoint;
double generate_random(double mean,double standardDeviation){
    static std::default_random_engine randomEngine(static_cast<unsigned int>(time(0)));
    //正态分布(平均,标志差)
    static std::normal_distribution<double> distribution(mean,standardDeviation);
    return distribution(randomEngine);
}