#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable()
{
	size = 256;
	hash_array = new HashList*[size];
	for (int i = 0; i < size; i++) hash_array[i] = NULL;
}

HashTable::HashTable(unsigned int Size)
{
	this->size = Size;
	hash_array = new HashList*[size];
	for (int i = 0; i < size; i++) hash_array[i] = NULL;
}

HashTable::~HashTable()
{
	for (int i = 0; i < size; i++)
	{
		if (hash_array[i]) ClearList(hash_array[i]);
	}
	free(hash_array);
}

unsigned int HashTable::HashFunction(int key)
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
	for (int i = 0; i < size; i++)
	{
		PrintList(hash_array[i]);
	}
}

void HashTable::PrintList(HashList* list)
{
	while (list)
	{
		cout << list->key << ", ";
		list = list->next;
	}
}


void HashTable::ClearList(HashList *list)
{
	if (list->next) ClearList(list->next);
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
