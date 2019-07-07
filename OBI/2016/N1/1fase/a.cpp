#include <bits/stdc++.h>

using namespace std;
#define db(x) cerr << #x << " = " << x << endl;

int main()
{
	int N, A, B, C, D, E, F, G;
	scanf("%d%d%d%d%d%d%d%d", &N, &A, &B, &C, &D, &E, &F, &G);
	bool found = false;
	
	if (A < D + E)
	{
		found = true;
	}
	
	if (B < D + F)
	{
		found = true;
	}
	
	if (C < E + F)
	{
		found = true;
	}
	
	int sa = A - (D + E);
	int sb = B - (D + F);
	int sc = C - (E + F);
	if (E+D+F+G+sa+sb+sc != N)
	{
		found = true;
	}
	
	
	if (found)
	{
		printf("S\n");
	}
	else
	{
		printf("N\n");
	}
	
	
}
