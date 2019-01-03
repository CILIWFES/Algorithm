#pragma once

#include <vector>
#include <ctime>
#include <random>
using std::vector;
class Neurons {
public:
    Neurons();
    Neurons(unsigned long long int weights, int range);
    double calculate(vector<double>& vals);
    double conversion(double val);
    vector<double> correct(double lastVal, double slope,double rate);
    ~Neurons();
private:
    static std::default_random_engine myRand;    // 将种子值设置为时间
    long long static  maxRand ;
    double static  e;
    vector<double>weights;
    double bias;
};

