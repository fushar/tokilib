/*
 * Test Case Generator via testlib
 * 
 * Array
 * TOKI Scientific Committee
 */

#include "../../tokilib.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> ar)
{
	int N = ar.size();
	cout << N << endl;
	for (int i = 0; i < N; i++)
	{
		if (i)
			cout << " ";
		cout << ar[i];
	}
	cout << endl;
}

vector<int> randomArray(int N, int elem_max)
{
	vector<int> ar(N);
	for (int i = 0; i < N; i++)
		ar[i] = rnd.next(1, elem_max);
	return ar;
}

vector<int> equalElementsArray(int N, int elem)
{
	vector<int> ar(N);
	for (int i = 0; i < N; i++)
		ar[i] = elem;
	return ar;
}

void printSample1()
{
	cout << "4" << endl;
	cout << "2 3 5 7" << endl;
}

void printSample2()
{
	cout << "8" << endl;
	cout << "1 2 3 4 5 6 7 8" << endl;
}

void subtask0()
{
	beginSampleSubtask();

	beginTestCase();	printSample1();							endTestCase();
	beginTestCase();	printSample2();							endTestCase();

	endSubtask();
}

void subtask1()
{
	beginSubtask();

	// Boundary cases
	beginTestCase();	print(equalElementsArray(1, 1));		endTestCase(); 
	beginTestCase();	print(equalElementsArray(1, 1e3));		endTestCase();
	beginTestCase();	print(equalElementsArray(1e3, 1));		endTestCase();
	beginTestCase();	print(equalElementsArray(1e3, 1e3));	endTestCase();

	// Tricky cases
	beginTestCase();	print(make_array(4,  2, 2, 4, 8));		endTestCase();
	beginTestCase();	print(make_array(3,  1, 10, 10));		endTestCase();

	// Uniformly random cases
	beginTestCase();	print(randomArray(1, 1e3));				endTestCase();
	beginTestCase();	print(randomArray(100, 1e3));			endTestCase();
	beginTestCase();	print(randomArray(1e3, 10));			endTestCase();
	beginTestCase();	print(randomArray(1e3, 100));			endTestCase();
	beginTestCase();	print(randomArray(1e3, 1e3));			endTestCase();

	endSubtask();
}

void subtask2()
{
	beginSubtask();

	// Boundary cases
	beginTestCase();	print(equalElementsArray(1001, 1));		endTestCase(); 
	beginTestCase();	print(equalElementsArray(1e5, 1));		endTestCase(); 
	beginTestCase();	print(equalElementsArray(1001, 1001));	endTestCase(); 
	beginTestCase();	print(equalElementsArray(1001, 1e3));	endTestCase();
	beginTestCase();	print(equalElementsArray(1e5, 1e9));	endTestCase();

	// Uniformly random cases
	beginTestCase();	print(randomArray(1, 1e3));				endTestCase();
	beginTestCase();	print(randomArray(100, 1e3));			endTestCase();
	beginTestCase();	print(randomArray(1e3, 1e9));			endTestCase();
	beginTestCase();	print(randomArray(1e4, 1e9));			endTestCase();
	beginTestCase();	print(randomArray(1e5, 10));			endTestCase();
	beginTestCase();	print(randomArray(1e5, 1e3));			endTestCase();
	beginTestCase();	print(randomArray(1e5, 1e9));			endTestCase();

	endSubtask();
}

int main(int argc, char* argv[])
{
	beginGenerator(argc, argv);

	setSlug("array"); 
	setMode("single");
	setSolution("./solution");
	setValidator("./validator");

	subtask0();
	subtask1(); 
	subtask2();

	endGenerator();
}