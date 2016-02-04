#include "HashTable.h"

#include <iostream>

using namespace std;

int main()
{
	HashTable A(4);
	int arr[10] = { 1,2,3,4,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " -> " << A.HashFunction(arr[i]) <<endl;
		A.Add(arr[i]);
	}
	//cout << A.HashFunction(22);
	A.Print();
	system("pause");
	return 0;
}