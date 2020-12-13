#pragma once
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <cmath>
#include "myStack.h"
#include "User.h"
#include "stackExceptions.h"
#include "InputExceptions.h"
#include "Files.h"

template <class T>
class algorithms {
public:
	static void registration();
	static User* authorization();
	static void add(myStack<T>& stack, std::vector<T>& returnPrev, std::vector<int>& action);
	static void remove(myStack<T>& stack, std::vector<T>& returnPrev, std::vector<int>& action);
	static void update(myStack<T>& stack, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place);
	static void sort(myStack<T>& stack);
	static void cancel(myStack<T>& stack, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place);
	static void giveAdminRole(myStack<T>& stack);
};

template<class T>
void algorithms<T>::add(myStack<T>& stack, std::vector<T>& returnPrev, std::vector<int>& action) {
	system("cls");
	T tmp;
	std::cin >> tmp;
	stack.push(tmp);
	returnPrev.insert(returnPrev.end(), tmp);
	action.insert(action.end(), 1);
	system("pause");
}

template<class T>
void algorithms<T>::remove(myStack<T>& stack, std::vector<T>& returnPrev, std::vector<int>& action) {
	system("cls");
	if (stack.size() == 0) {
		throw stackExceptions(1);
	}
	else {
		T tmp = stack[0];
		returnPrev.insert(returnPrev.end(), tmp);
		action.insert(action.end(), 2);
		stack.pop();
	}
	system("pause");
}

template<class T>
void algorithms<T>::update(myStack<T>& stack, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place) {
	system("cls");
	if (!stack.size()) {
		throw stackExceptions(1);
	}
	stack.output();
	std::cout << std::endl;
	std::cout << "Введите номер изменяемого продукта : ";
	int tempNum = Error::inputExceptions::Input(1, stack.size());
	T tmp;
	std::cin >> tmp;
	returnPrev.insert(returnPrev.end(), stack[tempNum - 1]);
	action.insert(action.end(), 3);
	place.insert(place.end(), tempNum);
	stack[tempNum - 1] = tmp;
	system("pause");
}

template<class T>
void algorithms<T>::sort(myStack<T>& stack) {
	system("cls");
	if (!stack.size()) {
		throw stackExceptions(1);
	}
	stack.output();
	std::cout << std::endl;
	std::cout << "Выберите по какому признаку отсортировать:" << std::endl;
	std::cout << "1. По лицевому счёту по возрастанию." << std::endl;
	std::cout << "2. По лицевому счёту по убыванию." << std::endl;
	std::cout << "3. По зарплате по возрастанию." << std::endl;
	std::cout << "4. По зарплате по убыванию." << std::endl;
	int type = Error::inputExceptions::Input(1, 4);
	stack.sort(type);
}

template<class T>
void algorithms<T>::cancel(myStack<T>& stack, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place) {
	if (!action.size()) {
		system("cls");
		throw stackExceptions(2);
	}
	switch (action.back()) {
	case 1: {
		stack.pop();
		action.erase(action.end() - 1);
		returnPrev.erase(returnPrev.end() - 1);
		break;
	}
	case 2: {
		stack.push(returnPrev.back());
		action.erase(action.end() - 1);
		returnPrev.erase(returnPrev.end() - 1);
		break;
	}
	case 3: {
		stack[place.back() - 1] = returnPrev.back();
		place.erase(place.end() - 1);
		action.erase(action.end() - 1);
		returnPrev.erase(returnPrev.end() - 1);
		break;
	}
	}
}

template<class T>
User* algorithms<T>::authorization() {
	myStack<User> users;
	files<User>::openUser(users, "users.txt");
	char BUFFER[20];
	std::string username;
	std::cout << "Введите логин: ";
	std::cin >> username;
	std::cout << "Введите пароль: ";
	int i = 0;
	std::cin >> BUFFER;
	for (int j = 0; BUFFER[j] != '\0'; ++j) {
		BUFFER[j] *= BUFFER[j];
	}
	std::string password(BUFFER);
	for (int i = 0; i < users.size(); i++) {
		if (users[i].getUsername() == username && users[i].getPassword() == password) {
			return new User(users[i]);
		}
	}
	std::cout << "Неверный пользователь или пароль!" << std::endl;
	system("cls");
	return nullptr;
}

template<class T>
void algorithms<T>::registration() {
	myStack<User> users;
	files<User>::openUser(users, "users.txt");
	User newUser;
	std::cin >> newUser;
	for (int i = 0; i < users.size(); i++) {
		if (users[i].getUsername() == newUser.getUsername() && users[i].getPassword() == newUser.getPassword()
			&& newUser.isAdmin() != users[i].isAdmin()) {
			std::cout << "Данный пользователь уже существует!" << std::endl;
			return;
		}
	}
	users.push(newUser);
	files<User>::saveUser(users, "users.txt");
}

template<class T>
void algorithms<T>::giveAdminRole(myStack<T>& stack) {
	stack.output();
	std::cout << std::endl;
	std::cout << "Введите номер пользователя для предоставления прав администратора : ";
	int tempNum = Error::inputExceptions::Input(1, stack.size());
	stack[tempNum - 1].setAdmin(1);
}

