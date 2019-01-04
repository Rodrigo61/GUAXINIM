#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll a, b, x, y;

vector<ll> divisors(ll num)
{
	vector<ll> res;
	ll sqr = sqrt(num);
	
	for (ll i = 1; i <= sqr; i++)
	{
		if (num % i == 0)
		{
			if (i >= a && i <= b)
			{
				res.push_back(i);
			}
			
			ll r = num / i;
			if (r != i && r >= a && r <= b)
			{
				res.push_back(r);
			}
			
		}
	}
	
	return res;
	
}

int main()
{
	scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
	
	ll xy = x * y;
	
	auto v = divisors(y);
	
	ll total = 0;
	for (ll n : v)
	{
		ll t = xy/n;
		ll gcd = __gcd(n, t);
		ll lcm = (n*t)/gcd;
		
		if (gcd == x && lcm == y && n >= a && n <= b && t >= a && t <= b)
		{
			++total;
		}
	}
	
	printf("%lld\n", total);
}
