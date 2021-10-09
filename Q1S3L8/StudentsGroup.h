#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <numeric>
#include <vector>
#include "hw.pb.h"
#include "IMethods.h"
#include "IRepository.h"

class StudentsGroup : public IMethods, public IRepository {
private:
	hw::StudentsGroup studs;
public:
	hw::StudentsGroup& getStuds();
	hw::FullName* genFN(std::string fname, std::string sname, std::string patr = "");
	void addStudent(std::vector<int>& evals, std::string fname, \
		std::string sname, std::string patronymic = "");

	std::string GetAllInfo() override;
	double GetAverageScore(const hw::FullName& name) override;
	std::string GetAllInfo(const hw::FullName& name) override;

	void Save() override;
	void Open() override;
};
