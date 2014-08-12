/*
 * Test Case Generator via tokilib
 * 
 * Problem: Tree
 * Problem author: TOKI Scientific Committee
 * Generator author: TOKI Scientific Committee
 */

#include "../../generator.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int par[100000];
int labels[100000];

void printSampleCase(int tc)
{
	if (tc == 1)
	{
		cout << "4" << '\n';
		cout << "0 1" << '\n';
		cout << "0 2" << '\n';
		cout << "2 3" << '\n';	
	}
	else
	{
		cout << "3" << '\n';
		cout << "0 1" << '\n';
		cout << "0 2" << '\n';
	}
}

void printCase()
{
	// Randomly label N nodes, 0 through N-1.
	for (int i = 0; i < N; i++)
		labels[i] = i;
	shuffle(labels, labels + N);

	cout << N << '\n';
	for (int i = 1; i < N; i++)
	{
		int u = labels[i], v = labels[par[i]];

		// Randomly swap the order of two nodes.
		if (rnd.next(2))
			swap(u, v);
		cout << u << " " << v << '\n';
	}
}

void randomTree()
{
	par[0] = -1;
	for (int i = 1; i < N; i++)
		par[i] = rnd.next(i);
}

void lineTree()
{
	for (int i = 0; i < N; i++)
		par[i] = i-1;
}

void fullBinaryTree()
{
	par[0] = -1;
	for (int i = 1; i < N; i++)
		par[i] = i/2;
}

void batch0()
{
	beginSampleBatch();

	beginCase();	{ setSubtasks("1");				}	endCase();
	beginCase();	{ setSubtasks("1");				}	endCase();

	endBatch();
}

void batch1()
{
	beginBatch();

	setSubtasks("1");

	beginCase();	{ N = 2; 	lineTree(); 		}	endCase();

	beginCase();	{ N = 100; 	lineTree();			}	endCase();
	beginCase();	{ N = 1e3;	lineTree();			}	endCase();
	beginCase();	{ N = 1e4;	lineTree();			}	endCase();
	beginCase();	{ N = 1e5;	lineTree();			}	endCase();

	beginCase();	{ N = 1e2;	fullBinaryTree();	}	endCase();
	beginCase();	{ N = 1e3;	fullBinaryTree();	}	endCase();
	beginCase();	{ N = 1e4;	fullBinaryTree();	}	endCase();
	beginCase();	{ N = 1e5;	fullBinaryTree();	}	endCase();

	beginCase();	{ N = 1e2;	randomTree();		}	endCase();
	beginCase();	{ N = 1e3;	randomTree();		}	endCase();
	beginCase();	{ N = 1e4;	randomTree();		}	endCase();
	beginCase();	{ N = 1e5;	randomTree();		}	endCase();

	endBatch();
}

int main(int argc, char* argv[])
{
	beginGenerator(argc, argv);

	setSlug("tree");
	setMode("single");
	setSolution("solution");
	setValidator("validator");

	batch0();
	batch1();

	endGenerator();
}