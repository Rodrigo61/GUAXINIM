#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll vet[20000];

int triangle(ll a, ll b, ll c)
{
	return (a < b+c) && (b < a+c) && (c < b+a);
}

main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%I64d", &vet[i]);
	sort(vet, vet+N);
	for(int i = 2; i < N; i++)
		if(triangle(vet[i], vet[i-1], vet[i-2]))
			return !printf("possible\n");
	printf("impossible\n");
	return 0;
}
