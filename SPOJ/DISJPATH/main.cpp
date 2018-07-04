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

#define INF 1000000000

struct edge{
    int dest;
    int capacity;
    int cancel_edge; // id da reverse edge associada

    edge(int x, int y, int z) : dest(x), capacity(y), cancel_edge(z){}
};

int V;
vi next_neighbor;
vi dist;
vector<vector<edge>> edge_list;

void put_edge(int u, int v, int capacity)
{
    edge_list[u].push_back(edge(v, capacity, edge_list[v].size()));
    edge_list[v].push_back(edge(u, 0, edge_list[u].size() - 1));
}

void put_edge_undirected(int u, int v, int capacity)
{
    edge_list[u].push_back(edge(v, capacity, edge_list[v].size()));
    edge_list[v].push_back(edge(u, capacity, edge_list[u].size() - 1));
}

bool bfs(int source, int target) {

    queue<int> q;
    q.push(source);

    dist.assign(V, INF);
    dist[source] = 0;

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        // se a bfs chega no sorvedouro podemos retornar porque os vÃ©rtices que nÃ£o estÃ£o no menor caminho para o sorvedouro nÃ£o importam
        if (u == target) { return true; }

        for(auto &e : edge_list[u]) {

            if(e.capacity > 0 && dist[e.dest] == INF) { // percorre todas as arestas que ainda podem passar fluxo

                dist[e.dest] = dist[u] + 1;
                q.push(e.dest);

            }
        }
    }


    return false;
}

int dfs(int u, int flow, int target)
{
    if (u == target) {
        return flow; // encontramos um caminho aumentante
    }

    for (int &i = next_neighbor[u]; i < edge_list[u].size(); i++) { //ignora arestas ja percorridas

        edge &e = edge_list[u][i];

        if (dist[u] + 1 == dist[e.dest] && e.capacity > 0) { // sÃ³ queremos as arestas que fazem parte de um caminho mÃ­nimo e podem passar fluxo

            int rec_flow = dfs(e.dest, min(flow, e.capacity), target);

            if (rec_flow == 0) { continue; }

            e.capacity -= rec_flow; // Passa fluxo pelo caminho aumentante encontrado.
            edge_list[e.dest][e.cancel_edge].capacity += rec_flow; // Essa linha nÃ£o afeta as prÃ³ximas iteraÃ§Ãµes da dfs porque a aresta reversa nÃ£o estÃ¡ em um caminho mÃ­nimo.

            return rec_flow;
        }

    }


    dist[u] = INF; // Se chegou aqui, esgotou-se as opcoes para esse vertice, vamos marca-lo como inutil
    return 0;
}

long long dinic(int source, int target) {

    ll flow = 0;
    V = edge_list.size();


    deb("source = ", source);
    int init_flow = 0;
    for (auto &edge : edge_list[source]) {
        init_flow += edge.capacity;
    }
    deb("init_flow = ", init_flow);

    while (bfs(source, target)) {

        next_neighbor.assign(V, 0);
        while (int path_flow = dfs(source, INF, target)) {
            flow += path_flow;

        }

    }

    return flow;
}

void dfs_sol(int u, vi &curr_path) {


    int V_original = V / 2;
    curr_path.pb(u);
    deb("u = ", u);

    if (u == 1 + V_original) {
        for (int i = 0; i < curr_path.size(); ++i) {
            printf("%d", curr_path[i] - V_original + 1);

            if (i != curr_path.size() - 1) {
                printf(" ");
            }
        }

        printf("\n");

    } else {

        deb("edge_list.size() = ", edge_list.size());
        for (auto &edge : edge_list[u]) {

            deb("V_original = ", V_original);
            deb("edge_list[u].size() = ", edge_list[u].size());
            deb("edge.dest = ", edge.dest);
            if (edge.dest != u - V_original && edge.capacity == 0) {
                dfs_sol(edge.dest + V_original, curr_path);
            }
        }

    }

    curr_path.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

//    int V;
//    vector<vector<edge>> edge_list;

    int n_cases = 0;
    int K;

    while (cin >> K >> V, K + V) {

        cin.ignore();
        edge_list.clear();
        edge_list.resize(2 * V);

        deb("K = ", K);
        for (int u = 0; u < V; ++u) {

            if (u == 0) {
                put_edge(0, V, K);
            } else {
                put_edge(u, u + V, 1);
            }

            while (cin.peek() != '\n') {
                int v;
                cin >> v;

                --v;

                deb("u + V = ", u + V);
                deb("v = ", v);
                put_edge(u + V, v, 1);

            }
            cin.ignore();

        }

        deb("V after = ", V);

        printf("Case %d:\n", ++n_cases);

        deb("V after2 = ", V);
        ll aux = dinic(0, 1);
        deb("max_flow = ", aux);

        if (aux == K) {
            deb("correct flow");
            vi sols;
            deb("V after3 = ", V);
            dfs_sol(V / 2, sols);
        } else {
            printf("Impossible\n");
        }

        printf("\n");

    }



    return 0;
}
