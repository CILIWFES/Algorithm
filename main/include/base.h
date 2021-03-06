#pragma once
#define E  2.7182818284
#define Pi 3.141592654

#include <iostream>
#include<random>
#include<string>
#include<Eigen/Eigen>
#include<ctime>
#include <vector>
#include <memory>
#include<cmath>
#include<cfloat>
#include "module/performance/time/TimePoint.h"
using std::cout,
std::endl,
std::string,
std::vector,
std::shared_ptr,
Eigen::MatrixXd,
Eigen::ArrayXd,
Eigen::RowVectorXd,
Eigen::VectorXd;

/**
 * 高斯分布
 * @param mean 平均数
 * @param standardDeviation 标志差
 * @return
 */
double random_normal_distribution(double mean,double standardDeviation);

/**
 * 均匀分布
 * @param startNum 起始
 * @param endNum 结束
 * @return
 */
double random_evenly_distributed(double startNum,double endNum);


template<class T>
unsigned int length(T& data)
{
    return sizeof(data)/sizeof(data[0]);
}
