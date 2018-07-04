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

        // se a bfs chega no sorvedouro podemos retornar porque os vértices que não estão no menor caminho para o sorvedouro não importam
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

        if (dist[u] + 1 == dist[e.dest] && e.capacity > 0) { // só queremos as arestas que fazem parte de um caminho mínimo e podem passar fluxo
        
            int rec_flow = dfs(e.dest, min(flow, e.capacity), target);

            if (rec_flow == 0) { continue; }

            e.capacity -= rec_flow; // Passa fluxo pelo caminho aumentante encontrado.
            edge_list[e.dest][e.cancel_edge].capacity += rec_flow; // Essa linha não afeta as próximas iterações da dfs porque a aresta reversa não está em um caminho mínimo.

            return rec_flow;
        }

    }


    dist[u] = INF; // Se chegou aqui, esgotou-se as opcoes para esse vertice, vamos marca-lo como inutil
    return 0;
}

long long dinic(int source, int target) {

    ll flow = 0;

    while (bfs(source, target)) {

        next_neighbor.assign(V, 0);
        while (int path_flow = dfs(source, INF, target)) {
            flow += path_flow;

        }

    }

    return flow;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;


    for (int q = 0; q < n_cases; ++q) {


        int n;
        cin >> n;

        edge_list.clear();
        edge_list.resize(28);

        vi is_name(28, 0);
        vector<string> vet_names(28);

        // [0] = Super source, [1] = super sink, [2-27] = iniciais, [28--] = problema + nomes

        for (int i = 0; i < n; ++i) {

            int n_names;
            cin >> n_names;

            edge_list.resize(edge_list.size() + 1);
            is_name.pb(0);
            vet_names.pb("");

            int problem_id = edge_list.size() - 1;
            deb("problem_id = ", problem_id);

            //liga o super source ao problema
            put_edge(0, problem_id, 1);

            for (int j = 0; j < n_names; ++j) {
                string word;
                cin >> word;

                for (auto &c : word) { c = tolower(c); }

                edge_list.resize(edge_list.size() + 1);
                is_name.pb(1);
                deb("word = ", word);
                vet_names.pb(word);

                char first_char = word[0];

                // liga nomes com sua inicial no grafo
                put_edge(edge_list.size() - 1, first_char - 'a' + 2, 1);

                // liga o problema com o nome lido
                put_edge(problem_id, edge_list.size() - 1, 1);
            }


        }


        // liga as iniciais com o super sink
        for (int i = 0; i < 26; ++i) {
            put_edge(i + 2, 1, 1);
        }


        V = edge_list.size();

        deb("V = ", V);
        deb("max_flow = ", dinic(0, 1));


        deb("n = ", n);
        vector<string> sol;
        for (int i = 29; i <= V; ++i) {
            if (is_name[i]) {

                deb("i = ", i);
                bool has_back_edge = false;
                for (auto &edge : edge_list[i]) {
                    deb("edge.dest = ", edge.dest);
                    if (edge.dest < i && edge.dest > 27 && edge.capacity > 0) {
                        has_back_edge = true;
                        break;
                    }
                }


                if (has_back_edge) {
                    sol.pb(vet_names[i]);
                }

            }
        }


        sort(all(sol));

        printf("Case #%d:\n", q + 1);
        for (auto &s : sol) {
            printf("%c", toupper(s[0]));
            for (int i = 1; i < s.size(); ++i) {
                printf("%c", s[i]);
            }
            printf("\n");
        }

    }

    return 0;
}
