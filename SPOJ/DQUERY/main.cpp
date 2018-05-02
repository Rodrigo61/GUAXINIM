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

void queryResults(int a[], int n, Query q[], int m, vi &results) {

    blocks = sqrt(n);

    sort(q, q + m, queryComparator);

    int currL = 0, currR = 0;
    vi freq(1000001, 0);

    int distinct_count = 1;
    freq[a[0]] = 1;

    results.resize(m);

    for (size_t i = 0; i < m; i++) {
        int L = q[i].L, R = q[i].R;


        while (currL > L) {
            deb("currL1 = ", currL);
            if (freq[a[currL - 1]] == 0) {
                distinct_count++;
            }
            ++freq[a[currL - 1]];
            --currL;

        }

        while (currR < R) {
            deb("currR1 = ", currR);
            if (freq[a[currR + 1]] == 0) {
                distinct_count++;
            }
            ++freq[a[currR + 1]];
            ++currR;
        }

        while (currR > R) {
            deb("currR = ", currR);
            --freq[a[currR]];
            if (freq[a[currR]] == 0) {
                --distinct_count;
            }
            --currR;
        }

        while (currL < L) {
            deb("currL = ", currL);
            --freq[a[currL]];
            if (freq[a[currL]] == 0) {
                --distinct_count;
            }
            ++currL;
        }

        results[q[i].order] = distinct_count;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n;
    int a[n];
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    Query q[m];
    for (size_t i = 0; i < m; i++) {
        Query new_query;
        cin >> new_query.L >> new_query.R;
        --new_query.L, --new_query.R;
        new_query.order = i;
        deb("new_query.L = ", new_query.L, "new_query.R = ", new_query.R);
        q[i] = new_query;
    }

    vi results;
    queryResults(a, n, q, m, results);

    for (auto &res : results) {
        printf("%d\n", res);
    }

    return 0;
}
