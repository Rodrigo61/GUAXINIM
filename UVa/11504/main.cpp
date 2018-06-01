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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;


    for (int i = 0; i < n_cases; ++i) {

        cin >> V >> E;

        vet_adj.clear();
        vet_adj.resize(V);

        int u, v;
        for (int j = 0; j < E; ++j) {
            cin >> u >> v;
            --u, --v;

            vet_adj[u].insert(v);
        }

        vector<vi> SCCs;
        SCC(SCCs);


        vi which_SCCS(V, -1);
        for (int i = 0; i < SCCs.size(); ++i) {
            print_vector_debug(SCCs[i]);
            for (int j = 0; j < SCCs[i].size(); ++j) {
                which_SCCS[SCCs[i][j]] = i;
            }
        }

        vi degree(SCCs.size(), 0);
        for (int i = 0; i < SCCs.size(); ++i) {
            for (int j = 0; j < SCCs[i].size(); ++j) {
                for (auto &v : vet_adj[SCCs[i][j]]) {
                    if (which_SCCS[SCCs[i][j]] != which_SCCS[v]) {
                        ++degree[which_SCCS[v]];
                    }
                }
            }
        }
        print_vector_debug(degree);

        deb("SCCS count = ", SCCs.size());
        printf("%d\n", count(all(degree), 0));
    }


    return 0;
}
