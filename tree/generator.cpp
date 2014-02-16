/*
 * Test Case Generator via testlib
 * 
 * Tree
 * TOKI Scientific Committee
 */

#include "../tokilib.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printTree(vector<int>& par)
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

void manualTree1()
{
	cout << "4" << endl;
	cout << "0 1" << endl;
	cout << "0 2" << endl;
	cout << "2 3" << endl;
}

void manualTree2()
{
	cout << "3" << endl;
	cout << "0 1" << endl;
	cout << "0 2" << endl;
}

void randomTree(int N)
{
	vector<int> par(N);

	// 0 is the root.
	// For each of the remaining nodes, randomly choose one of previous nodes as its parent.
	par[0] = -1;
	for (int i = 1; i < N; i++)
		par[i] = rnd.next(i);

	printTree(par);
}

void lineTree(int N)
{
	vector<int> par(N);

	for (int i = 0; i < N; i++)
		par[i] = i-1;

	printTree(par);
}

void fullBinaryTree(int N)
{
	vector<int> par(N);

	par[0] = -1;
	for (int i = 1; i < N; i++)
		par[i] = i/2;

	printTree(par);
}

void subtask0()
{
	beginCase(0, 1);	manualTree1();					endCase();
	beginCase(0, 2);	manualTree2();					endCase();
}

void subtask1()
{
	// Smallest case.
	beginCase(1, 1);	lineTree(2);					endCase();

	beginCase(1, 2);	lineTree(1e2);					endCase();
	beginCase(1, 3);	lineTree(1e3);					endCase();
	beginCase(1, 4);	lineTree(1e4);					endCase();
	beginCase(1, 5);	lineTree(1e5);					endCase();

	beginCase(1, 6);	fullBinaryTree(1e2);			endCase();
	beginCase(1, 7);	fullBinaryTree(1e3);			endCase();
	beginCase(1, 8);	fullBinaryTree(1e4);			endCase();
	beginCase(1, 9);	fullBinaryTree(1e5);			endCase();

	beginCase(1, 10);	randomTree(1e2);				endCase();
	beginCase(1, 11);	randomTree(1e3);				endCase();
	beginCase(1, 12);	randomTree(1e4);				endCase();
	beginCase(1, 13);	randomTree(1e5);				endCase();
}

int main(int argc, char* argv[])
{ 
	registerGen(argc, argv, 1);
	setProblemCode("tree");
	setTestCaseDir("tc");
	setSolution("./solution");
	setValidator("./validator");

	subtask0();
	subtask1();
}