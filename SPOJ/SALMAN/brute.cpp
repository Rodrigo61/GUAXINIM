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


vector<pii> ranged_tree;
int curr_time;
vector<vi> vet_adj;
vi salary_tree;


void update_rec(int id, ll value) {

    salary_tree[id] += value;

    for (auto &adj : vet_adj[id]) {
        update_rec(adj, value);
    }
}

ll get_min(int id) {

    ll mini = salary_tree[id];

    for (auto &adj : vet_adj[id]) {
        mini = min(mini, get_min(adj));
    }

    return mini;
}

void update(int id) {

    ll mini = get_min(id);

    update_rec(id, min((ll)1000, mini));
}

ll query(int id) {

    ll res = salary_tree[id];

    for (auto &adj : vet_adj[id]) {
        res += query(adj);
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;
    int case_count = 0;

    for (int w = 0; w < n_cases; ++w) {

        cout << "Case " << ++case_count << ":" <<endl;
        int sz, query_count;

        cin >> sz >> query_count;


        salary_tree.clear();
        salary_tree.resize(sz);

        vet_adj.clear();
        vet_adj.resize(sz);

        ranged_tree.clear();
        ranged_tree.resize(sz);

        int parent;
        for (int i = 0; i < sz; ++i) {
            cin >> parent >> salary_tree[i];

            --parent;

            if (i != 0)
                vet_adj[parent].push_back(i);
        }



        int type_query, emplo_id;
        for (int i = 0; i < query_count; ++i) {
            cin >> type_query >> emplo_id;

            --emplo_id;

            deb("type_query = ", type_query, "emplo_id = ", emplo_id);
            deb("ranged_tree[emplo_id] = ", ranged_tree[emplo_id].first, ",", ranged_tree[emplo_id].second);

            if (type_query == 1) {
                cout << query(emplo_id) << endl;
            } else {
                update(emplo_id);
            }

        }



    }

    return 0;
}
