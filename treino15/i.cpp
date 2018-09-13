#include<bits/stdc++.h>

using namespace std;

int pd[300001][11];
int vis[300001][11];
int N, K;
int vet[300001];

int solve(int x, int y)
{
	if(x == N)
		return 0;
	if(vis[x][y])
		return pd[x][y];
	vis[x][y] = 1;
	int r = solve(x+1, min(K, y+1));
	if(y == K)
		r = max(r, solve(x+1, 1) + vet[x]);
	return pd[x][y] = r;
}

main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		scanf("%d", &vet[i]);
	printf("%d\n", solve(0, 0));
	return 0;
}
