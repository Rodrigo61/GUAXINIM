/*
	Setar V e vet_adj.
	Alterar funcao para retornar as bridges
*/

int V;
vector<set<int>> vet_adj;
// int bridge_edge[][]

void aux_AP_and_bridges(int u, int &dfs_time, int root_dfs, vi &discovery_time, vi &lowest_discovery_reachable,
                        vi &articulation_vertex, vi &parent) {


    lowest_discovery_reachable[u] = ++dfs_time;
    discovery_time[u] = lowest_discovery_reachable[u];

    int root_dfs_children = 0;

    for (auto v : vet_adj[u]) {
        if (discovery_time[v] == 0) {
            parent[v] = u;

            if (u == root_dfs) {  // Tratando caso raiz do DFS
                root_dfs_children++;

                if (root_dfs_children > 1) {
                    articulation_vertex[u] = 1;
                }
            }

            aux_AP_and_bridges(v, dfs_time, root_dfs, discovery_time, lowest_discovery_reachable,
                               articulation_vertex, parent);

            if (u != root_dfs && lowest_discovery_reachable[v] >= discovery_time[u]) {
                articulation_vertex[u] = 1;
            }

            // FOR bridge
            //	if (lowest_discovery_reachable[v] > discovery_time[u])
            //		bridge_edge[u][v] = briged_edge[v][u] = true;

            lowest_discovery_reachable[u] = min(lowest_discovery_reachable[u], lowest_discovery_reachable[v]);
        } else if (v != parent[u]) {
            lowest_discovery_reachable[u] = min(lowest_discovery_reachable[u], discovery_time[v]);
        }
    }
}

void AP_and_bridges(vi &articulation_vertex) {

    articulation_vertex.clear();
    articulation_vertex.resize(V);

    vi discovery_time(V, 0);
    vi lowest_discovery_reachable(V);
    vi parent(V, 0);
    int dfs_time = 0;

    aux_AP_and_bridges(0, dfs_time, 0, discovery_time,
                       lowest_discovery_reachable, articulation_vertex, parent);
}


