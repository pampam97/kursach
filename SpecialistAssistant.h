#pragma once

#include "Salary.h"

class SpecialistAssistant : public Salary {
private:
	int group;
	int numberOfCompletedTasks;
public:
	SpecialistAssistant(int salary = 0, int bankBook = 0, int group = 0, int numberOfCompletedTasks = 0);

	int getGroup() const;
	void setGroup(int group);
	int getNumberOfCompletedTasks() const;
	void setNumberOfCompletedTasks(int numberOfCompletedTasks);

	friend std::istream& operator>>(std::istream& is, SpecialistAssistant& specialistAssistant);
	friend std::ostream& operator<<(std::ostream& os, const SpecialistAssistant& specialistAssistant);
};
