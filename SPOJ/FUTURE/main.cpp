#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define db(x) //cerr << #x << " = " << x << endl;
#define int long long
#define INF (ll)100000000

struct Edge{
    int dest;
    ll capacity;
    ll max_capacity;
    ll cost;
    int cancel_edge; // id da reverse edge associada

    Edge(int x, ll y, ll c, int z) : dest(x), capacity(y), max_capacity(y), cost(c), cancel_edge(z){}
};

vector<vector<Edge>> edge_list;
int V;

void put_edge(int u, int v, ll capacity, ll cost) {

    edge_list[u].push_back(Edge(v, capacity, cost, edge_list[v].size()));
    edge_list[v].push_back(Edge(u, 0, -cost, edge_list[u].size() - 1));
}

ll augment(int v, vi &parent, vi &prev_edge, ll minEdge) {

    if (parent[v] == -1) {
        return minEdge;

    } else {

        int u = parent[v];
        Edge &edge = edge_list[u][prev_edge[v]];

        ll curr_flow = augment(u, parent, prev_edge, min(minEdge, edge.capacity));

        edge.capacity -= curr_flow;
        edge_list[v][edge.cancel_edge].capacity += curr_flow;

        return curr_flow;

    }
}

pair<ll, ll> mcmf(int source, int target) {

    ll max_flow = 0;

    ll source_flow = 0;
    for (auto &edge : edge_list[source]) {
        source_flow += edge.capacity;
    }

    while (true) {

        vi dist(V, INF);
        dist[source] = 0;
        vi parent(V, -1);
        vi prev_edge(V, -1);
        vi in_queue(V, 0);

        queue<int> q;
        q.push(source);
        in_queue[source] = 1;

        //SPFA
        while (!q.empty()) {

            int u = q.front();
            q.pop();
            in_queue[u] = 0;

            for (int e = 0; e < edge_list[u].size(); ++e) {

                auto &edge  = edge_list[u][e];
                int v = edge.dest;

                if (edge.capacity > 0 && dist[u] + edge.cost < dist[v]) {

                    dist[v] = dist[u] + edge.cost; // relax
                    parent[v] = u;
                    prev_edge[v] = e;

                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = 1;
                    }

                }
            }
        }


        if (dist[target] != INF) {
            max_flow += augment(target, parent, prev_edge, INF);
        } else {
            break;
        }
    }
        
	ll cost = 0;
	for (int i = 0; i < V; i++)
	{
		for (auto &edge : edge_list[i])
		{
			if (edge.cost > 0)
			{
				cost += edge.cost * (edge.max_capacity - edge.capacity);
			}
		}
	}

    return {max_flow, cost};
}


main()
{
	
	int M;
	
	vector<pair<pair<int, int>, int>> input;
	int n_cases = 0;
	while (scanf("%lld%lld", &V, &M) != EOF)
	{
		
		db(V);
		db(M);
		
		printf("Instancia %lld\n", ++n_cases);
		input.clear();
		input.resize(M);
		for (int i = 0; i < M; i++)
		{
			scanf("%lld%lld%lld", &input[i].first.first, &input[i].first.second, &input[i].second);
			input[i].first.first--;
			input[i].first.second--;
			db(input[i].first.first);
		}
		db(input.size());
		
		int D, K;
		scanf("%lld%lld", &D, &K);
		
		edge_list.clear();
		edge_list.resize(V + 1);
		
		put_edge(0, V, D, 0);
		
		for (auto &p : input)
		{
			int u = p.first.first;
			int v = p.first.second;
			int c = p.second;
			
			db(u);
			db(v);
			db(c);
			
			if (u == 0)
			{
				put_edge(V, v, K, c);
			}
			else
			{
				put_edge(u, v, K, c);
			}
			
			if (v == 0)
			{
				put_edge(V, u, K, c);
			}
			else
			{
				put_edge(v, u, K, c);
			}
			
				
		}
		
		V++;
		
		auto ans = mcmf(0, V - 2);
		
		if (ans.first == D)
		{
			printf("%lld\n\n", ans.second);
			
		}
		else
		{
			printf("impossivel\n\n");
		}
		
	}
	
	return 0;
}
