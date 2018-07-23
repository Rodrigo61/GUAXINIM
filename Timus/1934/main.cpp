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

int V, E;


vector<vii> vet_adj;
vi dist;
vector<double> prob;


void sssp(int source, int target){

    dist.clear();
    dist.resize(V, INF);

    prob.clear();
    prob.resize(V, INF);

    vi in_queue(V, 0);

    vi parent(V, -1);

    dist[source] = 0;
    prob[source] = 1;

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    pq.push(mp(0, source));
    in_queue[source] = 1;


    while(!pq.empty()){

        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();
        in_queue[u] = 0;

        if(dist[u] < d_u) continue;

        for(auto &pv : vet_adj[u]){

            int v = pv.first;
            int d_u2v = 1;
            double p_u2v = 1 - (double)pv.second/100;
            deb("p_u2v = ", p_u2v);

            if(d_u + d_u2v < dist[v]) {
                dist[v] = d_u + d_u2v;
                prob[v] = prob[u] * p_u2v;

                parent[v] = u;

                if (!in_queue[v]){
                    pq.push(mp(dist[v], v));
                    in_queue[v] = 1;
                }

            } else if(d_u + d_u2v == dist[v] && prob[u] * p_u2v > prob[v]) {

                dist[v] = d_u + d_u2v;
                prob[v] = prob[u] * p_u2v;

                parent[v] = u;

                if (!in_queue[v]){
                    pq.push(mp(dist[v], v));
                    in_queue[v] = 1;
                }
            }

        }
    }


    vi path;
    int u = target;
    while (parent[u] != -1) {
        path.pb(u);
        u = parent[u];
    }
    path.pb(u);

    reverse(all(path));


    printf("%d %lf\n", path.size(), 1.0 - prob[target]);
    for (int i = 0; i < path.size(); ++i) {
        printf("%d", path[i] + 1);

        if (i != path.size() - 1) {
            printf(" ");
        }
    }
    printf("\n");


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;

    int source, target;
    cin >> source >> target;
    --source, --target;

    vet_adj.resize(V);

    for (int i = 0; i < E; ++i) {
        int u, v, p;
        cin >> u >> v >> p;
        --u, --v;

        vet_adj[u].pb(mp(v, p));
        vet_adj[v].pb(mp(u, p));
    }

    sssp(source, target);

    return 0;
}
