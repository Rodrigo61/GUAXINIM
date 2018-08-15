#include<bits/stdc++.h>

using namespace std;

int N;

struct st
{
	int x, w, t;
	st(){}
	bool operator <(const st &st2) const
	{
		return x < st2.x;
	}
};

st vet[300000];

int dist[300000];
int pd[300000];
int vis[300000];

int solve(int x)
{
	if(x == N)
		return 0;
	if(vis[x])
		return pd[x];
	vis[x] = 1;
	int r = solve(x+1);
	r = max(r, vet[x].w+solve(lower_bound(dist+x+1, dist+N, vet[x].t+vet[x].x)-dist));
	return pd[x] = r;
}


main()
{
	scanf("%d", &N); 
	for(int i = 0; i < N; i++)
		scanf("%d %d %d", &vet[i].x, &vet[i].w, &vet[i].t);
	sort(vet, vet+N);
	for(int i = 0; i < N; i++)
		dist[i] = vet[i].x;
	printf("%d\n", solve(0));
	return 0;
}
