/*
 * Nao testado
 *
 * Setar V e vet_adj
 * A resposta eh dada no vetor global dist
 *
 * */


vi dist;
int V;
vector<vii> vet_adj;

void SPFA(int source) {

        dist.assign(V, INF);
        dist[source] = 0;

        vi in_queue(V, 0);
        queue<int> q;

        q.push(source);
        in_queue[source] = 1;


        while (!q.empty()) {

            int u = q.front();
            q.pop();
            in_queue[u] = 0;

            for (auto &edge : vet_adj[u]) {

                int v = edge.first;
                int u2v = edge.second;

                if (dist[u] + u2v < dist[v]) {

                    dist[v] = dist[u] + u2v; // relax

                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = 1;
                    }

                }
            }
        }
}
