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

 
#define INF 1000000000
 
vector<vi> vet_adj;
int V_left, V_right;
 
vi match;
vi dist;
 
bool bfs() {
 
    queue<int> q;
    dist.assign(V_left + V_right + 1, INF);
 
    // comeca um BFS a partir de todo vertice livre (i.e. p[u] == 0) da esquerda
    for (int i = 1; i <= V_left; i++) {
        if (match[i] == 0) {
            dist[i] = 0;
            q.push(i);
        }
    }
 
    while(!q.empty()) {
 
        int u = q.front();
        q.pop();
 
        if (u == 0) { return true; } // cheguei no dummy, significa que cheguei em alguem na direita sem match
 
        for(auto &v : vet_adj[u]) {
 
            if (dist[match[v]] == INF) { // perceba que usamos o vetor match para descobrir caminhos alternados
 
                q.push(match[v]);
                dist[match[v]] = dist[u] + 1;
 
            }
        }
 
    }
 
    return false;
}
 
bool dfs(int u) {
 
    if (u == 0) { return true; } // cheguei no dummy, significa que cheguei em alguem na direita sem match
 
 
    for(auto &v : vet_adj[u]) {
 
        if (dist[u] + 1 == dist[match[v]]) {
            if (dfs(match[v])) {
 
                match[u] = v;
                match[v] = u;
 
                return true;
            }
        }
 
    }
 
 
    // Se chegou aqui, o vertice u nao tem mais caminhos para oferecer, entao ja invalidamos ele
    dist[u] = INF;
    return false;
}
 
int hopcroft() {
 
    match.assign(V_left + V_right + 1, 0);
    int matching = 0;
    while (bfs()) {
 
        for (int i = 1; i <= V_left; i++) {
 
            if (match[i] == 0) {
 
                if (dfs(i)) {
                    matching++;
                }
 
            }
 
        }
 
    }
 
    return matching;
}

int vertex_id[100001];
char vertex_sex[100001];

#define MAXN (int)1e6
int isprime[MAXN+1];
vi primos;
vi valores[MAXN + 1];

void crivo()
{
	primos.push_back(2);
	for(int i = 2; i <= MAXN; i += 2)
	{
		isprime[i] = 1;
		valores[i].pb(2);
	}
	for(int i = 3; i <= MAXN; i += 2)
	{
		if(!isprime[i])
		{
			primos.push_back(i);
			for(int j = i; j <= MAXN; j += i)
			{
				isprime[j] = 1;
				valores[j].pb(i);
			}
		}	
	}
}

int main() 
{
	
	int T;
	scanf("%d", &T);
	crivo();
	
	while (T--)
	{
		int N;
		scanf("%d", &N);
		
		V_left = V_right = 0;
		
		vi vals(N);
		vector<char> sex(N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d%*c", &vals[i]);
		}
		for (int i = 0; i < N; i++)
		{
			scanf("%c%*c", &sex[i]);
			
			if (sex[i] == 'M')
			{
				++V_left;
			}
			else
			{
				++V_right;
			}
		}
		
		//~ print_vector_debug(vals);
		//~ print_vector_debug(sex);
		
		db(V_left);
		db(V_right);
		
		
		int l_id = 1, r_id = V_left + 1;
		vector<char> real_sex(N);
		for (int i = 0; i < N; i++)
		{
			vertex_id[i] = sex[i] == 'M' ? l_id++: r_id++;
			vertex_sex[vertex_id[i]] = sex[i] == 'M' ? 'M': 'F';
		}
		
		db(l_id);
		db(r_id);
		
		vet_adj.clear();
		vet_adj.resize(N + 1);
		
		vector<vi> lprimos(MAXN + 1);
		for (int i = 0; i < N; i++)
		{
			db(vals[i]);
			for(int p : valores[vals[i]])
			{
				lprimos[p].pb(vertex_id[i]);
			}
		}
		
				
		for(int i : primos)
		{
			if (lprimos[i].size() == 2)
			{
				int u = lprimos[i][0];
				int v = lprimos[i][1];
				db(u);
				db(v);
				if (vertex_sex[u] != vertex_sex[v])
				{
					vet_adj[u].pb(v);
					vet_adj[v].pb(u);
				}
			}
		}
		
		db(V_left + V_right);
		printf("%d\n", V_left + V_right - hopcroft());
		
	}

	return 0;
}
