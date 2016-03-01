#include "HashTable.h"
#include <iostream>

#define __TableSize  4
#define __ScoresSize 3

using namespace std;

HashTable::HashTable()
{
	size = __TableSize;
	hash_array = new HashList*[size];
	for (int i = 0; i < size; i++) hash_array[i] = nullptr;
}

HashTable::HashTable( int Size)
{
	this->size = Size;	
	this->hash_array = new HashList*[size];
	for (int i = 0; i < size; i++) this->hash_array[i] = nullptr;
}

HashTable::~HashTable()
{
	if (hash_array)
	{
		for (int i = 0; i < size; i++)
		{
			if (hash_array[i]) ClearList(hash_array[i]);
		}
		//free(hash_array);
		
	}
	hash_array = nullptr;
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
	return HashFunction(number);
}

void HashTable::Print(char *name)
{
	if (hash_array)
	{
		cout << ":::::::::::::::::::::::::::::::::" << endl;
		if (name) {
			cout << "::::::::::: " << name << endl;
			cout << ":::::::::::::::::::::::::::::::::" << endl;
		}
		for (int i = 0; i < size; i++)
		{
			cout << ":: " << i << " -> ";
			PrintList(hash_array[i]);
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "ERR: EMPTY" <<endl;
	}
}

void HashTable::PrintList(const HashList* list)
{	
	while (list)
	{		
		cout << list->key << ", ";
		list = list->next;
	}
	cout << "*";
}

HashTable HashTable::RandTable()
{
	HashTable C(size);	
	int *arr=new int[__ScoresSize];
	for (int i = 0; i < __ScoresSize; i++)
	{	
		int tmp;		
		do
		{
			tmp = rand() % 100;
		} while (checkRepeat(arr, __ScoresSize, tmp));
		arr[i] = tmp;
		C.Add(arr[i]);
	}
	free(arr);
	return C;
}

bool HashTable::checkRepeat(const int *arr, int sizem, int number)
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
	list = nullptr;
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

int * HashTable::ListToArray(const HashList *list)
{
	int *arr = nullptr;
	if (list)
	{
		int arrSize = ListSize(list);
		int *arr = new int[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			arr[i] = list->key;
			list = list->next;
		}
	}
	return arr;
}

int HashTable::ListSize(const HashList *list)
{
	int count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return count;
}
