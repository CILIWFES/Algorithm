#pragma once
#define E  2.7182818284
#define Pi 3.141592654

#include <iostream>
#include <Eigen/Dense>
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
//定义全局变量
TimePoint timePoint;