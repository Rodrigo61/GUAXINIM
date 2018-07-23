/*
 * O (V + E)
 * Setar V e vet_adj
*/

#define INF 1000000000
int V;
vector<vi> vet_adj;

pii bfs_max_dist_and_index(int source) {

    vi dist(V, INF);
    stack<int> stack;

    stack.push(source);
    dist[source] = 0;

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

	return mp(max_dist, max_dist_index);
}

int get_diameter() {

    int max_dist_index = bfs_max_dist_and_index(0).second;
	return bfs_max_dist_and_index(max_dis_index).first;

}
