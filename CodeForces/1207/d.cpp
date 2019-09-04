#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pll pair<ll, ll>

#define MOD 998244353 
#define MAXN 312345

ll freq1[MAXN], freq2[MAXN];
pll vals[MAXN];

ll vis[MAXN];
ll dp[MAXN];

ll mult(ll a, ll b)
{
	return (a * b) % MOD;
}

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}

ll sub(ll a, ll b)
{
	return (a - b + MOD) % MOD;
}

ll fat(ll i)
{
	if (i == 0)
		return 1;
	if (vis[i])
		return dp[i];
	vis[i] = 1;
	return dp[i] = mult(i, fat(i - 1));
}

int main()
{
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%lld%lld", &vals[i].fi, &vals[i].se);
		freq1[vals[i].fi]++;
		freq2[vals[i].se]++;
	}
	
	ll cnt1 = 1;
	ll cnt2 = 1;
	for (int i = 0; i < MAXN; i++)
	{
		cnt1 = mult(cnt1, fat(freq1[i]));
		cnt2 = mult(cnt2, fat(freq2[i]));
	}
	
	sort(vals, vals + N);
	ll acu = 0;
	ll cnt12 = 1;
	pll last = {-1, -1};
	for (int i = 0; i < N; i++)
	{
		if (vals[i] != last)
		{
			acu = 0;
		}
		
		if (vals[i].se < last.se)
		{
			cnt12 = 0;
			break;
		}
		
		++acu;
		cnt12 = mult(cnt12, acu);
		last = vals[i];
	}
	
	db(cnt1);
	db(cnt2);
	db(cnt12);
	printf("%lld\n", add(sub(sub(fat(N), cnt1), cnt2), cnt12));
}
