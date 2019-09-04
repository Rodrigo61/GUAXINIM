#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>


int main()
{
	int N;
	scanf("%d", &N);
	vii dragons(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &dragons[i].fi, &dragons[i].se);
	}
	sort(all(dragons), [](pii &x, pii &y)
	{
		return x.fi - x.se > y.fi - y.se;
	});
	
	ll up = 1e18;
	ll lo = 1;
	ll best;
	
	while (lo <= up)
	{
		ll mid = lo + (up - lo)/2;
		ll R = mid;
		bool possible = true;
		for (auto p : dragons)
		{
			if (p.fi <= R)
			{
				R -= p.se;
			}
			else
			{
				possible = false;
				break;
			}
		}
		
		if (possible)
		{
			best = mid;
			up = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	
	printf("%lld\n", best);
}
