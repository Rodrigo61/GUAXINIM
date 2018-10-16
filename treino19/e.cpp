#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007


ll modInverse(ll a, ll b)
{
	return a > 1LL ? b - ((modInverse(b%a, a)*b)/a) : 1LL;
}

ll inv(ll a)
{
	ll z = modInverse(a, MOD);
	if(z < 0)
		return z + MOD;
	return z;
}

ll vet[100001];

main()
{
	int T, N;
	ll prod, ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		prod = 1;
		ans = 0;
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &vet[i]);
			prod = (prod*vet[i])%MOD;
		}
		for(int i = 0; i < N; i++)
		{
			ans += (((prod*inv(vet[i]))%MOD)*(vet[i]-1))%MOD;
		}
		printf("%lld\n", ans%MOD);
	}
	return 0;
}
