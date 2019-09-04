#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

#define MAXN 512

int N, C;
pair<pii, int> apps[MAXN];
ll dp[MAXN][MAXN];
int dpr[MAXN][MAXN];
int vis[MAXN][MAXN];

ll solve(int idx, int used)
{
	if (idx == N)
		return used == 0 ? 0:INF;
		
	if (vis[idx][used])
	{
		return dp[idx][used];
	}
	vis[idx][used] = 1;
	
	
	if (used < N)
		solve(idx, used + 1);
	
	ll res = solve(idx + 1, used);
	ll rec = solve(idx + 1, used - 1);
	if (C - rec >= apps[idx].fi.fi && rec + apps[idx].fi.se < res)
	{
		res = rec + apps[idx].fi.se;
		dpr[idx][used] = 1;
	}
	
	return dp[idx][used] = res;
}

int main()
{
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++)
	{
		int d, s;
		scanf("%d%d", &d, &s);
		apps[i].fi.fi = max(d, s);
		apps[i].fi.se = s;
		apps[i].se = i + 1;
	}
	sort(apps, apps + N, [] (pair<pii, int> &i, pair<pii, int> &j)
	{
		return i.fi.fi - i.fi.se < j.fi.fi - j.fi.se;
	});
	
	solve(0, 0);
	for (int i = N; i >= 0; i--)
	{
		if (dp[0][i] <= C)
		{
			printf("%d\n", i);
			int idx = 0;
			int used = i;
			vi res;
			while (idx < N)
			{
				if (dpr[idx][used])
				{
					res.pb(apps[idx].se);
					used--;
				}
				++idx;
			}
			
			reverse(all(res));
			for (int r : res)
				printf("%d ", r);
			printf("\n");
			
			break;
		}
	}
	
}
