#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define pll pair<ll, ll>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

#define MOD 1000000007

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}

ll mult(ll a, ll b)
{
	return (a * b) % MOD;
}

int main()
{
	int T;
	scanf("%d", &T);
	int tc = 0;
	
	while (T--)
	{
		int K;
		scanf("%d", &K);
		vi vals(K);
		for (int i = 0; i < K; i++)
		{
			scanf("%d", &vals[i]);
		}
		
		ll res = 0;
		for (int i = 0; i < K; i++)
		{
			ll p = 1;
			for (int j = i + 1; j < K; j++)
			{
				res = add(res, mult(vals[j] - vals[i], p));
				p = mult(p, 2);
			}
		}
		
		printf("Case #%d: %lld\n", ++tc, res);
	}
}
