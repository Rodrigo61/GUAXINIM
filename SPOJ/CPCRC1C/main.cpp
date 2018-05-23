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

int A, B;
vi values;
vector<vll> memo;

ll solve(int curr_idx, int freedom) {

    if (curr_idx == values.size()) {
        return 0;
    }

    ll &res = memo[curr_idx][freedom];

    if (res != -1) {
        return res;
    }

    res = 0;

    int full_remain_num = 0;
    for (int i = curr_idx + 1; i < values.size(); ++i){
        full_remain_num *= 10;
        full_remain_num += 9;
    }

    if (freedom) {
        for (ll i = 0; i < 10; i++) {
            res += solve(curr_idx + 1, 1) + i * (full_remain_num + 1);
        }
    } else {

        int remaining_num = 0;
        for (int i = curr_idx + 1; i < values.size() ; ++i){
            remaining_num *= 10;
            remaining_num += values[i];
        }

        res = solve(curr_idx + 1, 0) + values[curr_idx] * (remaining_num + 1);

        for (ll i = 0; i < values[curr_idx]; ++i) {
            deb("res1 = ", res);
            res += solve(curr_idx + 1, 1) + i * (full_remain_num + 1);
            deb("res2 = ", res);
        }

    }

    deb("curr_idx = ", curr_idx);
    deb("res = ", res);
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> A >> B, A != -1) {

        string str_A = to_string(A);
        values.clear();
        values.reserve(str_A.size());
        ll sum_A = 0;
        for (auto &c : str_A) {
            values.push_back(c - '0');
            sum_A += c - '0';
        }
        deb("str_A = ", str_A);
        print_vector_debug(values);
        memo.clear();
        memo.resize(11, vll(2, -1));
        ll res_A = solve(0, 0);

        string str_B = to_string(B);
        values.clear();
        values.reserve(str_B.size());
        deb("str_B = ", str_B);
        for (auto &c : str_B) {
            values.push_back(c - '0');
        }
        print_vector_debug(values);
        memo.clear();
        memo.resize(11, vll(2, -1));
        ll res_B = solve(0, 0);


        deb("res_B = ", res_B);
        deb("res_A = ", res_A);
        printf("%lld\n", res_B - res_A + sum_A);
    }

    return 0;
}
