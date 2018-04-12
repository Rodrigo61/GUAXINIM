using namespace std;
bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "

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
vector<list<pii>> vet_adj;
vi visited;
vi topo_ordered;

int sssp(){

    vi dist(V, INF);
    dist[0] = 0;

    priority_queue<pii, vii, greater<pii>> pq;
    pq.push(mp(0, 0));

    while(!pq.empty()){
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();

        if(d_u != dist[u]) continue;

        for(auto &pv : vet_adj[u]){
            int v = pv.first;
            int u_v = pv.second;
            if(d_u + u_v < dist[v]){
                dist[v] = d_u + u_v;
                pq.push(mp(dist[v], v));
            }
        }
    }

    return dist[V-1];
}

void dfs(int root){

    visited[root] = 1;

    for(auto adj : vet_adj[root]){
        int v = adj.first;
        if(!visited[v]){
            dfs(v);
        }
    }

    topo_ordered.push_back(root);
}

void topologic_sort(){

    visited.resize(V,0);

    for (size_t i = 0; i < V; i++) {
        if(!visited[i]){
            dfs(i);
        }
    }

    print_vector_debug(topo_ordered);
    reverse(all(topo_ordered));
    deb("REVERSED");
    print_vector_debug(topo_ordered);
}

int sslp(){

    topo_ordered.clear();
    topologic_sort();

    vector<list<pii>> in_adj(V);

    for (size_t i = 0; i < V; i++) {
        for(auto &adj : vet_adj[i]){
            in_adj[adj.first].push_back(mp(i, adj.second));
        }
    }

    deb("index_on_topo");
    vi index_on_top_vector(V);
    for (size_t i = 0; i < V; i++) {
        index_on_top_vector[topo_ordered[i]] = i;
    }
    print_vector_debug(index_on_top_vector);

    int dp[V];

    for (size_t i = 0; i < V; i++) {
        int curr = topo_ordered[i];
        dp[i] = 0;

        for(auto &prev : in_adj[curr]){
            dp[i] = max(dp[i], dp[index_on_top_vector[prev.first]] + prev.second);
        }

        if(curr != 0 && in_adj[curr].empty()){
            dp[i] = -INF;
        }

    }

    deb("dp");
    print_array_debug(dp, V);
    return dp[index_on_top_vector[V-1]];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int C;
    cin >> V >> C >> E;

    vi has_store(V, 0);
    int u, v;
    for (size_t i = 0; i < C; i++) {
        cin >> u;
        --u;

        has_store[u] = 1;
    }

    print_vector_debug(has_store);
    vet_adj.resize(V);
    for (size_t i = 0; i < E; i++) {
        cin >> u >> v;
        --u,--v;

        if(v == 0) continue;
        if(u == V-1) continue;

        if(has_store[v]){
            vet_adj[u].push_back(mp(v, 1));
        }else{
            vet_adj[u].push_back(mp(v, 0));
        }
    }

    int store_source = has_store[0];
    int shortest = sssp() + store_source;
    int larger = sslp() + store_source;


    cout << shortest << "  " <<larger << endl;


    return 0;
}
