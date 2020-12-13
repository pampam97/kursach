#include "SpecialistAssistant.h"
#include "InputExceptions.h"

SpecialistAssistant::SpecialistAssistant(int salary, int bankBook, int group, int numberOfCompletedTasks) :
	Salary(salary, bankBook), group(group),
	numberOfCompletedTasks(numberOfCompletedTasks) {
}

int SpecialistAssistant::getGroup() const {
	return group;
}

void SpecialistAssistant::setGroup(int group) {
	SpecialistAssistant::group = group;
}

int SpecialistAssistant::getNumberOfCompletedTasks() const {
	return numberOfCompletedTasks;
}

void SpecialistAssistant::setNumberOfCompletedTasks(int numberOfCompletedTasks) {
	SpecialistAssistant::numberOfCompletedTasks = numberOfCompletedTasks;
}

std::ostream& operator<<(std::ostream& os, const SpecialistAssistant& specialistAssistant) {
	os << "№ группы: " << specialistAssistant.group << std::endl << "Количество выполненных задач: "
		<< specialistAssistant.numberOfCompletedTasks << std::endl;
	os << static_cast<const Salary&>(specialistAssistant);
	return os;
}

std::istream& operator>>(std::istream& is, SpecialistAssistant& specialistAssistant) {
	std::cout << "Введите номер группы стажёра: ";
	specialistAssistant.group = Error::inputExceptions::Input(100000, 999999);
	std::cout << "Введите количество заданий, выполненных стажёром: ";
	specialistAssistant.numberOfCompletedTasks = Error::inputExceptions::Input(0, 1000);
	is >> dynamic_cast<Salary&>(specialistAssistant);
	return is;
}
