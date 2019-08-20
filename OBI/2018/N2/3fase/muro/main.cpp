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

#define MOD 1000000007
#define MAXN 11234

ll G1(ll);
ll G2(ll);
ll G3(ll);
int vis1[MAXN], vis2[MAXN], vis3[MAXN];
ll dp1[MAXN], dp2[MAXN], dp3[MAXN];

ll mult(ll a, ll b)
{
	return (a * b) % MOD;
}

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}

ll G2(ll n)
{
	if (n < 2)
	{
		return 0;
	}
	if (n == 2) return 4;
	if (vis2[n]) return dp2[n];
	vis2[n] = 1;
	
	return dp2[n] = mult(4 , add(G2(n - 2), add(G3(n - 2), G1(n - 2))));
}
ll G3(ll n)
{
	if (n < 3)
	{
		return 0;
	}
	if (n == 3) return 2;
	if (vis3[n]) return dp3[n];
	vis3[n] = 1;
	
	return dp3[n] = mult(2 , add(G2(n - 3), add(G3(n - 3), G1(n - 3))));
}
ll G1(ll n)
{
	if (n < 1)
	{
		return 0;
	}
	if (n == 1) return 1;
	if (vis1[n]) return dp1[n];
	vis1[n] = 1;
	
	return dp1[n] = mult(1 , add(G2(n - 1), add(G3(n - 1), G1(n - 1))));
}
 
int main()
{
	int N;
	scanf("%d", &N);
	printf("%lld", max({(ll)1, (ll)add(G2(N) , add(G3(N) , G1(N)))}));
}
