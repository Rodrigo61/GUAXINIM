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
int N;

void put_edge(int u, int v, ll capacity, ll cost) {

    edge_list[u].push_back(Edge(v, capacity, cost, edge_list[v].size()));
    edge_list[v].push_back(Edge(u, 0, -cost, edge_list[u].size() - 1));
}

ll augment(int v, vi &parent, vi &prev_edge, ll minEdge) {

	db("x");
    if (parent[v] == -1) {
        return minEdge;

    } else {

		db("x1");
        int u = parent[v];
        Edge &edge = edge_list[u][prev_edge[v]];
		db("x2");
		db(u);
		db(edge.capacity);
		db(min(minEdge, edge.capacity));
        ll curr_flow = augment(u, parent, prev_edge, min(minEdge, edge.capacity));
		db("x3");
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

	db("a");
    while (true) {
		db("b");
        vi dist(N, INF);
        dist[source] = 0;
        vi parent(N, -1);
        vi prev_edge(N, -1);
        vi in_queue(N, 0);

        queue<int> q;
        q.push(source);
        in_queue[source] = 1;

        //SPFA
        while (!q.empty()) {
			db("c");
            int u = q.front();
            q.pop();
            in_queue[u] = 0;

            for (int e = 0; e < (int)edge_list[u].size(); ++e) {

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
		db("d");

        if (dist[target] != INF) {
            max_flow += augment(target, parent, prev_edge, INF);
        } else {
            break;
        }
        db("e");
    }
        
	ll cost = 0;
	for (int i = 0; i < N; i++)
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



int main() 
{
	
	while (scanf("%d", &N), N)
	{
		int M;
		scanf("%d", &M);
		
		++N;
		edge_list.clear();
		edge_list.resize(N);
		
		int u, v, u2v;
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &u, &v, &u2v);
			put_edge(u, v, 1, u2v);
			put_edge(v,u, 1, u2v);
		}
		put_edge(0,1, 2, 0);
		db("d1");
		
		auto res = mcmf(0, N-1);
		db("d2");
		
		if (res.first == 2)
		{
			printf("%lld\n", res.second);
		}
		else
		{
			printf("Back to jail\n");
		}
		
	}

	return 0;
}
