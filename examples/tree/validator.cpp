/*
 * Test Case Validator via tokilib
 * 
 * Problem: Tree
 * Problem author: TOKI Scientific Committee
 * Validator author: TOKI Scientific Committee
 */

#include "../../validator.h"

int N;
int par[100000];

int N_min, N_max;

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

void validateCase()
{
	N = inf.readInt(N_min, N_max, "N");
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
}

int main(int argc, char* argv[])
{
	beginValidator(argc, argv);

	beginSubtask();	{ N_min = 2; N_max = 1e5; }	endSubtask();

	endValidator();
}