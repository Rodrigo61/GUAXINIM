#include<bits/stdc++.h>

#define INF 1001001001
#define MAXN 200005
#define MAXL 20
using namespace std;

typedef vector<int> vi;


int N, Q;
vi tin, tout;
int tempo;
vi BIT;
vector<vi> arestas_saida;
vi arestas;

vi G[200001];
vi W[200001];

int ancestral[MAXN][MAXL], nivel[MAXN];

void updateRange(int i, int j, int val);

void dfs_lca(int u, int dist)
{
	int v, w;
	tin[u] = ++tempo;
	for (int i = 0; i < G[u].size(); i++)
	{
		v = G[u][i];
		w = W[u][i];
		
		if (nivel[v] == -1)
		{
			nivel[v] = nivel[u] + 1;
			ancestral[v][0] = u;
			dfs_lca(v, dist + w);
		}
	}
	tout[u] = tempo;
	updateRange(tin[u], tin[u], dist);	
}

void buildLCA()
{
	for(int i = 2; i <= N; i++)
		nivel[i] = -1; 
	//tempo = 1;
	//printf("AHN");
	dfs_lca(1, 0);
	//printf("OI?\n");
	for (int i = 1; i <= N; i++)
	{
		for ( int j = 1; j < MAXL; j++)
		{
			ancestral[i][j] = 0;
		}
	}
	
	for ( int j = 1; j < MAXL; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			if (ancestral[i][j - 1] != 0)
			{
				ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];
			}
		}
	}

}


int LCA(int u, int v)
{
	if (nivel[u] < nivel[v]) swap(u, v);
	
	for (int i = MAXL - 1; i >= 0; i--)
	{
		if (nivel[u] - (1 << i) >= nivel[v])
			u = ancestral[u][i];
	}
	
	if (u == v)
	{
		return u;
	}
	
	for (int i = MAXL - 1; i >= 0; i--)
	{
		if ((ancestral[u][i] != 0) && (ancestral[u][i] != ancestral[v][i]))
		{
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
	}
	
	return ancestral[u][0];
}

void update (int i, int val)
{
	//~ printf("uipd\n");
	while (i <= N)
	{
		//~ printf("i = %d\n", i);
		BIT[i] += val;
		i += (i&-i);
	}
}

int sum(int i)
{
	int s = 0;
	while (i > 0)
	{
		s += BIT[i];
		i -= (i & -i);
	}
	
	return s;
}

void updateRange(int i, int j, int val)
{
	update(i, val);
	update(j + 1, -val);
}

struct st
{
	int u, v, w;
	st(){}
	st(int u, int v, int w)
	{
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

st vet[200001];

int main()
{
	int u, v, w, Q, ans;
	scanf("%d", &N);
	for(int i = 1; i < N; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		vet[i] = st(u, v, w);
		G[u].push_back(v);
		G[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
		//printf("%d %d %d\n", u, v, w);
	}
	BIT.resize(N+1);
	tin.resize(N+1);
	tout.resize(N+1);
	//printf("OI");
	buildLCA();
	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d %d %d", &w, &u, &v);
		if(w == 1)
		{
			//printf("(%d, %d)\n(%d, %d)\n", tin[u], tout[u], tin[v], tout[v]);
			
			ans = sum(tin[u]) + sum(tin[v]) - 2*sum(tin[LCA(u, v)]);
			printf("%d\n", ans);
		}
		else
		{
			if(vet[u].u == ancestral[vet[u].v][0])
			{
				updateRange(tin[vet[u].v], tout[vet[u].v], v-vet[u].w);
				vet[u].w = v;
			}
			else
			{
				updateRange(tin[vet[u].u], tout[vet[u].u], v-vet[u].w);
				vet[u].w = v;
			}
		}
	}
	return 0;
}
