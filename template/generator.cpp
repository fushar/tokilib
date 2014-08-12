/*
 * Test Case Generator via tokilib
 * 
 * Problem: XXX
 * Problem author: XXX
 * Generator author: XXX
 */

#include "../generator.h"

#include <iostream>
using namespace std;

void printSampleCase(int tc)
{

}

void printCase()
{

}

void batch0()
{
	beginSampleBatch();

	endBatch();
}

int main(int argc, char* argv[])
{
	beginGenerator(argc, argv);

	setSlug("problem"); 
	setMode("single");
	setSolution("solution");
	setValidator("validator");

	batch0();

	endGenerator();
}