#pragma once
//shape.h -- Библиотека фигур 
#include "Screen.h"
class shape : public point { //Виртуальный базовый класс "фигура"
public:
	static shape* list;
	shape* next;
	shape() { next = list; list = this; }
	virtual point north() const = 0;
	virtual point south() const = 0;
	virtual point east() const = 0;
	virtual point west() const = 0;
	virtual point neast() const = 0;
	virtual point seast() const = 0;
	virtual point nwest() const = 0;
	virtual point swest() const = 0;
	virtual void draw() = 0;
	virtual void move(int a, int b) { x += a; y += b; };
	virtual ~shape() {};
};

shape * shape::list = nullptr;	//Инициализация списка фигур (список пуст)

class rotatable : virtual public shape { //Фигуры, пригодные к повороту 
	enum class rotated { left, no, right };
	rotated state; //Текущее состояние поворота
public:
	rotatable(rotated r = rotated::no) : state(r) {}
	virtual void rotate_left() = 0;		//Повернуть влево
	virtual void rotate_right() = 0;	//Повернуть вправо
};

class mirrorable : virtual public shape { //Фигуры, пригодные к зеркальному отражению
	enum class mirrored { no, hor, vert };
	mirrored state;	//Текущее состояние отражения
public:
	mirrorable(mirrored m = mirrored::no) : state(m) {}
	virtual void flip_horisontally() = 0;	//Отразить горизонтально
	virtual void flip_vertically() = 0;		//Отразить вертикально
};

class line : virtual public shape {
	point w, e;
public:
	point north() const { return point((w.x + e.x) / 2, e.y<w.y ? w.y : e.y); }
	point south() const { return point((w.x + e.x) / 2, e.y<w.y ? e.y : w.y); }
	point east() const { return point(e.x<w.x ? e.x : w.x, (w.y + e.y) / 2); }
	point west() const { return point(e.x<w.x ? w.x : e.x, (w.y + e.y) / 2); }
	point neast() const { return point(e.x<w.x ? w.x : e.x, e.y<w.y ? w.y : e.y); }
	point seast() const { return point(e.x<w.x ? w.x : e.x, e.y<w.y ? e.y : w.y); }
	point nwest() const { return point(e.x<w.x ? e.x : w.x, e.y<w.y ? w.y : e.y); }
	point swest() const { return point(e.x<w.x ? e.x : w.x, e.y<w.y ? e.y : w.y); }
	void move(int a, int b)
	{
		w.x += a; w.y += b; e.x += a; e.y += b;
	}
	void draw() { put_line(w, e); }
	line(point a, point b) { w = a; e = b; }
	line(point a, int l) { w = point(a.x + l - 1, a.y); e = a; }
};

class rectangle : public rotatable {
	point sw, ne;
public:
	rectangle() { }
	point north() const { return point((sw.x + ne.x) / 2, ne.y); }
	point south() const { return point((sw.x + ne.x) / 2, sw.y); }
	point east() const { return point(ne.x, (sw.y + ne.y) / 2); }
	point west() const { return point(ne.x, (sw.y + ne.y) / 2); }
	point neast() const { return ne; }
	point seast() const { return point(sw.x, ne.y); }
	point nwest() const { return point(ne.x, sw.y); }
	point swest() const { return sw; }
	void rotate_right() //Поворот вправо - относительно se
	{
		int w = ne.x - sw.x, h = ne.y - sw.y;
		sw.x = ne.x - h * 2; ne.y = sw.y + w / 2;
	}
	void rotate_left() //Поворот влево - относительно sw
	{
		int w = ne.x - sw.x, h = ne.y - sw.y;
		ne.x = sw.x + h * 2; ne.y = sw.y + w / 2;
	}
	void move(int a, int b)
	{
		sw.x += a; sw.y += b; ne.x += a; ne.y += b;
	}
	
	void draw();
	rectangle(point, point);
};


