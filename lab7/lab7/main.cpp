#include "SETfunc.h"
#include <fstream>
#include <windows.h>

using namespace std;

void main()
{
//int size; 
	system("color F0");
	ofstream outF("in.txt");
	unsigned __int64 start;
	unsigned __int64 end;
	unsigned __int64 tickcount;
	srand((unsigned int)__rdtsc());
	outF << 190 << endl;
	SET A(0), B(0), C(0), D(0), E(0), TMP(0);
	for (int size = 10; size < 200; size++)
	{
		try
		{
			start = __rdtsc();
			A.makeRandSet(size);
			B.makeRandSet(size);
			C.makeRandSet(size);
			D.makeRandSet(size);
			E.makeRandSet(0);
			TMP.makeRandSet(0);
			E.UNION(A, B);
			TMP.INTERSECTION(C, D);
			E.UNION(E, TMP);
			E.CONCAT(A, B);
			E.EXCL(B);
			E.SUBST(B, A, 3);
			end = __rdtsc();
			tickcount = end - start;
			outF << size << " " << tickcount<<endl;
		}
		catch (exception err)
		{
			outF << "Panic! " << err.what() << "!\n";
			outF.close();
			outF.open("in.txt", ios_base::app);
		}
		catch (...) {
			outF << "Unexcepted error\n";
			outF.close();
			outF.open("in.txt", ios_base::app);
		}
	}
	outF.close();
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