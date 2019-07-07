//escadinha
#include <bits/stdc++.h>

using namespace std;


int main()
{
	int N;
	scanf("%d", &N);
	
	vector<int> vet(N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vet[i]);
	}
	
	if (N == 1)
	{
		return !printf("1\n");
	}
	
	int last_diff = vet[0] - vet[1];
	int total = 0;
	
	for (int i = 1; i < N; i++)
	{
		if (vet[i - 1] - vet[i] != last_diff)
		{
			++total;
		}
		last_diff = vet[i - 1] - vet[i];
	}
	
	printf("%d\n", total + 1);
}
