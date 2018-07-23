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
typedef pair<int, pii> piii;

int V, E, T;
vi vertex_cost;
vector<vii> vet_adj;

void add_edge(int u, int v, int u2v) {

    vet_adj[u].pb(mp(v, u2v));
    vet_adj[v].pb(mp(u, u2v));

}

int sssp() {

    priority_queue<piii> pq;
    pq.push(mp(0, mp(T, 0)));

    int memo[V + 1][T + 1];
    memset(memo, 0, sizeof(memo));

    while (!pq.empty()) {

        int u = pq.top().second.second;
        int cost_u = -pq.top().first;
        int fuel_u = pq.top().second.first;
        pq.pop();

        if (memo[u][fuel_u]) continue;
        memo[u][fuel_u] = 1;

        if (u == V - 1) return cost_u;

        for (auto &pv : vet_adj[u]) {

            int v = pv.first;
            int u2v = pv.second;

            for (int g = max(u2v - fuel_u, 0) ; g <= T - fuel_u ; ++g) {

                pq.push(mp(-(cost_u + g * vertex_cost[u]), mp(fuel_u - u2v + g, v)));

            }

        }


    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> V >> E >> T, V) {


        vet_adj.clear();
        vet_adj.resize(V);

        int u, v, u2v;
        for (int i = 0; i < E; ++i) {

            cin >> u >> v >> u2v;

            --u, --v;

            add_edge(u, v, u2v);
        }


        vertex_cost.assign(V, 0);
        for (int i = 0; i < V; ++i) {
            cin >> vertex_cost[i];
        }


        printf("%d\n", sssp());


    }

    return 0;
}
