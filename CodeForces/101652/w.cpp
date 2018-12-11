#include "bits/stdc++.h"

using namespace std;
#define db(x) cerr << #x << " = " << x << endl;
int M, N;
char grid [31][31];

int limit[31];

int main()
{
	scanf("%d%d\n", &N, &M);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%c", &grid[i][j]);
		}
		scanf("\n");
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == 'B')
			{
				for (int l = 0; l <= i; l++)
				{
					for (int k = 0; k <= j; k++)
					{
						limit[k] = max(limit[k], l);
						
						if (grid[l][k] == 'R')
						{
							return !printf("0\n");
						}
					}
				}
			}
		}
	}
	
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = M - 1; j >= 0; j--)
		{
			if (grid[i][j] == 'R')
			{
				for (int l = N - 1; l >= i; l--)
				{
					for (int k = M - 1; k >= j; k--)
					{
						limit[k] = min(limit[k], l);
					}
				}
			}
		}
	}
	
	printf("limit: ");
	for (int i = 0; i < M; i++)
	{
		printf("%d ", limit[i]);
	}
	printf("\n");
	
	
	
	
	
	return 0;
}
