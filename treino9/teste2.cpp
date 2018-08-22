#include<bits/stdc++.h>
#define ll long long

main()
{
	ll N = 5989840988999909996LL;
	while(N)
	{
		printf("%d\n", N%10000);
		N /= 10000;
	}
	return 0;
}
