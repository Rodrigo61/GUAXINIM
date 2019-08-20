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

#define MAXN 112345

int N;
ll cost[MAXN];
vector<string> vet_s;
int gte[MAXN][2][2];
ll dp[MAXN][2];
int vis[MAXN][2];

ll solve(int idx, int last)
{
	if (idx == N)
	{
		return 0;
	}
	
	if (vis[idx][last])
	{
		return dp[idx][last];
	}
	vis[idx][last] = 1;
	
	
	ll res = INF;
	if (gte[idx][0][last])
	{
		res = min(res, solve(idx + 1, 0));
	}
	if (gte[idx][1][last])
	{
		res = min(res, solve(idx + 1, 1) + cost[idx]);
	}
	
	return dp[idx][last] = res;
	
}
 
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cost[i];
	}
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		vet_s.pb(s);
	}
	
	for (int i = 1; i < N; i++)
	{
		string s = vet_s[i];
		string t = vet_s[i - 1];
		gte[i][0][0] = s >= t;
		reverse(all(t));
		gte[i][0][1] = s >= t;
		reverse(all(t));
		reverse(all(s));
		gte[i][1][0] = s >= t;
		reverse(all(t));
		gte[i][1][1] = s >= t;
	}
	
	ll res = min(solve(1, 0), solve(1,1) + cost[0]);
	if (res >= INF) res = -1;
	printf("%lld\n", res);
	
	
}
