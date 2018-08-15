#include<bits/stdc++.h>
#define ll long long

using namespace std;

main()
{
	ll a, b, c, d;
	scanf("%lld %lld %lld", &a, &b, &c);
	d = 100*a-100*b+2*b*c;
	printf("%.7lf\n", d/100.0);
	return 0;
}
