#pragma once
#define E  2.7182818284
#define Pi 3.141592654

#include <iostream>
#include<random>
#include<Eigen/Eigen>
#include<ctime>
#include <vector>
#include <memory>
#include "module/class/TimePoint.h"
using std::cout,
std::endl,
std::vector,
std::shared_ptr,
Eigen::MatrixXd,
Eigen::ArrayXd,
Eigen::RowVectorXd,
Eigen::VectorXd;
/**
 * 平均数引擎
 * @param mean 平均数
 * @param standardDeviation 标志差
 * @return
 */
double generate_random(double mean,double standardDeviation);

