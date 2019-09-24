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

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	ll last = 0;
	ll total = 0;
	for (int i = 0; i < N; i++)
	{
		ll v;
		scanf("%lld", &v);
		ll mi = min(v, M - v);
		ll ma = max(v, M - v);
		
		if (mi >= last)
		{
			total += mi;
			last = mi;
		}
		else if (ma >= last)
		{
			total += ma;
			last = ma;
		}
		else
		{
			return !printf("-1\n");
		}
	}
	
	printf("%lld\n", total);
}
