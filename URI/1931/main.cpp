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

#define INF 100000000000000

int V, E;

typedef pair<ll, pair<int, bool>> par;

vector<list<pair<int, ll>>> vet_adj;


ll sssp(int source, int target){

    vll dist_even(V, INF);
    vll dist_odd(V, INF);

    dist_even[source] = 0;
    dist_odd[source] = 0;

    priority_queue<par, vector<par>, greater<par>> pq;

    pq.push(mp(0, mp(source, true)));

    while(!pq.empty()){

        int u = pq.top().second.first;
        ll d_u = pq.top().first;
        bool is_even = pq.top().second.second;
        pq.pop();


        if (is_even) {

            if(dist_even[u] < d_u) continue;

            for(auto &pv :  vet_adj[u]){
                int v = pv.first;
                ll u_v = pv.second;

                if(d_u + u_v < dist_odd[v]){
                    dist_odd[v] = d_u + u_v;
                    pq.push(mp(dist_odd[v], mp(v, false)));
                }

            }

        } else {

            if(dist_odd[u] < d_u) continue;

            for(auto &pv :  vet_adj[u]){
                int v = pv.first;
                ll u_v = pv.second;

                if(d_u + u_v < dist_even[v]){
                    dist_even[v] = d_u + u_v;
                    pq.push(mp(dist_even[v], mp(v, true)));
                }

            }

        }
    }

    if (dist_even[target] != INF) {
        return dist_even[target];
    } else {
        return -1;
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;

    vet_adj.resize(V);
    for (int i = 0; i < E; ++i) {
        int u, v, u2v;

        cin >> u >> v >> u2v;

        --u, --v;

        vet_adj[u].pb(mp(v, u2v));
        vet_adj[v].pb(mp(u, u2v));
    }


    printf("%lld\n", sssp(0, V-1));

    return 0;
}