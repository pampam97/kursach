#include "Leader.h"
#include "InputExceptions.h"

Leader::Leader(int salary, int bankBook, int numberOfHoursWorked, int workExperience,
	int numberOfContracts, bool retraining) : Worker(salary, bankBook, numberOfHoursWorked,
		workExperience), numberOfContracts(numberOfContracts), retraining(retraining) {
}

int Leader::getNumberOfContracts() const {
	return numberOfContracts;
}

void Leader::setNumberOfContracts(int numberOfContracts) {
	Leader::numberOfContracts = numberOfContracts;
}

bool Leader::isRetraining() const {
	return retraining;
}

void Leader::setRetraining(bool retraining) {
	Leader::retraining = retraining;
}

std::ostream& operator<<(std::ostream& os, const Leader& leader) {
	os << "Количество контрактов: " << leader.numberOfContracts << std::endl
		<< "Пройденная переподготовка: " << leader.retraining << std::endl
		<< static_cast<const Worker&>(leader);
	return os;
}

std::istream& operator>>(std::istream& is, Leader& leader) {
	std::cout << "Введите количество контрактов управляющего: ";
	leader.numberOfContracts = Error::inputExceptions::InputNumber();
	std::cout << "Проходил ли сотрудник переподготовку? (1. Да. 0. Нет.) ";
	leader.retraining = Error::inputExceptions::Input(0, 1);
	is >> dynamic_cast<Worker&>(leader);
	return is;
}
