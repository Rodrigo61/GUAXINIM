#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

int limit[6];
ll vals[] = {2, 5, 10, 20, 50, 100};
int vis[5123][10];
ll dp[5123][10];

ll solve(int r, int idx)
{
	if (idx == 6)
	{
		return r == 0;
	}
	
	if (r < 0)
	{
		return 0;
	}
	
	if (vis[r][idx])
	{
		return dp[r][idx];
	}
	vis[r][idx] = 1;
	
	
	int res = 0;
	for (int i = 0; i <= limit[idx]; i++)
	{
		res += solve(r - (i * vals[idx]), idx + 1);
	}
	
	return dp[r][idx] = res;
}
 
int main()
{
	int S;
	scanf("%d%d%d%d%d%d%d", &S, &limit[0], &limit[1], &limit[2], &limit[3], &limit[4], &limit[5]);
	printf("%lld\n", solve(S, 0));
}
