#include<bits/stdc++.h>
#define INF 1001001001

using namespace std;

int N;
int vis[4000][1801][2];
int pd[4000][1801][2];
int vet[4000];

int solve(int x, int y, int z)
{
	//printf("%d %d %d\n", x, y, z);
	if(y > 1800)
		return INF;
	if(x == N)
		return 0;
	if(vis[x][y][z])
		return pd[x][y][z];
	vis[x][y][z] = 1;
	int r = INF;
	if(z)
	{
		int dif = vet[x+1]-vet[x];
		if(y+20 >= dif)
		{
			r = solve(x+1, y+20-dif, 1)+20;
		}
		else
		{
			r = min(solve(x+1, 0, 1)+dif-y,
			solve(x+1, max(y+80-dif, 0), 0)+20); 
		}
	}
	else
	{
		r = min(solve(x, y+60, 1)+120, solve(x, y+1, 0));
	}
	//printf("%d %d %d -> %d\n", x, y, z, r);
	return pd[x][y][z] = r;
}

main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &vet[i]);
	}
	for(int i = 0; i < N; i++)
		printf("%d\n", vet[i]);
	vet[N] = 1000000;
	printf("%d\n", solve(0, 0, 0));
	return 0;
}
