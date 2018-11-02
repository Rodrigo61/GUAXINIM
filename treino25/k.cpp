#include<bits/stdc++.h>

using namespace std;

int vet[100010];
int acum[100010];


main()
{
	int N, p, val;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &vet[i]);
		acum[i] = acum[i-1] + vet[i];
		//printf("%d:\n", acum[i]);
	}
	acum[N+1] = acum[N];
	for(int i = 1; i <= N; i++)
	{
		p = i;
		val = 0;
		for(int j = 1; p <= N; j++)
		{
			
			if(acum[min(N+1, p+3*j-1)]-acum[p-1] > 0)
				val += acum[min(N+1, p+3*j-1)]-acum[p-1];
			p += 3*j;
			//printf("%d %d!\n", p, val);
		}
		printf("%d\n", val);
	}
	return 0;
}
