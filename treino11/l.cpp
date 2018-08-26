#include<bits/stdc++.h>

using namespace std;

vector<int> G[100001];


int solve(int x, int p)
{
	int r = 1;
	for(int i = 0; i < G[x].size(); i++)
		if(G[x][i] != p)
			r = max(r, solve(G[x][i], x)+1);
	return r;
}

main()
{
	int N, a, u, v;
	scanf("%d %d", &N, &a);
	for(int i = 1; i < N; i++)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	printf("%d\n", solve(a, a));
	return 0;
}
