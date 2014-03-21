/*
 * Test Case Validator via testlib
 * 
 * Pair
 * TOKI Scientific Committee
 */

#include "../../tokilib.h"

int subtask, testCase;

void validate(int AB_max)
{
	inf.readInt(1, AB_max, "A");
	inf.readSpace();
	inf.readInt(1, AB_max, "B");
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
		validate(1e3);
		break;
	case 2:
		validate(1e9);
		break;
	}

	endValidator();
}