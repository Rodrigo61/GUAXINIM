#include <bits/stdc++.h>

using namespace std;

#define MAXN 112345

int vals[MAXN];
int bigger_left[MAXN], bigger_right[MAXN];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	int big = 0;
	for (int i = 0; i < N; i++)
	{
		bigger_left[i] = max(big, vals[i]);
		big = bigger_left[i];
	}
	
	big = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		bigger_right[i] = max(big, vals[i]);
		big = bigger_right[i];
	}
	
	
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		if (bigger_left[i] > vals[i] && bigger_right[i] > vals[i])
		{
			++total;
		}
	}
	
	printf("%d\n", total);
	
	

}
