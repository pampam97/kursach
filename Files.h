#pragma once

#include "MyStack.h"
#include "SpecialistAssistant.h"
#include "Worker.h"
#include "Leader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

template <class T>
class files {
public:
	files() = default;
	~files() = default;;

	static void openUser(myStack<T>& stack, const char* file);
	static void openSpecialistAssistant(myStack<T>& stack, const char* file);
	static void openWorker(myStack<T>& stack, const char* file);
	static void openLeader(myStack<T>& stack, const char* file);

	static void saveUser(myStack<T>& stack, const char* file);
	static void saveSpecialistAssistant(myStack<T>& stack, const char* file);
	static void saveWorker(myStack<T>& stack, const char* file);
	static void saveLeader(myStack<T>& stack, const char* file);
};

template<class T>
void files<T>::openUser(myStack<T>& stack, const char* file) {
	std::ifstream in;
	in.open(file);
	if (!in.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	char BUFFER[20];
	int val3;
	while (EOF) {
		int i = 0;
		in >> BUFFER[i];
		if (!in || BUFFER[i++] == '%') {
			break;
		}
		while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
			i++;
		}
		BUFFER[i] = '\0';
		std::string val1(BUFFER);
		i = 0;
		while ((BUFFER[i] = in.get()) != '|' && BUFFER[i] != '\n') {
			i++;
		}
		BUFFER[i] = '\0';
		std::string val2(BUFFER);
		in >> val3;
		T t(val1, val2, val3);
		stack.push(t);
	}
	in.close();
}

template<class T>
void files<T>::saveUser(myStack<T>& stack, const char* file) {
	std::ofstream on;
	on.open(file, std::ios_base::out);
	if (!on.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	for (int i = 0; i < stack.size(); i++) {
		on << stack[i].getUsername() << "|" << stack[i].getPassword() << "|" << stack[i].isAdmin();
		on << std::endl;
	}
	on << "%";
	on.close();
}

template<class T>
void files<T>::openSpecialistAssistant(myStack<T>& stack, const char* file) {
	std::ifstream in;
	in.open(file, std::ios::in);
	if (!in.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	int val1, val2, val3, val4;
	while (EOF) {
		in >> val1;
		if (!in) {
			in.clear();
			break;
		}
		in >> val2 >> val3 >> val4;
		SpecialistAssistant specialistAssistant(val1, val2, val3, val4);
		stack.push(specialistAssistant);
	}
	in.close();
}

template<class T>
void files<T>::saveSpecialistAssistant(myStack<T>& stack, const char* file) {
	std::ofstream on;
	on.open(file, std::ios_base::out);
	if (!on.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	for (int i = 0; i < stack.size(); i++) {
		on << stack[i].getSalary() << " " << stack[i].getBankBook() << " " <<
			stack[i].getGroup() << " " << stack[i].getNumberOfCompletedTasks();
		on << std::endl;
	}
	on << "%";
	on.close();
}

template<class T>
void files<T>::openWorker(myStack<T>& stack, const char* file) {
	std::ifstream in;
	in.open(file);
	if (!in.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	int val1, val2, val3, val4;
	while (EOF) {
		in >> val1;
		if (!in) {
			in.clear();
			break;
		}
		in >> val2;
		in >> val3;
		in >> val4;
		Worker worker(val1, val2, val3, val4);
		stack.push(worker);
	}
	in.close();
}

template<class T>
void files<T>::saveWorker(myStack<T>& stack, const char* file) {
	std::ofstream on;
	on.open(file, std::ios_base::out);
	if (!on.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	for (int i = 0; i < stack.size(); i++) {
		on << stack[i].getSalary() << " " << stack[i].getBankBook() << " " <<
			stack[i].getnumberOfHoursWorked() << " " << stack[i].getWorkExperience();
		on << std::endl;
	}
	on << "%";
	on.close();
}

template<class T>
void files<T>::openLeader(myStack<T>& stack, const char* file) {
	std::ifstream in;
	in.open(file, std::ios::in);
	if (!in.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	int val1, val2, val3, val4, val5;
	bool val6;
	while (EOF) {
		in >> val1;
		if (!in) {
			in.clear();
			break;
		}
		in >> val2 >> val3 >> val4 >> val5 >> val6;
		Leader leader(val1, val2, val3, val4, val5, val6);
		stack.push(leader);
	}
	in.close();
}

template<class T>
void files<T>::saveLeader(myStack<T>& stack, const char* file) {
	std::ofstream on;
	on.open(file, std::ios_base::out);
	if (!on.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	for (int i = 0; i < stack.size(); i++) {
		on << stack[i].getSalary() << " " << stack[i].getBankBook() << " " <<
			stack[i].getnumberOfHoursWorked() << " " << stack[i].getWorkExperience() << " " << stack[i].getNumberOfContracts()
			<< " " << stack[i].isRetraining();
		on << std::endl;
	}
	on << "%";
	on.close();
}

