#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;


int main()
{
	int q;
	scanf("%d", &q);
	while (q--)
	{
		ll c, m, x;
		scanf("%lld%lld%lld", &c, &m, &x);
		
		ll up = 112345678;
		ll lo = 0;
		ll best = 0;
		
		while (lo <= up)
		{
			ll mid = lo + (up - lo) / 2;
			
			bool poss = true;
			
			if (c < mid || m < mid)
				poss = false;
				
			ll rest = x + (c - mid) + (m - mid);
			
			if (rest < mid)
				poss = false;
				
			if (poss)
			{
				lo = mid + 1;
				best = mid;
			}
			else
			{
				up = mid - 1;
			}
		}
		
		printf("%lld\n", best);
	}
}
