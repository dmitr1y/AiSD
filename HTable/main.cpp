#include "HashTable.h"
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	system("color F0");
	srand(time(NULL));
	HashTable A,B,C,D,E;
	A.RandTable();
	A.Print("A");
	B.RandTable();
	B.Print("B");
	C.RandTable();
	C.Print("C");
	D.RandTable();
	D.Print("D");
	E =A + B+(C&D);
	E.Print("E=A+B+C&D");
	system("pause");
	return 0;
}