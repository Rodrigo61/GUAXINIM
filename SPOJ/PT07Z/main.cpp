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

#define INF 99999
int V;
vector<vi> vet_adj;

int get_diameter() {

    deb("get_diamter");
    vi dist(V, INF);

    stack<int> stack;
    stack.push(0);
    dist[0] = 0;

    int max_dist = 0;
    int max_dist_index = 0;

    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();

        for (auto &v : vet_adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                stack.push(v);

                if (dist[v] > max_dist) {
                    max_dist = dist[v];
                    max_dist_index = v;
                }
            }
        }
    }

    deb("DFS 1 (max_dist)= ", max_dist);

    fill(all(dist), INF);

    stack.push(max_dist_index);
    dist[max_dist_index] = 0;

    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();

        for (auto &v : vet_adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                stack.push(v);

                if (dist[v] > max_dist) {
                    max_dist = dist[v];
                    max_dist_index = v;
                }
            }
        }
    }

    deb("DFS 2 (max_dist)= ", max_dist);

    return max_dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V;

    deb("V = ", V);
    vet_adj.resize(V);
    int u, v;
    for (int i = 0; i < V - 1; i++) {
        cin >> u >> v;
        --u, --v;
        vet_adj[u].push_back(v);
        vet_adj[v].push_back(u);
    }

    deb("read");
    printf("%d\n", get_diameter());


    return 0;
}
