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

int V, E;
vector<vi> vet_adj;
vi visited;
vi diameters;
int visit_count;

int get_farthest(int root) {

    int farthest = root;
    int farthest_distance = 0;

    ++visit_count;

    queue<pii> q;

    visited[root] = visit_count;
    q.push(mp(root, 0));

    while (!q.empty()) {
        int u = q.front().first;
        int dist_u = q.front().second;
        q.pop();

        for (auto &v : vet_adj[u]) {
            if (visited[v] != visit_count) {
                visited[v] = visit_count;
                int dist_v = dist_u + 1;

                if (dist_v > farthest_distance) {
                    farthest_distance = dist_v;
                    farthest = v;
                }

                q.push(mp(v, dist_v));
            }
        }
    }


    return farthest;
}


int get_distance(int source, int target) {

    ++visit_count;

    queue<pii> q;

    visited[source] = visit_count;
    q.push(mp(source, 0));

    while (!q.empty()) {
        int u = q.front().first;
        int dist_u = q.front().second;
        q.pop();

        for (auto &v : vet_adj[u]) {
            if (visited[v] != visit_count) {
                visited[v] = visit_count;
                int dist_v = dist_u + 1;
                q.push(mp(v, dist_v));

                if (v == target) {
                    return dist_v;
                }
            }
        }
    }

    return -1;
}


void calc_diameters() {

    diameters.clear();

    visited.resize(V, 0);
    visit_count = 0;

    for (size_t i = 0; i < V; i++) {
        if (!visited[i]) {

            int farthest = get_farthest(i);
            int farthest_from_farthest = get_farthest(farthest);

            //deb("i = ", i);
            //deb("farthest = ", farthest);
            //deb("farthest_from_farthest = ", farthest_from_farthest);

            diameters.push_back( -1 * get_distance(farthest, farthest_from_farthest));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;

    vet_adj.resize(V);

    int u, v;
    for (size_t i = 0; i < E; i++) {
        cin >> u >> v;

        vet_adj[u].push_back(v);
        vet_adj[v].push_back(u);
    }


    calc_diameters();

    sort(all(diameters));

    int max_diameter = -diameters[0];
    int r1, r2 = -1, r3 = -1;

    r1 = (-diameters[0] + 1) / 2;

    if (diameters.size() >= 2) {
        r2 = (-diameters[1] + 1) / 2;
    }

    if (diameters.size() >= 3) {
        r3 = (-diameters[2] + 1) / 2;
    }

    cout << max({max_diameter, r1 + r2 + 1, r2 + r3 + 2}) << endl;

    return 0;
}