//Параллелограмм
class parallelogramm :  public mirrorable, public rotatable {
	point sw, ne, nw, se;
public:
	parallelogramm() { }
	point north() const { return point((sw.x + ne.x) / 2, ne.y); }
	point south() const { return point((sw.x + ne.x) / 2, sw.y); }
	point east() const { return point(ne.x, (ne.y+se.y)/2);}
	point west() const { return sw; }
	point neast() const { return ne; }
	point seast() const { return se; }
	point nwest() const { return nw; }
	point swest() const { return sw; }
	void rotate_right() //Поворот вправо - относительно se
	{
		int width=abs(se.x-sw.x), height=(nw.y-sw.y), dw;
		if (sw.y != se.y)
		{
			dw = sw.y - se.y;
			nw.x = se.x + dw;;
			nw.y = se.y + width;
			ne.x = se.x + height+dw;
			ne.y = se.y + width;
			sw = se;
			se.x = sw.x + height;
			se.y = sw.y;
		}
		else
		{
			dw = nw.x - sw.x;
			nw.x = se.x;
			nw.y = se.y + width;
			ne.x = se.x + height;
			ne.y = se.y + width + dw;
			sw = se;
			se.x = sw.x + height;
			se.y = sw.y + dw;
		}
	}
	void rotate_left() //Поворот влево - относительно sw
	{
		int width = abs(se.x - sw.x), height = (nw.y - sw.y), dw;
		if (sw.y != se.y)
			dw = sw.y - se.y;
		else
			dw = nw.x - sw.x;
		ne.x = sw.x;
		ne.y = sw.y + width;
		nw.x = sw.x - height;
		nw.y = sw.y + width + dw;
		se = sw;
		sw.x = se.x - height;
		sw.y = se.y  + dw;
	}
	void move(int a, int b)
	{
		sw.x += a; sw.y += b; ne.x += a; ne.y += b; nw.x += a; nw.y += b; se.x += a; se.y += b;
	}
	void flip_horisontally();
	void flip_vertically();

	void draw();
	parallelogramm(point, point, point, point);
};

parallelogramm::parallelogramm(point a, point b,point c, point d)
//sw=a, nw=b, ne=c, se=d
{
	//(y1 != y2 || y3 != y4 || x2 - x1 != x3 - x4)
	/*if (a.y != b.y || c.y != d.y ||( b.x - a.x )!= (c.x - d.x))
	{
		throw MyException("Error: Nevernie parametri figuri!!\n");
	}*/
	bool isHorisont = false;
	int numX = -1, numY=-1;
	bool isVertical = false;
	int arrx[] = { a.x,b.x,c.x,d.x };
	int arry[] = { a.y,b.y,c.y,d.y };
	for (int i = 1; i < 4; i++)
	{
		if (arrx[0]==arrx[i])
		{
			isVertical = true;
			numX = i;
			std::cout << "for X: " << arrx[0] << "=" << arrx[i] << " in 0 and " << numX<<"\n";
		}
		if (arry[0]==arry[i])
		{
			isHorisont = true;
			numY = i;
			std::cout << "for Y: " << arry[0] << "=" << arry[i] << " in 0 and " << numY <<"\n";
		}
	}
	std::cout << "horisont:" << isHorisont << "  vertical:" << isVertical << "\n";
	int lineSize=0;
	if (isHorisont)
	{
		lineSize = abs(arrx[0] - arrx[numY]);
	}
	if(isVertical)
	{
		lineSize = abs(arry[0] - arry[numX]);
	}
	std::cout << "lineSize: " << lineSize << "\n";
	
	if (!isHorisont && !isVertical)
	{

	}
	int point3, point4;
	
	sw = a;
	nw = b;
	ne = c;
	se = d;

	/*if (a.x <=d.x) {
		if (a.y <= b.y) {
			sw = a;
			ne = b;
		}
		else {
			sw = point(a.x, b.y);
			ne = point(b.x, a.y);
		}
	}
	else {
		if (a.y <= b.y) {
			sw = point(b.x, a.y);
			ne = point(a.x, b.y);
		}
		else {
			sw = b;
			ne = a;
		}
	}*/
	/*if (a.x<d.x)
	{
		if (b.x<c.x)
		{
			if (a.y<b.y)
			{
				sw = a;
				nw = b;
				if (d.x < c.x) {
					ne = c;
					se = d;
				}
				else {
					ne = d;
					se=c;
				}
			}
			else
			{
				sw = b;
				nw = a;
				if (d.x < c.x) {
					ne = d;
					se = c;
				}
				else {
					ne = c;
					se = d;
				}
			}
		}
		else
		{
			if (a.y<c.y)
			{
				sw = a;
				nw = c;
				if (d.x < c.x) {
					ne = d;
					se = c;
				}
				else {
					ne = c;
					se = d;
				}
			}
			else
			{
				sw = c;
				nw = a;
			}
		}
	}
	else
	{

	}*/
}

void parallelogramm::draw()
{
//	point nw(sw.x, ne.y);
//	point se(ne.x, sw.y);
	put_line(nw, ne);
	put_line(ne, se);
	put_line(se, sw);
	put_line(sw, nw);
}

inline void parallelogramm::flip_horisontally() {
	int dh;
	if (sw.y != se.y)
	{
		dh = nw.y - ne.y;
		nw.y -= dh;
		sw.y -= dh;
		ne.y += dh;
		se.y += dh;
	}
	else
	{
		dh = nw.x - sw.x;
		nw.x -= dh;
		ne.x -= dh;
		se.x += dh;
		sw.x += dh;
	}
}

