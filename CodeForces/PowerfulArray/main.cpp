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

int blocks;

struct Query{
    int L, R;
    int order;
};

bool queryComparator(Query &q1, Query &q2) {

    if (q1.L / blocks == q2.L / blocks) {
        return q1.R < q2.R;
    }

    return q1.L / blocks < q2.L / blocks;
}

void solve(vi &values, vector<Query> &vet_query, vll &results) {

    blocks = sqrt(values.size());

    sort(all(vet_query), queryComparator);

    results.resize(vet_query.size());
    vll freq(1000001, 0);
    int currL = 0, currR = 0;
    freq[values[0]] = 1;
    ll current_power = values[0];

    int n_query = vet_query.size();
    for (size_t i = 0; i < n_query; i++) {
        int L = vet_query[i].L;
        int R = vet_query[i].R;

        while (currL > L) {
            current_power += (freq[values[currL - 1]] << 1) * values[currL - 1] + values[currL - 1];
            freq[values[currL - 1]]++;
            --currL;
        }

        while (currR < R) {
            current_power += (freq[values[currR + 1]] << 1) * values[currR + 1] + values[currR + 1];
            freq[values[currR + 1]]++;
            ++currR;
        }


        while (currL < L) {
            current_power = current_power - ((freq[values[currL]] << 1) * values[currL]) + values[currL];
            freq[values[currL]]--;
            ++currL;
        }

        while (currR > R) {
            current_power = current_power - ((freq[values[currR]] << 1) * values[currR]) + values[currR];
            freq[values[currR]]--;
            --currR;
        }

        results[vet_query[i].order] = current_power;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sz, n_querys;
    cin >> sz >> n_querys;

    vi values(sz);
    for (size_t i = 0; i < sz; i++) {
        cin >> values[i];
    }

    vector<Query> vet_query(n_querys);
    for (size_t i = 0; i < n_querys; i++) {
        cin >> vet_query[i].L >> vet_query[i].R;
        --vet_query[i].L, --vet_query[i].R;

        vet_query[i].order = i;
    }

    vll results;
    solve(values, vet_query, results);

    for (auto &res : results) {
        printf("%lld\n", res);
    }

    return 0;
}
