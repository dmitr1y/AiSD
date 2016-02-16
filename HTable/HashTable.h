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
	HashTable(int );
	~HashTable();
	int HashFunction(int );
	void ClearList(HashList *);
	void Add(int);
	int Get(const int);
	void Print();
	void PrintList(HashList *);
	HashTable RandTable();
	bool checkRepeat(int * , int, int);
	HashTable operator &(const HashTable &)const;
	HashTable operator +(const HashTable &)const;
	void arraySort(int* );
	int* ListToArray(HashList*);
	int ListSize(HashList*);
private:
	int size;
	HashList **hash_array;
};

