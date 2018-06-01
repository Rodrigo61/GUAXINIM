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
vector<vi> vet_adj;
vector<vi> vet_adj_rev;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V;

    vi vertices;

    vet_adj.resize(1001);
    vet_adj_rev.resize(1001);

    for (size_t i = 0; i < V; i++) {
        int u;
        int sz;

        cin >> u >> sz;

        vertices.pb(u);

        int v;
        for (size_t j = 0; j < sz; j++) {
            cin >> v;
            vet_adj[u].pb(v);
            vet_adj_rev[v].pb(u);
        }
    }

    vi visited(1001, 0);
    queue<int> q;
    visited[0] = 1;
    q.push(0);
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


    vi visited_rev(1001, 0);
    visited_rev[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &v : vet_adj_rev[u]) {
            if (!visited_rev[v]) {
                visited_rev[v] = 1;
                q.push(v);
            }
        }
    }


    int unreachable = 0;
    for (auto &u : vertices) {
        if (!visited[u]) {
            ++unreachable;
        }
    }

    int trapped = 0;
    for (auto &u : vertices) {
        if (!visited_rev[u]) {
            ++trapped;
        }
    }

    deb("unreachable = ", unreachable);
    deb("trapped = ", trapped);

    if (trapped + unreachable == 0) {
        printf("NO PROBLEMS\n");
    } else {
        for (auto &u : vertices) {
            if (!visited_rev[u]) {
                printf("TRAPPED %d\n", u);
            }
        }

        for (auto &u : vertices) {
            if (!visited[u]) {
                printf("UNREACHABLE %d\n", u);
            }
        }
    }

    return 0;
}
