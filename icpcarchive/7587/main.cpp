#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pll pair<ll, ll>
#define vii vector<pii>

int N;
vector<pll> pos, neg;
		
bool possible(ll R)
{
	for (auto p : pos)
	{
		if (R >= p.fi)
		{
			R += p.se;
		}
		else
		{
			return false;
		}
	}
	
	for (auto p : neg)
	{
		if (R >= p.fi)
		{
			R -= p.se;
		}
		else
		{
			return false;
		}
		
	}
	
	return true;
	
}
		

ll solve()
{
	ll up = 1e18;
	ll lo = 1;
	ll best;
	
	while (lo <= up)
	{
		ll mid = lo + (up - lo)/2;
		if (possible(mid))
		{
			best = mid;
			up = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	
	return best;
}

void clear()
{
	pos.clear();
	neg.clear();
}

int main()
{
	while (scanf("%d", &N) != EOF)
	{
		for (int i = 0; i < N; i++)
		{
			ll a, b;
			scanf("%lld%lld", &a, &b);
			
			ll c = b - a;
			
			if (c >= 0)
			{
				pos.pb({a, c});
			}
			else
			{
				neg.pb({max(a, -c), -c});
			}
		}
		
		sort(all(pos));
		sort(all(neg), [](pll &a, pll &b)
		{
			return a.fi - a.se > b.fi - b.se;
		});

		
		printf("%lld\n", solve());

		clear();
	}
}
