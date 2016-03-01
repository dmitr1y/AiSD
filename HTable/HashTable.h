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
	void Print(char*);
	void PrintList(const HashList *);
	HashTable RandTable();
	bool checkRepeat(const int * , int, int);
	HashTable operator &(const HashTable &)const;
	HashTable operator +(const HashTable &)const;
	int* ListToArray(const HashList*);
	int ListSize(const HashList*);
private:
	int size;
	HashList **hash_array;
};

