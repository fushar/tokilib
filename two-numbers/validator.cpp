/*
 * Test Case Validator via testlib
 * 
 * Two Numbers
 * TOKI Scientific Committee
 */

#include "../tokilib.h"

typedef long long ll;

int subtask, testCase;

int main(int argc, char* argv[])
{
	registerValidation();
	extractValidationInfo(argc, argv, subtask, testCase);

	switch (subtask)
	{
	case 0:
	case 1:
		inf.readInt(1, (int)1e9, "A");
		inf.readSpace();
		inf.readInt(1, (int)1e9, "B");
		inf.readEoln();
		inf.readEof();
		break;
	case 2:
		inf.readLong(1ll, (ll)1e12, "A");
		inf.readSpace();
		inf.readLong(1ll, (ll)1e12, "B");
		inf.readEoln();
		inf.readEof();
		break;
	}
}