/*
 * min(O(VE^2), O(flow*E))
 *
 * Setar V
 * Resetar/Setar edge_list no tamanho de V
 * Usar put_edge para ligar os vertices
 * */

#define INF 1000000000

struct Edge{
    int dest;
    ll capacity;
    int cancel_edge; // id da reverse edge associada

    Edge(int x, ll y, int z) : dest(x), capacity(y),  cancel_edge(z){}
};

vector<vector<Edge>> edge_list;
int V;

void put_edge(int u, int v, ll capacity) {

    edge_list[u].push_back(Edge(v, capacity, edge_list[v].size()));
    edge_list[v].push_back(Edge(u, 0, edge_list[u].size() - 1));

}

void put_edge_undirected(int u, int v, ll capacity) {

    edge_list[u].push_back(Edge(v, capacity, edge_list[v].size()));
    edge_list[v].push_back(Edge(u, capacity, edge_list[u].size() - 1));

}

ll augment(int v, vi &prev_vertex, vi &prev_edge, ll min_edge) {

    if (prev_vertex[v] == -1) {

        return min_edge;

    } else {

        int u = prev_vertex[v];
        Edge &edge = edge_list[u][prev_edge[v]];

        ll curr_flow = augment(u, prev_vertex, prev_edge, min(min_edge, edge.capacity)); // recursive

        edge.capacity -= curr_flow;
        edge_list[v][edge.cancel_edge].capacity += curr_flow;

        return curr_flow;

    }

}

ll max_flow(int source, int target) {

    ll max_flow = 0;

    while (true) {

        vi dist(V, INF);
        queue<int> q;
        vi prev_vertex(V, -1);
        vi prev_edge(V, -1);

        dist[source] = 0;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == target) { break; }

            for (int i = 0; i < edge_list[u].size(); ++i) {
                auto &edge = edge_list[u][i];

                if (edge.capacity > 0 && dist[edge.dest] == INF) {

                    dist[edge.dest] = dist[u] + 1;
                    q.push(edge.dest);

                    prev_vertex[edge.dest] = u;
                    prev_edge[edge.dest] = i;
                }
            }
        }

        if (dist[target] != INF) {
            max_flow += augment(target, prev_vertex, prev_edge, INF);
        } else {
            break;
        }
    }

    return max_flow;

}

