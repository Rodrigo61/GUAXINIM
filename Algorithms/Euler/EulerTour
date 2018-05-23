bool checkParity()
bool checkConnectivity()

void euler_tour (int u, list<int>::iterator it) {

    deb("u = ", u);
    deb("vet_adj[u].size() = ", vet_adj[u].size());
    while (!vet_adj[u].empty()) {
        int v = *vet_adj[u].begin();
        deb("v = ", v);
        vet_adj[u].erase(find(all(vet_adj[u]), v));
        vet_adj[v].erase(find(all(vet_adj[v]), u));
        euler_tour(v, tour_list.insert(it, v));
    }

}
