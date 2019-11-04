#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define sz(x) x.size()

#define MAXN 212

struct V {
	vector<pii> outs;  // (dest vertice idx, edge index)
};

vi adj[MAXN];
int comp[MAXN];
int degree[MAXN];
int vis[MAXN];
set<pii> created_edge;

// Undirected version
int find_src(vector<V>& vertices)
{
	int src = 0;
	for (int i = 0; i < (int)vertices.size(); i++)
	{
		if (sz(vertices[i].outs) & 1)
		{
			src = i;
			break;
		}
		if (sz(vertices[i].outs))
			src = i;
	}

    return src;
}

// Undirected version
bool check_condition(vector<V>& vertices)
{
	int c = 0;
    for (auto &n : vertices)
	    c += (sz(n.outs) & 1);
	return (c == 2 || c == 0);
}


vi euler_tour(vector<V>& vertices, int n_edges, int src = -1) {
	
    if (!check_condition(vertices))
		return {};

    if (src == -1)
    {
        src = find_src(vertices);
    }

    vector<vector<pii>::iterator> its;
    for(auto &n : vertices)
    {
        its.push_back(n.outs.begin());
    }
    
	vector<int> eu(n_edges);
	vi ret, s = {src};
	while(!s.empty()) 
    {
		int x = s.back();
		auto& it = its[x], end = vertices[x].outs.end();

		while(it != end && eu[it->second]) 
            ++it;

		if(it == end) 
        { 
            ret.push_back(x);
            s.pop_back(); 
        }
		else 
        { 
            s.push_back(it->first);
            eu[it->second] = true; 
        }
	}
	if(sz(ret) != n_edges+1)
		ret.clear(); // No Eulerian cycles/paths.
	// else, non-cycle if ret.front() != ret.back()
	reverse(all(ret));
	return ret;
}

void dfs(int u, int color)
{
    vis[u] = 1;
    comp[u] = color;

    for (int v : adj[u])
        if (!vis[v])
            dfs(v, color);
}


int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        
        for (int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
            degree[u]++;
            degree[v]++;
        }

        int color = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i, color);
                color++;
            }
        }
        
        int evens = 0;
        for (int i = 0; i < color; i++)
        {
            vi odds;
            
            for (int j = 1; j <= n; j++)
            {
                if (comp[j] == i)
                {
                    if (degree[j] & 1)
                        odds.pb(j);
                    else
                        ++evens;
                }
            }
            for (int j = 0; j < (int)sz(odds); j += 2)
            {
                adj[odds[j]].pb(odds[j + 1]);
                adj[odds[j + 1]].pb(odds[j]);
                created_edge.insert({min(odds[j], odds[j + 1]), max(odds[j], odds[j + 1])});
            }
        }
        
        printf("%d\n", evens);

        vi vertice_id(n + 1);
        vi id_2_vertice(n + 1);
        for (int i = 0; i < color; i++)
        {
            vector<V> vertices;
            for (int j = 1; j <= n; j++)
            {
                if (comp[j] == i)
                {
                    V u;
                    vertice_id[j] = vertices.size();
                    id_2_vertice[vertices.size()] = j;
                    vertices.pb(u);
                }
            }


            int edge_id = 0;
            for (int j = 1; j <= n; j++)
            {
                if (comp[j] == i)
                {
                    for (int v : adj[j])
                    {
                        if (v > j)
                        {
                            vertices[vertice_id[v]].outs.pb({vertice_id[j], edge_id});
                            vertices[vertice_id[j]].outs.pb({vertice_id[v], edge_id++});
                        }
                        
                    }
                }
            }

            auto res = euler_tour(vertices, edge_id);
            for (int j = 0; j < (int)sz(res) - 1; j++)
            {
                int a = id_2_vertice[res[j]];
                int b = id_2_vertice[res[j + 1]];
                auto it = created_edge.find({min(a, b), max(a, b)});
                if (it == created_edge.end())
                    printf("%d %d\n", a, b);
                else
                    created_edge.erase(it);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = degree[i] = comp[i] = 0;
        }
        created_edge.clear();
        
    }
    
}