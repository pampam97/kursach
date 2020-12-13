#pragma once

#include "Worker.h"

class Leader : public Worker {
private:
	int numberOfContracts;
	bool retraining;
public:
	explicit Leader(int salary = 0, int bankBook = 0, int numberOfHoursWorked = 0, int workExperience = 0,
		int numberOfContracts = 0, bool retraining = false);

	int getNumberOfContracts() const;
	void setNumberOfContracts(int numberOfContracts);
	bool isRetraining() const;
	void setRetraining(bool retraining);

	friend std::istream& operator>>(std::istream& is, Leader& leader);
	friend std::ostream& operator<<(std::ostream& os, const Leader& leader);
};
