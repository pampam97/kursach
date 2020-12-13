#pragma once
#include <iostream>

class Salary {
protected:
	int salary;
	int bankBook;
public:
	Salary(int salary = 0, int bankBook = 0);

	int getSalary() const;
	void setSalary(int salary);
	int getBankBook() const;
	void setBankBook(int bankBook);

	friend std::istream& operator>>(std::istream& is, Salary& salary);
	friend std::ostream& operator<<(std::ostream& os, const Salary& salary);
};
