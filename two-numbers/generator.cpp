/*
 * Test Case Generator via testlib
 * 
 * Two Numbers
 * TOKI Scientific Committee
 */

#include "../tokilib.h"

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

void manualCase(ll A, ll B)
{
	cout << A << " " << B << endl;
}

void randomCase(ll maxAB, int wA = 0, int wB = 0)
{
	ll A = rnd.wnext(1ll, maxAB, wA);
	ll B = rnd.wnext(1ll, maxAB, wB);

	if (rnd.next(2))
		swap(A, B);

	cout << A << " " << B << endl;
}

void subtask0()
{
	beginCase(0, 1);	manualCase(3, 5);				endCase();
	beginCase(0, 2);	manualCase(100, 200);			endCase();
}

void subtask1()
{
	// Boundary cases
	beginCase(1, 1);	manualCase(1, 1);				endCase();
	beginCase(1, 2);	manualCase(1e9, 1e9);			endCase();

	// Uniformly random cases
	beginCase(1, 3);	randomCase(1e3);				endCase();
	beginCase(1, 4);	randomCase(1e5);				endCase();
	beginCase(1, 5);	randomCase(1e7);				endCase();
	beginCase(1, 6);	randomCase(1e9);				endCase();

	// Big random cases
	beginCase(1, 7);	randomCase(1e9, 32, 32);		endCase();
	beginCase(1, 8);	randomCase(1e9, 32, 32);		endCase();

	// Big-and-small random cases
	beginCase(1, 9);	randomCase(1e9, -32, 32);		endCase();
	beginCase(1, 10);	randomCase(1e9, -32, 32);		endCase();	
}


void subtask2()
{
	// Boundary cases
	beginCase(2, 1);	manualCase(1e9+1, 1e9+1);		endCase();
	beginCase(2, 2);	manualCase(1e12, 1e12);			endCase();

	// Uniformly random cases
	beginCase(2, 3);	randomCase(1e10);				endCase();
	beginCase(2, 4);	randomCase(1e11);				endCase();
	beginCase(2, 5);	randomCase(1e12);				endCase();
	beginCase(2, 6);	randomCase(1e12);				endCase();

	// Big random cases
	beginCase(2, 7);	randomCase(1e12, 32, 32);		endCase();
	beginCase(2, 8);	randomCase(1e12, 32, 32);		endCase();

	// Big-and-small random cases
	beginCase(2, 9);	randomCase(1e12, -32, 32);		endCase();
	beginCase(2, 10);	randomCase(1e12, -32, 32);		endCase();	
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);
	setProblemCode("two");
	setTestCaseDir("tc");
	setSolution("./solution");
	setValidator("./validator");

	subtask0();
	subtask1();
	subtask2();
}