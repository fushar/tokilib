/*
 * Test Case Validator via tokilib
 * 
 * Problem: Pair
 * Problem author: TOKI Scientific Committee
 * Validator author: TOKI Scientific Committee
 */

#include "../../validator.h"

int AB_max;

void validateCase()
{
	inf.readInt(1, AB_max, "A");
	inf.readSpace();
	inf.readInt(1, AB_max, "B");
	inf.readEoln();
	inf.readEof();
}

int main(int argc, char* argv[])
{
	beginValidator(argc, argv);

	beginSubtask();	{ AB_max = 1e3;	}	endSubtask();
	beginSubtask();	{ AB_max = 1e9;	}	endSubtask();

	endValidator();
}