/*
	O (V)

	Parametros:
		* vetor de graus
		* vet_adj que sera a saida da funcao
		* curr_idx = 0 [indice no vetor de degree]
		* diff_one_pos = posicao do primeiro numero diferente de 1
	
	A ideia aqui eh que qualquer vetor de grau que contenha N elementos e tenha
	uma soma total de 2n - 2 (Total de graus de uma arvore de tamanho N), pode
	ter uma arvore construida respeitando seus graus. Isso pode ser provado facil-
	mente por inducao matematica no numero de vértices. Da prova deriva o algoritmo.
*/


void gen_tree(vii &degree, vector<vi> &vet_adj, int curr_idx, int diff_one_pos) {


    if (curr_idx == vet_adj.size() - 2) {
        // Base: two vertices, always possible
        vet_adj[degree[curr_idx].second].push_back(degree[curr_idx + 1].second);
        return;
    }

    vet_adj[degree[curr_idx].second].push_back(degree[diff_one_pos].second);

    --degree[diff_one_pos].first;
    if (degree[diff_one_pos].first == 1) {
        ++diff_one_pos;
    }

    gen_tree(degree, vet_adj, curr_idx + 1, diff_one_pos);

}
