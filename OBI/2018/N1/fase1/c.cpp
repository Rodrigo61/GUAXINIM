// piramide
#include <bits/stdc++.h>

using namespace std;

#define MAXN 112

int N;
int grid[MAXN][MAXN];
int vis[MAXN][MAXN];
int dp[MAXN][MAXN];

int solve(int pos, int level)
{
	if (level == 0)
	{
		return grid[level][pos];
	}
	
	if (vis[pos][level])
	{
		return dp[pos][level];
	}
	vis[pos][level] = 1;
	
	int sum = 0;
	for (int i = pos; i <= pos + level; i++)
	{
		sum += grid[level][i];
	}
	
	dp[pos][level] = min(solve(pos, level - 1), solve(pos + 1, level - 1)) + sum;
	
	return dp[pos][level];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}
	
	printf("%d\n", solve(0, N - 1));
}
