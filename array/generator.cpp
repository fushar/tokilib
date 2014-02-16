/*
 * Test Case Generator via testlib
 * 
 * Array
 * TOKI Scientific Committee
 */

#include "../tokilib.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<int>& data)
{
	int N = data.size();
	cout << N << endl;
	for (int i = 0; i < N; i++)
	{
		if (i)
			cout << " ";
		cout << data[i];
	}
	cout << endl;
}

void randomArray(int N, int maxData, int w = 0)
{
	vector<int> data(N);
	for (int i = 0; i < N; i++)
		data[i] = rnd.wnext(1, maxData, w);
	printArray(data);
}

void equalElementsArray(int N, int maxData)
{
	vector<int> data(N);
	for (int i = 0; i < N; i++)
		data[i] = maxData;
	printArray(data);
}

void subtask0()
{
	int raw1[] = {2, 3, 5, 7}; 
	int raw2[] = {1, 2, 3, 4, 5, 6, 7, 8};

	vector<int> data1(raw1, raw1 + sizeof(raw1)/sizeof(int));
	vector<int> data2(raw2, raw2 + sizeof(raw2)/sizeof(int));

	beginCase(0, 1);	printArray(data1);				endCase();
	beginCase(0, 2);	printArray(data2);				endCase();
}

void subtask1()
{
	// Boundary cases
	beginCase(1, 1);	equalElementsArray(1e0, 1e0);	endCase(); 
	beginCase(1, 2);	equalElementsArray(1e0, 1e3);	endCase();
	beginCase(1, 3);	equalElementsArray(1e3, 1e0);	endCase();
	beginCase(1, 4);	equalElementsArray(1e3, 1e3);	endCase();

	// Uniformly random cases
	beginCase(1, 5);	randomArray(1e1, 1e3);			endCase();
	beginCase(1, 6);	randomArray(1e2, 1e3);			endCase();
	beginCase(1, 7);	randomArray(1e3, 1e3);			endCase();
	beginCase(1, 8);	randomArray(1e3, 1e3);			endCase();

	// Big random cases
	beginCase(1, 9);	randomArray(1e3, 1e3, 10);		endCase();
	beginCase(1, 10);	randomArray(1e3, 1e3, 10);		endCase();

	// Small random cases
	beginCase(1, 11);	randomArray(1e3, 1e3, -10);		endCase();
	beginCase(1, 12);	randomArray(1e3, 1e3, -10);		endCase();
}

void subtask2()
{
	// Boundary cases
	beginCase(2, 1);	equalElementsArray(1e3+1, 1e0);	endCase();
	beginCase(2, 2);	equalElementsArray(1e3+1, 1e9);	endCase();
	beginCase(2, 3);	equalElementsArray(1e3+1, 1e0);	endCase();
	beginCase(2, 4);	equalElementsArray(1e3+1, 1e9);	endCase();

	// Uniformly random cases
	beginCase(2, 5);	randomArray(1e4, 1e9);			endCase();
	beginCase(2, 6);	randomArray(1e4, 1e9);			endCase();
	beginCase(2, 7);	randomArray(1e5, 1e9);			endCase();
	beginCase(2, 8);	randomArray(1e5, 1e9);			endCase();

	// Big random cases
	beginCase(2, 9);	randomArray(1e5, 1e9, 10);		endCase();
	beginCase(2, 10);	randomArray(1e5, 1e9, 10);		endCase();

	// Small random cases
	beginCase(2, 11);	randomArray(1e5, 1e9, -10);		endCase();
	beginCase(2, 12);	randomArray(1e5, 1e9, -10);		endCase();
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);
	setProblemCode("array");
	setTestCaseDir("tc");
	setSolution("./solution");
	setValidator("./validator");

	subtask0();
	subtask1();
	subtask2();
}