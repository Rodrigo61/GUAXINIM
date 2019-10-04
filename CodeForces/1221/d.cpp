#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define vll vector<ll>
#define ull unsigned long long
typedef long double ld;

#define MAXN 312345

ll h[MAXN], b[MAXN];
ll dp[MAXN][5];
int t;
int vis[MAXN][5];
int n;

ll solve(int idx, int p_offs)
{
	if (idx == n)
		return 0;

	if (vis[idx][p_offs] == t)
		return dp[idx][p_offs];
	vis[idx][p_offs] = t;
	
	ll res = INF;
	if (idx == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			ll rec = solve(idx + 1, i) + (b[idx] * i);
			res = min(res, rec);
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (h[idx] + i != (h[idx - 1] + p_offs))
			{
				ll rec = solve(idx + 1, i) + (b[idx] * i);
				res = min(res, rec);
			}
		}	
	}

	return dp[idx][p_offs] = res;
}

int main()
{
	int q;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++)
		{
			scanf("%lld%lld", &h[i], &b[i]);
		}

		++t;
		printf("%lld\n", solve(0, 0));		
	}
}
