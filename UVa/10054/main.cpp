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

int E;
vector<list<int>> vet_adj;
list<int> tour_list;

bool check_parity() {

    for (int i = 0; i < 51; ++i){

        list<int> &set = vet_adj[i];
        int count = 0;

        for (auto &edge : set) {
            if (edge != i) {
                ++count;
            }
        }

        if (count % 2 != 0) {
            return false;
        }
    }

    return true;
}


void euler_tour (int u, list<int>::iterator it) {

    deb("u = ", u);
    deb("vet_adj[u].size() = ", vet_adj[u].size());
    while (!vet_adj[u].empty()) {
        int v = *vet_adj[u].begin();
        deb("v = ", v);
        vet_adj[u].erase(find(all(vet_adj[u]), v));
        vet_adj[v].erase(find(all(vet_adj[v]), u));
        euler_tour(v, tour_list.insert(it, v));
    }

}

bool connected(vi used_stones) {

    int root = 0;
    for (int i = 0; i < 51; ++i) {
        if (used_stones[i]) {
            root = i;
            break;
        }
    }


    used_stones[root] = 0;
    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &v : vet_adj[u]) {
            if (used_stones[v]) {
                used_stones[v] = 0;
                q.push(v);
            }
        }
    }


    for (int i = 0; i < 51; ++i) {
        if (used_stones[i]) {
            return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;
    int case_count = 0;

    for (size_t q = 0; q < n_cases; q++) {

        cin >> E;

        vet_adj.clear();
        vet_adj.resize(51);

        vi used_stones(51, 0);
        int u, v;
        for (size_t i = 0; i < E; i++) {
            cin >> u >> v;

            vet_adj[u].push_back(v);
            vet_adj[v].push_back(u);

            used_stones[u] = used_stones[v] = 1;
        }

        printf("Case #%d\n", ++case_count);
        if (!check_parity() || !connected(used_stones)) {
            printf("some beads may be lost\n");
        } else {
            tour_list.clear();
            tour_list.insert(tour_list.begin(), u);
            euler_tour(u, tour_list.begin());

            deb("tour_list.size() = ", tour_list.size());
            auto it = tour_list.begin();
            int last_vertice = *it;
            ++it;

            for (; it != tour_list.end(); ++it) {
                printf("%d %d\n", last_vertice, *it);
                last_vertice = *it;
            }

        }

        if (q != n_cases - 1) {
            printf("\n");
        }


    }
    return 0;
}
