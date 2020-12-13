#pragma once

#include <iostream>
#include <string>
#include "Exceptions.h"
using namespace std;
namespace Error {
	class inputExceptions : public exceptions {
	public:
		explicit inputExceptions(int code = 0) : exceptions(code) {};

		void ErrorText() {
			cout << "Ошибка ввода (код " << this->code << "): ";
			switch (this->code) {
			case 1: {
				cout << "Введён недопустимый символ!" << endl;
				cout << "Ввод любых символов, кроме цифр, запрещён!" << endl;
				break;
			}
			case 2: {
				cout << "Вы ввели символы вместо числа либо превышен предел по вводу чисел!" << endl;
				break;
			}
			default:
				cout << "Повторите ввод!" << endl;
				break;
			}
		}

		static int Input(int min, int max) {
			bool flag = true;
			int value;
			do {
				try {
					cin.sync();
					cin.clear();
					rewind(stdin);
					cin >> value;
					flag = true;
					if (!cin || cin.peek() != '\n') {
						flag = false;
						throw inputExceptions(2);
					}
					if (value < min || value > max) {
						flag = false;
						throw "Limit error";
					}
				}
				catch (inputExceptions e) {
					rewind(stdin);
					e.ErrorText();
					cin.sync();
					cin.clear();
				}
				catch (...) {
					rewind(stdin);
					cin.sync();
					cin.clear();
					cout << "Введено некорректное значение. Необходимо ввести значение в диапазоне (" << min << ","
						<< max << ")." << endl;
				}
			} while (!flag);
			return value;
		}

		static int InputNumber() {
			int input;
			try {
				rewind(stdin);
				cin.sync();
				cin.clear();
				cin >> input;
				if (!cin || cin.peek() != '\n') {
					throw inputExceptions(2);
				}
			}
			catch (inputExceptions e) {
				e.ErrorText();
				cin.clear();
				cin.sync();
				input = InputNumber();
			}
			rewind(stdin);
			return input;
		}

		static char* inputStringWithoutNumbers() {
			rewind(stdin);
			char input;
			char* buffer = new char[20];
			int i = 0;
			bool flag = true;
			while (flag) {
				try {
					input = cin.get();
					if (input != '\n' && (input < 'a' || input > 'z') && (input < 'A' || input > 'Z')) {
						throw (inputExceptions(4));
					}
					if (input == '\n') {
						input = '\0';
						flag = false;
					}
					buffer[i] = input;
					i++;
				}
				catch (inputExceptions e) {
					rewind(stdin);
					e.ErrorText();
					cin.clear();
					cin.sync();
				}
			}
			return buffer;
		}
	};
}
