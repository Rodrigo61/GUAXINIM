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

#define MAXN 110
#define INF 1e18

int N;
map<string, int> name2id;
map<int, string> id2name;
ll dist[MAXN][MAXN];

int main() 
{
	
	int tc = 0;
	while (scanf("%d\n", &N), N)
	{
		
		printf("Case #%d:\n", ++tc);
		int id = 0;
		char aux[30];
		string name;
		
		name2id.clear();
		id2name.clear();
		
		
		for (int i = 0; i < N; i++)
		{
			scanf("%s ", aux);
			name = aux;
			
			name2id[name] = id;
			id2name[id] = name;
			++id;
			
			ll d;
			for (int j = 0; j < N; j++)
			{
				scanf("%lld", &d);
				dist[i][j] = d;
				
				if (dist[i][j] == 0)
				{
					dist[i][j] = INF;
				}
				
			}
			scanf("\n");
		}
		//~ for (int i = 0; i < N; i++)
		//~ {
			//~ for (int j = 0; j < N; ++j)
			//~ {
				//~ printf("%lld ", dist[i][j]);
			//~ }
			//~ printf("\n");
		//~ }
		
		for (int k = 0; k < N; ++k)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; ++j)
				{
					if (dist[i][k] < INF && dist[k][j] < INF)
							dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		
		
		//~ for (int i = 0; i < N; i++)
		//~ {
			//~ for (int j = 0; j < N; ++j)
			//~ {
				//~ printf("%lld ", dist[i][j]);
			//~ }
			//~ printf("\n");
		//~ }
		//~ printf("\n");
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; ++j)
			{
				for (int t = 0; t < N; ++t)
				{
					if (dist[t][t] < 0 && dist[i][t] != INF && dist[t][j] != INF)
					{
						dist[i][j] = -INF;
					}
					
				}
			}
		}
		
		int Q;
		scanf("%d\n", &Q);
		int u, v;
		for (int i = 0; i < Q; i++)
		{
			scanf("%d%d\n", &u, &v);
			
			if (dist[u][v] == -INF)
			{
				printf("NEGATIVE CYCLE\n");
			}
			else if (dist[u][v] == INF && u != v)
			{
				printf("%s-%s NOT REACHABLE\n", id2name[u].c_str(), id2name[v].c_str());
			}
			else
			{
				printf("%s-%s %lld\n", id2name[u].c_str(), id2name[v].c_str(), dist[u][v] > 0 && u == v ? 0: dist[u][v]);
			}
			
			
		}
		
	}
	
	return 0;
}
