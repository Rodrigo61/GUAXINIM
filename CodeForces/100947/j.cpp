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
#define pii pair<int, int>
#define piii pair<int, pii>

#define MAXN 2123

int N, P, Q;
int positions[MAXN];
int w;
int t;
int d[MAXN][MAXN];
int vis[MAXN][MAXN];

int dp(int idx, int p)
{
	if (vis[idx][p] == t)
	{
		return d[idx][p];
	}
	vis[idx][p] = t;
	
	//dp
	int res = INF;
	
	// small 
	if (p)
	{
		int target = positions[idx] + (w - 1);
		int it2 = upper_bound(positions + idx, positions + N, target) - positions;	
		if (it2 < N)
			res = min(res, dp(it2, p - 1));
		else
			return d[idx][p] = 0;
	}
	
	// large
	int target = positions[idx] + (2 * w) - 1;
	int it2 = upper_bound(positions + idx, positions + N, target) - positions;	
	if (it2 < N)
		res = min(res, dp(it2, p) + 1);
	else
		return d[idx][p] = 1;
	
	return d[idx][p] = res;
}

int solve()
{
	ll up = 1000000000;
	ll lo = 1;
	ll best;
	
	while (lo <= up)
	{
		++t;
		ll mid = lo + (up - lo) /2;
		w = mid;
		int aux = dp(0, P);
		if (aux <= Q)
		{
			best = mid;
			up = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	
	return best;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &N, &P, &Q);
		P = min(P, N);
		Q = min(Q, N);
		
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &positions[i]);
		}
		sort(positions, positions + N);
		
		printf("%d\n", solve());
		
	}
	
}
