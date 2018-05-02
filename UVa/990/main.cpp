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

    int T, W;
    int n_treasures;

    bool first = true;

    while (cin >> T >> W >> n_treasures) {

        if (!first) {
            cout << endl;
        }

        first = false;

        vi distance(n_treasures);
        vi price(n_treasures);

        for (size_t i = 0; i < n_treasures; i++) {
            cin >> distance[i] >> price[i];
        }



        ll dp[n_treasures + 1][T + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = n_treasures - 1; i >= 0; i--) {
            for (int j = 0; j <= T; ++j) {

                dp[i][j] = dp[i + 1][j];

                int consumed = j + distance[i] * W + 2 * W * distance[i];

                if (consumed <= T) {
                    if (dp[i + 1][consumed] + price[i] > dp[i + 1][j]) {
                        dp[i][j] = dp[i + 1][consumed] + price[i];
                    }
                }
            }
        }

        if (debug) {

            for (size_t i = 0; i < n_treasures + 1; i++) {
                for (size_t j = 0; j < T + 1; j++) {

                    cout << dp[i][j] << space;
                }
                cout << endl;
            }
            cout << endl;
        }


        cout << dp[0][0] << endl;

        int idx = 0;
        int curr_mount = dp[0][0];
        int curr_time = 0;

        vii solution;

        while (idx != n_treasures) {

            if (dp[idx + 1][curr_time] != curr_mount) {
                solution.push_back(mp(distance[idx], price[idx]));
                curr_mount -= price[idx];
                curr_time +=  distance[idx] * W + 2 * W * distance[idx];
            }

            idx = idx + 1;

        }

        cout << solution.size() << endl;
        for (auto &p : solution) {
            cout << p.first << " " << p.second << endl;
        }

    }

    return 0;
}
