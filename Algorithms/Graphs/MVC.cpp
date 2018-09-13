/*
	Algoritmo para recuperar o conjunto de vertices que forma um MVC.
	Lembre-se que MVC = MCBM (dual).
	Esse algoritmo pré-supoem que o MCBM já foi calculado.
	MVC = Vertices a esquerda nao visitados + vertices a direita visitados durante um
		  DFS alternado em um MCBM
	[COMPLEX] O(V + E)
	[USAGE]
		[INIT] Rode algum algoritmo de MCBM. É preciso que se tenha:
					* vi match: Usado para definir qual vertice do lado esquerdo
								se conecta com o vertice i do lado direito.
								OBS: usamos -1 se não há conexao com o vertice i;
					* int V_left & V_right: tamanhos dos respectivos lados
	
	[OUT]
		Retorna um vetor de indices dos vértices que compoem um MVC.
*/

#define LEFT_TYPE 0
#define RIGHT_TYPE 1

vector<vi> vet_adj;
vi match;
int V_left, V_right;

vi matched; // will track left vertex that did not matched
vi visited;


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
	
    matched.assign(V_left, 0);
    for (int u : match) {
        if (u != - 1) {
            matched[u] = 1;
        }
    }

    alternate_dfs();

    vi result;
    for (int i = 0; i < V_left; i++) {
        if (!visited[i]) {
            result.pb(i);
        }
    }

    for (int i = 0; i < V_right; i++) {
        if (visited[i + V_left]) {
            result.pb(i + V_left);
        }
    }

    return result;
}
