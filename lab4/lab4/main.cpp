using namespace std;
#include <conio.h>
#include <iostream>
#include "screen.h"
#include "shape.h"
#include "errorExceptions.h"

class myshape : public rectangle {
	line* mouth; // рот
public:
	myshape(point, point);
	void draw();
	void move(int, int);
};

myshape::myshape(point a, point b) : rectangle(a, b)
{
	int ll = neast().x - swest().x + 1;
	int hh = neast().y - swest().y + 1;
	mouth = new line(point(swest().x + 2, swest().y + hh / 4), ll - 4);
}

void myshape::draw()
{
	rectangle::draw();
	int a = (swest().x + neast().x) / 2;
	int b = (swest().y + neast().y) / 2;
	put_point(point(a, b));
}

void myshape::move(int a, int b)
{
	rectangle::move(a, b);
	mouth->move(a, b);
}


int main()
{
	setlocale(0, "rus");
	system("color F0");
	int a = 2;
	try
	{
		screen_init();
		rotatable* hat = new rectangle(point(0, 0), point(18, 6));
		shape* mouth = new line(point(0, 15), 17);
		shape* face = new myshape(point(25, 10), point(37, 18));
		shape* hat_circle = new circle(point(5, 6), point(13, 14));
		shape* L_eye = new circle(point(8, 8), point(10, 10));
		shape* R_eye = new circle(point(13, 8), point(15, 10));
		parallelogramm* R_rog = new parallelogramm(point(0, 0), point(2, 4), point(10, 4), point(8, 0));
		parallelogramm* L_rog = new parallelogramm(point(2, 2), point(4, 6), point(12, 6), point(10, 2));
		shape_refresh();
		_getch();
		hat->rotate_right();
		L_rog->rotate_left();
		R_rog->rotate_right();
		face->move(-10, -10);
		stack(mouth, face);
		stack(hat, mouth);
		stack(hat_circle, mouth);
		L_eye->move(9, -3);
		R_eye->move(10, -3);		
		L_rog->move(11, 7);
		R_rog->move(21, 9);		
		shape_refresh();
	}
	catch (pointError &err) {
		err.ShowError();
	}
	catch (shapeError &err) {
		err.ShowExeption();
	}
	system("pause>>void");
	return 0;
}