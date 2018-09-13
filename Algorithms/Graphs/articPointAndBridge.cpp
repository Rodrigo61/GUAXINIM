/*
	Algoritmo de tarjan, utilizamos dois marcadores para os vertices: ldr(lowest_discovery_reachable) e dt(discovery_time).
	
	[COMPLEX] O(V + E)
	[USAGE]
		[INIT] Setar V e vet_adj.
		[MODES] Alterar funcao para retornar as bridges.
	[OUT]
		O vetor articulation_vertex terá os indices de todos os vértices que forem AP
		A matriz bridge_edge[i][j] terá valor 1 se a aresta (i,j) for uma bridge
*/

int V;
vector<set<int>> vet_adj;
vi articulation_vertex;
// int bridge_edge[][]

void aux_AP_and_bridges(int u, int &dfs_time, int root_dfs, vi &dt, vi &ldr, vi &parent) {


    ldr[u] = ++dfs_time;
    dt[u] = ldr[u];

    int root_dfs_children = 0;

    for (auto v : vet_adj[u]) {
        if (dt[v] == 0) {
            parent[v] = u;

            if (u == root_dfs) {  // Tratando caso raiz do DFS
                root_dfs_children++;

                if (root_dfs_children > 1) {
                    articulation_vertex[u] = 1;
                }
            }

            aux_AP_and_bridges(v, dfs_time, root_dfs, dt, ldr, parent);

            if (u != root_dfs && ldr[v] >= dt[u]) {
                articulation_vertex[u] = 1;
            }

            // To set bridges
            //	if (ldr[v] > dt[u])
            //		bridge_edge[u][v] = briged_edge[v][u] = true;

            ldr[u] = min(ldr[u], ldr[v]);
        } else if (v != parent[u]) {
            ldr[u] = min(ldr[u], dt[v]);
        }
    }
}

void AP_and_bridges() {

    articulation_vertex.clear();
    articulation_vertex.resize(V);

    vi dt(V, 0);
    vi ldr(V);
    vi parent(V, 0);
    int dfs_time = 0;

    aux_AP_and_bridges(0, dfs_time, 0, dt, ldr, parent);
}


