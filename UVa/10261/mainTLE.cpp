using namespace std;
bool debug = true;

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

vi car_sz;
vector<vector<vector<vector<string>>>> memo;
vector<vector<vector<int>>> memo_check;

vector<string> solve(int idx, int port_remaining, int starport_remaining) {

    deb("idx = ", idx);
    deb("port_remaining = ", port_remaining);
    deb("starport_remaining = ", starport_remaining);


    if (idx == car_sz.size()) {
        vector<string> res;
        return res;
    }

    vector<string> &res = memo[idx][port_remaining][starport_remaining];

    if (memo_check[idx][port_remaining][starport_remaining]) {
        return res;
    }

    memo_check[idx][port_remaining][starport_remaining] = 1;

    vector<string> go_port;
    vector<string> go_starport;

    if (port_remaining - car_sz[idx] >= 0) {
        go_port = solve(idx + 1, port_remaining - car_sz[idx], starport_remaining);
    }

    if (starport_remaining - car_sz[idx] >= 0) {
        go_starport = solve(idx + 1, port_remaining, starport_remaining  - car_sz[idx]);
    }

    if (port_remaining - car_sz[idx] < 0 && starport_remaining - car_sz[idx] < 0) {
        return res;
    }

    if (go_port.size() > go_starport.size()) {
        res = go_port;
        res.push_back("port");
        return res;
    } else {
        res = go_starport;
        res.push_back("starport");
        return res;
    }


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

        deb("creating memo");
        memo.clear();
        memo.resize(car_sz.size(), vector<vector<vector<string>>>(ferry_sz + 1, vector<vector<string>> (ferry_sz + 1)));
        memo_check.clear();
        memo_check.resize(car_sz.size(), vector<vector<int>>(ferry_sz + 1, vector<int> (ferry_sz + 1, 0)));
        deb("created memo");

        auto res = solve(0, ferry_sz, ferry_sz);
        reverse(all(res));

        deb("res final.size() = ", res.size());
        cout << res.size() << endl;
        for (auto &s : res) {
            cout << s << endl;
        }

        if (q != n_cases - 1) {
            cout << endl;
        }

    }
    return 0;
}
