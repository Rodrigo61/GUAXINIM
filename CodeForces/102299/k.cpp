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
#define vii vector<pii>


int main()
{
	int n;
	scanf("%d", &n);
	vll vals(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &vals[i]);
	}
	sort(all(vals));
	ll hi = 0;
	
	for (int i = 0; i < n; i++)
	{
		db(hi);
		if (vals[i] > hi + 1)
		{
			return !printf("%lld\n", hi + 1);
		}
		hi = vals[i] + hi;
	}
	db(hi);
	printf("%lld\n", hi + 1);
	
}
