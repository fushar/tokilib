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
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

static std::string mode = "single";
static std::string slug = "problem";
static std::string solution = "";
static std::string validator = "";
static int cur_subtask = 0;
static int cur_test_case;
static bool has_errors;

void setMode(std::string mode)
{
	::mode = mode;
}

void setSlug(std::string slug)
{
	::slug = slug;
}

void setSolution(std::string solution)
{
	::solution = solution;
}

void setValidator(std::string validator)
{
	::validator = validator;
}

void beginSampleSubtask()
{
	std::cerr << std::endl;
	cur_subtask = 0;
	cur_test_case = 0;
}

void beginSubtask()
{
	std::cerr << std::endl;
	cur_subtask++;
	cur_test_case = 0;
}

void endSubtask()
{
	if (mode == "single")
		return;

	std::string command;

	command = format("echo %d > tc/%s_%d.in", cur_test_case, slug.c_str(), cur_subtask);
	system(command.c_str());
	
	for (int tc = 1; tc <= cur_test_case; tc++)
	{
		command = format("cat tc/%s_%d_%d.in >> tc/%s_%d.in",
						 slug.c_str(), cur_subtask, tc,
						 slug.c_str(), cur_subtask);
		system(command.c_str());
		command = format("cat tc/%s_%d_%d.out >> tc/%s_%d.out",
						 slug.c_str(), cur_subtask, tc,
						 slug.c_str(), cur_subtask);
		system(command.c_str());
		command = format("rm tc/%s_%d_%d.in tc/%s_%d_%d.out",
						 slug.c_str(), cur_subtask, tc,
						 slug.c_str(), cur_subtask, tc);
		system(command.c_str());
	}
}

void beginTestCase()
{
	cur_test_case++;
	
	std::cerr << "Generating test case " << cur_subtask << "/" << cur_test_case << " ...\t" << std::flush;
	std::string filename = format("tc/%s_%d_%d.in", slug.c_str(), cur_subtask, cur_test_case);

	freopen(filename.c_str(), "w", stdout);
}

void endTestCase()
{
	if (validator != "")
	{

		std::string command = format("%s %d %d < tc/%s_%d_%d.in 2>&1",
									 validator.c_str(), cur_subtask, cur_test_case,
									 slug.c_str(), cur_subtask, cur_test_case);

		FILE* proc = popen(command.c_str(), "r");

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
		{
			std::cerr << "\t\t\t\t[validation \x1b[31;1mFAILED\x1b[0m]\t" << std::flush;
			has_errors = true;
		}
		else
			std::cerr << "[validation \x1b[32;1mOK\x1b[0m]\t\t" << std::flush;
	}
	
	if (solution != "")
	{
		std::string command = format("%s < tc/%s_%d_%d.in > tc/%s_%d_%d.out 2>&1",
									 solution.c_str(),
									 slug.c_str(), cur_subtask, cur_test_case,
									 slug.c_str(), cur_subtask, cur_test_case);
		
		FILE* proc = popen(command.c_str(), "r");

		if (pclose(proc) >> 8)
		{
			std::cerr << "\t[output \x1b[31;1mFAILED\x1b[0m]" << std::flush;
			has_errors = true;
		}
		else
			std::cerr << " [output \x1b[32;1mOK\x1b[0m]" << std::flush;
	}
	
	std::cerr << std::endl;
}

void beginGenerator(int argc, char* argv[])
{
	registerGen(argc, argv, 1);
	system("rm -rf tc");
	system("mkdir -p tc");
	has_errors = false;
}

void endGenerator()
{
	std::cerr << std::endl;
	if (has_errors)
		std::cerr << "Some test cases failed!" << std::endl;
	else
		std::cerr << "All test cases OK!" << std::endl;
	std::cerr << std::endl;
}

void beginValidator(int argc, char* argv[], int* subtask, int* testCase)
{
	if (argc != 3)
	{
		std::cerr << "Validator incorrectly called." << std::endl;
		exit(1);
	}

	registerValidation();

	std::stringstream ss;
	ss << argv[1] << " " << argv[2];
	ss >> *subtask >> *testCase;
}

void endValidator()
{
	// TODO
}

std::vector<int> make_array(int n, ...)
{
	std::vector<int> ar;
	va_list vl;
	va_start(vl, n);
	for (int i = 0; i < n; i++)
		ar.push_back(va_arg(vl, int));
	va_end(vl);
	return ar;
}

#endif