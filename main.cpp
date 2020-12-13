#include <iostream>
#include "windows.h"
#include "User.h"
#include "Display.h"

int main() {
	system("color 11");
	SetConsoleOutputCP(CP_UTF8);
	int select;
	User* user = display<User>::authorization();
	if (user == nullptr) {
		return 0;
	}
	if (user->isAdmin()) {
		while (true) {
			std::cout << "Выберите данные с которыми хотите работать:" << std::endl;
			std::cout << "1. Работники." << std::endl;
			std::cout << "2. Управляющие." << std::endl;
			std::cout << "3. Стажеры." << std::endl;
			std::cout << "4. Выход." << std::endl;
			select = Error::inputExceptions::Input(1, 4);
			switch (select) {
			case 1: {
				myStack<Worker> stack;
				files<Worker>::openWorker(stack, "worker.txt");
				display<Worker>::adminMenu(stack);
				files<Worker>::saveWorker(stack, "worker.txt");
				break;
			}
			case 2: {
				myStack<Leader> stack;
				files<Leader>::openLeader(stack, "leader.txt");
				display<Leader>::adminMenu(stack);
				files<Leader>::saveLeader(stack, "leader.txt");
				break;
			}
			case 3: {
				myStack<SpecialistAssistant> stack;
				files<SpecialistAssistant>::openSpecialistAssistant(stack, "stager.txt");
				display<SpecialistAssistant>::adminMenu(stack);
				files<SpecialistAssistant>::saveSpecialistAssistant(stack, "stager.txt");
				break;
			}
			case 4: {
				return 0;
			}
			}
		}
	}
	else {
		while (true) {
			std::cout << "Выберите данные с которыми хотите рабоать:" << std::endl;
			std::cout << "1. Работники." << std::endl;
			std::cout << "2. Управляющие." << std::endl;
			std::cout << "3. Стажеры." << std::endl;
			std::cout << "4. Выход." << std::endl;
			select = Error::inputExceptions::Input(1, 4);
			switch (select) {
			case 1: {
				myStack<Worker> stack;
				files<Worker>::openWorker(stack, "worker.txt");
				display<Worker>::menu(stack);
				files<Worker>::saveWorker(stack, "worker.txt");
				break;
			}
			case 2: {
				myStack<Leader> stack;
				files<Leader>::openLeader(stack, "leader.txt");
				display<Leader>::menu(stack);
				files<Leader>::saveLeader(stack, "leader.txt");
				break;
			}
			case 3: {
				myStack<SpecialistAssistant> stack;
				files<SpecialistAssistant>::openSpecialistAssistant(stack, "stager.txt");
				display<SpecialistAssistant>::menu(stack);
				files<SpecialistAssistant>::saveSpecialistAssistant(stack, "stager.txt");
				break;
			}
			case 4: {
				return 0;
			}
			}
		}
	}
	return 0;
}


