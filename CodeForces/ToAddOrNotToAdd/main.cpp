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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll N, K;
    cin >> N >> K;

    vll vet(N);
    for (size_t i = 0; i < N; i++) {
        cin >> vet[i];
    }

    sort(all(vet));

    vll acu(N, 0);
    acu[0] = vet[0];
    for (size_t i = 1; i < N; i++) {
        acu[i] = acu[i - 1] + vet[i];
    }


    ll max_seq_sz = 0;
    ll max_seq_rep = vet[0];
    ll last_reached = 0;
    for (ll i = 0; i < N; i++) {

        deb("i = ", i);
        deb("max_seq_sz = ", max_seq_sz);
        deb("max_seq_rep = ", max_seq_rep);
        deb("last_reached = ", last_reached);

        if (i - last_reached < max_seq_sz) {
            continue;
        }

        ll beg_interval = last_reached;
        ll interval_sz = 0;

        while (beg_interval < i) {
            deb("beg_interval = ", beg_interval);
            interval_sz = i - beg_interval;
            deb("interval_sz = ", interval_sz);

            ll expected_sum = interval_sz * vet[i];
            ll real_sum = acu[i] - vet[i] - acu[beg_interval] + vet[beg_interval];

            deb("expected_sum = ", expected_sum);
            deb("real_sum = ", real_sum);

            if (expected_sum - real_sum <= K) {
                break;
            }

            ++beg_interval;
        }


        deb("interval_sz final = ", interval_sz);
        if (interval_sz > max_seq_sz) {
            max_seq_sz = interval_sz;
            max_seq_rep = vet[i];
        }

        last_reached = beg_interval;
    }


    cout << max_seq_sz + 1 << " " << max_seq_rep << endl;


    return 0;
}
