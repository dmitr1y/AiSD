#pragma once
#include <iostream>
class shapeError {
public:
	char *message;
	shapeError() { };
	shapeError(char *msg) : message(msg) { };
	~shapeError() {};
	void shapeError::ShowExeption() {
		std::cout << "EXCEPTION: " << message;
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