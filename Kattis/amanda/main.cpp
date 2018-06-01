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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    vi colors(V, -1);
    set<int> easy_vertices;

    vector<vi> vet_adj(V);
    int u, v;
    int type;
    bool possible = true;

    for (size_t i = 0; i < E; i++) {
        cin >> u >> v >> type;
        --u, --v;

        if (type == 0) {

            if (colors[u] == 1 || colors[v] == 1) {
                possible = false;
                break;
            } else {
                colors[u] = 0;
                colors[v] = 0;
                easy_vertices.insert(u);
                easy_vertices.insert(v);
            }

        } else if (type == 2) {

            if (colors[u] == 0 || colors[v] == 0) {
                possible = false;
                break;
            } else {
                colors[u] = 1;
                colors[v] = 1;
                easy_vertices.insert(u);
                easy_vertices.insert(v);
            }

        } else {
            vet_adj[u].pb(v);
            vet_adj[v].pb(u);
        }


    }

    if (!possible) {
        printf("impossible\n");
        return 0;
    }

    for (auto &s : easy_vertices) {

        deb("s = ", s);
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &v : vet_adj[u]) {
                if (colors[v] == colors[u]) {
                    possible = false;
                    break;
                } else if (colors[v] == -1) {
                    colors[v] = !colors[u];
                    q.push(v);
                }
            }

            if (!possible) { break; }
        }

        if (!possible) { break; }
    }


    if (!possible) {
        printf("impossible\n");
    } else {

        int lounges_count = 0;
        for (size_t i = 0; i < V; i++) {
            if (colors[i] == 1) {
                ++lounges_count;
            }
        }


        for (size_t i = 0; i < V; i++) {
            if (colors[i] == -1) {

                vi color_count(2, 0);

                colors[i] = 1;
                ++color_count[1];

                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (auto &v : vet_adj[u]) {
                        if (colors[v] == colors[u]) {
                            possible = false;
                            break;
                        } else if (colors[v] == -1) {
                            colors[v] = !colors[u];
                            ++color_count[colors[v]];
                            q.push(v);
                        }
                    }

                    if (!possible) { break; }
                }

                lounges_count += *min_element(all(color_count));

                if (!possible) { break; }
            }
        }

        if (!possible) {
            printf("impossible\n");
        } else {
            printf("%d\n", lounges_count);
        }

    }

    return 0;
}
