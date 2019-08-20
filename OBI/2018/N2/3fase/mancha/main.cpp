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
	int N;
	scanf("%d\n", &N);
	char grid[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%c", &grid[i][j]);
		}
		scanf("\n");
	}
	
	for (int i = 0; i < N; i++)
	{
		int starts = 0;
		char last = 0;
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == '*' && last != '*')
			{
				++starts;
			}
			last = grid[i][j];
		}
		if (starts > 1)
			return !printf("N\n");
	}
	
	for (int j = 0; j < N; j++)
	{
		int starts = 0;
		char last = 0;
		for (int i = 0; i < N; i++)
		{
			if (grid[i][j] == '*' && last != '*')
			{
				++starts;
			}
			last = grid[i][j];
		}
		if (starts > 1)
			return !printf("N\n");
	}
	
	printf("S\n");
}
