/*
 * Test Case Validator via testlib
 * 
 * Tree
 * TOKI Scientific Committee
 */

#include "../tokilib.h"

int subtask, testCase;

int N;
int par[100000];

int find_set(int x)
{
	if (x != par[x])
		par[x] = find_set(par[x]);
	return par[x];
}

void merge_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	par[a] = b;
}

int main(int argc, char* argv[])
{
	registerValidation();
	extractValidationInfo(argc, argv, subtask, testCase);

	switch (subtask)
	{
	case 0:
	case 1:
		N = inf.readInt(2, 1e5, "N");
		inf.readEoln();

		for (int i = 0; i < N; i++)
			par[i] = i;

		for (int i = 0; i < N-1; i++)
		{
			int u = inf.readInt(0, N-1, "u");
			inf.readSpace();
			int v = inf.readInt(0, N-1, "v");
			inf.readEoln();

			int par_u = find_set(u);
			int par_v = find_set(v);
			ensuref(par_u != par_v, "Tree must not contain loop");
			merge_set(u, v);
		}
		inf.readEof();
		break;
	}
}