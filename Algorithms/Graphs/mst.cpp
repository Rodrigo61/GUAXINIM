/*
 * O (ElgV)
 *
 * Setar UF com os vertices iniciais.
 * Criar edge_list e ordena-la.
 *
 */


class UnionFind {
private:
  vi rep, rank, set_sz;                       
  int n_sets;
public:

	UnionFind(int N) {
		set_sz.assign(N, 1); 
		n_sets = N;
		rank.assign(N, 0);
		rep.assign(N, 0); 
		for (int i = 0; i < N; i++) {
			rep[i] = i; 
		}
	}

	int find_set(int i) { 
		
		if (rep[i] == i) {
			return i;	
		}

		rep[i] = find_set(rep[i]);
		
		return rep[i];

	}

	bool is_same_set(int i, int j) { 
		return find_set(i) == find_set(j); 
	}

	void union_by_rank(int i, int j) { 
		if (!is_same_set(i, j)) { 

			n_sets--; 
			int rep_i = find_set(i);
			int rep_j = find_set(j);
			

			if (rank[rep_i] > rank[rep_j]) { 

				rep[rep_j] = rep_i; 
				set_sz[rep_i] += set_sz[rep_j]; 

			} else {

				rep[rep_i] = rep_j; 
				set_sz[rep_j] += set_sz[rep_i];

				if (rank[rep_i] == rank[rep_j]) {
					rank[rep_j]++; 
				}

			} 
		} 
	}

	int sets_count() { 
		return n_sets; 
	}
	
};

struct Edge{
	int u, v;
	int weight;

	bool operator < (Edge const& other) const {
        return this->weight < other.weight;
    }
};

/* USAGE: */

int main() {
	int mst_cost = 0;
	UnionFind UF(V);     
	auto it = edge_list.begin();  // already sorted   
    while (it != edge_list.end() && UF.sets_count() > 1) {
        Edge curr_edge = *(it++);
		if (!UF.is_same_set(curr_edge.u, curr_edge.v)) {
			mst_cost += curr_edge.weight;
			UF.union_by_rank(curr_edge.u, curr_edge.v);
		} 
	}                       
}
