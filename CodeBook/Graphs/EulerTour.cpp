/*
 * Algoritmo para calcular um caminho euleriano.
   [COMPLEX] O(V + E)
   [USAGE]	
		[ARGS] (int u) é o vértice inicial. É importante destacar que se o grafo possui exatamente
				2 vertices de grau impar 'u' deve ser um deles.
			   (iterator it) é o begin() da sua lista vazia que será populada com a ordem dos
			   vertices do caminho euleriano.
		[TODO] É preciso implementar as funções de checagem de paridade e conectividade, caso isso não
			   seja garantido no problema. Lembre-se que o caminho euleriano acontece em cima de um 
			   grafo CONEXO e com o numero de vertices de grau IMPAR iguais a 0 ou 2.
	[OUT]
		VOID, mas a lista passada como argumento foi populada com os indices dos vertices do caminho euleriano.

 */

bool checkParity()
bool checkConnectivity()
vector<set<int>> vet_adj;

void euler_tour (int u, list<int>::iterator it) {

    while (!vet_adj[u].empty()) {
        int v = *vet_adj[u].begin();
        vet_adj[u].erase(find(all(vet_adj[u]), v));
        vet_adj[v].erase(find(all(vet_adj[v]), u));
        euler_tour(v, tour_list.insert(it, v));
    }

}
