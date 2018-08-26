#include <bits/stdc++.h>

#define db(x) cerr << #x << " = " << x << endl;

typedef long long ll;
using namespace std;

ll lcm(ll a, ll b)
{
	return (a*b)/__gcd(a, b);
}

int main()
{
	
	ll N, K;
	scanf("%lld%lld", &N, &K);
	
	ll ans = lcm(N, K) - K + (__gcd(N, K) - 1) * (K - 1);
	
	db(__gcd(N, K));
	db(lcm(N, K));
	
	printf("%lld\n", ans);
	return 0;
}
