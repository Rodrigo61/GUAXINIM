#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fib[46];

ll modInverse(ll a, ll b)
{
	return a > 1LL ? b - ((modInverse(b % a, a) * b)/a): 1LL;
}

ll inv(ll a, ll b)
{
	ll z = modInverse(a, b);
	if(z < 0)
		return z + b;
	return z;
}

int main()
{
	int T;
	ll X, a, b, k, sola, solb;
	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i < 46; i++)
	{
		fib[i] = fib[i-1]+fib[i-2];
	}
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &X);
		if(X <= 3)
		{
			printf("1 1\n");
			continue;
		}
		solb = (X+1)/2;
		sola = X/2;
		b = (X+2)/3;
		a = X-2*((X+2)/3);
		if(b >= a && a > 0 && solb > b)
		{
			solb = b;
			sola = a;
		}
		for(int i = 45; i > 3; i--)
		{
			if(X <= fib[i])
				continue;
			b = (X*inv(fib[i], fib[i-1]))%fib[i-1];
			a = (X-fib[i]*b)/fib[i-1];
			if(b >= a)
			{
				if(a > 0 && solb > b)
				{
					solb = b;
					sola = a;
				}
			}
			else
			{
				k = ((a-b)+fib[i-1]+fib[i]-1)/(fib[i]+fib[i-1]);
				b += k*fib[i-1];
				a -= k*fib[i];
				if(b >= a && a > 0 && solb > b)
				{
					solb = b;
					sola = a;
				}
			}
		}
		printf("%lld %lld\n", sola, solb);
	}
	return 0;
}
