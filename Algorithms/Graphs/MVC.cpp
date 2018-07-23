/*
 * O(V + E)  // Mas o algoritmo aumentador eh O(VE)
 *
 * Setar o vetor match com algoritmo aumentador
 *
 * MVC = Vertices a esquerda nao visitados + vertices a direita visitados durante um
 * DFS alternado em um MCBM
*/

#define LEFT_TYPE 0
#define RIGHT_TYPE 1

vector<vi> vet_adj;
vi match;
vi matched; // will track left vertex that did not matched
vi visited;
int V_left, V_right, N;

void alternate_dfs_aux(int u, int type) {

    if (type == LEFT_TYPE) {

        for (auto v : vet_adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                alternate_dfs_aux(v, RIGHT_TYPE);
            }
        }

    } else {

        if (!visited[match[u]]) {
            visited[match[u]] = 1;
            alternate_dfs_aux(match[u], LEFT_TYPE);
        }

    }

}

void alternate_dfs() {

    visited.assign(V_left + V_right, 0);

    for (int i = 0; i < V_left; ++i) {
        if (!matched[i]) {
            visited[i] = 1;
            alternate_dfs_aux(i, LEFT_TYPE);
        }
    }
}

vi min_vertex_cover() {

    match.assign(V_left + V_right, -1);
    for (int l = 0; l < V_left; l++) {
        visited.assign(V_left, 0);
        aug(l);
    }

    matched.assign(V_left, 0);
    for (int u : match) {
        if (u != - 1) {
            matched[u] = 1;
        }
    }

    alternate_dfs();

    vi result;

    for (size_t i = 0; i < V_left; i++) {
        if (!visited[i]) {
            result.pb(i);
        }
    }

    for (size_t i = 0; i < V_right; i++) {
        if (visited[i + V_left]) {
            result.pb(i + V_left);
        }
    }

    return result;
}
