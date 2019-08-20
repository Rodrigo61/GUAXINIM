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

#define MAXN 112345

int N;
ll u[MAXN];
ll d[MAXN];
int vis[MAXN][3];
ll dp[MAXN][3];

ll solve(int idx, int last)
{
	if (idx == N)
	{
		return 0;
	}
	
	//DP
	if (vis[idx][last])
	{
		return dp[idx][last];
	}
	vis[idx][last] = 1;
	
	
	ll res = solve(idx + 1, 2);
	if (last != 0)
	{
		res = max(res, solve(idx + 1, 0) + u[idx]);
	}
	if (last != 1)
	{
		res = max(res, solve(idx + 1, 1) + d[idx]);
	}
	
	return dp[idx][last] = res;
}
 
 
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &u[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &d[i]);
	}
	printf("%lld\n", solve(0, -1));
	
}
