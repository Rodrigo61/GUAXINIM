#include<bits/stdc++.h>

using namespace std;

main()
{
	int T, x, N, r, q;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &x, &N);
		if(N > x)
			printf("-1\n");
		else
		{
			q = x/N;
			r = x%N;
			for(int i = 0; i < N; i++)
			{
				printf("%d ", q + (i+r >= N));
			}
			printf("\n");
		}
	}
	return 0;
}
