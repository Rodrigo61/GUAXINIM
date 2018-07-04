/*
 * O(VE)
 *
 * Setar vet_adj, V e V_left.
 * Resposta pode ser encontrada no vetor match.
 *
 * */

vi match;
vector<vi> vet_adj;
vi visited;

bool aug(int u) {                 

    if (visited[u]) 
		return false;

    visited[u] = 1;

	for (auto &v : vet_adj[u]) {

        if (match[v] == -1 || aug(match[v])) {
            match[v] = u;
            return true;
        }
    }

	return false;
}


int MCBM() {

	int MCBM = 0;
    match.assign(V, -1);    				// V is the number of vertices in bipartite graph
	for (int l = 0; l < V_left; l++) {         		  // Vleft = size of the left set
        visited.assign(V_left, 0);
	    MCBM += aug(l);
	}
	
	return MCBM;
}
