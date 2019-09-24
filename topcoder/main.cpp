#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main()
{
	ll N, R, C, D, A_MAX, B_MAX;
	scanf("%lld%lld%lld%lld%lld%lld", &N, &R, &C, &D, &A_MAX, &B_MAX);
	vector<pair<ll, ll>> vals(N);
	for (ll i = 0; i < N; i++)
	{
		R = (C * R + D) % MOD;
		vals[i].se = R % A_MAX;
		R = (C * R + D) % MOD;
		vals[i].fi = R % B_MAX;
	}

	sort(all(vals));
	reverse(all(vals));
	
	multiset<pair<ll, pll>> ms;
	ll B = 0;
	for (ll i = 0; i < N; i++)
	{
		ms.insert({vals[i].fi + vals[i].se, vals[i]});
		if (i % 2)
		{
			while (ms.size() > (i + 1) / 2)
			{
				auto smaller = ms.begin();
				B += smaller->se.fi;
				ms.erase(smaller);
			}
		}
	}
	
	ll A = 0;
	for (auto p : ms)
		A += p.se.se;
		
	printf("%lld\n", A - B);
	
	
	
}
