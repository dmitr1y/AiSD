#include "HashTable.h"

#include <iostream>

using namespace std;

int main()
{
	HashTable A,B,C,D,E;
	A = A.RandTable();
	A.Print();
	B = B.RandTable();
	B.Print();
	E = A & B;
	E.Print();
	system("pause");
	return 0;
}