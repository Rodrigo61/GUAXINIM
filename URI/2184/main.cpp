#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;

template<typename T>
void print_vector_debug(const T& t) {
	cout << "[DEBUG] VECTOR:";
	for (auto i = t.cbegin(); i != t.cend(); ++i) {
		if ((i + 1) != t.cend()) {
			cout << *i << " ";
		} else {
			cout << *i << endl;
		}
	}
}

int N, M;


struct Edge
{
	int u, v, w;
};

#define MAXN 2005
#define MAXL 18
#define MAXM 1000005

vector<int> G[MAXN], W[MAXN];

int p[MAXN], l[MAXN];
Edge e[MAXM];
int used_e[MAXM];

int ancestral[MAXN][MAXL], valores[MAXN][MAXL], nivel[MAXN];

void dfs(int u)
{
	int v, w;
	for(int i = 0; i < (int)G[u].size(); i++)
	{
		v = G[u][i];
		w = W[u][i];
		if(nivel[v] == -1)
		{
			nivel[v] = nivel[u] + 1;
			ancestral[v][0] = u;
			valores[v][0] = w;
			dfs(v);
		}
	}
}

void buildLCA(int raiz)
{
	for(int i = 1; i <= N; i++)
		nivel[i] = -1;
	nivel[raiz] = 0;
	dfs(raiz);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j < MAXL; j++)
		{
			ancestral[i][j] = 0;
			valores[i][j] = 0;	
		}
    for(int j = 1; j < MAXL; j++)
		for(int i = 1; i <= N; i++)
			if(ancestral[i][j-1] != 0)
			{
				ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
				valores[i][j] = max(valores[i][j-1], valores[ancestral[i][j-1]][j-1]);
			}
}

int LCA(int u, int v)
{   
	int ans = 0;
    if(nivel[u] < nivel[v]) swap(u, v);
    for(int i = MAXL-1; i >= 0; i--)
        if(nivel[u] - (1<<i) >= nivel[v])
        {
        	ans = max(ans, valores[u][i]);
            u = ancestral[u][i];
        }
        
    if(u == v)
		return ans;
		
    for(int i = MAXL-1; i >= 0; i--)
        if((ancestral[u][i] != 0) && (ancestral[u][i] != ancestral[v][i]))
		{
			ans = max(ans, valores[u][i]);
            u = ancestral[u][i];
            ans = max(ans, valores[v][i]);
            v = ancestral[v][i];
        }    

    return max(ans, max(valores[u][0], valores[v][0]));
}

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

int id(int x)
{
	return (x != p[x] ? p[x] = id(p[x]) : p[x]);
}
 
int kruskal() 
{
	int i, j, u, v, w, cost = 0;
	
	for (int i = 0; i <= N; i++)
	{
		p[i] = i;
		l[i] = 1;
	}
	
	sort(e, e+M, cmp);
    for (i = 0, j = 1; i < M && j < N; i++) 
	{
        u = id(e[i].u);
		v = id(e[i].v);
        if (u != v)
		{
			if(l[u] < l[v])
				swap(u, v);
		
			used_e[i] = 1;
			
            p[v] = u;
            l[u] += l[v];
			j++;
			
			u = e[i].u;
			v = e[i].v;
			w = e[i].w;
			
			
			G[u].push_back(v);
			W[u].push_back(w);
			G[v].push_back(u);
			W[v].push_back(w);
			cost += w;
        }
    }
    
    if (j != N)
	{
		return -1;
	}
    
    return cost;
}

void restart()
{
	for (int i = 0; i < MAXN; i++)
	{
		G[i].clear();
		W[i].clear();
	}
	
	for (int i = 0; i < MAXM; i++)
	{
		used_e[i] = 0;
	}
	
}

int main() 
{
	while (scanf("%d%d", &N, &M) != EOF)
	{
	
		int u, v, u2v;
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &u, &v, &u2v);
			e[i].u = u;
			e[i].v = v;
			e[i].w = u2v;
		}
		
		int base = kruskal();
		int mini = base;
		
		if (base == -1)
		{
			printf("disconnected\n");
			continue;
		}
		
		buildLCA(1);
		
		db(base);
		
		for (int i = 0; i < M; i++)
		{
			auto edge = e[i];
			if (used_e[i])
			{
				//~ printf("(%d,%d)", edge.u, edge.v);
				mini = min(mini, base - edge.w - edge.w);
			}
			else
			{
				//~ printf("(%d,%d) LCA = %d\n", edge.u, edge.v, LCA(edge.u, edge.v));
				mini = min(mini, base - LCA(edge.u, edge.v) - edge.w);
			}
			
		}
		
		printf("%d\n", mini);
		restart();
	}
	return 0;
}
