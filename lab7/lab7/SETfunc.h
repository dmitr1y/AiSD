#pragma once

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <iterator>
//generating random sets with given size
//std::set<int>makeRandSet(int );
//std::set<int>EXCL(std::set<int>, std::set<int>);
//std::set<int>CONCAT(std::set<int>, std::set<int>);
//std::set<int>SUBST(std::set<int>, std::set<int>, int);
class SET
{
public:
	SET();
	~SET();
	void EXCL(const SET&, const SET&);
	void CONCAT(const SET&, const SET&);
	void SUBST(const SET&, const SET&, int);
	void UNION(const SET&, const SET&);
	void INTERSECTION(const SET&, const SET&);
	void makeRandSet(int);
private:
	int maxNumber;//макс элемент
	int capacity;//мощность
	std::set<int>data;
	std::vector<std::set<int>::const_iterator> dataPointer;
};