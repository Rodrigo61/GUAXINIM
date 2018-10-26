#include<bits/stdc++.h>
#define ll long long

using namespace std;

pair<double, int> vet[15];

double yver(ll a, ll b, ll c)
{
	return (b*b+4*a*c)/(4.0*a);
}

main()
{
	int T, a, b, c, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			vet[i] = {yver(a, b, c), i+1};
			//printf("%.4lf\n", yver(a, b, c));
		}
		sort(vet, vet+N);
		printf("%d\n", vet[N-1].second);
	}
	return 0;
}
