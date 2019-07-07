/*
 * O (V + E)
 *
 * Setar V e vet_adj;
 * resposta dada em sorted_vertices
 *
*/

vector<vi> vet_adj;
vi visited;
vi sorted_vertices;
int V;

void aux_dfs(int root){

    visited[root] = 1;

    for(auto &v : vet_adj[root]){
        if(!visited[v])
            aux_dfs(v);
    }

    sorted_vertices.push_back(root);
}

void topological_sort(){

	visited.clear();
	visited.resize(V, 0);

	sorted_vertices.clear();
	sorted_vertices.reserve(V);

    for (size_t i = 0; i < V; i++) {
        if(!visited[i]){
            aux_dfs(i);
        }
    }

    reverse(all(sorted_vertices));

}
