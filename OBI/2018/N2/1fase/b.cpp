#include <bits/stdc++.h>

using namespace std;
#define MAXN 10004

int freq[MAXN];

int main()
{
	int N, C, M;
	scanf("%d%d%d", &N, &C, &M);
	
	for (int i = 0; i < C; i++)
	{
		int v;
		scanf("%d", &v);
		freq[v]++;
	}
	
	for (int i = 0; i < M; i++)
	{
		int v;
		scanf("%d", &v);
		freq[v] = max(0, freq[v] - 1);
	}
	
	int total = 0;
	for (int i = 0; i < MAXN; i++)
	{
		total += freq[i];
	}
	
	printf("%d\n", total);
	
}
