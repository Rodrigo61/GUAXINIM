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


/*
    A ideia é que feito um SSSP na fonte e no alvo. O vertice que tiver
    dist_source[v] + dist_target[v] = min_dist_source2target
    pertence a um caminho minimo.

    Outra ideia é que o caminho nao pode passar por um vertice que n pertenca
    a um caminho minimo nos dois alvos, senao n seria minimo. Entao precisamos
    pegar vertices em comum que respeitem a def. acima.
*/

#define INF 100000000000000

int source, target1, target2;
int V, E;
vector<list<pair<int, ll>>> vet_adj;
vll dist;


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

    print_vector_debug(dist);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> V >> source >> target1 >> target2 >> E, V != -1) {

        --source, --target1, --target2;


        vet_adj.clear();
        vet_adj.resize(V);
        int u, v, u2v;
        for (size_t i = 0; i < E; i++) {
            cin >> u >> v >> u2v;
            --u,--v;

            vet_adj[u].pb(mp(v, u2v));
            vet_adj[v].pb(mp(u, u2v));
        }


        sssp(source);
        vll dist_source = dist;
        ll min_dist_target1 = dist[target1];
        ll min_dist_target2 = dist[target2];


        set<int> min_path_vertices1, min_path_vertices2;

        sssp(target1);
        vll dist_target1 = dist;
        for (int i = 0; i < V; ++i) {

            if (dist_source[i] + dist_target1[i] == min_dist_target1) {
                min_path_vertices1.insert(i);
            }
        }

        sssp(target2);
        vll dist_target2 = dist;
        for (int i = 0; i < V; ++i) {

            if (dist_source[i] + dist_target2[i] == min_dist_target2) {
                min_path_vertices2.insert(i);
            }
        }

        ll max_dist_together = 0;
        for (auto &v : min_path_vertices1) {
            if (min_path_vertices2.find(v) != min_path_vertices2.end()) {
                max_dist_together = max(max_dist_together, dist_source[v]);
            }
        }

        printf("%lld %lld %lld\n", max_dist_together, min_dist_target1 - max_dist_together, min_dist_target2 - max_dist_together);

    }

    return 0;
}
