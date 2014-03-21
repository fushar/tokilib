/*
 * Test Case Generator via testlib
 * 
 * Tree
 * TOKI Scientific Committee
 */

#include "../../tokilib.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> par)
{
	int N = par.size();

	// Randomly label N nodes, 0 through N-1.
	vector<int> labels(N);
	for (int i = 0; i < N; i++)
		labels[i] = i;
	shuffle(labels.begin(), labels.end());

	cout << N << endl;
	for (int i = 1; i < N; i++)
	{
		int u = labels[i], v = labels[par[i]];

		// Randomly swap the order of two nodes.
		if (rnd.next(2))
			swap(u, v);
		cout << u << " " << v << endl;
	}
}

void printSample1()
{
	cout << "4" << endl;
	cout << "0 1" << endl;
	cout << "0 2" << endl;
	cout << "2 3" << endl;
}

void printSample2()
{
	cout << "3" << endl;
	cout << "0 1" << endl;
	cout << "0 2" << endl;
}

vector<int> randomTree(int N)
{
	vector<int> par(N);

	par[0] = -1;
	for (int i = 1; i < N; i++)
		par[i] = rnd.next(i);

	return par;
}

vector<int> lineTree(int N)
{
	vector<int> par(N);

	for (int i = 0; i < N; i++)
		par[i] = i-1;

	return par;
}

vector<int> fullBinaryTree(int N)
{
	vector<int> par(N);

	par[0] = -1;
	for (int i = 1; i < N; i++)
		par[i] = i/2;

	return par;
}

void subtask0()
{
	beginSampleSubtask();

	beginTestCase();	printSample1();					endTestCase();
	beginTestCase();	printSample2();					endTestCase();

	endSubtask();
}

void subtask1()
{
	beginSubtask();

	beginTestCase();	print(lineTree(2));				endTestCase();

	beginTestCase();	print(lineTree(100));			endTestCase();
	beginTestCase();	print(lineTree(1e3));			endTestCase();
	beginTestCase();	print(lineTree(1e4));			endTestCase();
	beginTestCase();	print(lineTree(1e5));			endTestCase();

	beginTestCase();	print(fullBinaryTree(1e2));		endTestCase();
	beginTestCase();	print(fullBinaryTree(1e3));		endTestCase();
	beginTestCase();	print(fullBinaryTree(1e4));		endTestCase();
	beginTestCase();	print(fullBinaryTree(1e5));		endTestCase();

	beginTestCase();	print(randomTree(1e2));			endTestCase();
	beginTestCase();	print(randomTree(1e3));			endTestCase();
	beginTestCase();	print(randomTree(1e4));			endTestCase();
	beginTestCase();	print(randomTree(1e5));			endTestCase();

	endSubtask();
}

int main(int argc, char* argv[])
{
	beginGenerator(argc, argv);

	setSlug("tree");
	setMode("single");
	setSolution("./solution");
	setValidator("./validator");

	subtask0();
	subtask1(); 

	endGenerator();
}