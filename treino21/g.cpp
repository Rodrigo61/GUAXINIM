#include<bits/stdc++.h>
#define ll long long
using namespace std;

int lcm(ll& a, ll b)
{
	ll g = a/__gcd(a, b);
	if(log(g)+log(b) > 35)
		return 0;
	a = g*b;
	return 1;
}

int vet[2000];

int main()
{
	int T, N, ans;
	ll acum, mmc;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &vet[i]);
		}
		ans = 0;
		for(int i = 0; i < N; i++)
		{
			mmc = 1;
			acum = 0;
			for(int j = i; j < N; j++)
			{
				acum += vet[j];
				if(!lcm(mmc, vet[j]))
					break;
				ans += acum%mmc == 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
