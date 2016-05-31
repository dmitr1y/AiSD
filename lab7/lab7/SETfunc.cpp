#include "SETfunc.h"


SET::SET()
{
	makeRandSet(16);	
	dataPointer.clear();
}

SET::SET(int in)
{
	dataPointer.clear();
	data.clear();
}


 void SET::EXCL(const SET &B)
{
	if (std::includes(data.begin(), data.end(), B.data.begin(), B.data.end()) == true)
		for (auto itr = B.data.begin(); itr != B.data.end(); ++itr)
			data.erase(*itr);
}

 void SET::CONCAT(const SET &A, const SET &B)
{
	std::vector <std::set<int>::const_iterator> tmpVector = A.dataPointer;
	tmpVector.insert(tmpVector.end(), B.dataPointer.begin(),B.dataPointer.end());
	swap(tmpVector, dataPointer);
}

 void SET::SUBST(const SET &A, const SET &B, int pos)
{
	if (dataPointer.size()<pos)
	{
		//ERR: wrong pos
	}
	else
	{
		std::vector <std::set<int>::const_iterator> tmpVector = A.dataPointer;
		tmpVector.insert(tmpVector.begin() + pos, B.dataPointer.begin(), B.dataPointer.end());
		dataPointer = tmpVector;
	}
}

 void SET::UNION(const SET &A, const SET &B)
{
	std::set_union<ITERATOR, ITERATOR, std::insert_iterator<std::set<int>>>(A.data.begin(), A.data.end(), B.data.begin(), B.data.end(), inserter(data, data.begin()));
}

 void SET::INTERSECTION(const SET &A, const SET &B)
{
	std::set_intersection<ITERATOR, ITERATOR, std::insert_iterator<std::set<int>>>(A.data.begin(), A.data.end(), B.data.begin(), B.data.end(), inserter(data, data.begin()));
}

 void SET::makeRandSet(int size)
{
	for (int i = 0; i < size; i++)
		data.insert(rand() % 100);
}

void SET::show()
{
	std::ostream_iterator<int> out(std::cout, ", ");
	copy(data.begin(), data.end(), out);
}
