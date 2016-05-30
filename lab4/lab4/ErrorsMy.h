#pragma once
#include <iostream>
class MyException {
public:
	char *message;
	MyException() { };
	MyException(char *msg) : message(msg) { };
	~MyException() {};
	void MyException::ShowExeption() {
		std::cout << "EXCEPTION:" << message;
	}
};

class pointError {
public:
	int coordX, coordY;
	pointError(int x, int y) : coordX(x), coordY(y) {
	};
	void pointError::ShowError() {
		std::cout << "ERROR COORD: " << coordX << ' ' << coordY;
	}
}; 