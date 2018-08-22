#include<bits/stdc++.h>

using namespace std;

int vet[11];

void preenche(int x)
{
	int k = 0;
	while(x)
	{
		vet[k++] = x&1;
		x >>= 1;
	}
}

int valido(int x, int tam, int K)
{
	int r = 0;
	for(int i = x-K+1; i < x; i++)
	{
		if(vet[(i+tam)%tam])
			r = 1;
	}
	if(r == 0)
		return 0;
	r = 0;
	for(int i = x+1; i < x+K; i++)
	{
		if(vet[(i+tam)%tam])
			r = 1;
	}
	return r;
}

main()
{
	for(int i = 1, lim = 1; i <= 5; i++, lim <<= 1)
	{
		for(int k = 1; k <= i; k++)
		{
			int r = 0;
			int j = 1;
			for(; j < lim; j++)
			{
				preenche(j);
				int l;
				for(l = 0; l < i; l++)
				{
					if(vet[l] && !valido(l, i, k))
						break;
				}
				r += (l == i);
			}	
			printf("%d %d -> %d\n", i, k, r);
		}
	}
	return 0;
}
