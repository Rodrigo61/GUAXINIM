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
typedef vector<int> vi;


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
        int sz;
        cin >> sz;
        vi vet(sz);

        for (size_t i = 0; i < sz; i++) {
            cin >> vet[i];
        }

        int dp[sz][sz];
        memset(dp, 0, sizeof(dp));

        for (size_t i = 0; i < sz; i++) {
            dp[i][i] = vet[i];
        }

        for (size_t i = 0; i < sz-1; i++) {
            dp[i][i+1] = max(vet[i], vet[i+1]);
        }

        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz; j++) {
                cout << dp[i][j] << space;
            }
            cout << endl;
        }
        cout << endl;

        for (size_t l = 2; l < sz; l++) {
            for (size_t i = 0; i+l < sz; i++) {
                int j = i+l;

                deb("i = ", i);
                deb("j = ", j);
                deb("dp[i][j-2] = ", dp[i][j-2]);
                deb("dp[i+1][j-1]", dp[i+1][j-1]);
                deb("dp[i+2][j] = ", dp[i+2][j]);

                int right = vet[j];
                if(dp[i][j-2] + vet[j-1] > dp[i+1][j-1] + vet[i]){
                    right += dp[i][j-2];
                }else{
                    right += dp[i+1][j-1];
                }

                int left = vet[i];
                if(dp[i+2][j] + vet[i+1] > dp[i+1][j-1] + vet[j]){
                    left += dp[i+2][j];
                }else{
                    left += dp[i+1][j-1];
                }

                deb("right = ", right);
                deb("left = ", left);
                dp[i][j] = max(right, left);
                for (size_t i = 0; i < sz; i++) {
                    for (size_t j = 0; j < sz; j++) {
                        cout << dp[i][j] << space;
                    }
                    cout << endl;
                }
                cout << endl;

            }
        }

        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz; j++) {
                cout << dp[i][j] << space;
            }
            cout << endl;
        }
        cout << endl;

        cout << dp[0][sz-1] << endl;

    }
    return 0;
}
