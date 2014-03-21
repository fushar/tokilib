/*
 * Test Case Generator via testlib
 * 
 * Pair
 * TOKI Scientific Committee
 */

#include "../../tokilib.h"

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

void printSample1()
{
	cout << "3 5" << endl;
}

void printSample2()
{
	cout << "100 200" << endl;
}

void print(pair<int, int> p)
{
	if (rnd.next(2))
		cout << p.first << " " << p.second << endl;
	else
		cout << p.second << " " << p.first << endl;
}

pair<int, int> randomPair(int AB_max)
{
	int A = rnd.next(1, AB_max);
	int B = rnd.next(1, AB_max);
	return make_pair(A, B);
}

pair<int, int> randomPair(int A_max, int B_max)
{
	int A = rnd.next(1, A_max);
	int B = rnd.next(1, B_max);
	return make_pair(A, B);
}

void subtask0()
{
	beginSampleSubtask();

	beginTestCase();	printSample1();						endTestCase();
	beginTestCase();	printSample2();						endTestCase();
	
	endSubtask();
}

void subtask1()
{
	beginSubtask();

	// Boundary cases
	beginTestCase();	print(make_pair(1, 1));				endTestCase();
	beginTestCase();	print(make_pair(1e3, 1e3));			endTestCase();
	beginTestCase();	print(make_pair(1, 1e3));			endTestCase();

	// Uniformly random cases
	beginTestCase();	print(randomPair(100));				endTestCase();
	beginTestCase();	print(randomPair(500));				endTestCase();
	beginTestCase();	print(randomPair(1e3));				endTestCase();
	beginTestCase();	print(randomPair(1e3));				endTestCase();

	// Big-and-small random cases
	beginTestCase();	print(randomPair(1e3, 10));			endTestCase();
	beginTestCase();	print(randomPair(1e3, 100));		endTestCase();
	
	endSubtask();
}

void subtask2()
{
	beginSubtask();

	// Boundary cases
	beginTestCase();	print(make_pair(1001, 1001));		endTestCase();
	beginTestCase();	print(make_pair(1e9, 1e9));			endTestCase();
	beginTestCase();	print(make_pair(1, 1e9));			endTestCase();
	beginTestCase();	print(make_pair(1001, 1e9));		endTestCase();

	// Uniformly random cases
	beginTestCase();	print(randomPair(1e4));				endTestCase();
	beginTestCase();	print(randomPair(1e5));				endTestCase();
	beginTestCase();	print(randomPair(1e6));				endTestCase();
	beginTestCase();	print(randomPair(1e7));				endTestCase();
	beginTestCase();	print(randomPair(1e8));				endTestCase();
	beginTestCase();	print(randomPair(1e9));				endTestCase();

	// Big-and-small random cases
	beginTestCase();	print(randomPair(1e9, 1e3));		endTestCase();
	beginTestCase();	print(randomPair(1e9, 1e4));		endTestCase();
	
	endSubtask();
}

int main(int argc, char* argv[])
{
	beginGenerator(argc, argv);

	setSlug("pair-of-integers");
	setMode("single");
	setSolution("./solution");
	setValidator("./validator");

	subtask0();
	subtask1(); 
	subtask2();

	endGenerator();
}