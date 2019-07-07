#include <bits/stdc++.h>

using namespace std;

#define MAXN 112345
#define ll long long

int N, M;
ll cities[MAXN], towers[MAXN];

bool simulate(ll r)
{
	int it_tower = 0;
	int it_cities = 0;
	
	for(; it_tower < M; ++it_tower)
	{
		if (towers[it_tower] - r > cities[it_cities])
		{
			return false;
		}
		
		while (it_cities < N && cities[it_cities] <= towers[it_tower] + r)
		{
			++it_cities;
		}
		
		if (it_cities == N)
		{
			break;
		}
	}
	
	return it_cities == N;
}

ll solve()
{
	ll lo = 0;
	ll up = 2000000001;
	ll best;
	
	while (lo <= up)
	{
		ll mid = lo + (up-lo)/2;
		
		if (simulate(mid))
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

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &cities[i]);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%lld", &towers[i]);
	}
	
	printf("%lld\n", solve());
}
