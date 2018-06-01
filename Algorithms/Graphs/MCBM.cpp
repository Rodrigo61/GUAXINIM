
vi match;
vector<vi> vet_adj;
vi visited;

bool Aug(int u) {                 

    if (visited[u]) 
		return false;

    visited[u] = 1;

	for (auto &v : vet_adj[u]) {

        if (match[v] == -1 || Aug(match[v])) {
            match[v] = u;
            return true;
        }
    }


	return true;
}


/* USAGE: */
int main() {

	int MCBM = 0;
    match.assign(V, -1);    				// V is the number of vertices in bipartite graph
	for (int l = 0; l < Vleft; l++) {         		  // Vleft = size of the left set
	    visited.assign(Vleft, 0);                    // reset before each recursion
	    MCBM += Aug(l);
	}
	
	printf("Found %d matchings\n", MCBM);  // the answer is 2 for Figure 4.42
}
