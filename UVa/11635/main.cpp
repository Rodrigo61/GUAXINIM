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

#define TEN_HOURS 600
#define INF 100000000000000


int V, E;
vector<vii> vet_adj;
vi dist;
set<int> hotels;


ll sssp(int source){

    dist.clear();
    dist.resize(V, INF);
    dist[source] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(mp(0, source));

    while(!pq.empty()){
        int u = pq.top().second;
        ll d_u = pq.top().first;
        pq.pop();

        if(dist[u] < d_u) continue;

        for(auto &pv :  vet_adj[u]){
            int v = pv.first;
            ll u_v = pv.second;

            if(d_u + u_v < dist[v]){
                dist[v] = d_u + u_v;
                pq.push(mp(dist[v], v));
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> V , V) {

        int n_hotels;
        cin >> n_hotels;

        hotels.clear();
        for (int i = 0; i < n_hotels; ++i) {
            int u;
            cin >> u;
            --u;

            hotels.insert(u);
        }
        hotels.insert(0);
        hotels.insert(V - 1);

        cin >> E;

        vet_adj.clear();
        vet_adj.resize(V);
        for (int i = 0; i < E; ++i) {
            int u, v, u2v;
            cin >> u >> v >> u2v;

            --u, --v;

            vet_adj[u].pb(mp(v, u2v));
            vet_adj[v].pb(mp(u, u2v));

        }

        vector<vi> sub_graph(V);
        for (auto u : hotels) {
            sssp(u);
            for (auto v: hotels) {
                if (u != v && dist[v] <= TEN_HOURS) {
                    sub_graph[u].pb(v);
                }
            }
        }

        vi dist_subgraph(V, 999999);
        queue<int> q;

        q.push(0);
        dist_subgraph[0] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &v : sub_graph[u]) {
                if (dist_subgraph[v] == 999999) {
                    dist_subgraph[v] = dist_subgraph[u] + 1;
                    q.push(v);
                 }
            }
        }


        if (dist_subgraph[V - 1] != 999999) {
            printf("%d\n", dist_subgraph[V - 1] - 1);
        } else {
            printf("-1\n");
        }

    }

    return 0;
}
