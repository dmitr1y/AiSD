#include "SETfunc.h"

std::set<int> makeRandSet(int size)
{
	std::set<int>newSet;
	for (int i = 0; i < size; i++)
	{
		newSet.insert(rand() % 100);
	}
	return newSet;
}