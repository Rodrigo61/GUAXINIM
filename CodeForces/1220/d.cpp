#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define fi first
#define se second
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define vll vector<ll>
#define ull unsigned long long
typedef long double ld;

int two_factor(ll a)
{
	int cnt = 0;
	while (a % 2 == 0)
	{
		a /= 2;
		cnt++;
	}
	return cnt;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	map<int, vll> freq2;
	for (int i = 0; i < n; i++)
	{
		ll a;
		scanf("%lld", &a);
		freq2[two_factor(a)].pb(a);
	}

	ll bigger = 0;
	int bigger_set = -1;

	for (auto f : freq2)
		if ((int)f.se.size() > bigger)
		{
			bigger = f.se.size();
			bigger_set = f.fi;
		}
	
	vll not_used;
	for (auto f : freq2)
		if (f.fi != bigger_set)
			for (auto i : f.se)
				not_used.pb(i);

	printf("%d\n", (int)not_used.size());
	for (ll i : not_used)
		printf("%lld ", i);
}
