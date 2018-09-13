#include<bits/stdc++.h>

using namespace std;

int dX[1001], dY[1001];
int X[1001], Y[1001];

int acum[1001][1001], mat[1001][1001];

set<int> cX, cY;
vector<int> vX, vY;

void construcao()
{
	int N = vX.size(), M = vY.size();
	for(int i = 0; i <= N; i++)
		acum[i][0] = 0;
	for(int i = 0; i <= M; i++)
		acum[0][i] = 0;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			acum[i][j] = mat[i-1][j-1] + acum[i-1][j] + acum[i][j-1] - acum[i-1][j-1];
}

int main()
{
	int T, N, M, K;
	scanf("%d", &T);
	while(T--)
	{
		cX.clear();
		cY.clear();
		scanf("%d %d %d", &N, &M, &K);
		for(int i = 0; i < K; i++)
		{
			scanf("%d %d", &X[i], &Y[i]);
			cX.insert(X[i]);
			cY.insert(Y[i]);
		}
		vX.assign(cX.begin(), cX.end());
		vY.assign(cY.begin(), cY.end());
		for(int i = 0; i < vX.size(); i++)
			for(int j = 0; j < vY.size(); j++)
				mat[i][j] = 0;
		for(int i = 0; i < K; i++)
		{
			dX[i] = lower_bound(vX.begin(), vX.end(), X[i]) - vX.begin();
			dY[i] = lower_bound(vY.begin(), vY.end(), Y[i]) - vY.begin();
			mat[dX[i]][dY[i]] = 1;
		}
		
	}
	return 0;
}
