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

int V, E, Q;
vector<vi> vet_adj;
vi parent;
vector<vi> bridge_edge;

class UnionFind {
private:
    vi rep, rank;
public:

    UnionFind(int N) {
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

            int rep_i = find_set(i);
            int rep_j = find_set(j);


            if (rank[rep_i] > rank[rep_j]) {

                rep[rep_j] = rep_i;

            } else {

                rep[rep_i] = rep_j;

                if (rank[rep_i] == rank[rep_j]) {
                    rank[rep_j]++;
                }

            }
        }
    }
};

void find_path(int source, int target) {

    vi visited(V, 0);
    visited[source] = 1;

    queue<int> q;
    q.push(source);


    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &v : vet_adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

}

void aux_AP_and_bridges(int u, int &dfs_time, int root_dfs, vi &discovery_time, vi &lowest_discovery_reachable,
                        vi &parent) {


    lowest_discovery_reachable[u] = ++dfs_time;
    discovery_time[u] = lowest_discovery_reachable[u];

    int root_dfs_children = 0;

    for (auto v : vet_adj[u]) {
        if (discovery_time[v] == 0) {
            parent[v] = u;

            if (u == root_dfs) {  // Tratando caso raiz do DFS
                root_dfs_children++;
                
            }

            aux_AP_and_bridges(v, dfs_time, root_dfs, discovery_time, lowest_discovery_reachable,
                               parent);
            
            // FOR bridge
            if (lowest_discovery_reachable[v] > discovery_time[u]) {
                bridge_edge[u][v] = 1;
                bridge_edge[v][u] = 1;
            }

            lowest_discovery_reachable[u] = min(lowest_discovery_reachable[u], lowest_discovery_reachable[v]);
        } else if (v != parent[u]) {
            lowest_discovery_reachable[u] = min(lowest_discovery_reachable[u], discovery_time[v]);
        }
    }
}

void AP_and_bridges() {

    vi discovery_time(V, 0);
    vi lowest_discovery_reachable(V);
    vi parent(V, 0);

    for (int i = 0; i < V; ++i) {
        if (discovery_time[i] == 0) {
            int dfs_time = 0;
            aux_AP_and_bridges(i, dfs_time, 0, discovery_time,
                               lowest_discovery_reachable, parent);
            print_vector_debug(discovery_time);
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> V >> E >> Q, V) {


        vet_adj.clear();
        vet_adj.resize(V);

        vii edges(E);

        for (int i = 0; i < E; ++i) {
            int u, v;

            cin >> u >> v;
            --u, --v;

            vet_adj[u].pb(v);
            vet_adj[v].pb(u);

            edges[i] = mp(u, v);
        }

        bridge_edge.clear();
        bridge_edge.resize(V, vi(V, 0));
        AP_and_bridges();
        

        UnionFind uf(V);

        for (auto edge : edges){

            if (bridge_edge[edge.first][edge.second]) {
                uf.union_by_rank(edge.first, edge.second);
            }

        }

        for (int i = 0; i < Q; ++i) {

            int source, target;
            cin >> source >> target;

            --source, --target;

            if (uf.is_same_set(source, target)) {
                printf("Y\n");
            } else {
                printf("N\n");
            }
        }

        printf("-\n");

    }

    return 0;
}
