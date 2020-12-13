#pragma once
#pragma once
#pragma once

#include "MyStack.h"
#include "Algorithms.h"
#include <iostream>
#include <string>
#include <vector>
#include "InputExceptions.h"
#include "stackExceptions.h"
#include "User.h"

template<class T>
class display {
public:
	static void menu(myStack<T>& stack);
	static void adminMenu(myStack<T>& stack);
	static User* authorization();
};

template<class T>
void display<T>::menu(myStack<T>& stack) {
	std::vector<T> ReturnPrev;
	std::vector<int> action;
	std::vector<int> place;
	int select = 0;
	do {
		system("cls");
		std::cout << "Вас приветствует система рабочего персонала предприятия!" << std::endl;
		std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
		std::cout << "1. Добавить сотрудника в систему" << std::endl;
		std::cout << "2. Посмотреть список сотрудников" << std::endl;
		std::cout << "3. Удалить последнего сотрудника из системы" << std::endl;
		std::cout << "4. Изменить данные о конкретном сотруднике" << std::endl;
		std::cout << "5. Отмена предыдущего действия с сотрудниками" << std::endl;
		std::cout << "6. Отсортировать список сотрудников" << std::endl;
		std::cout << "0. Выход из программы" << std::endl;
		try {
			select = Error::inputExceptions::Input(0, 6);
			switch (select) {
			case 1:
			{
				system("cls");
				algorithms<T>::add(stack, ReturnPrev, action);
				break;
			}
			case 2:
			{
				system("cls");
				if (stack.size() == 0) {
					throw stackExceptions(1);
				}
				else {
					stack.output();
					std::cout << std::endl;
					system("pause");
				}
				break;
			}
			case 3:
			{
				system("cls");
				algorithms<T>::remove(stack, ReturnPrev, action);
				break;
			}
			case 4:
			{
				system("cls");
				algorithms<T>::update(stack, ReturnPrev, action, place);
				break;
			}
			case 5:
			{
				system("cls");
				algorithms<T>::cancel(stack, ReturnPrev, action, place);
				break;
			}
			case 6:
			{
				system("cls");
				algorithms<T>::sort(stack);
				break;
			}
			}
		}
		catch (stackExceptions e) {
			e.ErrorText();
			system("pause");
			std::cin.sync();
			std::cin.clear();
			rewind(stdin);
		}
	} while (select != 0);
}

template<class T>
User* display<T>::authorization() {
	int select = 0;
	do {
		system("cls");
		std::cout << "Авторизация в систему работников предприятия!" << std::endl;
		std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
		std::cout << "1. Авторизация в систему" << std::endl;
		std::cout << "2. Регистрация нового пользователя" << std::endl;
		std::cout << "3. Выход из системы" << std::endl;
		select = Error::inputExceptions::Input(1, 3);
		switch (select) {
		case 1: {
			User* currentUser = algorithms<User>::authorization();
			if (currentUser != nullptr) {
				return currentUser;
			}
			break;
		}
		case 2: {
			algorithms<User>::registration();
			break;
		}
		case 3: exit(0);
		}
	} while (select != 3);
}

template<class T>
void display<T>::adminMenu(myStack<T>& stack) {
	myStack<User> userList;
	files<User>::openUser(userList, "users.txt");
	std::vector<T> ReturnPrev;
	std::vector<int> action;
	std::vector<User> ReturnPrevForUsers;
	std::vector<int> actionOfUsers;
	std::vector<int> place;
	int select = 0;
	do {
		system("cls");
		std::cout << "Вас приветствует система рабочего персонала предприятия!" << std::endl;
		std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
		std::cout << "1. Добавить сотрудника в систему" << std::endl;
		std::cout << "2. Посмотреть список сотрудников" << std::endl;
		std::cout << "3. Удалить последнего сотрудника из системы" << std::endl;
		std::cout << "4. Изменить данные о конкретном сотруднике" << std::endl;
		std::cout << "5. Отмена предыдущего действия с сотрудниками" << std::endl;
		std::cout << "6. Отсортировать список сотрудников" << std::endl;
		std::cout << "7. Добавить пользователя" << std::endl;
		std::cout << "8. Просмотреть список пользователей" << std::endl;
		std::cout << "9. Удалить пользователя" << std::endl;
		std::cout << "10. Назначить пользователя администратором" << std::endl;
		std::cout << "0. Выход из программы" << std::endl;
		try {
			select = Error::inputExceptions::Input(0, 10);
			switch (select) {
			case 1:
			{
				system("cls");
				algorithms<T>::add(stack, ReturnPrev, action);
				break;
			}
			case 2:
			{
				system("cls");
				if (stack.size() == 0) {
					throw stackExceptions(1);
				}
				else {
					stack.output();
					std::cout << std::endl;
					system("pause");
				}
				break;
			}
			case 3:
			{
				system("cls");
				algorithms<T>::remove(stack, ReturnPrev, action);
				break;
			}
			case 4:
			{
				system("cls");
				algorithms<T>::update(stack, ReturnPrev, action, place);
				break;
			}
			case 5:
			{
				system("cls");
				algorithms<T>::cancel(stack, ReturnPrev, action, place);
				break;
			}
			case 6:
			{
				system("cls");
				algorithms<T>::sort(stack);
				break;
			}
			case 7: {
				system("cls");
				algorithms<User>::add(userList, ReturnPrevForUsers, actionOfUsers);
				files<User>::saveUser(userList, "users.txt");
				break;
			}
			case 8: {
				system("cls");
				if (userList.size() == 0) {
					throw stackExceptions(1);
				}
				else {
					userList.output();
					std::cout << std::endl;
					system("pause");
				}
				break;
			}
			case 9: {
				system("cls");
				algorithms<User>::remove(userList, ReturnPrevForUsers, actionOfUsers);
				files<User>::saveUser(userList, "users.txt");
				break;
			}
			case 10: {
				system("cls");
				algorithms<User>::giveAdminRole(userList);
				files<User>::saveUser(userList, "users.txt");
				break;
			}
			}
		}
		catch (stackExceptions e) {
			e.ErrorText();
			system("pause");
			std::cin.sync();
			std::cin.clear();
			rewind(stdin);
		}
	} while (select != 0);
}
