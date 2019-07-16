#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, M;
		scanf("%d%d\n", &N, &M);
		int grid[N][M];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				char c;
				scanf("%c", &c);
				if (c == '*')
				{
					grid[i][j] = 1;
				}
				else
				{
					grid[i][j] = 0;
				}
			}
			scanf("\n");
		}
		
		vi rowSum(N), colSum(M);
		
		for (int i = 0; i < N; i++)
		{
			int sum = 0;
			for (int j = 0; j < M; j++)
			{
				sum += grid[i][j];
			}
			rowSum[i] = sum;
		}
		
		for (int j = 0; j < M; j++)
		{
			int sum = 0;
			for (int i = 0; i < N; i++)
			{
				sum += grid[i][j];
			}
			colSum[j] = sum;
		}
		
		int res = INF;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int aux = N - rowSum[i] + M - colSum[j];
				if (grid[i][j] == 0)
				{
					aux--;
				}
				
				res = min(res, aux);
			}
		}
		
		printf("%d\n", res);
	}
	
}
