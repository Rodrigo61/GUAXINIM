bool debug = true;

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

vi deep;
vll dist;
vi pai;

int lca(int u, int v) {


    while (u != v) {

        if (deep[u] > deep[v]) {
            u = pai[u];
        } else {
            v = pai[v];
        }

    }

    return u;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V;
    while (cin >> V, V) {

        vector<vii> vet_adj(V);
        pai.assign(V, 0);
        deep.assign(V, 0);
        dist.assign(V, 0);


        for (int i = 1; i < V; ++i) {

            int u;
            ll cost;

            cin >> u >> cost;

            vet_adj[u].pb(mp(i, cost));
            pai[i] = u;
            dist[i] = dist[u] + cost;
            deep[i] = deep[u] + 1;
        }

//        queue<int> q;
//        q.push(0);
//
//
//        while (!q.empty()) {
//
//            int u = q.front();
//            q.pop();
//
//            for (auto &pv : vet_adj[u]) {
//
//                int v = pv.first;
//                ll u2v = pv.second;
//
//                dist[v] = dist[u] + u2v;
//                deep[v] = deep[u] + 1;
//
//                q.push(v);
//            }
//
//        }


        // Resolver querys
        int n_query;
        cin >> n_query;

        for (int i = 0; i < n_query; ++i) {

            int u, v;
            cin >> u >> v;


            printf("%lld", dist[u] + dist[v] - 2 * dist[lca(u, v)]);

            if (i != n_query - 1) {
                putchar(' ');
            } else {
                putchar('\n');
            }
        }

    }

    return 0;
}
