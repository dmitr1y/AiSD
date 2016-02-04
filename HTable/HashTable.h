#pragma once

struct HashList
{
	int key;
	struct HashList *next;
};

class HashTable
{
public:
	HashTable();
	HashTable(unsigned int );
	~HashTable();
	unsigned int HashFunction(int );
	void ClearList(HashList *);
	void Add(int);
	int Get(const int);
	void Print();
	void PrintList(HashList *);
private:
	int size;
	HashList **hash_array;
};

