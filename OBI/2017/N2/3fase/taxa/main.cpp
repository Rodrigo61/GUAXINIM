#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 412

int N;
double F;
ll vals[MAXN];
ll prefix[MAXN];
int vis[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll sum(int l, int r)
{
	if (l > r) return 0;
	if (l == 0) return prefix[r];
	return prefix[r] - prefix[l - 1];
}

ll solve(int b, int e)
{
	if (b >= e)
		return 0;
		
	if (vis[b][e])
	{
		return dp[b][e];
	}
	vis[b][e] = 1;
	
	ll res = INF;
	for (int i = b; i < e; i++)
	{
		res = min(res, solve(b, i) + solve(i + 1, e) + max(sum(b, i), sum(i + 1, e)));
	}
	
	return dp[b][e] = res;
}

int main()
{
	scanf("%d%lf", &N, &F);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
		vals[i + N] = vals[i];
	}
	
	if (N == 1)
		return !printf("0.00\n");
		
	ll acu = 0;
	for (int i = 0; i < 2*N; i++)
	{
		acu += vals[i];
		prefix[i] = acu;
	}
	
	ll res = INF;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			int i2 = j + 1;
			int j2 = i2 + (N - (j - i) - 2);
			ll curr = max(sum(i, j), sum(i2, j2));
			curr += solve(i, j) + solve(i2, j2);
			res = min(res, curr);
		}
	}
	
	printf("%.2lf\n", (double)res * F);
}
