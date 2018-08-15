#include<bits/stdc++.h>

using namespace std;

int vet[3], vet2[3];

main()
{
	scanf("%d %d %d", &vet[0], &vet[1], &vet[2]);
	scanf("%d %d %d", &vet2[0], &vet2[1], &vet2[2]);
	sort(vet, vet+3);
	sort(vet2, vet2+3);
	for(int i = 0; i < 3; i++)
		if(vet[i] != vet2[i])
			return !printf("NO\n");
	printf("%s\n", (vet[0]*vet[0]+vet[1]*vet[1] == vet[2]*vet[2]) ? "YES" : "NO");
	
	return 0;
}
