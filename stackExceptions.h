#pragma once

#include <iostream>
#include "Exceptions.h"

class stackExceptions : exceptions {
public:
	explicit stackExceptions(int code = 0) : exceptions(code) {};
	void ErrorText() override;
};

void stackExceptions::ErrorText() {
	std::cout << "Ошибка (код " << code << "): " << std::endl;
	switch (code) {
	case 1: {
		std::cout << "Стек пуст" << std::endl;
		break;
	}
	case 2: {
		std::cout << "Невозможно отменить действие!";
		std::cout << " Все возможные последние действия отменены." << std::endl;
		break;
	}
	}
}
