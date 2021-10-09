#include "StudentsGroup.h"

std::ostream& operator<<(std::ostream& out, const hw::FullName& fn) {
	out << fn.fname() << ' ' << fn.sname();
	if (fn.patronymic() != "") {
		out << ' ' << fn.patronymic();
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const hw::Student& st) {
	out << st.name() << ":\nEvaluations: ";
	for (auto i : st.evaluations()) {
		out << i << ' ';
	}
	out << "\nAverage:" << st.average();
	return out;
}

std::ostream& operator<<(std::ostream& out, const hw::StudentsGroup& sg) {
	for (auto i : sg.students()) {
		out << i << std::endl << std::endl;
	}
	return out;
}

hw::StudentsGroup& StudentsGroup::getStuds() {
	return studs;
}

hw::FullName* StudentsGroup::genFN(std::string fname, std::string sname, \
								   std::string patronymic) {
	hw::FullName* nm = new hw::FullName();
	nm->set_fname(fname);
	nm->set_sname(sname);
	nm->set_patronymic(patronymic);
	return nm;
}

void StudentsGroup::addStudent(std::vector<int>& evals, std::string fname, \
	                           std::string sname, std::string patronymic) {
	hw::FullName* nm = genFN(fname, sname, patronymic);
	hw::Student* stud = new hw::Student();
	stud->set_average(std::accumulate(evals.begin(), evals.end(), 0.0) / evals.size());
	stud->set_allocated_name(nm);
	for (auto i : evals) {
		stud->mutable_evaluations()->Add(i);
	}
	studs.mutable_students()->AddAllocated(stud);
}

std::string StudentsGroup::GetAllInfo() {
	std::stringstream ss;
	ss << "All Info:\n\n" << studs;
	return ss.str();
}

double StudentsGroup::GetAverageScore(const hw::FullName& name) {
	for (auto i : studs.students()) {
		if (i.name() == name) {
			return i.average();
		}
	}
}

std::string StudentsGroup::GetAllInfo(const hw::FullName& name) {
	std::stringstream ss;
	for (auto i : studs.students()) {
		if (i.name() == name) {
			ss << i;
			return ss.str();
		}
	}
}

void StudentsGroup::Save() {
	std::ofstream out("StudenstGroup.bin", std::ios_base::binary);
	studs.SerializeToOstream(&out);
	std::cout << "Serializated:" << "\n===\n" << studs << "===\n\n";
}

void StudentsGroup::Open() {
	std::ifstream in("StudenstGroup.bin", std::ios_base::binary);
	studs.ParseFromIstream(&in);
	std::cout << "Deserializated:" << "\n===\n" << studs << "===\n";
}