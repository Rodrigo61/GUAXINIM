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
#define INF 100000000000000

struct Edge {
    int u, v;
    ll primary;
    ll secondary;
};

int V, E;
int source, target;
char type;

vector<vector<Edge>> in_adj;
vector<vector<Edge>> out_adj;

ll source_to_target;
vll dist_from_source, dist_from_target;

vll dist;
vi visited;
vi sorted_vertices;

void aux_dfs(int root){

    visited[root] = 1;

    for(auto &edge : out_adj[root]){
        int v = edge.v;
        if(!visited[v] && dist_from_source[root] + edge.primary == dist_from_source[v])
            aux_dfs(v);
    }

    sorted_vertices.push_back(root);
}

void topological_sort(){

    visited.clear();
    visited.resize(V, 0);

    sorted_vertices.clear();
    sorted_vertices.reserve(V);

    aux_dfs(source);

    reverse(all(sorted_vertices));

}

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

        for(auto &edge : out_adj[u]){
            int v = edge.v;
            ll u_v = edge.primary;

            if(d_u + u_v < dist[v]){
                dist[v] = d_u + u_v;
                pq.push(mp(dist[v], v));
            }
        }
    }

    return dist[target];

}

ll sssp_rev(int source, int target){

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

        for(auto &edge : in_adj[u]){
            int v = edge.u;
            ll u_v = edge.primary;

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


    cin >> V >> E >> type;

    cin >> source >> target;
    --source, --target;

    in_adj.resize(V);
    out_adj.resize(V);

    for (int i = 0; i < E; ++i) {
        int u, v;
        ll cost, time;

        cin >> u >> v >> cost >> time;
        --u, --v;

        if (type == 'P') {

            Edge new_edge;
            new_edge.v = v;
            new_edge.u = u;
            new_edge.primary = cost;
            new_edge.secondary = time;

            out_adj[u].pb(new_edge);
            in_adj[v].pb(new_edge);
        } else {
            Edge new_edge;
            new_edge.v = v;
            new_edge.u = u;
            new_edge.primary = time;
            new_edge.secondary = cost;

            out_adj[u].pb(new_edge);
            in_adj[v].pb(new_edge);
        }
    }


    source_to_target = sssp(source, target);
    if (source_to_target == INF) {
        printf("-1\n");
        return 0;
    }
    dist_from_source = dist;

    sssp_rev(target, source);
    dist_from_target = dist;


    topological_sort();
    vi map_to_sorted(V, -1);
    for (int i = 0; i < sorted_vertices.size(); ++i) {
        map_to_sorted[sorted_vertices[i]] = i;
    }


    vector<pair<ll, ll>> dp(sorted_vertices.size(), mp(INF, INF));
    dp[0] = mp(0, 0);

    for (int i = 1; i < dp.size(); ++i) {
        int v = sorted_vertices[i];

        for (auto &edge : in_adj[v]) {

            if (dist_from_source[edge.u] + edge.primary == dist_from_source[v]) {
                dp[i] = min(dp[i], mp(dp[map_to_sorted[edge.u]].first + edge.secondary, dp[map_to_sorted[edge.u]].second + 1));
            }
        }
    }


    if (type == 'P') {
        printf("%lld %lld %lld\n", source_to_target, dp[map_to_sorted[target]].first, dp[map_to_sorted[target]].second - 1);
    } else {
        printf("%lld %lld %lld\n", dp[map_to_sorted[target]].first, source_to_target, dp[map_to_sorted[target]].second - 1);
    }


    return 0;
}
