/*
 * TOKI Scientific Committee
 * 
 * Adapter and additional functions for testlib.
 *
 */


#include "testlib.h"

#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

static int validator_subtask = 0;
static int case_subtask;

void validateCase();

void beginValidator(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Validator incorrectly called." << std::endl;
		exit(1);
	}

	registerValidation();

	std::stringstream ss;
	ss << argv[1];
	ss >> case_subtask;
}

void endValidator()
{
	// empty
}

void beginSubtask()
{
	validator_subtask++;
}

void endSubtask()
{
	if (validator_subtask == case_subtask)
		validateCase();
}