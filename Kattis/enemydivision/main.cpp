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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> V >> E;

    vet_adj.resize(V);
    int u, v;
    for (size_t i = 0; i < E; i++) {
        cin >> u >> v;
        --u, --v;

        vet_adj[u].insert(v);
        vet_adj[v].insert(u);
    }


    vi enimies_in_same_group(V);
    vi which_group(V);
    set<pii> has_to_move;

    for (size_t i = 0; i < V; i++) {

        which_group[i] = 1;
        enimies_in_same_group[i] = vet_adj[i].size();

        if (vet_adj[i].size() > 1) {
            has_to_move.insert(mp(i, 1));
        }

    }

    while (!has_to_move.empty()) {
        int u = has_to_move.begin()->first;
        int group = has_to_move.begin()->second;
        has_to_move.erase(has_to_move.begin());

        if (group == 1) {
            enimies_in_same_group[u] = 0;
            which_group[u] = 2;

            for (auto &v : vet_adj[u]) {
                if (which_group[v] == 2) {
                    ++enimies_in_same_group[v];
                    ++enimies_in_same_group[u];

                    if (enimies_in_same_group[v] > 1) {
                        has_to_move.erase(mp(v, 1));
                        has_to_move.insert(mp(v, 2));
                    }

                } else {

                    --enimies_in_same_group[v];
                    if (enimies_in_same_group[v] == 1) {
                        has_to_move.erase(mp(v, 1));
                        has_to_move.erase(mp(v, 2));
                    }
                }
            }
        } else {

            enimies_in_same_group[u] = 0;
            which_group[u] = 1;

            for (auto &v : vet_adj[u]) {
                if (which_group[v] == 1) {
                    ++enimies_in_same_group[v];
                    ++enimies_in_same_group[u];

                    if (enimies_in_same_group[v] > 1) {
                        has_to_move.erase(mp(v, 2));
                        has_to_move.insert(mp(v, 1));
                    }

                } else {
                    --enimies_in_same_group[v];
                    if (enimies_in_same_group[v] == 1) {
                        has_to_move.erase(mp(v, 1));
                        has_to_move.erase(mp(v, 2));
                    }
                }
            }
        }
    }

    int n_groups = *max_element(all(which_group)) == 2 ? 2:1;

    printf("%d\n", n_groups);

    bool first = true;
    for (int v = 0; v < V; ++v) {
        if (which_group[v] == 1) {
            if (first) {
                printf("%d", v + 1);
                first = false;
            } else {
                printf(" %d", v + 1);
            }
        }
    }
    printf("\n");

    first = true;
    for (int v = 0; v < V; ++v) {
        if (which_group[v] == 2) {
            if (first) {
                printf("%d", v + 1);
                first = false;
            } else {
                printf(" %d", v + 1);
            }
        }
    }
    printf("\n");


    return 0;
}
