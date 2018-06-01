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

void aux_AP_and_bridges(int u, int &dfs_time, int root_dfs, vi &discovery_time, vi &lowest_discovery_reachable,
                        vi &articulation_vertex, vi &parent) {

    lowest_discovery_reachable[u] = ++dfs_time;
    discovery_time[u] = lowest_discovery_reachable[u];

    int root_dfs_children = 0;

    for (auto v : vet_adj[u]) {
        if (discovery_time[v] == 0) {
            parent[v] = u;

            if (u == root_dfs) {  // Tratando caso raiz do DFS
                root_dfs_children++;

                if (root_dfs_children > 1) {
                    articulation_vertex[u] = 1;
                }
            }

            aux_AP_and_bridges(v, dfs_time, root_dfs, discovery_time, lowest_discovery_reachable,
                               articulation_vertex, parent);

            if (u != root_dfs && lowest_discovery_reachable[v] >= discovery_time[u]) {
                articulation_vertex[u] = 1;
            }

            lowest_discovery_reachable[u] = min(lowest_discovery_reachable[u], lowest_discovery_reachable[v]);

        } else if (v != parent[u]) {
            lowest_discovery_reachable[u] = min(lowest_discovery_reachable[u], discovery_time[v]);
        }
    }
}

void AP_and_bridges(vi &articulation_vertex) {

    articulation_vertex.clear();
    articulation_vertex.resize(V);

    vi discovery_time(V, 0);
    vi lowest_discovery_reachable(V);
    vi parent(V, 0);
    int dfs_time = 0;

    aux_AP_and_bridges(0, dfs_time, 0, discovery_time,
                       lowest_discovery_reachable, articulation_vertex, parent);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int M;

    while (cin >> V >> M, V) {

        vet_adj.clear();
        vet_adj.resize(V);

        int u, v;
        while (cin >> u >> v, u + v != -2) {
            vet_adj[u].insert(v);
            vet_adj[v].insert(u);
        }
        deb("vet_adj");

        vi  articulation_vertex;
        AP_and_bridges(articulation_vertex);
        deb("APS");
        print_vector_debug(articulation_vertex);


        vii articulation_points;
        for (int i = 0; i < V; ++i) {

            if (!articulation_vertex[i]) { continue; }

            vi visited(V, 0);
            visited[i] = 1;

            int component_count = 0;

            for (int j = 0; j < V; ++j) {

                if (!visited[j]) {

                    queue<int> q;

                    q.push(j);
                    visited[j] = 1;

                    deb("i = ", i,  "j = ", j);
                    ++component_count;

                    while (!q.empty()) {
                        int u = q.front();
                        q.pop();

                        for (auto &v : vet_adj[u]) {

                            if (!visited[v]) {
                                visited[v] = 1;
                                q.push(v);
                            }

                        }
                    }
                }

            }

            articulation_points.pb(mp(-component_count, i));

        }

        auto it = articulation_vertex.begin();
        while (articulation_points.size() < M) {
            while (*it == 1) { ++it; }
            articulation_points.pb(mp(-1, distance(articulation_vertex.begin(), it)));
            ++it;
        }

        sort(all(articulation_points));

        for (int i = 0; i < M; ++i) {
            printf("%d %d\n", articulation_points[i].second, -1 * articulation_points[i].first);
        }

        printf("\n");
    }

    return 0;
}
