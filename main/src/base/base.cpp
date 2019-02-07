#include "base.h"
//定义全局变量
TimePoint timePoint;
double random_normal_distribution(double mean,double standardDeviation){
    static std::default_random_engine randomEngine(static_cast<unsigned int>(time(nullptr)));
    //正态分布(平均,标志差)
    static std::normal_distribution<double> distribution(mean,standardDeviation);
    return distribution(randomEngine);
}


double random_evenly_distributed(double startNum,double endNum){
    static std::default_random_engine randomEngine(static_cast<unsigned int>(time(nullptr)));
//    static std::uniform_real_distribution<double> distribution(startNum, std::nextafter(endNum,DBL_MAX)); cmath cfloat
    static std::uniform_real_distribution<double> distribution(startNum, endNum);
    return distribution(randomEngine);

}
