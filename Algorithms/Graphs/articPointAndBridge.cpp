/*
	Aqui utilizamos o algoritmo de Tarjan (DFS) para encontrar os articulation points (APs) e as bridges.

	A ideia é manter 2 atributos para cada vértice: discovery_time e lowest_discovery_reachable.
	
	O atributo discovery_time[u] de um vértice u nos diz em qual iteracao do DFS o vértice u foi visitado pela primeira vez. Já o atributo lowest_discovery_reachable[u] nos diz qual o menor discovery_time[w] de um vértice w qualquer que é alcancavel por u.

	A ideia do algoritmo, depois de computar esses valores, é dizer que:

		* u é um AP se existir um vizinho v, tal que lowest_discovery_reachable[v] >= discovery_time[u].
			Ou u é um AP se ele for o vértice raiz do DFS e tiver mais de um filho na arvore DFS.

		* u->v é uma bridge sse lowest_discovery_reachable[v] > discovery_time[u] (perceba que n é >=).
			Ou u é o vertice raiz do DFS e tem mais de um filho na arvore DFS.

	Perceba que se lowest_discovery_reachable[v] >= discovery_time[u], isso significa que v não alcancava nenhum vertice w tal que discovery_time[w] < discovery_time[u]. Ou seja, se pensarmos na subarvore DFS onde u é a raiz, entao v nao consegue se conectar com ninguem que venha antes de u. Logo, se cortarmos u, v ficará isolado de tais vértices.
	Claro que, se nao existirem tais vértices anteriores a u isso nao será verdade. Essa situacao ocorre justamente quando u é a raiz de toda a DFS, pois ai nao existem ancestrais a ele. Mas nesse caso, podemos verificar se u é um AP trivialmente checando se ele tem mais de um filho na árvore DFS.
	Para explicar o porque usamos '>' inves de '>=' na busca pelas pontes, basta imaginar a mesma árvore DFS. Se tivermos lowest_discovery_reachable[v] = discovery_time[u], entao significa que v é tem 2 caminhos até u, entao cortar u->v nao o desconecta. Mas se lowest_discovery_reachable[v] > discovery_time[u], entao para v se conectar com qualquer vértice ancestral à u ele precisa necessariamente passar por u->v.
*/

int V;
vector<set<int>> vet_adj;

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



/ * Usage */
int main() {


	...
	vet_adj
	...


	vi articulation_vertex(V);
	AP_and_bridges(articulation_vertex);
}
