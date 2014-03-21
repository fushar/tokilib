/*
 * Test Case Validator via testlib
 * 
 * String
 * TOKI Scientific Committee
 */

#include "../../tokilib.h"

int subtask, testCase;

void validate(int len_max)
{
	inf.readToken(format("[a-zA-Z]{1,%d}", len_max), "S");
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
		validate(1e5);
		break;
	}

	endValidator();
}