/*
	Setar V_left e V_right
	Nao usar o vertice 0, pois esse sera o vertice dummy do algoritmo
	Inserir arestas no grafo sempre da esquerda para a direita.
*/
 
#define INF 1000000000
 
vector<vi> vet_adj;
int V_left, V_right;
 
vi match;
vi dist;
 
bool bfs() {
 
    queue<int> q;
    dist.assign(V_left + V_right + 1, INF);
 
    // comeca um BFS a partir de todo vertice livre (i.e. p[u] == 0) da esquerda
    for (int i = 1; i <= V_left; i++) {
        if (match[i] == 0) {
            dist[i] = 0;
            q.push(i);
        }
    }
 
    while(!q.empty()) {
 
        int u = q.front();
        q.pop();
 
        if (u == 0) { return true; } // cheguei no dummy, significa que cheguei em alguem na direita sem match
 
        for(auto &v : vet_adj[u]) {
 
            if (dist[match[v]] == INF) { // perceba que usamos o vetor match para descobrir caminhos alternados
 
                q.push(match[v]);
                dist[match[v]] = dist[u] + 1;
 
            }
        }
 
    }
 
    return false;
}
 
bool dfs(int u) {
 
    if (u == 0) { return true; } // cheguei no dummy, significa que cheguei em alguem na direita sem match
 
 
    for(auto &v : vet_adj[u]) {
 
        if (dist[u] + 1 == dist[match[v]]) {
            if (dfs(match[v])) {
 
                match[u] = v;
                match[v] = u;
 
                return true;
            }
        }
 
    }
 
 
    // Se chegou aqui, o vertice u nao tem mais caminhos para oferecer, entao ja invalidamos ele
    dist[u] = INF;
    return false;
}
 
int hopcroft() {
 
    match.assign(V_left + V_right + 1, 0);
    int matching = 0;
    while (bfs()) {
 
        for (int i = 1; i <= V_left; i++) {
 
            if (match[i] == 0) {
 
                if (dfs(i)) {
                    matching++;
                }
 
            }
 
        }
 
    }
 
    return matching;
}

