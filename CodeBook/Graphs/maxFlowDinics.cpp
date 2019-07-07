/*
 * min(O(V^2E), O(flow*E))
 *
 * Setar V
 * Resetar/Setar edge_list no tamanho de V
 * Usar put_edge para ligar os vertices
 * */

#define INF 1000000000

struct edge{
    int dest;
    int capacity;
    int cancel_edge; // id da reverse edge associada

    edge(int x, int y, int z) : dest(x), capacity(y), cancel_edge(z){}
};

int V;
vi next_neighbor;
vi dist;
vector<vector<edge>> edge_list;

void put_edge(int u, int v, int capacity)
{
    edge_list[u].push_back(edge(v, capacity, edge_list[v].size()));
    edge_list[v].push_back(edge(u, 0, edge_list[u].size() - 1));
}

void put_edge_undirected(int u, int v, int capacity)
{
    edge_list[u].push_back(edge(v, capacity, edge_list[v].size()));
    edge_list[v].push_back(edge(u, capacity, edge_list[u].size() - 1));
}

bool bfs(int source, int target) {

    queue<int> q;
    q.push(source);

    dist.assign(V, INF);
    dist[source] = 0;

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        // se a bfs chega no sorvedouro podemos retornar porque os vertices que nao estao no menor caminho para o sorvedouro nao importam
        if (u == target) { return true; }

        for(auto &e : edge_list[u]) {

            if(e.capacity > 0 && dist[e.dest] == INF) { // percorre todas as arestas que ainda podem passar fluxo

                dist[e.dest] = dist[u] + 1;
                q.push(e.dest);

            }
        }
    }


    return false;
}

int dfs(int u, int flow, int target)
{
    if (u == target) {
        return flow; // encontramos um caminho aumentante
    }

    for (int &i = next_neighbor[u]; i < edge_list[u].size(); i++) { //ignora arestas ja percorridas
    
        edge &e = edge_list[u][i];

        if (dist[u] + 1 == dist[e.dest] && e.capacity > 0) { // so queremos as arestas que fazem parte de um caminho minimo e podem passar fluxo
        
            int rec_flow = dfs(e.dest, min(flow, e.capacity), target);

            if (rec_flow == 0) { continue; }

            e.capacity -= rec_flow; // Passa fluxo pelo caminho aumentante encontrado.
            edge_list[e.dest][e.cancel_edge].capacity += rec_flow; // Essa linha nao afeta as proximas iteracoes da dfs porque a aresta reversa nao esta em um caminho minimo.

            return rec_flow;
        }

    }


    dist[u] = INF; // Se chegou aqui, esgotou-se as opcoes para esse vertice, vamos marca-lo como inutil
    return 0;
}

long long dinic(int source, int target) {

    ll flow = 0;
	V = edge_list.size();

    while (bfs(source, target)) {

        next_neighbor.assign(V, 0);
        while (int path_flow = dfs(source, INF, target)) {
            flow += path_flow;

        }
        
    }

    return flow;
}
