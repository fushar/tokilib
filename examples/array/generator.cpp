/*
 * Test Case Generator via tokilib
 * 
 * Problem: Array
 * Problem author: TOKI Scientific Committee
 * Generator author: TOKI Scientific Committee
 */

#include "../../generator.h"

#include <stdarg.h>
#include <iostream>
using namespace std;

int N;
int data[100000];

int data_max, data_wanted;

void printSampleCase(int tc)
{
	if (tc == 1)
	{
		cout << "4" << '\n';
		cout << "2 3 5 7" << '\n';
	}
	else
	{
		cout << "8" << '\n';
		cout << "1 2 3 4 5 6 7 8" << '\n';
	}
}

void printCase()
{
	cout << N << '\n';
	for (int i = 0; i < N; i++)
	{
		if (i)
			cout << " ";
		cout << data[i];
	}
	cout << '\n';
}

void randomArray()
{
	for (int i = 0; i < N; i++)
		data[i] = rnd.next(1, data_max);
}

void equalElementsArray()
{
	for (int i = 0; i < N; i++)
		data[i] = data_wanted;
}

void batch0()
{
	beginSampleBatch();

	beginCase();	{ setSubtasks("1, 2");									}	endCase();
	beginCase();	{ setSubtasks("1, 2");									}	endCase();

	endBatch();
}

void batch1()
{
	beginBatch();

	setSubtasks("1, 2");

	// Boundary cases
	beginCase();	{ N = 1;	data_wanted = 1; 	equalElementsArray();	}	endCase(); 
	beginCase();	{ N = 1; 	data_wanted = 1e3;	equalElementsArray();	}	endCase(); 
	beginCase();	{ N = 1e3; 	data_wanted = 1;	equalElementsArray();	}	endCase(); 
	beginCase();	{ N = 1e3; 	data_wanted = 1e3;	equalElementsArray();	}	endCase(); 

	// Tricky cases
	beginCase();	{ set_array(data, N, "2, 2, 4, 8");						}	endCase();
	beginCase();	{ set_array(data, N, "1, 10, 10");						}	endCase();

	// Uniformly random cases
	beginCase();	{ N = 1;	data_max = 1e3;	randomArray();				}	endCase();
	beginCase();	{ N = 100;	data_max = 1e3;	randomArray();				}	endCase();
	beginCase();	{ N = 1e3;	data_max = 10;	randomArray();				}	endCase();
	beginCase();	{ N = 1e3;	data_max = 100;	randomArray();				}	endCase();
	beginCase();	{ N = 1e3;	data_max = 1e3;	randomArray();				}	endCase();

	endBatch();
}

void batch2()
{
	beginBatch();

	setSubtasks("2");

	// Boundary cases
	beginCase();	{ N = 1001;	data_wanted = 1; 	equalElementsArray();	}	endCase(); 
	beginCase();	{ N = 1e5; 	data_wanted = 1;	equalElementsArray();	}	endCase(); 
	beginCase();	{ N = 1001; data_wanted = 1001;	equalElementsArray();	}	endCase(); 
	beginCase();	{ N = 1001; data_wanted = 1e3;	equalElementsArray();	}	endCase(); 
	beginCase();	{ N = 1e5; 	data_wanted = 1e9;	equalElementsArray();	}	endCase(); 

	// Uniformly random cases
	beginCase();	{ N = 1;	data_max = 1e3;	randomArray();				}	endCase();
	beginCase();	{ N = 100;	data_max = 1e3;	randomArray();				}	endCase();
	beginCase();	{ N = 1e3;	data_max = 1e9;	randomArray();				}	endCase();
	beginCase();	{ N = 1e4;	data_max = 1e9;	randomArray();				}	endCase();
	beginCase();	{ N = 1e5;	data_max = 10;	randomArray();				}	endCase();
	beginCase();	{ N = 1e5;	data_max = 1e3;	randomArray();				}	endCase();
	beginCase();	{ N = 1e5;	data_max = 1e9;	randomArray();				}	endCase();

	endBatch();
}

int main(int argc, char* argv[])
{
	beginGenerator(argc, argv);

	setSlug("array"); 
	setMode("multiple");
	setSolution("solution");
	setValidator("validator");

	batch0();
	batch1(); 
	batch2();

	endGenerator();
}