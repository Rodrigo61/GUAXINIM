bool debug = false;
#define INF 100000000000000

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

/* pair com o id do vizinho e a distancia até ele */
vector<set<pair<int, pair<ll, int>>>> vet_adj;
vll dist;

ll sssp(int source, int target){

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
            ll u_v = pv.second.first;

            if(d_u + u_v < dist[v]){
                dist[v] = d_u + u_v;
                pq.push(mp(dist[v], v));
            }
        }
    }

    return dist[target];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;

    vet_adj.resize(V);
    int u, v, u2v;
    for (size_t i = 0; i < E; i++) {
        cin >> u >> v >> u2v;

        deb("u = ", u, "v = ", v);
        if (u != v) {

            auto lower = vet_adj[u].lower_bound(mp(v, mp(0, 0)));
            deb("d1");
            if (lower == vet_adj[u].end() || lower->first != v) {
                vet_adj[u].insert(mp(v, mp(u2v, 1)));
                vet_adj[v].insert(mp(u, mp(u2v, 1)));
                deb("d2");
            } else if (lower->second.first > u2v){
                deb("d3");
                vet_adj[u].erase(lower);
                vet_adj[u].insert(mp(v, mp(u2v, 1)));

                lower = vet_adj[v].lower_bound(mp(u, mp(0,0)));
                vet_adj[v].erase(lower);
                vet_adj[v].insert(mp(u, mp(u2v, 1)));
            } else if (lower->second.first == u2v){
                deb("d4");
                int count = lower->second.second + 1;
                vet_adj[u].erase(lower);
                vet_adj[u].insert(mp(v, mp(u2v, count)));
deb("d44");
                lower = vet_adj[v].lower_bound(mp(u, mp(0,0)));
                vet_adj[v].erase(lower);
                vet_adj[v].insert(mp(u, mp(u2v, count)));
                deb("d4444");
            }

        }
    }

    deb("fim insert");
    sssp(0, V - 1);
    vll dist_source = dist;
    vector<vi> edge_visited(V, vi(V, 0));

    deb("dist_source[V - 1] = ", dist_source[V - 1]);

    sssp(V - 1, 0);
    vll dist_target = dist;
    queue<pii> q;

    q.push(mp(0, 0));

    ll cost = 0;

    while (!q.empty()) {
        int u = q.front().first;
        int dist_u = q.front().second;
        q.pop();

        deb("iteration");

        for (auto pv : vet_adj[u]) {
            int v = pv.first;
            int u2v = pv.second.first;
            int count = pv.second.second;


            deb("u = ", u);
            deb("v = ", v);
            deb("dist_u + u2v = ", dist_u + u2v);
            deb("dist_source[v] = ", dist_source[v]);
            deb("dist_target[v] = ", dist_target[v]);
            if (!edge_visited[u][v] && dist_source[v] + dist_target[v] == dist_source[V - 1] && dist_u + u2v == dist_source[v]) {
                edge_visited[u][v] = 1;

                deb("u2v = ", u2v);
                deb("cost = ", cost);

                deb("cost = ", cost);
                cost += 2 * u2v * count;

                deb("cost after = ", cost);
                q.push(mp(v, dist_source[v]));
            }

        }
    }

    printf("%lld\n", cost);



    return 0;
}
