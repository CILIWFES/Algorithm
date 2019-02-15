#include "module/performance/time/TimePoint.h"
#include <ctime>
#include<iostream>
TimePoint::TimePoint()
{
	endTime = 0l;
	startTime = 0l;
}
void TimePoint::setPoint() {
	this->startTime = clock();
}
void TimePoint::showPoint() {
	this->endTime = clock();
	std::cout << "timeCost:\t" << (this->endTime - this->startTime) / 1000.0 << "\tsecond" << std::endl;

}