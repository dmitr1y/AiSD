#include "SETfunc.h"

using namespace std;

void main()
{
	system("color F0");
	ofstream outF("in.txt");
	srand((unsigned int)__rdtsc());
	SET A, B, C, D, E(0), TMP(0);

	E.UNION(A, B);
	TMP.INTERSECTION(C, D);
	E.UNION(E, TMP);
	E.CONCAT(A, B);
	E.EXCL(B);
	E.SUBST(B, A, 3);


	////_________________________- INITIAL RAND SETS -_________________________
	//cout << "################ INITIAL ################" << endl << endl;
	//cout << " A: ";
	//A.show();
	//cout <<endl<< " B: ";
	//B.show();
	//cout << endl << " C: ";
	//C.show();
	//cout << endl << " D: ";
	//D.show();
	//cout << endl;
	////_________________________- COMPUTING -_________________________
	//cout << endl<<endl<< "################ COMPUTING ###############"<<endl<<endl;
	//cout << " computing E=A+B:";
	////_________________________- UNION -_________________________
	//E.UNION(A, B);
	//cout << endl << "  E: ";
	//E.show();
	//cout << endl;
	//cout << " computing tmp=C&D:";
	////_________________________- INTERSECTION -_________________________
	//SET TMP(0);
	//TMP.INTERSECTION(C, D);
	//cout << endl << "  TMP: ";
	//TMP.show();
	//cout << endl;
	//cout << " computing E=A+B+C&D:";
	////_________________________- UNION -_________________________
	//E.UNION(E, TMP);
	//cout << endl << "  E: ";
	//E.show();
	//cout << endl;
	system("pause>>void");
}