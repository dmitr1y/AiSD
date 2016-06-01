#pragma once

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <iterator>

typedef std::multiset<int>::const_iterator ITERATOR;

class SET
{
public:
	SET();
	SET(int);
	void EXCL(const SET&);
	void CONCAT(const SET&, const SET&);
	void SUBST(const SET&, const SET&, int);
	void UNION(const SET&, const SET&);
	void INTERSECTION(const SET&, const SET&);
	void makeRandSet(int);
	void show();
private:
	int maxNumber;//макс элемент
	int capacity;//мощность
	std::multiset<int>data;
	std::vector<ITERATOR> dataPointer;
};