inline void parallelogramm::flip_vertically()
{
	int dh;
	if (sw.y!=se.y)
	{
		dh = nw.y - ne.y;
		nw.y -= dh;
		sw.y -= dh;
		ne.y += dh;
		se.y += dh;
	}
	else
	{
		dh = nw.x - sw.x;
		nw.x -= dh;
		ne.x -= dh;
		sw.x += dh;
		se.x += dh;
	}
}


class circle : virtual public shape {
	point sw, ne, nw, se;
public:
	point north() const { return point((sw.x + ne.x) / 2, ne.y); }
	point south() const { return point((sw.x + ne.x) / 2, sw.y); }
	point east() const { return point(sw.x, (sw.y + ne.y) / 2); }
	point west() const { return point(ne.x, (sw.y + ne.y) / 2); }
	point neast() const { return ne; }
	point seast() const { return point(sw.x, ne.y); }
	point nwest() const { return point(ne.x, sw.y); }
	point swest() const { return sw; }
	void draw();
	void move(int a, int b)
	{
		sw.x += a; sw.y += b; ne.x += a; ne.y += b;
	}
	circle(point  a, point b);
};
circle::circle(point  a, point b)
{
	if (a.x <= b.x) {
		if (a.y <= b.y) {
			sw = a;
			ne = b;
		}
		else {
			sw = point(a.x, b.y);
			ne = point(b.x, a.y);
		}
	}
	else {
		if (a.y <= b.y) {
			sw = point(b.x, a.y);
			ne = point(a.x, b.y);
		}
		else {
			sw = b;
			ne = a;
		}
	}
}

void circle::draw()
{
	point n((ne.x + sw.x) / 2, ne.y);
	point s((ne.x + sw.x) / 2, sw.y);
	point w(sw.x, (ne.y + sw.y) / 2);
	point e(ne.x, (sw.y + ne.y) / 2);


	point n1(n.x - 1, n.y - 1);
	point n2(n.x + 1, n.y - 1);
	point s1(s.x - 1, s.y + 1);
	point s2(s.x + 1, s.y + 1);
	point w1(w.x + 1, w.y + 1);
	point w2(w.x + 1, w.y - 1);
	point e1(e.x - 1, e.y + 1);
	point e2(e.x - 1, e.y - 1);
	point w3(w.x + 1, w.y);
	point e3(e.x - 1, e.y);

	if (w.x == e.x - 2) { // если круг очень маленький, то формируется как четрырёхугольник по 4 точкам
		put_line(w, n);
		put_line(n, e);
		put_line(e, s);
		put_line(s, w);
	}
	else {
		put_line(w1, n1);
		put_line(n2, e1);
		put_line(e2, s2);
		put_line(s1, w2);
		put_point(w.x + 1, w.y);
		put_point(e.x - 1, e.y);
		put_point(n1.x + 1, n1.y);
		put_point(s1.x + 1, s1.y);
	}
}

rectangle::rectangle(point a, point b)
{
	if (a.x == b.x && b.y == a.y) {
		throw MyException("Error: Nevernie parametri figuri!!\n");
	}
	if (a.x <= b.x) {
		if (a.y <= b.y) {
			sw = a;
			ne = b;
		}
		else {
			sw = point(a.x, b.y);
			ne = point(b.x, a.y);
		}
	}
	else {
		if (a.y <= b.y) {
			sw = point(b.x, a.y);
			ne = point(a.x, b.y);
		}
		else {
			sw = b;
			ne = a;
		}
	}
}

void rectangle::draw()
{
	point nw(sw.x, ne.y);
	point se(ne.x, sw.y);
	put_line(nw, ne);
	put_line(ne, se);
	put_line(se, sw);
	put_line(sw, nw);
}

void shape_refresh() // Перерисовка всех фигур
{
	screen_clear();
	for (shape* p = shape::list; p; p = p->next) p->draw();
	screen_refresh();
}
void stack(shape* p, const shape* q) // поместить p над q
{
	point n = q->north();
	point s = p->south();
	p->move(n.x - s.x, n.y - s.y + 1);
}
void r_side(shape* p, const shape* q) // поместить p справа от q
{
	point e = q->east();
	point w = p->west();
	p->move(e.x - w.x - 1, e.y - w.y);
}
void l_side(shape* p, const shape* q) // поместить p слева от q
{
	point w = q->west();
	point e = p->east();
	p->move(w.x - e.x + 1, w.y - e.y);
}
