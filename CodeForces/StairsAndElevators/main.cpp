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

    ll R, C;
    ll n_ladders, n_elevators;
    ll elevator_speed;

    cin >> R >> C >> n_ladders >> n_elevators >> elevator_speed;

    vi ladders(n_ladders);
    for (size_t i = 0; i < n_ladders; i++) {
        cin >> ladders[i];
        --ladders[i];
    }

    vi elevators(n_elevators);
    for (size_t i = 0; i < n_elevators; i++) {
        cin >> elevators[i];
        --elevators[i];
    }




    ll n_querys;
    cin >> n_querys;

    ll i_s, j_s, i_t, j_t;
    for (size_t i = 0; i < n_querys; i++) {
        cin >> i_s >> j_s >> i_t >> j_t;

        --i_s, --j_s, --i_t, --j_t;

        ll min_dist = numeric_limits<ll>::max();
        ll rows_diff = abs(i_t - i_s);

        // left ladder
        auto it = lower_bound(all(ladders), j_s);
        if (it != ladders.begin()) {
            --it;
            if (*it < j_s) {
                ll total_dist = abs(j_s - *it);
                total_dist += rows_diff;
                total_dist += abs(j_t - *it);
                min_dist = min(min_dist, total_dist);
            }
        }

        // left elevator
        it = lower_bound(all(elevators), j_s);
        if (it != elevators.begin()) {
            --it;
            if (*it < j_s) {
                ll total_dist = abs(j_s - *it);
                total_dist += ceil((double)rows_diff / elevator_speed);
                total_dist += abs(j_t - *it);
                min_dist = min(min_dist, total_dist);
            }
        }

        // right ladder
        it = upper_bound(all(ladders), j_s);
        if (it != ladders.end()) {
            ll total_dist = abs(j_s - *it);
            total_dist += rows_diff;
            total_dist += abs(j_t - *it);
            min_dist = min(min_dist, total_dist);
        }

        // right elevator
        it = upper_bound(all(elevators), j_s);
        if (it != elevators.end()) {
            ll total_dist = abs(j_s - *it);
            total_dist += ceil((double)rows_diff / elevator_speed);
            total_dist += abs(j_t - *it);
            min_dist = min(min_dist, total_dist);
        }

        if (rows_diff == 0) {
            min_dist = abs(j_t - j_s);
        }

        cout << min_dist << endl;

    }





    return 0;
}
