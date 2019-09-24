#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define MAXN 112345
#define MOD 1000000007

int n;
ll vals[MAXN];
vi adj[MAXN];
ll res = 0;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

ll mult_mod(ll a, ll b)
{
	return (a * b) % MOD;
}

ll add_mod(ll a, ll b)
{
	return (a + b) % MOD;
}

void dfs(int u, int pu, map<ll, int> s)
{
	s[vals[u]] += 1;
	map<ll, int> m;
	for (auto i : s)
	{
		ll a = gcd(i.fi, vals[u]);
		res = add_mod(res, mult_mod(i.se, a % MOD));
		m[a] += i.se;
	}
	
	for (auto v : adj[u])
	{
		if (v != pu)
		{
			dfs(v, u, m);
		}
	}

}


int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &vals[i]);
		vals[i] = vals[i];
	}
	
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	map<ll, int> aux;
	dfs(1, 0, aux);
	printf("%lld\n", res);
}
