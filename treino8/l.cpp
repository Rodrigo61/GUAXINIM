#include<bits/stdc++.h>
#define INFN -1001001001
#define MAXN 100007

using namespace std;

int N, L;
vector<pair<int, int> > mat[MAXN];
int X[MAXN];
int Y[MAXN];
int vis[MAXN];
int pd[MAXN];


int dfs(int a)
{
	int beg, en;
	//printf("%d (%d, %d)\n", a, X[a], Y[a]-1000);
	if(a > N)
		return -1;
	if(vis[a])
		return pd[a];
	vis[a] = 1;
	int r = INFN;
	for(int i = 1; i <= 5; i++)
	{
		beg = lower_bound(mat[X[a]+i].begin(), mat[X[a]+i].end(), make_pair(Y[a]-(5-i), 0))-mat[X[a]+i].begin();
		en = upper_bound(mat[X[a]+i].begin(), mat[X[a]+i].end(), make_pair(Y[a]+(6-i), 0))-mat[X[a]+i].begin();
		for(int j = beg; j < en; j++)
		{
			r = max(r, dfs(mat[X[a]+i][j].second)+1);
		}
	}
	return pd[a] = r;
}

int main()
{
	scanf("%d %d", &N, &L);
	if(N == 0)
		return !printf("0\n");
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d", &X[i], &Y[i]);
		Y[i] += 1000;
		mat[X[i]].push_back(make_pair(Y[i], i));
	}
	X[0] = 0;
	Y[0] = 1000;
	X[N+1] = L;
	Y[N+1] = 1000;
	mat[L].push_back(make_pair(1000, N+1));
	for(int i = 1; i <= L; i++)
		sort(mat[i].begin(), mat[i].end());
	printf("%d\n", dfs(0));
	return 0;
}
