#include <bits/stdc++.h>

#define db(x) //cerr << #x << " = " << x << endl;
using namespace std;

#define MAXN 205
#define INF 1000000

int N, K;
int vet[MAXN];
int dp[MAXN][MAXN];
int dpr[MAXN][MAXN];
int vis[MAXN][MAXN];
int inter[MAXN][MAXN];
int inicio[MAXN];
int resto[MAXN];
int begi[MAXN], endi[MAXN];
int t;

void pre_calc()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			inter[i][j] = 0;
			for (int k = i + 1; k < j; k++)
			{
				inter[i][j] += min(abs(vet[i] - vet[k]), abs(vet[j] - vet[k]));
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		resto[i] = 0;
		for (int j = i; j <= N; j++)
		{
			resto[i] += abs(vet[i] - vet[j]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		inicio[i] = 0;
		for (int j = 1; j <= i; j++)
		{
			inicio[i] += abs(vet[i] - vet[j]);
		}
	}
}

int solve(int l, int k)
{
	db(l);
	db(k);
	if (l == N)
	{
		if (k == 0)
		{
			dp[l][k] = resto[l];
		}
		else
		{
			dp[l][k] = INF;
		}
		
		return dp[l][k];
	}
	
	if (k == 0)
	{
		dp[l][k] = resto[l];
		return dp[l][k];
	}
	
	if (vis[l][k] == t)
	{
		return dp[l][k];
	}
	vis[l][k] = t;
	
	int res = INF, rec, escolhido = l + 1;
	for (int i = l + 1; i <= N; i++)
	{
		rec = solve(i, k - 1);
		
		if (l == 0)
		{
			rec = solve(i, k - 1) + inicio[i];
		}
		else
		{
			rec = solve(i, k - 1) + inter[l][i];
		}
		
		db(rec);
		
		if (rec < res)
		{
			escolhido = i;
			res = rec;
		}
	}
	
	dp[l][k] = res;
	dpr[l][k] = escolhido;
	return res;
}

int main()
{
	int tc = 0;
	while (scanf("%d%d", &N, &K), N+K)
	{
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &vet[i]);
			db(vet[i]);
		}
		
		pre_calc();
		
		memset(dpr, 0, sizeof(dpr));
		
		t++;
		int total = solve(0, K);
		
		int k = K;
		int esq = dpr[0][k];
		int dir = dpr[esq][--k];
		vector<int> points;
		points.push_back(esq);
		
		begi[esq] = 1;
		db(esq);
		db(dir);
		while (dir != 0 && k)
		{
			points.push_back(dir);
			int i;
			for (i = esq + 1; i < dir && abs(vet[i] - vet[esq]) < abs(vet[i] - vet[dir]); ++i);
			
			endi[esq] = i - 1;
			begi[dir] = i;
			
			esq = dir;
			dir = dpr[esq][--k];
		}
		endi[points.back()] = N;
		
		printf("Chain %d\n", ++tc);
		for (int i = 0; i < K; ++i)
		{
			int p = points[i];
			
			if (begi[p] == endi[p])
			{
				printf("Depot %d at restaurant %d serves restaurant %d\n", i + 1, p, p);
			}
			else
			{
				printf("Depot %d at restaurant %d serves restaurants %d to %d\n", i + 1, p, begi[p], endi[p]);
			}
		}
		printf("Total distance sum = %d\n\n", total);
		
	}
	return 0;
}
