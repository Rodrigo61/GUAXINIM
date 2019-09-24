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

#define MAXN 112345

int BIT[MAXN];

void update(int pos)
{
	++pos;
	while (pos < MAXN)
	{
		BIT[pos] += 1;
		pos += pos & -pos;
	}
}

int prefix(int pos)
{
	if (pos < 0) return 0;
	++pos;
	int res = 0;
	
	while (pos > 0)
	{
		res += BIT[pos];
		pos -= pos & -pos;
	}
	
	return res;
}

int main()
{
	int N;
	scanf("%d", &N);
	vector<double> coords(N);
	vll in(N);
	for (int i = 0; i < N; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		in[i] = x * x + y * y;
		coords[i] = in[i];
	}
	sort(all(coords));
	
	ll res = 0;
	for (ll p : in)
	{
		int coord = lower_bound(all(coords), p) - coords.begin();
		res += prefix(coord);
		update(coord);
	}
	
	printf("%lld\n", res);	
	
}
