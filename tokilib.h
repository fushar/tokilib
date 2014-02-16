/*
 * TOKI Scientific Committee
 * 
 * Adapter and additional functions for testlib.
 *
 */

#ifndef _TOKILIB_H_
#define _TOKILIB_H_

#include "testlib.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

static std::string __tokilib_problemCode = "problem";
static std::string __tokilib_testCaseDir = "tc";
static std::string __tokilib_solution = "";
static std::string __tokilib_validator = "";
static int __tokilib_currentSubtask;
static int __tokilib_currentTestCase;

void setTestCaseDir(std::string dir)
{
	__tokilib_testCaseDir = dir;

	std::ostringstream sout;
	sout << "rm -rf " << dir << " && " << "mkdir -p " << dir;

	system(sout.str().c_str());
}

void setProblemCode(std::string code)
{
	__tokilib_problemCode = code;
}

void setSolution(std::string exe)
{
	__tokilib_solution = exe;
}

void setValidator(std::string exe)
{
	__tokilib_validator = exe;
}

void beginCase(int subtask, int testCase)
{
	__tokilib_currentSubtask = subtask;
	__tokilib_currentTestCase = testCase;

	std::ostringstream sout;
	sout << __tokilib_testCaseDir << "/" << __tokilib_problemCode << "_" << subtask << "_" << testCase << ".in";
	std::cerr << "Generating test case " << subtask << "/" << testCase << " ...\t" << std::flush;

	freopen(sout.str().c_str(), "w", stdout);
}

void endCase()
{
	if (__tokilib_validator != "")
	{
		std::ostringstream sout;
		sout << __tokilib_validator << " " << __tokilib_currentSubtask << " " << __tokilib_currentTestCase << " < ";
		sout << __tokilib_testCaseDir << "/" << __tokilib_problemCode << "_" << __tokilib_currentSubtask << "_" << __tokilib_currentTestCase << ".in";
		sout << " 2>&1";
		FILE* proc = popen(sout.str().c_str(), "r");

		char buf[1024];
		bool any = false;
		while (fgets(buf, sizeof buf, proc))
		{
			if (!any)
				std::cerr << std::endl;
			any = true;
			std::cerr << "\t" << std::string(buf) << std::flush;
		}

		if (pclose(proc) >> 8)
			std::cerr << "\t\t\t\t[validation \x1b[31;1mFAILED\x1b[0m]\t" << std::flush;
		else
			std::cerr << "[validation \x1b[32;1mOK\x1b[0m]\t\t" << std::flush;
	}
	
	if (__tokilib_solution != "")
	{
		std::ostringstream sout;
		sout << __tokilib_solution << " < ";
		sout << __tokilib_testCaseDir << "/" << __tokilib_problemCode << "_" << __tokilib_currentSubtask << "_" << __tokilib_currentTestCase << ".in > ";
		sout << __tokilib_testCaseDir << "/" << __tokilib_problemCode << "_" << __tokilib_currentSubtask << "_" << __tokilib_currentTestCase << ".out";
		sout << " 2>&1";
		FILE* proc = popen(sout.str().c_str(), "r");

		if (pclose(proc) >> 8)
			std::cerr << "\t[output \x1b[31;1mFAILED\x1b[0m]" << std::flush;
		else
			std::cerr << " [output \x1b[32;1mOK\x1b[0m]" << std::flush;
	}
	
	std::cerr << std::endl;
}

void extractValidationInfo(int argc, char* argv[], int& subtask, int& testCase)
{
	if (argc != 3)
	{
		std::cerr << "Validator incorrectly called." << std::endl;
		exit(1);
	}

	std::stringstream ss;
	ss << argv[1];
	ss >> subtask;
	ss << argv[2];
	ss >> testCase;
}

#endif