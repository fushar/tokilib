/*
 * Test Case Validator via tokilib
 * 
 * Problem: String
 * Problem author: TOKI Scientific Committee
 * Validator author: TOKI Scientific Committee
 */

#include "../../validator.h"

int N_max;

void validateCase()
{
	inf.readToken(format("[a-zA-Z]{1,%d}", N_max), "S");
	inf.readEoln();
	inf.readEof();
}

int main(int argc, char* argv[])
{
	beginValidator(argc, argv);

	beginSubtask();	{ N_max = 1e3;	}	endSubtask();
	beginSubtask();	{ N_max = 1e5;	}	endSubtask();

	endValidator();
}