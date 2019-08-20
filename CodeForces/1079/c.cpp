#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
#define MAXN 112345
 
int N;
int vals[MAXN];
int vis[MAXN][10];
bool dp[MAXN][10];
int dpr[MAXN][10];

bool solve(int idx, int last_used)
{
	if (idx == N)
	{
		return true;
	}
	
	//dp
	if (vis[idx][last_used])
	{
		return dp[idx][last_used];
	}
	vis[idx][last_used] = 1;

	
	bool res = false;

	if (idx == 0)
	{
		for (int i = 1; i <= 5; i++)
		{
			if (solve(1, i))
			{
				res = true;
				dpr[idx][last_used] = i;
			}
		}
		
	}
	else
	{
		if (vals[idx] > vals[idx - 1])
		{
			for (int i = last_used + 1; i <= 5; i++)
			{
				if (solve(idx + 1, i))
				{
					res = true;
					dpr[idx][last_used] = i;
				}
			}
		}
		else if (vals[idx] < vals[idx - 1])
		{
			for (int i = last_used - 1; i >= 1; i--)
			{
				if (solve(idx + 1, i))
				{
					res = true;
					dpr[idx][last_used] = i;
				}
			}
		}
		else
		{
			for (int i = 1; i <= 5; i++)
			{
				if (i != last_used)
				{
					if (solve(idx + 1, i))
					{
						res = true;
						dpr[idx][last_used] = i;
					}
				}
			}
		}
	}
	
	dp[idx][last_used] = res;
	return res;
}
 
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	if (solve(0, 0))
	{
		int idx = 0;
		int last_used = 0;
		while (idx < N)
		{
			printf("%d ", dpr[idx][last_used]);
			last_used = dpr[idx][last_used];
			idx++;
		}
	}
	else
	{
		printf("-1\n");
	}
	
	
	
}
