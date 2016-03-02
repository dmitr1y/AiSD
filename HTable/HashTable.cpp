#include "HashTable.h"
#include <iostream>

#define __TableSize  4
#define __ScoresSize 3
#define __RandWidth 10

using namespace std;

HashTable::HashTable()
{
	this->size = __TableSize;
	this->hash_array = new HashList*[size];
	for (int i = 0; i < size; i++) this->hash_array[i] = nullptr;
}

HashTable::HashTable( int Size)
{
	this->size = Size;	
	this->hash_array = new HashList*[size];
	for (int i = 0; i < size; i++) this->hash_array[i] = nullptr;
}

HashTable::~HashTable()
{
	if (this->hash_array)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->hash_array[i]) ClearList(this->hash_array[i]);
		}
		//delete[]hash_array;
	}
	this->hash_array = nullptr;
}

int HashTable::HashFunction(int key)
{	
	key += ~(key << 16);
	key ^= (key >> 5);
	key += (key << 3);
	key ^= (key >> 13);
	key += ~(key << 9);
	key ^= (key >> 17);
	return key%(this->size);
}

int HashTable::Get(const int number)
{
	return HashFunction(number);
}

void HashTable::Print(char *name)
{
	if (this->hash_array)
	{
		cout << ":::::::::::::::::::::::::::::::::" << endl;
		if (name) {
			cout << "::::::::::: " << name << endl;
			cout << ":::::::::::::::::::::::::::::::::" << endl;
		}
		for (int i = 0; i < size; i++)
		{
			cout << ":: " << i << " -> ";
			PrintList(this->hash_array[i]);
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

void HashTable::RandTable()
{
	int *arr=new int[__ScoresSize];
	for (int i = 0; i < __ScoresSize; i++)
	{	
		int tmp;		
		do
		{
			tmp = rand() % __RandWidth;
		} while (checkRepeat(arr, __ScoresSize, tmp));
		arr[i] = tmp;
		this->Add(arr[i]);
	}
	delete[]arr;
}

bool HashTable::checkRepeat(const int *arr, int sizem, int number)
{
	for (int i = 0; i < sizem; i++)
	{
		if (arr[i] == number)
			return true;
	}
	return false;
}

void HashTable::ClearList(HashList *list)
{
	if (list && list->next) ClearList(list->next);
	delete list;
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
				delete new_value;
				return;
			}
			if (last_value->next) last_value = last_value->next;
			else break;
		}
		last_value->next = new_value;
	}
	else hash_array[HashFunction(key)] = new_value;
}

HashTable & HashTable:: operator &(const HashTable & B)const
{
	HashTable *C= new HashTable();
	for (int i = 0; i < size; i++)
	{
		for (HashList *tmp = this->hash_array[i]; tmp; tmp = tmp->next)
		{
			for (HashList *tmp1 = B.hash_array[i]; tmp1; tmp1 = tmp1->next)
				if (tmp1->key == tmp->key)
					C->Add(tmp->key);
		}
	}
	return *C;
}

HashTable & HashTable:: operator +(const HashTable & B)const
{
	HashTable *C=new HashTable();
	for (int i = 0; i < size; i++)
	{
		HashList *tmp= this->hash_array[i];
		HashList *tmp1 = B.hash_array[i];
		while (tmp && tmp1)
		{
			if (tmp->key != tmp1->key)
			{
				C->Add(tmp->key);
				C->Add(tmp1->key);
			}
			tmp = tmp->next;
			tmp1 = tmp1->next;
		}
		while (tmp)
		{
			C->Add(tmp->key);
			tmp = tmp->next;
		}

		while (tmp1)
		{
			C->Add(tmp1->key);
			tmp1 = tmp1->next;
		}
	}
	return *C;
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
