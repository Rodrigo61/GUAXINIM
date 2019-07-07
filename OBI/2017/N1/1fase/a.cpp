#include <bits/stdc++.h>

using namespace std;

#define MAXN 112345

int freq[10];
int vals[MAXN];
int query[MAXN];
int prefix[10][MAXN];
int N, Q;

int get_sum(int p, int a, int b)
{
	if (a == b)
	{
		return 0;
	}
	
	int r, l;
	if (a > b)
	{
		r = a - 1;
		l = b;
	}
	else
	{
		l = a + 1;
		r = b;
	}
	
	
	int result = prefix[p][r];
	
	if (l > 0)
	{
		result -= prefix[p][l - 1];
	}
	
	return result;
}


int main()
{
	scanf("%d%d", &N, &Q);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	for (int i = 0; i < 10; i++)
	{
		int acu = 0;
		for (int j = 1; j <= N; j++)
		{
			if (vals[j] == i)
			{
				++acu;
			}
			prefix[i][j] = acu;
		}
	}
	
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", &query[i]);
	}
	
	
	for (int i = 0; i < 10; i++)
	{
		int curr = query[0];
		int nex = query[1];
		int total = 0;
		for (int j = 2; j < Q; j++)
		{
			total += get_sum(i, curr, nex);
			curr = nex;
			nex = query[j];
		}
		total += get_sum(i, curr, nex);
		if (vals[1] == i)
		{
			total++;
		}
		
		printf("%d ", total);
	}
	printf("\n");
}
