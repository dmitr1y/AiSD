#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "SETfunc.h"

using namespace std;

void main()
{
	system("color F0");
	srand((unsigned int)__rdtsc());
	ostream_iterator<int> out(cout, ", ");
	set<int> A, B, C, D, E;
	int size = 16;// SETS size
	//_________________________- INITIAL RAND SETS -_________________________
	cout << "################ INITIAL ################" << endl << endl;
	A = makeRandSet(size);
	cout << "  A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	B = makeRandSet(size);
	cout << "  B: ";
	copy(B.begin(), B.end(), out);
	cout << endl;
	C = makeRandSet(size);
	cout << "  C: ";
	copy(C.begin(), C.end(), out);
	cout << endl;
	D = makeRandSet(size);
	cout << "  D: ";
	copy(D.begin(), D.end(), out);
	//_________________________- COMPUTING -_________________________
	cout << endl<<endl<< "################ COMPUTING ###############"<<endl<<endl;
	cout << " computing E=A+B:" << endl << "  E: ";;
	//_________________________- UNION -_________________________
	set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(E, E.begin()));
	copy(E.begin(), E.end(), out);
	cout << endl;
	cout << " computing tmp=C&D:" << endl << "  tmp: ";;
	set<int>tmp;//temporary set for minor calculating: tmp=C&D
	//_________________________- INTERSECTION -_________________________
	set_intersection(C.begin(), C.end(), D.begin(), D.end(), inserter(tmp, tmp.begin()));
	copy(tmp.begin(), tmp.end(), out);
	cout << endl;
	cout << " computing E=A+B+C&D:" << endl << "  E: ";;
	//_________________________- UNION -_________________________
	set_union(E.begin(), E.end(), tmp.begin(), tmp.end(), inserter(E, E.begin()));
	copy(E.begin(), E.end(), out);
	system("pause>>void");
}