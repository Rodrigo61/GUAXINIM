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

#define SIDE_A 0
#define SIDE_B 1 
#define MAXN 100001
#define INF 1001001001
using namespace std;

vector<pair<int, int>> G[MAXN];

int N, M;
int dist[MAXN];
int ds[MAXN], dt[MAXN];
int end_time[MAXN], beg_time[MAXN];
int time2vertex[MAXN];
int curr_time;
vector<vector<int>> tree;
vi parent;
set<pair<int, pii>> vet_edges;

int vertex_side[MAXN];

int just_added[MAXN];

void ett(int u)
{
	beg_time[u] = curr_time;

	for (int v : tree[u])
	{
		ett(v);
	}
	
	time2vertex[curr_time] = u;
	end_time[u] = curr_time;
	++curr_time;
	
}

void dijkstra(int s)
{
	int u, v, w;
	priority_queue<pair<int, int> > fila;
	for(int i = 1; i <= N; i++)
			dist[i] = INF;
	dist[s] = 0;
	fila.push(make_pair(0, s));
	
	parent.clear();
	parent.resize(N + 1);
	tree.clear();
	tree.resize(N + 1);
	
	while(!fila.empty())
	{
		w = -fila.top().first;
		u = fila.top().second;
		fila.pop();
		
		if(w > dist[u])
			continue;
			
		tree[parent[u]].pb(u);
			
		for (auto &edge : G[u])
		{
			v = edge.first;
			w = edge.second;
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				parent[v] = u;
				fila.push(make_pair(-dist[v], v));
			}	
		}
	}
}

int climb_up(int curr_root)
{
	int new_root = parent[curr_root];
	
	int added = 0;
	
	for (int i = beg_time[new_root]; i < beg_time[curr_root]; ++i)
	{
		vertex_side[time2vertex[i]] = SIDE_B;
		
		just_added[added] = time2vertex[i];
		++added;
	}
	
	for (int i = end_time[curr_root] + 1; i <= end_time[new_root]; ++i)
	{
		vertex_side[time2vertex[i]] = SIDE_B;
		just_added[added] = time2vertex[i];
		++added;
	}
	
	for (int i = 0; i < added; i++)
	{
		int u = just_added[i];
		for (int j = 0; j < (int)G[u].size(); ++j)
		{
			int v = G[u][j].first;
			int u2v = G[u][j].second;
			
			if (vertex_side[v] == SIDE_A)
			{
				vet_edges.insert({ds[v] + dt[u] + u2v, {v, u}});
			}
		}
	}
	
	return new_root;
}

int get_min_dist(int curr_root)
{
	for (auto it = vet_edges.begin(); it != vet_edges.end();)
	{
		int a = it->second.first;
		int b = it->second.second;
		int dist = it->first;
		
		if ((b == curr_root && a == parent[curr_root]))
		{
			++it;
			continue;
		}
			
		if (vertex_side[a] == SIDE_B)
		{
			it = vet_edges.erase(it);
			continue;
		}
			
		return dist;
	}
	
	return INF;
}


int main() 
{
	scanf("%d%d", &N, &M);
	
	int source, target;
	scanf("%d%d", &source, &target);
	
	int u, v, u2v;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &u, &v, &u2v);
		
		G[u].pb({v, u2v});
		G[v].pb({u, u2v});
	}
	
	dijkstra(target);
	memcpy(dt, dist, sizeof(dist));
	
	dijkstra(source);
	memcpy(ds, dist, sizeof(dist));

	ett(source);
	
	for (int i = 1; i <= N; i++)
	{
		if (end_time[i] >= beg_time[target] && end_time[i] <= end_time[target])
			vertex_side[i] = SIDE_B;
		else
			vertex_side[i] = SIDE_A;
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (vertex_side[i] == SIDE_A)
		{
			for (int j = 0; j < (int)G[i].size(); ++j)
			{
				int v = G[i][j].first;
				int u2v = G[i][j].second;
				
				if (vertex_side[v] == SIDE_B)
				{
					vet_edges.insert({ds[i] + dt[v] + u2v, {i, v}});
				}
			}
		}
	}
	
	int curr_root = target;
	
	int max_dist = 0;
	while (curr_root && curr_root != source)
	{
		db(curr_root);
		max_dist = max(max_dist, get_min_dist(curr_root));
		curr_root = climb_up(curr_root);
	}
	
	if (max_dist == INF)
	{
		max_dist = -1;
	}
	
	printf("%d\n", max_dist);
	return 0;
}
