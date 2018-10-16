#include<bits/stdc++.h>

using namespace std;

int vet[2001];

main()
{
	int T, N, ma;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		ma = 0;
		for(int i = 0; i < N; i++)
			scanf("%d", &vet[i]);
		for(int i = N; i < N+N; i++)
		{
			scanf("%d", &vet[i]);
			ma = max(ma, vet[2*N-1-i]+vet[i]);
		}
		printf("%d\n", ma);
	}
	return 0;
}
