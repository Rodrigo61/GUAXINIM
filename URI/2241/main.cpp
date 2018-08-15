#include<stdio.h>

char mat[501][501];

main()
{
	int N, M, x, y, cp, cb, i, j, k;
	scanf("%d %d", &N, &M);
	cp = cb = M;
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		mat[x][y] = 1;
	}
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		mat[x][y] = 2;
	}
	for(k = 1; k <= N; k++)
	{
		for(i = 1; i <= N-k; i++)
		{
			for(j = 1; j <= N-k; j++)
			{
				mat[i][j] |= mat[i+1][j+1] | mat[i+1][j] | mat[i][j+1];
				if(mat[i][j] == 1)
					cp++;
				if(mat[i][j] == 2)
					cb++;
			}
		}
	}
	printf("%d %d\n", cp, cb);
	return 0;
}
