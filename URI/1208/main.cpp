bool debug = true;

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

int N, M;

/*
	Setar V_left e V_right
	Nao usar o vertice 0, pois esse sera o vertice dummy do algoritmo
	Inserir arestas no grafo sempre da esquerda para a direita.
*/

#define INF 1000000000

vector<vi> vet_adj;
int V_left, V_right;

vi match;
vi dist;

bool bfs() {

    queue<int> q;
    dist.assign(V_left + V_right + 1, INF);

    // comeca um BFS a partir de todo vertice livre (i.e. p[u] == 0) da esquerda
    for (int i = 1; i <= V_left; i++) {
        if (match[i] == 0) {
            dist[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        if (u == 0) { return true; } // cheguei no dummy, significa que cheguei em alguem na direita sem match

        for(auto &v : vet_adj[u]) {

            if (dist[match[v]] == INF) { // perceba que usamos o vetor match para descobrir caminhos alternados

                q.push(match[v]);
                dist[match[v]] = dist[u] + 1;

            }
        }

    }

    return false;
}

bool dfs(int u) {

    if (u == 0) { return true; } // cheguei no dummy, significa que cheguei em alguem na direita sem match


    for(auto &v : vet_adj[u]) {

        if (dist[u] + 1 == dist[match[v]]) {
            if (dfs(match[v])) {

                match[u] = v;
                match[v] = u;

                return true;
            }
        }

    }


    // Se chegou aqui, o vertice u nao tem mais caminhos para oferecer, entao ja invalidamos ele
    dist[u] = INF;
    return false;
}

int hopcroft() {

    match.assign(V_left + V_right + 1, 0);
    int matching = 0;
    while (bfs()) {

        for (int i = 1; i <= V_left; i++) {

            if (match[i] == 0) {

                if (dfs(i)) {
                    matching++;
                }

            }

        }

    }

    return matching;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {

        vet_adj.clear();
        vet_adj.resize(2 * N + 1);

        V_left = N;
        V_right = N;

        int u, v;
        for (int i = 0; i < M; ++i) {

            cin >> u >> v;

            vet_adj[u].pb(v + N);
        }

        printf("%d\n", N - hopcroft());

    }

    return 0;
}
