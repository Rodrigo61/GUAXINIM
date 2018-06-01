/*
	Utilizamos o algoritmo de Tarjan para detectar as SCC.

	Dizemos que um conjunto de vértices em um grafo DIRECIONADO é uma SCC, sse pegando quaisquer vértices u e v deste conjunto nós podemos encontrar um caminho que os liga.

	O algoritmo de Tarjan é semelhante ao algoritmo para encontrar AP e Brigdes. É uma modificacao do DFS que utiliza o tempo de descoberta dos vértices.

	A ideia é manter 2 atributos para cada vértice: discovery_time e lowest_discovery_reachable.
	
	O atributo discovery_time[u] de um vértice u nos diz em qual iteracao do DFS o vértice u foi visitado pela primeira vez. Já o atributo lowest_discovery_reachable[u] nos diz qual o menor discovery_time[w] de um vértice w que é alcancavel por u. DETALHE: diferentemente do algoritmo de Tarjan para AP, o vértice w só tem seu tempo de descoberta (discovery_time[w]) levado em consideração se ele já foi marcado como visitado (visited[w] = 1) pelo DFS atual. 	A ideia é que todo vértice pertence a apenas uma SCC, pois se pertencece a mais de uma nós poderiámos junta-las através dele. Então, só consideramos os vértices que foram descobertos apenas nessa tentativa de criar um novo SCC, se por acaso encontrássemos um vértice w tal que diminuisse o valor do lowest_discovery_reachabl[u], mas w não foi visitado nessa tentativa, então o desprezamos, pois sabemos que por mais que u chegue em w, w não chegará em u (já que w está em outra SCC e se chegasse em u, entao u deveria estar na mesma SCC).

	A ideia do algoritmo, depois de computar esses valores, é dizer que:

		* Um vértice u é a raiz de uma SCC sse discovery_time[u] == lowest_discovery_reachable[u]


	Perceba que se discovery_time[u] > lowest_discovery_reachable[u], então é por que existe um vértice w já visitado, alcancável por u,  que tem um tempo de descoberta menor. Isso é, o DFS já foi aplicado sobre e ele seria um melhor candidato a raiz desta árvore DFS, ou seja, raiz do SCC. Manter essa ordenacao de tempo é importante, pois mantemos uma "stack" com tal ordenacao para dar a resposta final.
	Se discovery_time[u] < lowest_discovery_reachable[u], significa que numa árvore DFS enraizada por u não existe uma aresta de volta para o mesmo. Então, existe algum vértice v nesta árvore que não alcanca u, logo não é uma SCC.

	O algoritmo também mantém uma "STACK" para guardar a ordem dos vértices sobre o qual o DFS iterou. Assim, após calcularmos os dois atributos de tempo, podemos ir desempilhando essa stack e a cada vértice raiz ( discovery_time[u] == lowest_discovery_reachable[u]) teremos uma nova SCC.
*/

int V, E;
vector<set<int>> vet_adj;

void SCC_aux(int u, int &dfs_time, vi &visited, vi &visit_order, vi &discovery_time, vi &lowest_discovery_reachable, vector<vi> &SCCs) {

    discovery_time[u] = ++dfs_time;
    lowest_discovery_reachable[u] = discovery_time[u];

    visit_order.push_back(u);

    visited[u] = 1;

    for (auto v : vet_adj[u]) {

        if (discovery_time[v] == 0) {
            SCC_aux(v, dfs_time, visited, visit_order, discovery_time, lowest_discovery_reachable, SCCs);
        }

        if (visited[v]) {
            lowest_discovery_reachable[u] = min(lowest_discovery_reachable[u], lowest_discovery_reachable[v]);
        }
    }


    if (discovery_time[u] == lowest_discovery_reachable[u]) {

        vi new_scc;
        SCCs.pb(new_scc);
        int v;

        do {
            v = visit_order.back();
            visit_order.pop_back();
            visited[v] = 0;
            SCCs.back().pb(v);
        } while (u != v);

    }



}

void SCC(vector<vi> &SCCs) {

    SCCs.clear(); // Para recuperar de fato o cada SCC

    vi visit_order;

    vi discovery_time(V, 0);
    vi lowest_discovery_reachable(V, 0);

    vi visited(V, 0);
    int dfs_time = 0;


    for (int i = 0; i < V; ++i) {
        if (discovery_time[i] == 0) {
            SCC_aux(i, dfs_time, visited, visit_order, discovery_time, lowest_discovery_reachable, SCCs);
        }
    }

}
