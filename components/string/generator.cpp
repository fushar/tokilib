/*
 * Test Case Generator via testlib
 * 
 * String
 * TOKI Scientific Committee
 */

#include "../../tokilib.h"

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void print(string s)
{
	cout << s << endl;
}

string randomString(int len)
{
	return rnd.next(format("[a-zA-Z]{%d}", len));
}

string equalCharString(int len)
{
	char c = rnd.next("[a-zA-Z]")[0];
	return rnd.next(format("[%c]{%d}", c, len));
}

void printSample1()
{
	cout << "TOKI" << endl;
}

void printSample2()
{
	cout << "ScientificCommittee" << endl;
}

void subtask0()
{
	beginSampleSubtask();

	beginTestCase();	printSample1();						endTestCase();
	beginTestCase();	printSample1();						endTestCase();

	endSubtask();
}

void subtask1()
{
	beginSubtask();

	// Tricky cases
	beginTestCase();	print("aAbBcC");					endTestCase();
	beginTestCase();	print("ZZZZa");						endTestCase();

	// Random cases
	beginTestCase();	print(randomString(1));				endTestCase();
	beginTestCase();	print(randomString(10));			endTestCase();
	beginTestCase();	print(randomString(100));			endTestCase();
	beginTestCase();	print(randomString(1e3));			endTestCase();
	beginTestCase();	print(randomString(1e3));			endTestCase();

	// Equal character cases
	beginTestCase();	print(equalCharString(1));			endTestCase();
	beginTestCase();	print(equalCharString(10));			endTestCase();
	beginTestCase();	print(equalCharString(100));		endTestCase();
	beginTestCase();	print(equalCharString(1e3));		endTestCase();
	beginTestCase();	print(equalCharString(1e3));		endTestCase();

	endSubtask();
}

void subtask2()
{
	beginSubtask();

	// Random cases
	beginTestCase();	print(randomString(1001));			endTestCase();
	beginTestCase();	print(randomString(1e4));			endTestCase();
	beginTestCase();	print(randomString(1e4));			endTestCase();
	beginTestCase();	print(randomString(1e5));			endTestCase();
	beginTestCase();	print(randomString(1e5));			endTestCase();

	// Equal character cases
	beginTestCase();	print(equalCharString(1001));		endTestCase();
	beginTestCase();	print(equalCharString(1e4));		endTestCase();
	beginTestCase();	print(equalCharString(1e4));		endTestCase();
	beginTestCase();	print(equalCharString(1e5));		endTestCase();
	beginTestCase();	print(equalCharString(1e5));		endTestCase();

	endSubtask();
}

int main(int argc, char* argv[])
{
	beginGenerator(argc, argv);

	setSlug("string"); 
	setMode("single");
	setSolution("./solution");
	setValidator("./validator");

	subtask0();
	subtask1();
	subtask2();

	endGenerator();
}