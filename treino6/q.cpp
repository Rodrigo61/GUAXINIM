#include<bits/stdc++.h>

using namespace std;

int vet[100000];

main()
{
	int N, me = 1001001001;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d", &vet[i]);
	sort(vet,vet+N);
	for(int i =0;i<N;i++)
		me = min(me, vet[i]+vet[N-1-i]);
	printf("%d\n",me);
	return 0;
}
