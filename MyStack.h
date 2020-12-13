#pragma once

#include <iostream>

template <class T>
struct Node {
	T data;
	Node<T>* previous;
	Node<T>* next;
};

template <class T>
class myStack {
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int amount = 0;
public:
	myStack() {};
	~myStack();

	//Длина списка
	int size() { return this->amount; }
	void push(T obj);
	T pop();
	T& operator[](int num);
	Node<T>* begin();
	Node<T>* end();
	void sort(int type);
	void output();
	void deleteAll();
};

template<class T>
void myStack<T>::push(T obj) {
	if (head == nullptr) {
		head = new Node<T>;
		head->data = obj;
		head->next = nullptr;
		head->previous = nullptr;
		tail = head;
		amount++;
	}
	else {
		auto* node = new Node<T>;
		node->data = obj;
		node->next = head;
		node->previous = nullptr;
		head->previous = node;
		head = node;
		amount++;
	}
}

template<class T>
T myStack<T>::pop() {
	if (!(head)) return T();
	T data = head->data;
	Node<T>* node = head;
	if (head != tail) {
		head = head->next;
		head->previous = nullptr;
		Node<T>* tmp = head;
	}
	else {
		head = tail = nullptr;
	}
	delete node;
	amount--;
	return data;
}

// Доступ к объектам с помощью индексации
template<class T>
T& myStack<T>::operator[](int num) {
	Node<T>* curr = head;
	if (num < 0 || num >= amount) return curr->data;
	for (int i = 0; i < num; i++)
		curr = curr->next;
	return curr->data;
}

// Функции для работы с итератором
template<class T>
Node<T>* myStack<T>::begin() { return head; }

template<class T>
Node<T>* myStack<T>::end() {
	if (tail != nullptr) return tail->next;
	return tail;
}

// Вывод на экран содержимого списка
template<class T>
void myStack<T>::output() {
	int i = 0;
	for (Node<T>* node = head; node != NULL; node = node->next) {
		std::cout << "№" << i + 1 << std::endl << node->data;
		std::cout << std::endl;
		i++;
	}
}



template<class T>
myStack<T>::~myStack() { while (this->head) { this->pop(); } }

template<class T>
void myStack<T>::sort(int type) {
	switch (type) {
	case 1: {
		for (Node<T>* tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
			for (Node<T>* another = this->tail; another != tmp; another = another->previous) {
				if (tmp->data.getBankBook() > another->data.getBankBook()) {
					auto* buf1 = new Node<T>;
					buf1->data = tmp->data;
					tmp->data = another->data;
					another->data = buf1->data;
				}
			}
		}
		break;
	}
	case 2: {
		for (Node<T>* tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
			for (Node<T>* another = this->tail; another != tmp; another = another->previous) {
				if (tmp->data.getBankBook() < another->data.getBankBook()) {
					auto* buf1 = new Node<T>;
					buf1->data = tmp->data;
					tmp->data = another->data;
					another->data = buf1->data;
				}
			}
		}
		break;
	}
	case 3: {
		for (Node<T>* tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
			for (Node<T>* another = this->tail; another != tmp; another = another->previous) {
				if (tmp->data.getSalary() > another->data.getSalary()) {
					auto* buf1 = new Node<T>;
					buf1->data = tmp->data;
					tmp->data = another->data;
					another->data = buf1->data;
				}
			}
		}
		break;
	}
	case 4: {
		for (Node<T>* tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
			for (Node<T>* another = this->tail; another != tmp; another = another->previous) {
				if (tmp->data.getSalary() < another->data.getSalary()) {
					auto* buf1 = new Node<T>;
					buf1->data = tmp->data;
					tmp->data = another->data;
					another->data = buf1->data;
				}
			}
		}
		break;
	}
	}
}

template<class T>
void myStack<T>::deleteAll() {
	while (this->head) { this->pop(); }
}
