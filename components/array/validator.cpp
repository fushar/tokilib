/*
 * Test Case Validator via testlib
 * 
 * Array
 * TOKI Scientific Committee
 */

#include "../../tokilib.h"

int subtask, testCase;

void validate(int N_max, int elem_max)
{
	int N = inf.readInt(1, N_max, "N");
	inf.readEoln();
	for (int i = 0; i < N; i++)
	{
		inf.readInt(1, elem_max, format("ar[%d]", i));
		if (i + 1 < N)
			inf.readSpace();
	}
	inf.readEoln();
	inf.readEof();
}

int main(int argc, char* argv[])
{
	beginValidator(argc, argv, &subtask, &testCase);

	switch (subtask)
	{
	case 0:
	case 1:
		validate(1e3, 1e3);
		break;
	case 2:
		validate(1e5, 1e9);
		break;
	}

	endValidator();
}