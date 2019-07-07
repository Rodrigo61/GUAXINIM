#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;

ll d, k, a, b, t;

ll get_less_multply(ll d, ll k)
{
	ll r = d/k;
	ll res = k * r;
	
	if (res == d)
	{
		return res - k;
	}
	return res;
	
}

int main()
{
	scanf("%lld%lld%lld%lld%lld", &d, &k, &a, &b, &t);
	
	if (d <= k)
	{
		printf("%lld\n", a * d);
	}
	else
	{
		ll only_foot = b * (d-k) + a * k;
		
		ll dl = get_less_multply(d, k);
		ll Tl = (dl/k*(a*k+t));
		
		ll only_car = Tl + (d-dl)*a;
		
		ll dll = get_less_multply(dl, k);
		ll Tll = (dll/k*(a*k+t));
		ll last_car = Tll + k*a;
		ll foot = (d-dl) * b;
		
		ll mini = min({only_car, last_car + foot, only_foot});
		printf("%lld\n", mini);
	}
	
}
