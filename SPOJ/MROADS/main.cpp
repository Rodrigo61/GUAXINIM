bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include "bits/stdc++.h"
using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;


/// Debug Start
template<class T1> void deb(T1 e1)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << endl;
    }
}
template<class T1,class T2> void deb(T1 e1, T2 e2)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << endl;
    }
}
template<class T1,class T2,class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << endl;
    }
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1, T2 e2, T3 e3, T4 e4)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << endl;
    }
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << space << e5 << endl;
    }
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1, T2 e2, T3 e3, T4 e4 ,T5 e5, T6 e6)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << space << e5 << space << e6 << endl;
    }
}


template<typename T>
void print_vector_debug(const T& t) {

    if(debug) {
        cout << "[DEBUG] VECTOR:";
        for (auto i = t.cbegin(); i != t.cend(); ++i) {
            if ((i + 1) != t.cend()) {
                cout << *i << " ";
            } else {
                cout << *i << endl;
            }
        }
    }
}

template<typename T>
void print_array_debug(const T arr, int size){

    if(debug) {
        cout << "[DEBUG] VECTOR:";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << space;
        }
        cout << endl;
    }
}

template<typename T>
void print_2Darray_debug(const T arr, int rows, int cols){

    if(debug) {
        cout << "[DEBUG] Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << arr[i][j] << space;
            }
            cout << endl;
        }
        cout << endl;
    }
}

template<typename T>
void print_matrix_debug(const T& t) {
    if(debug) {
        cout << "[DEBUG] MATRIX:" << endl;
        for (auto i = t.cbegin(); i != t.cend(); ++i) {
            for(auto j = i->cbegin(); j != i->cend(); ++j){
                cout << *j << " ";
            }
            cout << endl;
        }
    }
}
//</editor-fold>

#define INF 999999999

typedef struct Edge {
    int v;
    int curr_time;
    int min_time;
    int id;
}Edge;

int V, K;
vector<list<Edge>> vet_adj;

int maximum_path, minimum_path;

pii leafs[100000];
int leafs_size;

int budget;

list<Edge*> dfs_path;
vector<Edge*> path;

vector<pair<Edge*, int>> persistent_dfs;
vi dp;

bool dfs(int curr_vertice, int curr_dist, int max_dist) {

    while (curr_vertice != 0){

        if (curr_dist <= dp[curr_vertice]) {
            return true;
        }


        // Se nao estamos no nó 0, necessariamente temos uma aresta de volta para ele.
        Edge* curr_edge = &(*(vet_adj[curr_vertice].begin()));

        // Inserimos a aresta atual na lista do caminho
        if (curr_edge->curr_time > curr_edge->min_time) {
            dfs_path.pb(curr_edge);
        }
        path.pb(curr_edge);


        while (curr_dist + curr_edge->curr_time > max_dist) {

            // Calculamos quanto precisamos reparar no caminho ja percorrido para que possamos
            // ir para o proximo vertice respeitando o tamanho máximo.
            int dist_needed = curr_dist + curr_edge->curr_time - max_dist;

            // deb("dist_needed = ", dist_needed);
            // deb("cur_dist = ", curr_dist);
            // deb("dfs_path.size() = ", dfs_path.size());
            // deb("curr_vertice = ", curr_vertice);

            // Se a distancia necessaria estoura orcamento ja sabemos que é impossivel
            if (dist_needed > budget) { return false; }

            // Se esgotou possibilidades de reparo ha sabemos que é impossivel
            if (dfs_path.empty()) { return false; }

            // Montando as informacoes da aresta que será reparada nessa iteracao
            Edge* prev_edge = dfs_path.back();

            // Verifica se é preciso reparar a aresta inteira, ou só o necessario
            int new_time = max(prev_edge->min_time, prev_edge->curr_time - dist_needed);
            int cost = prev_edge->curr_time - new_time;

            // Atualiza a aresta para seu novo peso (new_time)
            if (persistent_dfs[prev_edge->id].second == -1) {
                persistent_dfs[prev_edge->id] = (mp(prev_edge, prev_edge->curr_time));
            }
            // deb("prev_edge->curr_time = ", prev_edge->curr_time);
            // deb("new_time = ", new_time);
            prev_edge->curr_time = new_time;


            // Atualiza o orcamento com o custo do reparo acima
            budget -= cost;

            // deb("prev_edge->id = ", prev_edge->id);
            // deb("curr_edge->id = ", curr_edge->id);
            if (prev_edge->id != curr_edge->id) {
                // Caso atualizamos uma aresta que nao seja a atual, precisamos reduzir
                // a distancia anterioemente calculada
                // deb("dist anterior alterada = ", curr_dist);
                curr_dist -= cost;
            }

            // Se a aresta marcada como passivel de reparos ja tiver sido totalmente reparada
            // nós atualizamos essa marcação para a aresta que antecede ela no caminho.
            if (prev_edge->curr_time == prev_edge->min_time) {
                dfs_path.pop_back();
                // deb("pop_back");
            }

        }

        // Agora que garantimos que podemos continuar para o proximo vertice, chamamos a funcao
        // recursivamente.
        curr_vertice = curr_edge->v;
        curr_dist = curr_dist + curr_edge->curr_time;
    }

    return true;
}

