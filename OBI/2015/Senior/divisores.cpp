#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	
	int total = 0;
	for (int i = 1; i*i <= N; i++)
	{
		if (N % i == 0)
		{
			total++;
			if (N/i != i)
			{
				total++;
			}
		}
	}
	
	printf("%d\n", total);
}
