#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define vll vector<ll>

#define MAXN 112

int N;
int grid[MAXN][MAXN];
int min_used[MAXN][MAXN];
int best = INF;

void dfs(int i, int j, int used)
{
	if (i < 0 || i >= N || j < 0 || j >= N)
		return;
		
	if (grid[i][j] == 1)
		++used;
	
	if (min_used[i][j] <= used)
		return;
	min_used[i][j] = used;
	
	if (i == N - 1 && j == N - 1)
	{
		best = min(best, used);
		return;
	}

	dfs(i - 1, j, used);
	dfs(i + 1, j, used);
	dfs(i, j - 1, used);
	dfs(i, j + 1, used);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &grid[i][j]);
			min_used[i][j] = N*N;
		}
	}
	
	dfs(0, 0, 0);
	printf("%d\n", best);
	
}
