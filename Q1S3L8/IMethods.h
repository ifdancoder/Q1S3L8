#pragma once

#include <iostream>
#include "hw.pb.h"

class IMethods {
	virtual double GetAverageScore(const hw::FullName& name) = 0;
	virtual std::string GetAllInfo(const hw::FullName& name) = 0;
	virtual std::string GetAllInfo() = 0;
};