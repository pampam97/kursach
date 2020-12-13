#pragma once

#include "Salary.h"

class Worker : public Salary {
protected:
	int numberOfHoursWorked;
	int workExperience;
public:
	Worker(int salary = 0, int bankBook = 0, int numberOfProjects = 0, int workExperience = 0);

	int getnumberOfHoursWorked() const;
	void setnumberOfHoursWorked(int numberOfHoursWorked);
	int getWorkExperience() const;
	void setWorkExperience(int workExperience);

	friend std::istream& operator>>(std::istream& is, Worker& worker);
	friend std::ostream& operator<<(std::ostream& os, const Worker& worker);
};
