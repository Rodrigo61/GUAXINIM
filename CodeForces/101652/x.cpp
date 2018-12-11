#include "bits/stdc++.h"

using namespace std;

int main()
{
	int S;
	scanf("%d", &S);

	printf("%d:\n", S);
	
	for (int i = 2; i < S; i++)
	{
		int j = i - 1;
		
		if (j)
		{
			if (S % (i + j) == 0)
			{
				printf("%d,%d\n", i, j);
			}
			else if ((S-i) % (i + j) == 0)
			{
				printf("%d,%d\n", i, j);
			}
		}
		
		j = i;
		
		if (S % (i + j) == 0)
		{
			printf("%d,%d\n", i, j);
		}
		else if ((S-i) % (i + j) == 0)
		{
			printf("%d,%d\n", i, j);
		}
		
		
		
	}
	
	return 0;
}
