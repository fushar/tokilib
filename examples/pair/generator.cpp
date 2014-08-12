/*
 * Test Case Generator via tokilib
 * 
 * Problem: Pair
 * Problem author: TOKI Scientific Committee
 * Generator author: TOKI Scientific Committee
 */

#include "../../generator.h"

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int A, B;
int A_max, B_max;

void printSampleCase(int tc)
{
	if (tc == 1)
		cout << "3 5" << '\n';
	else
		cout << "100 200" << '\n';
}

void printCase()
{
	if (rnd.next(2))
		cout << A << " " << B << '\n';
	else
		cout << B << " " << A << '\n';
}

void randomPair()
{
	A = rnd.next(1, A_max);
	B = rnd.next(1, B_max);
}

void batch0()
{
	beginSampleBatch();

	beginCase();	{ setSubtasks("1, 2");						}	endCase();
	beginCase();	{ setSubtasks("1, 2");						}	endCase();

	endBatch();
}

void batch1()
{
	beginBatch();

	setSubtasks("1, 2");

	// Boundary cases
	beginCase();	{ A = 1;	B = 1;							}	endCase();
	beginCase();	{ A = 1e3;	B = 1e3;						}	endCase();
	beginCase();	{ A = 1;	B = 1e3;						}	endCase();

	// Uniformly random cases
	beginCase();	{ A_max = B_max = 100; 		randomPair();	}	endCase();
	beginCase();	{ A_max = B_max = 500; 		randomPair();	}	endCase();
	beginCase();	{ A_max = B_max = 1e3; 		randomPair();	}	endCase();
	beginCase();	{ A_max = B_max = 1e3; 		randomPair();	}	endCase();

	// Big-and-small random cases
	beginCase();	{ A_max = 1e3; B_max = 10;	randomPair();	}	endCase();
	beginCase();	{ A_max = 1e3; B_max = 100;	randomPair();	}	endCase();

	endBatch();
}

void batch2()
{
	beginBatch();

	setSubtasks("2");

	// Boundary cases
	beginCase();	{ A = 1001;	B = 1001;						}	endCase();
	beginCase();	{ A = 1e9;	B = 1e9;						}	endCase();
	beginCase();	{ A = 1;	B = 1e9;						}	endCase();
	beginCase();	{ A = 1001;	B = 1e9;						}	endCase();

	// Uniformly random cases
	beginCase();	{ A_max = B_max = 1e4;		randomPair();	}	endCase();
	beginCase();	{ A_max = B_max = 1e5;		randomPair();	}	endCase();
	beginCase();	{ A_max = B_max = 1e6;		randomPair();	}	endCase();
	beginCase();	{ A_max = B_max = 1e7;		randomPair();	}	endCase();
	beginCase();	{ A_max = B_max = 1e8;		randomPair();	}	endCase();
	beginCase();	{ A_max = B_max = 1e9;		randomPair();	}	endCase();

	// Big-and-small random cases
	beginCase();	{ A_max = 1e9; B_max = 1e3; randomPair();	}	endCase();
	beginCase();	{ A_max = 1e9; B_max = 1e4; randomPair();	}	endCase();

	endBatch();
}

int main(int argc, char* argv[])
{
	beginGenerator(argc, argv);

	setSlug("pair");
	setMode("single");
	setSolution("solution");
	setValidator("validator");

	batch0();
	batch1(); 
	batch2();

	endGenerator();
}