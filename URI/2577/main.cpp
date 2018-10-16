#include "bits/stdc++.h"
using namespace std;

#define db(x) cout << #x << " == " << x << endl
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

#define MAXN 100005

int N, M;
ll vals[MAXN];
set<int> adj[MAXN];
int which_comp[MAXN];
ll acu_comp[MAXN];
int articulation_vertex[MAXN];
ll remove_gain[MAXN];
int vis[MAXN];


void acu_component(int u, int comp)
{
	which_comp[u] = comp;
	acu_comp[comp] += vals[u];
	vis[u] = 1;
	
	for (int v : adj[u])
	{
		if (!vis[v])
		{
			acu_component(v, comp);
		}
	}
}


ll aux_AP_and_bridges(int u, int &dfs_time, int root_dfs, vi &dt, vi &ldr, vi &parent) {


    ldr[u] = ++dfs_time;
    dt[u] = ldr[u];

    int root_dfs_children = 0;
	ll sub_tree_acu = vals[u];
	
    for (auto v : adj[u]) {
        if (dt[v] == 0) {	
            parent[v] = u;

            if (u == root_dfs) { 
                root_dfs_children++;

                if (root_dfs_children > 1) {
                    articulation_vertex[u] = 1;
                }
            }

            ll rec = aux_AP_and_bridges(v, dfs_time, root_dfs, dt, ldr, parent);
            
            sub_tree_acu += rec;
            
            if (rec > 0)
				remove_gain[u] += rec;
            
            if (u != root_dfs && ldr[v] >= dt[u]) {
                articulation_vertex[u] = 1;
            }

            ldr[u] = min(ldr[u], ldr[v]);
        } else if (v != parent[u]) {
            ldr[u] = min(ldr[u], dt[v]);
        }
    }
    
    ll above = acu_comp[which_comp[u]] - sub_tree_acu;
    
    if (above > 0)
	{
		if (u == 16)
		{
			db(above);
			db(remove_gain[u]);
		}
		
		remove_gain[u] += above;
	}
	
    return sub_tree_acu;
}

int check_vis[MAXN];

ll dfs_check(int u)
{
	check_vis[u] = 1;
	ll ret = vals[u];
	
	for (int v : adj[u])
	{
		if (!check_vis[v])
			ret += dfs_check(v);
	}
	
	return ret;
}

ll check(int root)
{
	ll res = 0;
	check_vis[root] = 1;
	for (int v : adj[root])
	{
		if (!check_vis[v])
		{
			ll aux = dfs_check(v);
			
			if (aux > 0)
				res += aux;
		}
	}
	
	return res;
}


void AP_and_bridges() {

    vi dt(N + 1, 0);
    vi ldr(N + 1);
    vi parent(N + 1, 0);
    int dfs_time = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (dt[i] == 0)
		{
			dfs_time = 0;
			aux_AP_and_bridges(i, dfs_time, i, dt, ldr, parent);
		}
	}
}

int main() 
{
	scanf("%d%d", &N, &M);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	db("d1");
	
	int u, v;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &u, &v);
		adj[u].insert(v);
		adj[v].insert(u);
	}
	db("d2");
	
	int id = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!vis[i])
		{
			acu_component(i, id++);
		}
	}
	db("d3");
	
	ll total = 0;
	for (int i = 0; i < id; i++)
	{
		if (acu_comp[i] > 0)
		{
			total += acu_comp[i];
		}
	}
	db(total);
	
	AP_and_bridges();
	
	for (int i = 1; i <= N; i++)
	{
		db(i);
		if (articulation_vertex[i])
		{
			db("AP");
			db(remove_gain[i]);
			db(acu_comp[which_comp[i]]);
			
			db(check(i));
			if (acu_comp[which_comp[i]] > 0)
			{
				printf("%lld", total - acu_comp[which_comp[i]] + remove_gain[i]);
			}
			else
			{
				printf("%lld", total + remove_gain[i]);
			}
			
		}
		else
		{
			db("NOT AP");
			if (vals[i] < 0)
			{
				if (acu_comp[which_comp[i]] > 0)
				{
					printf("%lld", total - vals[i]);
				}
				else if (acu_comp[which_comp[i]] - vals[i] > 0)
				{
					printf("%lld", total + (acu_comp[which_comp[i]] - vals[i]));
				}
				else
				{
					printf("%lld", total);
				}
				
			}
			else
			{
				if (acu_comp[which_comp[i]] > 0 && acu_comp[which_comp[i]] - vals[i] <= 0)
				{
					printf("%lld", total - acu_comp[which_comp[i]]);
				}
				else if (acu_comp[which_comp[i]] > 0 && acu_comp[which_comp[i]] - vals[i] > 0)
				{
					printf("%lld", total - vals[i]);
				}
				else
				{
					printf("%lld", total);
				}
				
			}
			
		}
		
		if (i != N)
		{
			printf("\n");
		}
	}

	printf("\n");
	
	return 0;
}
