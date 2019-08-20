#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
 
ll W;
ll vals[9];
ll L = 840;
ll dp[9][9 * 8400];
int vis[9][9 * 8400];
ll L_cnt;
 
ll solve(ll idx, ll sum_diff)
{
	if (idx == 9)
	{
		if (sum_diff > W) return 0;
		ll r = W - sum_diff;
		ll L_in_r = r / L;
		return sum_diff + (L * min(L_cnt, L_in_r));
	}
	
	if (vis[idx][sum_diff])
	{
		return dp[idx][sum_diff];
	}
	vis[idx][sum_diff] = 1;
	
	ll res = 0;
	for (ll i = 0; i <= vals[idx]; i++)
	{
		res = max(res, solve(idx + 1, sum_diff + i * idx));
	}
	
	return dp[idx][sum_diff] = res;
}
 
int main()
{
	scanf("%lld", &W);
	for (ll i = 1; i <= 8; i++)
	{
		scanf("%lld", &vals[i]);
		if ((vals[i] * i) >= L )
		{
			ll cnt_L = ((vals[i] * i) / L) - 1;
			L_cnt += cnt_L;
			vals[i] = (vals[i] * i - cnt_L * L)/i;
		}
		
		db(vals[i]);
	}
	
	printf("%lld\n", solve(1, 0));
	
}
