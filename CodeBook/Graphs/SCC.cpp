/*
 *  O (V + E)
 *
 *  Setar V e vet_adj
 *  Resposta : vetor SCC contem as componentes.
 */

int V;
vector<set<int>> vet_adj;

void SCC_aux(int u, int &dfs_time, vi &visited, vi &visit_order, vi &discovery_time, vi &lowest_discovery_reachable, vector<vi> &SCCs) {

    discovery_time[u] = ++dfs_time;
    lowest_discovery_reachable[u] = discovery_time[u];

    visit_order.push_back(u);

    visited[u] = 1;

    for (auto v : vet_adj[u]) {

        if (discovery_time[v] == 0) {
            SCC_aux(v, dfs_time, visited, visit_order, discovery_time, lowest_discovery_reachable, SCCs);
        }

        if (visited[v]) {
            lowest_discovery_reachable[u] = min(lowest_discovery_reachable[u], lowest_discovery_reachable[v]);
        }
    }


    if (discovery_time[u] == lowest_discovery_reachable[u]) {

        vi new_scc;
        SCCs.pb(new_scc);
        int v;

        do {
            v = visit_order.back();
            visit_order.pop_back();
            visited[v] = 0;
            SCCs.back().pb(v);
        } while (u != v);

    }

}

void SCC(vector<vi> &SCCs) {

    SCCs.clear(); // Para recuperar de fato o cada SCC

    vi visit_order;

    vi discovery_time(V, 0);
    vi lowest_discovery_reachable(V, 0);

    vi visited(V, 0);
    int dfs_time = 0;


    for (int i = 0; i < V; ++i) {
        if (discovery_time[i] == 0) {
            SCC_aux(i, dfs_time, visited, visit_order, discovery_time, lowest_discovery_reachable, SCCs);
        }
    }

}