void redo_dfs() {

    for (int i = 0; i < V - 1; i++) {
        if (persistent_dfs[i].second != -1) {
            (persistent_dfs[i].first)->curr_time = persistent_dfs[i].second;
        }
    }
}

bool possible(int dist) {

    budget = K;

    //vet_adj = vet_adj;

    for (size_t i = 0; i < V - 1; i++) {
        persistent_dfs[i].second = -1;
    }

    fill(all(dp), -1);

    bool res = true;
    for (auto leaf: leafs) { //O (V)
        dfs_path.clear();
        path.clear();
        res = dfs(leaf.second, 0, dist);
        if (!res) { break; }

        int dist = 0;
        for (auto &edge : path) {
            dist += edge->curr_time;
            dp[edge->v] = max(dp[edge->v], dist);
        }
    }

    if (res) {
        print_vector_debug(dp);
         K = budget;
    } else {
         redo_dfs();
    }

    return res;

}

void find_leafs() {

    leafs_size = 0;

    int dist[V];
    for (size_t i = 0; i < V; i++) {
        dist[i] = INF;
    }

    stack<int> s;

    dist[0] = 0;
    s.push(0);

    maximum_path = 0;
    minimum_path = 0;

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (vet_adj[u].size() == 1 && dist[vet_adj[u].begin()->v] != INF) {
            leafs[leafs_size] = mp(-dist[u], u);
            ++leafs_size;
        }

        for (auto it = vet_adj[u].begin(); it != vet_adj[u].end();){
            Edge u2v = *it;

            if (dist[u2v.v] == INF) {
                dist[u2v.v] = dist[u] + u2v.curr_time;
                maximum_path = max(maximum_path, dist[u2v.v]);
                minimum_path = max(minimum_path, u2v.min_time);
                s.push(u2v.v);
                it = vet_adj[u].erase(it);
            } else {
                ++it;
            }
        }
    }

    sort(leafs, leafs + leafs_size);

}

int solve() {

    find_leafs();

    int upper = maximum_path;
    int lower = minimum_path;
    int mid;

    while (upper > lower ) {
        mid = lower + (upper - lower)/2;

        if (possible(mid)) {
            upper = mid;
        } else {
            lower = mid + 1;
        }
    }

    return lower;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> K;

    vet_adj.resize(V);
    persistent_dfs.resize(V - 1);
    dp.resize(V);

    int u, v;
    int A, B;
    for (size_t i = 0; i < V - 1; i++) {
        cin >> u >> v >> A >> B;
        --u, --v;

        Edge edge, reverse_edge;

        edge.v = v;
        edge.curr_time = A;
        edge.min_time = B;
        edge.id = i;

        reverse_edge = edge;
        reverse_edge.v = u;

        vet_adj[u].pb(edge); // O(N)
        vet_adj[v].pb(reverse_edge);
    }


    printf("%d\n", solve());


    return 0;
}
