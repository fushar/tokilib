/*
 * Test Case Validator via tokilib
 * 
 * Problem: Array
 * Problem author: TOKI Scientific Committee
 * Validator author: TOKI Scientific Committee
 */

#include "../../validator.h"

int N_max, data_max;

void validateCase()
{
	int N = inf.readInt(1, N_max, "N");
	inf.readEoln();
	for (int i = 0; i < N; i++)
	{
		inf.readInt(1, data_max, format("data[%d]", i));
		if (i + 1 < N)
			inf.readSpace();
	}
	inf.readEoln();
	inf.readEof();
}

int main(int argc, char* argv[])
{
	beginValidator(argc, argv);

	beginSubtask();	{ N_max = 1e3; data_max = 1e3;	}	endSubtask();
	beginSubtask();	{ N_max = 1e5; data_max = 1e9;	}	endSubtask();

	endValidator();
}