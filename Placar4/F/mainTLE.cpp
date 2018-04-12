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
typedef vector<int> vi;


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

int n_magias, V, E, n_monsters;
vi V_monster;
vector<list<int> > vet_adj;
vector<pii> vet_magias;
vi memo(1001);
long long INF = numeric_limits<long long>::max() -10000;

void gen_memo(){

    memo[0] = 0;
    for (size_t i = 1; i <= 1000; i++) {
        memo[i] = 1000000;
        for(auto &magic : vet_magias){
            int ni = i - magic.second;
            if(ni < 0) ni = 0;
            memo[i] = min(memo[i], memo[ni] + magic.first);
        }
    }
}


bool possible(long long M){

    vi visited(V, 0);
    vi blocked(V, 0);
    vector<long long> dist(V, INF);

    dist[0] = M - V_monster[0];
    visited[0] = 1;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(blocked[u]) continue;

        for(auto &v : vet_adj[u]){
            if(!visited[v]){
                visited[v] = 1;
                dist[v] = dist[u] - V_monster[v];
                if(dist[v] < 0){
                    blocked[v] = 1;
                }
                q.push(v);
            }
        }
    }

    return visited[V-1] && dist[V-1] >= 0;

}


long long solve(){
    long long upper = numeric_limits<long long>::max()-1000;
    long long lower = 0;
    long long mid = lower + (upper-lower)/2;

    while(lower < upper){
        mid = lower + (upper-lower)/2;
        if(possible(mid)){
            upper = mid;
        }else{
            lower = mid+1;
        }
    }

    return lower;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n_magias >> V >> E >> n_monsters, V != 0){

        vet_magias.clear();
        vet_magias.resize(n_magias);
        for (size_t i = 0; i < n_magias; i++) {
            cin >> vet_magias[i].first >> vet_magias[i].second;
        }

        vet_adj.clear();
        vet_adj.resize(V);
        int u, v;
        for (size_t i = 0; i < E; i++) {
            cin >> u >> v;
            --u,--v;
            vet_adj[u].push_back(v);
            vet_adj[v].push_back(u);
        }

        gen_memo();

        V_monster.clear();
        V_monster.resize(V, 0);
        int force = 0;
        for (size_t i = 0; i < n_monsters; i++) {
            cin >> u >> force;
            --u;
            V_monster[u] += memo[force];
        }

        print_vector_debug(V_monster);


        long long ans = solve();
        if(possible(ans)){
            cout << ans << endl;
        }else{
            cout << -1 << endl;
        }

    }

    return 0;
}
