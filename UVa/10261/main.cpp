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

#define INF 999999

vi car_sz;
vi acu_sum;
int max_idx;
int total_ferry_sz;
vector<vector<pair<vi, int>>> memo;
vector<vi> memo_check;

pair<vi, int> solve(int idx, int ferry_sz) {


    if (ferry_sz <= 0 || idx == -1){
        pair<vi, int>  res;
        res.second = 0;

        if (ferry_sz < 0)
            res.second = INF;

        return res;
    }

    auto &res = memo[idx][ferry_sz];

    if (memo_check[idx][ferry_sz]) {
        return res;
    }

    memo_check[idx][ferry_sz] = 1;

    auto take_option = solve(idx - 1, ferry_sz - car_sz[idx]);
    auto not_take_option = solve(idx - 1, ferry_sz);

    deb("idx = ", idx);
    deb("ferry_sz = ", ferry_sz);
    deb("take_option.second = ", take_option.second);
    deb("not_take_option.second = ", not_take_option.second);
    deb("acu_sum[idx] = ", acu_sum[idx]);

    res.second = INF;

    if (not_take_option.second != INF && not_take_option.second <= ferry_sz && acu_sum[idx] - not_take_option.second <= total_ferry_sz) {

        res = not_take_option;

    }

    if (take_option.second != INF && take_option.second + car_sz[idx] <= ferry_sz && acu_sum[idx] - take_option.second - car_sz[idx] <= total_ferry_sz){

        if (res.second != INF && take_option.second + car_sz[idx] > res.second) {
            res = take_option;
            res.second += car_sz[idx];
            res.first.push_back(idx);
        }

    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (size_t q = 0; q < n_cases; q++) {

        int ferry_sz;

        car_sz.clear();

        cin >> ferry_sz;
        ferry_sz *= 100;

        int car;
        while (cin >> car, car) {
            car_sz.push_back(car);
        }

        acu_sum.clear();
        acu_sum.resize(car_sz.size(), 0);
        acu_sum[0] = car_sz[0];
        for (size_t i = 1; i < car_sz.size(); i++) {
            acu_sum[i] = acu_sum[i - 1] + car_sz[i];
        }

        deb("solving");
        max_idx = car_sz.size();

        pair<vi, int> res;
        vi port_cars;
        int idx = car_sz.size() - 1;

        memo.clear();
        memo.resize(car_sz.size(), vector<pair<vi, int>>(ferry_sz + 1));
        memo_check.clear();
        memo_check.resize(car_sz.size(), vi(ferry_sz + 1));

        for (size_t i = 0; i < car_sz.size(); i++) {
            for (size_t j = 0; j < ferry_sz + 1; j++) {
                memo_check[i][j] = 0;
            }
        }

        total_ferry_sz = ferry_sz;
        do {
            res = solve(idx, ferry_sz);
            port_cars = res.first;
            --idx;
        } while (res.second == INF);

        deb("idx= ", idx);
        print_vector_debug(port_cars);
        cout << idx + 2 << endl;
        for (int i = idx + 1; i >= 0; i--) {
            if (binary_search(all(port_cars), i)) {
                cout << "port" << endl;
            } else {
                cout << "starboard" << endl;
            }
        }

        if (q != n_cases - 1) {
            cout << endl;
        }

    }
    return 0;
}
