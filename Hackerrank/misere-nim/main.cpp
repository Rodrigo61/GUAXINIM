#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		int xr = 0;
		bool diff_one = false;
		for (int i = 0; i < N; i++)
		{
			int v;
			scanf("%d", &v);
			xr ^= v;
			if (v != 1) diff_one = true;
			
		}
		if (xr == 0)
		{
			if (diff_one)
			{
				printf("Second\n");
			}
			else
			{
				printf("First\n");
			}
		}
		else
		{
			if (diff_one)
			{
				printf("First\n");
			}
			else
			{
				printf("Second\n");
			}
		}
	}
	
}
