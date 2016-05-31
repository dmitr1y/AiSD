#include "SETfunc.h"

std::set<int> makeRandSet(int size)
{
	std::set<int>newSet;
	for (int i = 0; i < size; i++)
		newSet.insert(rand() % 100);
	return newSet;
}
//
//std::set<int>EXCL(std::set<int> S1, std::set<int>S2) {
//	if (std::includes(S1.begin(), S1.end(), S2.begin(), S2.end()) == true)
//		for (auto itr = S2.begin(); itr != S2.end(); ++itr)
//			S1.erase(*itr);
//	return S1;
//}

SET::SET()
{
	makeRandSet(16);
	
}

SET::~SET()
{
}

inline void SET::EXCL(const SET &A, const SET &B)
{
	
}

inline void SET::CONCAT(const SET &A, const SET &B)
{
	std::vector <std::set<int>::const_iterator> tmpVector = A.dataPointer;
	tmpVector.insert(tmpVector.end(), B.dataPointer.begin(),B.dataPointer.end());
	swap(tmpVector, dataPointer);
}

inline void SET::SUBST(const SET &A, const SET &B, int pos)
{
	if (dataPointer.size()<pos)
	{
		//err
	}
	std::vector <std::set<int>::const_iterator> tmpVector = A.dataPointer;
	tmpVector.insert(tmpVector.begin()+pos, B.dataPointer.begin(), B.dataPointer.end());
	dataPointer = tmpVector;
}

inline void SET::UNION(const SET &A, const SET &B)
{
	set_union(A.data.begin(), A.data.end(), B.data.begin(), B.data.end(), inserter(data, data.begin()));
}

inline void SET::INTERSECTION(const SET &A, const SET &B)
{
	set_intersection(A.data.begin(), A.data.end(), B.data.begin(), B.data.end(), inserter(data, data.begin()));
}

inline void SET::makeRandSet(int size)
{
	for (int i = 0; i < size; i++)
		data.insert(rand() % 100);
}
