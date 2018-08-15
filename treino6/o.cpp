#include<bits/stdc++.h>
#define INF 1001001001

using namespace std;

int N, M;
char mat[500][501];
int dist[500][501];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int inRange(int x, int y)
{
	return x>=0 && x < N && y >= 0 && y < M;
}

main()
{
	int x, y, x2, y2;
	scanf("%d %d", &N, &M);
	for(int i = 0; i <N; i++)
		scanf("%s", mat[i]);
	queue< pair<int, int> > fila;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			dist[i][j] = INF;
	dist[0][0] = 0;
	fila.push({0,0});
	while(!fila.empty())
	{
		x = fila.front().first;
		y = fila.front().second;
		fila.pop();
		if(mat[x][y] == '0')
			continue;
		for(int i = 0; i < 4; i++)
		{
			x2 = x + dx[i]*(mat[x][y]-'0');
			y2 = y + dy[i]*(mat[x][y]-'0');
			if(inRange(x2, y2) && dist[x2][y2] > dist[x][y]+1)
			{
				dist[x2][y2] = dist[x][y]+1;
				fila.push({x2, y2});
			}
		}
	}
	if(dist[N-1][M-1] == INF)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", dist[N-1][M-1]);
	return 0;
}
