#include<bits/stdc++.h>

typedef long long ll;
using namespace std;


int main()
{
	ll N;
	ll xs, ys, xt, yt;
	
	scanf("%lld%lld%lld%lld%lld", &N, &xs, &ys, &xt, &yt);
	
	ll dist = abs(xs - xt) + abs(ys - yt);
	
	if (dist == 0)
	{
		dist = 2;
	}
	
	if (dist > N)
	{
		return !printf("0\n");
	}
	
	ll diff = N - dist + 1;
	//~ printf("%d\n", diff);
	
	if (diff % 2 == 0)
	{
		printf("%lld\n", diff / 2);
	} else
	{
		printf("%lld\n", diff / 2 + 1);
	}
	
	return 0;
}
