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

    int n_cases;
    cin >> n_cases;

    for (size_t q = 0; q < n_cases; q++) {

        string line;
        cin >> line;

        int sz = line.size();

        ll dp[sz];
        memset(dp, 0, sizeof(dp));

        ll maxi = 1;
        for (int i = sz-1; i >= 0; i--) {
            dp[i] = 1;

            for (size_t k = i+1; k < sz; k++) {

                if (line[i] <= line[k]) {
                    dp[i] = max(dp[i], dp[k] + 1);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        print_array_debug(dp, sz);

        vector< vector<string> > solutions(sz);
        for (int i = sz-1; i >= 0; i--) {
            ll target = dp[i] - 1;

            deb("i = ", i);
            deb("target = ", target);
            for (int j = i + 1; j < sz; j++) {

                if (dp[j] == target && line[i] <= line[j]) {
                    deb("assigned index j = ", j);
                    solutions[i].insert(solutions[i].end(), all(solutions[j]));
                    deb("solutions[i].size() = ", solutions[i].size());
                }

            }

            if (solutions[i].empty()) {
                string s = string(1, line[i]);
                solutions[i].push_back(s);
            } else {

                for (auto &sol : solutions[i]) {
                    sol.push_back(line[i]);
                }

            }
        }

        vii starters;
        for (size_t i = 0; i < sz; i++) {
            if (dp[i] == maxi) {
                starters.push_back(mp(line[i], i));
            }
        }

        sort(all(starters));

        deb("maxi = ", maxi);
        for (auto &starter : starters){
            int i = starter.second;
            for (auto &sol : solutions[i]) {
                reverse(all(sol));
            }

            sort(all(solutions[i]));

            for (auto &sol : solutions[i]) {
                cout << sol << endl;
            }
        }

        cout << endl;
    }

    return 0;
}
