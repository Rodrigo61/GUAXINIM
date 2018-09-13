#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> G[801];
long double W[801][801];


int main()
{
	int x, y, j;
	long double w, ans = 0;
	scanf("%d %d", &N, &M);
	//if(M == 0)
		//return !printf("inadmissible\n");
	for(int i = 1; i <= N; i++)
		for(j = 1; j <= N; j++)
			W[i][j] = 0;
	while(M--)
	{
		cin >> x >> y >> w;
		G[x].push_back(y);
		W[x][y] = w;
	}
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int l = 0; l < (int)G[k].size(); l++)
			{
				j = G[k][l];
				W[i][j] = max(W[i][k]*W[k][j], W[i][j]);
			}
	for(int i = 1; i <= N; i++)
		ans = max(ans, W[i][i]);
	printf("%s\n", ans < 1 ? "admissible" : "inadmissible");
	return 0;
}
