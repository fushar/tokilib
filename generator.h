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
using namespace std;

#ifdef ON_WINDOWS
	#define SEP "\\"
	#define MKDIR "md"
	#define RMFILE "del"
	#define RMDIR "rd /s /q"
	#define CAT "type"
	#define POPEN _popen
	#define PCLOSE _pclose
	#define CHECK_PIPE_STATUS
	#define RUN_PROGRAM ""
	#define OK "OK"
	#define FAILED "FAILED"
#else
 	#define SEP "/"
 	#define MKDIR "mkdir"
 	#define RMFILE "rm"
 	#define RMDIR "rm -rf"
 	#define CAT "cat"
 	#define POPEN popen
 	#define PCLOSE pclose
 	#define CHECK_PIPE_STATUS >> 8
 	#define RUN_PROGRAM "./"
	#define OK "\x1b[32;1mOK\x1b[0m"
	#define FAILED "\x1b[31;1mFAILED\x1b[0m"
#endif

static string mode = "single";
static string slug = "problem";
static string solution = "";
static string validator = "";
static int cur_batch = 0;
static int cur_case;
static vector<int> cur_subtasks;
static bool has_errors;

void printCase();
void printSampleCase(int);

void beginGenerator(int argc, char* argv[])
{
	registerGen(argc, argv, 1);
	system(format("%s tc", RMDIR).c_str());
	system(format("%s tc", MKDIR).c_str());
	has_errors = false;

	cerr << "Case\tSolution\tValidation" << endl;
	cerr << "----\t--------\t----------" << endl;
}

void endGenerator()
{
	cerr << endl;
	if (solution == "" && validator == "")
		cerr << "Please specify solution and/or validator." << endl;
	else if (has_errors)
		cerr << "Some cases [" << FAILED << "] :(" << endl;
	else
		cerr << "All cases [" << OK << "] :)" << endl;
	cerr << endl;
}

void setMode(string mode)
{
	::mode = mode;
}

void setSlug(string slug)
{
	::slug = slug;
}

void setSolution(string solution)
{
	::solution = solution;
}

void setValidator(string validator)
{
	::validator = validator;
}

void beginSampleBatch()
{
	cerr << endl;
	cur_batch = 0;
	cur_case = 0;
	cur_subtasks.clear();
}

void beginBatch()
{
	cerr << endl;
	cur_batch++;
	cur_case = 0;
	cur_subtasks.clear();
}

void endBatch()
{
	if (mode == "single")
		return;

	string command;

	command = format("echo %d > tc%s%s_%d.in", cur_case, SEP, slug.c_str(), cur_batch);
	system(command.c_str());
	
	for (int tc = 1; tc <= cur_case; tc++)
	{
		command = format("%s tc%s%s_%d_%d.in >> tc%s%s_%d.in",
						CAT, SEP,
						slug.c_str(), cur_batch, tc,
						SEP, slug.c_str(), cur_batch);
		system(command.c_str());
		command = format("%s tc%s%s_%d_%d.out >> tc%s%s_%d.out",
						CAT, SEP,
						slug.c_str(), cur_batch, tc,
						SEP, slug.c_str(), cur_batch);
		system(command.c_str());
		command = format("%s tc%s%s_%d_%d.in tc%s%s_%d_%d.out",
						RMFILE, SEP,
						slug.c_str(), cur_batch, tc,
						SEP, slug.c_str(), cur_batch, tc);
		system(command.c_str());
	}
}

void setSubtasks(string subtasks)
{
	replace(subtasks.begin(), subtasks.end(), ',', ' ');
	istringstream sin(subtasks);
	int subtask;
	while (sin >> subtask)
		cur_subtasks.push_back(subtask);
}

void beginCase()
{
	cur_case++;
	
	cerr << cur_batch << "/" << cur_case << "\t" << flush;
	string filename = format("tc%s%s_%d_%d.in", SEP, slug.c_str(), cur_batch, cur_case);

	freopen(filename.c_str(), "w", stdout);
}

void endCase()
{
	if (cur_batch == 0)
		printSampleCase(cur_case);
	else
		printCase();

	cout << flush;

	if (solution != "")
	{
		string command = format("%s%s < tc%s%s_%d_%d.in > tc%s%s_%d_%d.out 2>&1",
									 RUN_PROGRAM, solution.c_str(),
									 SEP, slug.c_str(), cur_batch, cur_case,
									 SEP, slug.c_str(), cur_batch, cur_case);
		
		FILE* proc = POPEN(command.c_str(), "r");

		if (PCLOSE(proc) CHECK_PIPE_STATUS)
		{
			cerr << "[" << FAILED << "]\t" << flush;
			has_errors = true;
		}
		else
			cerr << "  [" << OK << "]  \t" << flush;
	}
	else
		cerr << " [N/A]  \t" << flush;

	if (validator != "")
	{
		bool failed = false;
		for (int i = 0; i < cur_subtasks.size(); i++)
		{
			int cur_subtask = cur_subtasks[i];

			string command = format("%s%s %d < tc%s%s_%d_%d.in 2>&1",
										 RUN_PROGRAM, validator.c_str(), cur_subtask,
										 SEP, slug.c_str(), cur_batch, cur_case);

			FILE* proc = POPEN(command.c_str(), "r");

			char buf[1024];
			bool any = false;

			vector<string> errors;

			while (fgets(buf, sizeof buf, proc))
				errors.push_back(buf);

			if (PCLOSE(proc) CHECK_PIPE_STATUS)
			{
				cerr << "[" << FAILED << " subtask " << cur_subtask << "]" << endl;
				for (int j = 0; j < errors.size(); j++)
					cerr << errors[i];
				failed = true;
				break;
			}
		}

		if (failed)
			has_errors = true;
		else
			cerr << "  [" << OK << "]" << endl;
	}
	else
		cerr << " [N/A]" << endl;
}

template<class T>
void set_array(T a[], int& n, string elements)
{
	replace(elements.begin(), elements.end(), ',', ' ');
	istringstream sin(elements);
	T e;
	n = 0;
	while (sin >> e)
		a[n++] = e;
}