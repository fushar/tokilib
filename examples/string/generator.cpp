/*
 * Test Case Generator via tokilib
 * 
 * Problem: String
 * Problem author: TOKI Scientific Committee
 * Generator author: TOKI Scientific Committee
 */

#include "../../generator.h"

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string S;

void printSampleCase(int tc)
{
	if (tc == 1)
		cout << "TOKI" << '\n';
	else
		cout << "ScientificCommittee" << '\n';
}

void printCase()
{
	cout << S << '\n';
}

void randomString()
{
	S = rnd.next(format("[a-zA-Z]{%d}", N));
}

void equalCharString()
{
	char c = rnd.next("[a-zA-Z]")[0];
	S = rnd.next(format("[%c]{%d}", c, N));
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

	setSubtasks("1, 2");

	// Tricky cases
	beginCase();	{ N = 6; S = "aAbBcC";			}	endCase();
	beginCase();	{ N = 5; S = "ZZZZa";			}	endCase();

	// Random cases
	beginCase();	{ N = 1; 	randomString();		}	endCase();
	beginCase();	{ N = 2; 	randomString();		}	endCase();
	beginCase();	{ N = 3; 	randomString();		}	endCase();
	beginCase();	{ N = 1e3;	randomString();		}	endCase();
	beginCase();	{ N = 1e3;	randomString();		}	endCase();

	// Equal character cases
	beginCase();	{ N = 1;	equalCharString();	}	endCase();
	beginCase();	{ N = 10;	equalCharString();	}	endCase();
	beginCase();	{ N = 100;	equalCharString();	}	endCase();
	beginCase();	{ N = 1e3;	equalCharString();	}	endCase();
	beginCase();	{ N = 1e3;	equalCharString();	}	endCase();

	endBatch();
}

void batch2()
{
	beginBatch();

	setSubtasks("2");

	// Random cases
	beginCase();	{ N = 1001; randomString();		}	endCase();
	beginCase();	{ N = 1e4; 	randomString();		}	endCase();
	beginCase();	{ N = 1e4; 	randomString();		}	endCase();
	beginCase();	{ N = 1e5;	randomString();		}	endCase();
	beginCase();	{ N = 1e5;	randomString();		}	endCase();

	// Equal character cases
	beginCase();	{ N = 1001;	equalCharString();	}	endCase();
	beginCase();	{ N = 1e4;	equalCharString();	}	endCase();
	beginCase();	{ N = 1e4;	equalCharString();	}	endCase();
	beginCase();	{ N = 1e5;	equalCharString();	}	endCase();
	beginCase();	{ N = 1e5;	equalCharString();	}	endCase();

	endBatch();
}

int main(int argc, char* argv[])
{
	beginGenerator(argc, argv);

	setSlug("string"); 
	setMode("single");
	setSolution("solution");
	setValidator("validator");

	batch0();
	batch1();
	batch2();

	endGenerator();
}