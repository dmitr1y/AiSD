#include "HashTable.h"
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	system("color F0");
	srand(time(NULL));
	HashTable A,B,C,D,E;
	A = A.RandTable();
	A.Print("A");
	A.~HashTable();
	A.Print("A");
	//B = B.RandTable();
	//B.Print("B");
	//D = D.RandTable();
	//D.Print("C");
	//C = C.RandTable();
	//C.Print("D");
	//E =( A + B+C)&D;
	//E.Print("E=A+B+C&D");
	system("pause");
	return 0;
}