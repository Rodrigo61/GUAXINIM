/*
 * O(V + E)
 * Setar vet_adj, escolher u inicial como vertice de grau impar.
 *
 * Eh importante checar se o grafo eh conexo e se comtem 0 ou 2 vertices de grau impar.
 *
 */

bool checkParity()
bool checkConnectivity()

void euler_tour (int u, list<int>::iterator it) {

    while (!vet_adj[u].empty()) {
        int v = *vet_adj[u].begin();
        vet_adj[u].erase(find(all(vet_adj[u]), v));
        vet_adj[v].erase(find(all(vet_adj[v]), u));
        euler_tour(v, tour_list.insert(it, v));
    }

}
