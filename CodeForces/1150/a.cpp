#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int N, M, R;

int main()
{
	scanf("%d%d%d", &N, &M, &R);
	
	int mini = INF;
	int v;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v);
		mini = min(mini, v);
	}
	
	int maxi = 0;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &v);
		maxi = max(maxi, v);
	}
	
	if (mini < maxi)
	{
		int sell = maxi*(R/mini);
		int rem = R - mini*(R/mini);
		printf("%d\n", rem + sell);
	}
	else
	{
		printf("%d\n", R);
	}
	
	
	
	
}
