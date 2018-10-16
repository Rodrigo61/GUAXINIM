#include<bits/stdc++.h>

#define ll long long
using namespace std;

ll get_min(ll n, ll m)
{
	
	if (n == 1)
	{
		return (m+1)/ 2;
	}
	
	if ((n + 1) % 2 == 0)
	{
		return ((n + 1)/2) * m;
	}
	else
	{
		return ((n/2) * m) + ((m)/ 2);
	}
}

main()
{
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		ll n, m;
		scanf("%lld%lld", &n, &m);
		
		printf("%lld\n", min(get_min(n, m), get_min(m, n)));
		
		
	}
	

	return 0;
}
