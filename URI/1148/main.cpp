#include "bits/stdc++.h"
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
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

#define MAXN 501
#define INF 1001001001
int N, E;

vector<int> G[MAXN], W[MAXN];
int dist[MAXN];
int adj[MAXN][MAXN];


void dijkstra(int s)
{
	int u, v, w;
	priority_queue<pair<int, int> > fila;
	for(int i = 1; i <= N; i++)
			dist[i] = INF;
	dist[s] = 0;
	fila.push(make_pair(0, s));
	while(!fila.empty())
	{
		w = -fila.top().first;
		u = fila.top().second;
		fila.pop();
		if(w > dist[u])
			continue;
		for(int i = 0; i < (int)G[u].size(); i++)
		{
			v = G[u][i];
			w = W[u][i];
			
			if (adj[u][v] == 1 && adj[v][u] == 1)
			{
				w = 0;
			}
			
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				fila.push(make_pair(-dist[v], v));
			}
		}
	}
}


int main() 
{

	while (scanf("%d%d", &N, &E), N + E)
	{
		
		for (int i = 1; i < N + 1; i++)
		{
			G[i].clear();
			W[i].clear();
		}
		
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				adj[i][j] = adj[j][i] = 0;
			}
			
		}
		
		int u, v, u2v;
		for (int i = 0; i < E; i++)
		{
			scanf("%d%d%d", &u, &v, &u2v);
			G[u].pb(v);
			W[u].pb(u2v);
			
			adj[u][v] = 1;
		}
		
		
		int K;
		scanf("%d", &K);
		for (int i = 0; i < K; i++)
		{
			scanf("%d%d", &u, &v);
			dijkstra(u);
			
			if (dist[v] != INF)
			{
				printf("%d\n", dist[v]);
			}
			else
			{
				printf("Nao e possivel entregar a carta\n");
			}
		}
		
		
		printf("\n");
		
	}

	return 0;
}
