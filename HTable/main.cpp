#include "HashTable.h"
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	HashTable A,B,C,D,E;
	A = A.RandTable();
	A.Print();
	B = B.RandTable();
	B.Print();
	D = D.RandTable();
	D.Print();
	C = C.RandTable();
	C.Print();
	E =( A + B+C)&D;
	E.Print();
	system("pause");
	return 0;
}