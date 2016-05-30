#pragma once
const int XMAX = 40; //������ ������
const int YMAX = 30;
#include "errorExceptions.h"

class point {	//����� �� ������
public:
	int x, y;
	point(int a = 0, int b = 0) : x(a), y(b) {
		if (x >= XMAX || y >= YMAX) {
			throw pointError(a, b);
		}
	}
};

extern void put_point(int a, int b); //����� �����
inline void put_point(point p) { put_point(p.x, p.y); }
extern void put_line(int, int, int, int); //����� �����


extern void put_line(point a, point b)
{
	put_line(a.x, a.y, b.x, b.y);
}
extern void screen_init();	//�������� ������
extern void screen_destroy();	//�������� ������
extern void screen_refresh();	//����������
extern void screen_clear();	//�������

							//1. ��������� ������ � ����� ������� ��������
char screen[XMAX][YMAX];


enum color { black = '#', white = ' ' };
void screen_init()
{
	for (int y = 0; y<YMAX; y++)
		for (int x = 0; x<XMAX; x++)
			screen[x][y] = white;
}

inline int on_screen(int a, int b) // �������� ���������
{
	return 0 <= a && a <XMAX && 0 <= b && b<YMAX;
}

void put_point(int a, int b)
{
	if (on_screen(a, b)) screen[a][b] = black; else throw shapeError("Something happend with your point\n");
}

void put_line(int x0, int y0, int x1, int y1)

{
	register int dx = 1;
	int a = x1 - x0;
	if (a < 0) dx = -1, a = -a;
	register int dy = 1;
	int b = y1 - y0;
	if (b < 0) dy = -1, b = -b;
	int two_a = 2 * a;
	int two_b = 2 * b;
	int xcrit = -b + two_a;
	register int eps = 0;

	for (;;) {
		put_point(x0, y0);
		if (x0 == x1 && y0 == y1) break;
		if (eps <= xcrit) x0 += dx, eps += two_b;
		if (eps >= a || a<b) y0 += dy, eps -= two_a;
	}
}

void screen_clear() { screen_init(); } //������� ������

void screen_refresh() // ���������� ������
{
	for (int y = YMAX - 1; 0 <= y; y--) { // � ������� ������ �� ������
		for (int x = 0; x<XMAX; x++) // �� ������ ������� �� �������
			std::cout << screen[x][y];
		std::cout << '\n';
	}
}
