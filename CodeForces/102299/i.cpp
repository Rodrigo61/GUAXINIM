#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define a first
#define b second
#define ll long long
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pll pair<ll, ll>
#define vii vector<pii>

int main()
{
	int N;
	scanf("%d", &N);
	vector<pll> vet;
	for (int i = 0; i < N; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		vet.pb({a, b});
	}
	sort(all(vet), [] (pll &x, pll &y)
	{
		return x.b < y.b;
	});
	
	ll res = -INF;
	ll curr = 0;
	for (auto p : vet)
	{
		curr += p.a;
		res = max(res, curr - p.b);
	}
	
	printf("%lld\n", res);
}
