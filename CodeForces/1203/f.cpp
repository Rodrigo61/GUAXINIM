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

#define MAXN 112
int SZ;
int vis[MAXN][MAXN];
int dp[MAXN][MAXN];
int N, R;
vii pos, neg;



int solve(int idx, int need_use)
{
	if (need_use == 0)
		return 0;
	if (idx == SZ)
		return INF;
		
	if (vis[idx][need_use])
	{
		return dp[idx][need_use];
	}
	vis[idx][need_use] = 1;
	
	solve(idx, need_use - 1);
	int res = solve(idx + 1, need_use);
	int rec = solve(idx + 1, need_use - 1);
	if (R - rec >= neg[idx].fi)
	{
		res = min(res, rec + neg[idx].se);
	}
	
	return dp[idx][need_use] = res;
}

int main()
{
	scanf("%d%d", &N , &R);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (b >= 0)
		{
			pos.pb({a, b});
		}
		else
		{
			neg.pb({a, -b});
		}
	}
	sort(all(pos));
	int offset = 0;
	for (pii p : pos)
	{
		if (p.fi <= R)
		{
			R += p.se;
			offset++;
		}
		else
		{
			break;
		}
	}
	
	for (auto &p : neg)
		p.fi = max(p.fi, p.se);
		
	sort(all(neg), [](pii &a, pii &b){
		return a.fi - a.se < b.fi - b.se;
	});
	
	SZ = neg.size();
	//~ db(offset);
	solve(0, SZ);
	for (int i = SZ; i >= 0; i--)
	{
		if (dp[0][i] < INF)
		{
			return !printf("%d\n", i + offset);
		}
	}
	
}
