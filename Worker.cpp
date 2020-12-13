#include "Worker.h"
#include "InputExceptions.h"
#include <cstring>
#include <iostream>

Worker::Worker(int salary, int bankBook, int numberOfHoursWorked, int workExperience) :
	Salary(salary, bankBook), numberOfHoursWorked(numberOfHoursWorked), workExperience(workExperience) {
}

int Worker::getnumberOfHoursWorked() const {
	return numberOfHoursWorked;
}

void Worker::setnumberOfHoursWorked(int numberOfHoursWorked) {
	Worker::numberOfHoursWorked = numberOfHoursWorked;
}

int Worker::getWorkExperience() const {
	return workExperience;
}

void Worker::setWorkExperience(int workExperience) {
	Worker::workExperience = workExperience;
}

std::ostream& operator<<(std::ostream& os, const Worker& worker) {
	os << "Количество проработанных часов: " << worker.numberOfHoursWorked << std::endl
		<< "Стаж работы: " << worker.workExperience << std::endl;
	os << static_cast<const Salary&>(worker);
	return os;
}

std::istream& operator>>(std::istream& is, Worker& worker) {
	std::cout << "Введите колиичество проработанных часов: ";
	worker.numberOfHoursWorked = Error::inputExceptions::Input(0, 1000);
	std::cout << "Введите стаж работы: ";
	worker.workExperience = Error::inputExceptions::Input(0, 100);
	is >> dynamic_cast<Salary&>(worker);
	return is;
}
