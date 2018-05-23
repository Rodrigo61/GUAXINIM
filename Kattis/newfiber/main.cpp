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

void gen_tree(vii &degree, vector<vi> &vet_adj, int curr_idx, int diff_one_pos) {


    if (curr_idx == vet_adj.size() - 2) {
        // Base: two vertices, always possible
        vet_adj[degree[curr_idx].second].push_back(degree[curr_idx + 1].second);
        return;
    }

    vet_adj[degree[curr_idx].second].push_back(degree[diff_one_pos].second);

    --degree[diff_one_pos].first;
    if (degree[diff_one_pos].first == 1) {
        ++diff_one_pos;
    }

    gen_tree(degree, vet_adj, curr_idx + 1, diff_one_pos);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    vii degree(V, mp(0, 0));

    int u, v;
    for (size_t i = 0; i < E; i++) {
        cin >> u >> v;

        degree[u].second = u;
        degree[v].second = v;
        ++degree[u].first;
        ++degree[v].first;
    }

    sort(all(degree));

    int target_degree = V + V - 2;

    int pos = 0;
    while (pos < V && target_degree - degree[pos].first >= V - pos - 1) {
        target_degree -= degree[pos].first;
        ++pos;
    }

    int change_count = V - pos;

    if (change_count > 0) {

        for (size_t i = pos; i < V - 1; i++) {
            degree[i].first = 1;
            target_degree -= 1;
        }

        degree[V - 1].first = target_degree;

        sort(all(degree));
    }

    vector<vi> vet_adj(V);
    pos = 0;
    while (degree[pos++].first == 1);

    gen_tree(degree, vet_adj, 0, pos - 1);

    printf("%d\n", change_count);
    printf("%d %d\n", V, V - 1);

    for (int i = 0; i < V; i++) {
        for (auto &v : vet_adj[i]) {
            printf("%d %d\n", i, v);
        }
    }

    return 0;
}
