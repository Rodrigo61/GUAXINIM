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

int V;
vector<set<int>> vet_adj;
vi articulation_vertex;
// int bridge_edge[][]

void aux_AP_and_bridges(int u, int &dfs_time, int root_dfs, vi &dt, vi &ldr, vi &parent) {


    ldr[u] = ++dfs_time;
    dt[u] = ldr[u];

    int root_dfs_children = 0;

    for (auto v : vet_adj[u]) {
        if (dt[v] == 0) {
            parent[v] = u;

            if (u == root_dfs) {  // Tratando caso raiz do DFS
                root_dfs_children++;

                if (root_dfs_children > 1) {
                    articulation_vertex[u] = 1;
                }
            }

            aux_AP_and_bridges(v, dfs_time, root_dfs, dt, ldr, parent);

            if (u != root_dfs && ldr[v] >= dt[u]) {
                articulation_vertex[u] = 1;
            }

            // To set bridges
            //	if (ldr[v] > dt[u])
            //		bridge_edge[u][v] = briged_edge[v][u] = true;

            ldr[u] = min(ldr[u], ldr[v]);
        } else if (v != parent[u]) {
            ldr[u] = min(ldr[u], dt[v]);
        }
    }
}

void AP_and_bridges() {

    articulation_vertex.clear();
    articulation_vertex.resize(V);

    vi dt(V, 0);
    vi ldr(V);
    vi parent(V, 0);
    int dfs_time = 0;

    aux_AP_and_bridges(0, dfs_time, 0, dt, ldr, parent);
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> V, V) {

        deb("V = ", V);

        vet_adj.clear();
        vet_adj.resize(V);

        while (true) {
            int u;
            cin >> u;

            if (u == 0) { break; }

            --u;

            deb("u = ", u);
            while (cin.peek() != '\n'){
                int v;
                cin >> v;

                --v;

                deb("v = ", v);

                vet_adj[u].insert(v);
                vet_adj[v].insert(u);

                deb("inserted");
            }
        }

        deb("vet_adj completed");
        
        AP_and_bridges();


        print_vector_debug(articulation_vertex);
        printf("%d\n", count(all(articulation_vertex), 1));


    }


    return 0;
}
