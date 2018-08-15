#include<bits/stdc++.h>
#define MAXN 1000000

using namespace std;

typedef long long ll;

ll M;


bool possible(ll k)
{
	ll sum = (k * (k + 1))/2;
	
	return sum <= M;
}

ll solve()
{
	ll upper = (ll)2000000000;
	ll lower = 1;
	ll best;
	
	while (lower <= upper)
	{
		ll mid = lower + (upper - lower)/2;
		
		if (possible(mid))
		{
			best = mid;
			lower = mid + 1;
		}
		else
		{
			upper = mid - 1;
		}
	}
	
	return best;
}

int main()
{
	int N;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &M);
		
		printf("%lld\n", solve());
	}
	

	return 0;
}
