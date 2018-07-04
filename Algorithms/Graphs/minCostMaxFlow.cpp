/*
 *
 * O(kVE^2) ???
 *
 * Carece de maiores testes
 *
 * Setar V
 * Resetar/Setar edge_list no tamanho de V
 * Usar put_edge para ligar os vertices
 *
 *
 * Esse algoritmo tambem funciona para redes de transporte (vertices com demandas), mas lembre-se:
 *      * Se a soma das demandas não for zero, crie um vertice dummy que a zere
 *      * Crie um source e um sink, O source eh ligado a todo vertice de demanda positiva (e fornece a mesma para eles)
 *        e o sink eh ligado a todo vertice de demanda negativa (e suga a mesma deles)
 *
 * */


#define INF 1000000000

struct Edge{
    int dest;
    int capacity;
    int cost;
    int cancel_edge; // id da reverse edge associada

    Edge(int x, int y, int c, int z) : dest(x), capacity(y), cost(c), cancel_edge(z){}
};

vector<vector<Edge>> edge_list;
int V;

void put_edge(int u, int v, int capacity, int cost) {

    edge_list[u].push_back(Edge(v, capacity, cost, edge_list[v].size()));
    edge_list[v].push_back(Edge(u, 0, -cost, edge_list[u].size() - 1));
}

int augment(int v, vi &parent, vi &prev_edge, int minEdge) {

    if (parent[v] == -1) {
        return minEdge;

    } else {

        int u = parent[v];
        Edge &edge = edge_list[u][prev_edge[v]];

        int curr_flow = augment(u, parent, prev_edge, min(minEdge, edge.capacity));

        edge.capacity -= curr_flow;
        edge_list[v][edge.cancel_edge].capacity += curr_flow;

        return curr_flow;

    }
}

int max_flow(int source, int target) {

    int max_flow = 0;

    int source_flow = 0;
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

    return max_flow;

}
