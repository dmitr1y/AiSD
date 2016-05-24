#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "SETfunc.h"

using namespace std;

void main()
{
	srand((unsigned int)__rdtsc());
	ostream_iterator<int> out(cout, ", ");
	set<int> A, B, C, D, E;
	int size = 16;
	A = makeRandSet(size);
	copy(A.begin(), A.end(), out);
	cout << endl;
	B = makeRandSet(size);
	copy(B.begin(), B.end(), out);
	cout << endl;
	C = makeRandSet(size);
	copy(C.begin(), C.end(), out);
	cout << endl;
	D = makeRandSet(size);
	copy(D.begin(), D.end(), out);
	cout << endl;
	set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(E, E.begin()));
	cout <<"A+B"<< endl;
	copy(E.begin(), E.end(), out);
	cout << endl;
	cout << "C&D" << endl;
	set<int>tmp;
	set_intersection(C.begin(), C.end(), D.begin(), D.end(), inserter(tmp, tmp.begin()));
	copy(tmp.begin(), tmp.end(), out);
	cout << endl;
	cout << "A+B+C&D" << endl;
	set_union(E.begin(), E.end(), tmp.begin(), tmp.end(), inserter(E, E.begin()));
	copy(E.begin(), E.end(), out);
	system("pause>>void");
}