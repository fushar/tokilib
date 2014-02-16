/*
 * Test Case Validator via testlib
 * 
 * Array
 * TOKI Scientific Committee
 */

#include "../tokilib.h"

typedef long long ll;

int subtask, testCase;

int N;
int data[100000];

int main(int argc, char* argv[])
{
	registerValidation();
	extractValidationInfo(argc, argv, subtask, testCase);

	switch (subtask)
	{
	case 0:
	case 1:
		N = inf.readInt(1, 1e3, "N");
		inf.readEoln();
		for (int i = 0; i < N; i++)
		{
			data[i] = inf.readInt(1, 1e3, "S_i");
			if (i < N-1)
				inf.readSpace();
		}
		inf.readEoln();
		inf.readEof();
		break;
	case 2:
		N = inf.readInt(1, 1e5, "N");
		inf.readEoln();
		for (int i = 0; i < N; i++)
		{
			data[i] = inf.readInt(1, 1e9, "S_i");
			if (i < N-1)
				inf.readSpace();
		}
		inf.readEoln();
		inf.readEof();
		break;
	}
}