#include<bits/stdc++.h>
#define MAXN 100005
#define MAXL 18
#define ll long long

using namespace std;

vector<int> G[MAXN];
vector< pair<int, int> > W[MAXN];

int N;
int ancestral[MAXN][MAXL], nivel[MAXN];
ll total;
pair<int, int> valores[MAXN][MAXL];

void dfs(int u)
{
	int v;
	for(int i = 0; i < (int)G[u].size(); i++)
	{
		v = G[u][i];
		if(nivel[v] == -1)
		{
			nivel[v] = nivel[u]+1;
			ancestral[v][0] = u;
			valores[v][0] = W[u][i];
			dfs(v);
		}
	}
}

pair<int, int> operator+(pair<int, int> p, pair<int, int> q)
{
	return {p.first+q.first, p.second+q.second};
}

void buildLCA(int raiz)
{
	for(int i = 1; i <= N; i++)
		nivel[i] = -1;
	nivel[raiz] = 0;
	dfs(raiz);
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j < MAXL; j++)
		{
			ancestral[i][j] = 0;
			valores[i][j] = {0, 0};
		}
	}
	for(int j = 1; j < MAXL; j++)
	{
		for(int i = 1; i <= N; i++)
			if(ancestral[i][j-1] != 0)
			{
				ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
				valores[i][j] = valores[i][j-1] + valores[ancestral[i][j-1]][j-1];
			}
	}
}

ll LCA(int u, int v)
{
	int f = 0;
	ll ans = 0;
	if(nivel[u] < nivel[v])
	{
		swap(u, v);
		f = 1;
	}
	for(int i = MAXL-1; i >= 0; i--)
	{
		if(nivel[u] - (1<<i) >= nivel[v])
		{
			if(f == 0)
				ans += valores[u][i].first;
			else
				ans += valores[u][i].second;
			u = ancestral[u][i];
		}
	}
	if(u == v)
	{
		return total - ans;
	}
	for(int i = MAXL-1; i >= 0; i--)
	{
		if((ancestral[u][i] != 0) && (ancestral[u][i] != ancestral[v][i]))
		{
			if(f == 0)
				ans += valores[u][i].first + valores[v][i].second;
			else
				ans += valores[u][i].second + valores[v][i].first;
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
	}
	if(f == 0)
		ans += valores[u][0].first + valores[v][0].second;
	else
		ans += valores[u][0].second + valores[v][0].first;
	return total - ans;
}

int main()
{
	int T, Q, u, v, a, b;
	scanf("%d", &T);
	while(T--)
	{
		for(int i = 1; i <= N; i++)
		{
			G[i].clear();
			W[i].clear();
		}
		total = 0;
		scanf("%d", &N);
		for(int i = 1; i < N; i++)
		{
			scanf("%d %d %d %d", &u, &v, &a, &b);
			G[u].push_back(v);
			W[u].push_back({a, b});
			G[v].push_back(u);
			W[v].push_back({b, a});
			total += a+b;
		}
		buildLCA(1);
		scanf("%d", &Q);
		while(Q--)
		{
			scanf("%d %d", &u, &v);
			printf("%lld\n", LCA(u, v));
		}
	}
	return 0;
}
