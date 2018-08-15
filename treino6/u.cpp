#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N, M, K;

ll mat[2][100][100];

ll convolve(int a, int x, int y)
{
	int x2, y2, ans = 0;
	for(int i = -1; i <= 1; i++)
		for(int j = -1; j <= 1; j++)
		{
			x2 = x+i;
			if(x2 == -1)
				x2 = N-1;
			if(x2 == N)
				x2 = 0;
			y2 = y+j;
			if(y2 == -1)
				y2 = M-1;
			if(y2 == M)
				y2 = 0;
			//printf("%d %d\n", x2, y2);
			ans += mat[a][x2][y2];
		}
	//printf("%d\n", ans);
	return ans;
}

set<ll> conju;

main()
{
	int at, ant;
	scanf("%d %d %d", &M, &N, &K);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%lld", &mat[0][i][j]);
	for(int k = 1; k <= K; k++)
	{
		at = k&1;
		ant = !at;
		for(int i = 0; i < N; i++)
		{	
			for(int j = 0; j < M; j++)
			{
				mat[at][i][j] = convolve(ant, i, j);
				//printf("%d ", mat[at][i][j]);
			}
			//printf("\n");
		}
		//printf("\n");
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			conju.insert(mat[at][i][j]);
	printf("%d\n", conju.size());
	return 0;
}
