#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable()
{
	size = 15;
	hash_array = new HashList*[size];
	for (int i = 0; i < size; i++) hash_array[i] = NULL;
}

HashTable::HashTable( int Size)
{
	this->size = Size;
	hash_array = new HashList*[size];
	for (int i = 0; i < size; i++) hash_array[i] = NULL;
}

HashTable::~HashTable()
{
	/*for (int i = 0; i < size; i++)
	{
		if (hash_array[i]) ClearList(hash_array[i]);
	}
	free(hash_array);*/
}

int HashTable::HashFunction(int key)
{	
	key += ~(key << 16);
	key ^= (key >> 5);
	key += (key << 3);
	key ^= (key >> 13);
	key += ~(key << 9);
	key ^= (key >> 17);
	return key%size;
}

int HashTable::Get(const int number)
{
	int id = HashFunction(number);

	return id;
}

void HashTable::Print()
{
	cout << "================================" << endl;
	cout << "+++++++++++Hash Table+++++++++++" << endl;
	cout << "================================"<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << "|| "<< i << " => ";
		PrintList(hash_array[i]);
		cout << endl;
	}
	cout << "================================" << endl;
}

void HashTable::PrintList(HashList* list)
{	
	if (!list)
	{
	//	cout << "empty";
	}
	HashList *tmp = list;
	while (tmp)
	{		
		cout << tmp->key << ", ";
		tmp = tmp->next;
	}
}

HashTable HashTable::RandTable()
{
	HashTable C(size);	
	int *arr=new int[size];
	for (int i = 0; i < 16; i++)
	{	
		int tmp;		
		do
		{
			tmp = rand() % 100;
		} while (checkRepeat(arr,size, tmp));
		arr[i] = tmp;
		C.Add(arr[i]);
	}
	//free(arr);
	return C;
}

bool HashTable::checkRepeat(int *arr, int sizem, int number)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i]==number)
		{
			return true;
		}
	}
	return false;
}

void HashTable::ClearList(HashList *list)
{
	if (list && list->next) ClearList(list->next);
	free(list);
}

void HashTable::Add(int key)
{
	HashList *new_value = new HashList();
	new_value->key = key;
	new_value->next = NULL;
	HashList *last_value;
	if ((last_value = hash_array[HashFunction(key)]))
	{
		for (;;)
		{			
			if (!last_value->key==key)
			{
				free(new_value);
				return;
			}
			if (last_value->next) last_value = last_value->next;
			else break;
		}
		last_value->next = new_value;
	}
	else hash_array[HashFunction(key)] = new_value;
}

HashTable HashTable:: operator &(const HashTable & B)const
{
	HashTable C(size);
	
	for (int i = 0; i < size; i++)
	{		
		for (HashList *tmp = this->hash_array[i]; tmp ; tmp=tmp->next)
		{
			for (HashList *tmp1 = B.hash_array[i]; tmp1; tmp1 = tmp1->next)
			{
				if (tmp1->key==tmp->key)
				{
					C.Add(tmp->key);
				}
			}
		}
	}
	return C;
}

HashTable HashTable:: operator +(const HashTable & B)const
{
	HashTable C(size);
	for (int i = 0; i < size; i++)
	{
		HashList *tmp= this->hash_array[i];
		while (tmp)
		{
			C.Add(tmp->key);
			tmp = tmp->next;
		}
		HashList *tmp1 = B.hash_array[i];
		while (tmp1)
		{
			C.Add(tmp1->key);
			tmp1 = tmp1->next;
		}
	}
	return C;
}

void HashTable::arraySort(int* arr)
{
//USE: http://habrahabr.ru/company/infopulse/blog/133303/ 
}

int * HashTable::ListToArray(HashList *list)
{
	int *arr = nullptr;
	if (list)
	{
		int arrSize = ListSize(list);
		int *arr = new int[arrSize];
		HashList *tmp = list;
		for (int i = 0; i < arrSize; i++)
		{
			arr[i] = tmp->key;
			tmp = tmp->next;
		}
	}
	return arr;
}

int HashTable::ListSize(HashList *list)
{
	int count = 0;
	HashList *tmp = list;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}


