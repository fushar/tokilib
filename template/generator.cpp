/*
 * Test Case Generator via testlib
 * 
 * <problem name>
 * <author of this file>
 */

#include "../tokilib.h"

/* <your own template> */

/* <test case generation function definitions> */

int main(int argc, char* argv[])
{
	beginGenerator(argc, argv);

	setSlug("problem");
	setMode("single");
	setSolution("./solution");
	setValidator("./validator");

	/* <test case generation function calls> */

	endGenerator();
}