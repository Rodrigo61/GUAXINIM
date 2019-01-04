#include <bits/stdc++.h>
#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
using namespace std;

ll sum(ll a, ll b)
{
	return ((a+b) * (b-a+1)) / 2;
}

int main()
{
	ll a, b;
	
	scanf("%lld%lld", &a, &b);
	db(a);
	db(b);
	ll m = sqrt(b);
	
	ll total = 0;
	
	for (int i = 1; i <= m; i++)
	{
		total += i*(b/i - (a-1)/i);
		
		ll mi = max((ll)ceil((double)a/i), m + 1);
		ll ma = b/i;
	
		
		if (i*mi >= a && i*mi <= b && i*ma >= a && i*ma <= b)
		{
			total += sum(mi, ma);
		}
		
	}
	
	printf("%lld\n", total);
	
	return 0;
}
