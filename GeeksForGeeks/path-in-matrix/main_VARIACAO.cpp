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


// VARIACAO SUGERIDA PELA PAGINA https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (size_t q = 0; q < n_cases; q++) {

        int N;
        cin >> N;

        int mat[N][N];
        vector<vi> cells;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> mat[i][j];
                cells.push_back(vi({-mat[i][j], i, j}));
            }
        }

        sort(all(cells));

        int dp[N][N];
        memset(dp, 0, sizeof(dp));
        int maxi_path = 0;
        for(auto cell : cells){
            int i = cell[1];
            int j = cell[2];
            int val = -cell[0];

            deb("val = ", val);
            deb("i = ", i);
            deb("j = ", j);

            dp[i][j] = 0;

            if(i-1 >= 0 && mat[i-1][j] == val+1){
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
            if(i+1 < N && mat[i+1][j] == val+1){
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
            }
            if(j-1 >= 0 && mat[i][j-1] == val+1){
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
            if(j+1 < N && mat[i][j+1] == val+1){
                dp[i][j] = max(dp[i][j], dp[i][j+1]);
            }

            dp[i][j] += val;
            maxi_path = max(maxi_path, dp[i][j]);
        }

        if(debug){
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < N; j++) {
                    cout << dp[i][j] << space;
                }
                cout << endl;
            }
            cout << endl;
        }


        cout << maxi_path << endl;
    }
    return 0;
}
