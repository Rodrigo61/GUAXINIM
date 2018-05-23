#define INF 99999
int V;
vector<vi> vet_adj;

int get_diameter() {

    vi dist(V, INF);

    stack<int> stack;

    stack.push(0);
    dist[0] = 0;

    int max_dist = 0;
    int max_dist_index = 0;

    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();

        for (auto &v : vet_adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                stack.push(v);

                if (dist[v] > max_dist) {
                    max_dist = dist[v];
                    max_dist_index = v;
                }
            }
        }
    }

    fill(all(dist), INF);

    stack.push(max_dist_index);
    dist[max_dist_index] = 0;

    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();

        for (auto &v : vet_adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                stack.push(v);

                if (dist[v] > max_dist) {
                    max_dist = dist[v];
                    max_dist_index = v;
                }
            }
        }
    }

    return max_dist;
}
