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
//</editor-fold desc="GUAXINIM TEMPLATE">




int main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    int count_case = 0;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {

        int n_buildings;
        cin >> n_buildings;

        vi height(n_buildings);
        vi width(n_buildings);

        for (int i = 0; i < n_buildings; ++i) {
            cin >> height[i];
        }

        for (int i = 0; i < n_buildings; ++i) {
            cin >> width[i];
        }


        /* LIS */
        vi dp(n_buildings);
        dp[0] = width[0];
        int maxi_inc = width[0];
        for (int i = 1; i < n_buildings; ++i) {
            dp[i] = width[i];
            for (int k = i-1; k >= 0; --k) {
                if(height[k] < height[i]){
                    if(dp[k] + width[i] > dp[i]){
                        dp[i] = dp[k] + width[i];
                    }
                }
            }

            maxi_inc = max(maxi_inc, dp[i]);
        }

        /* LDS */
        dp[0] = width[0];
        int maxi_dec = width[0];
        for (int i = 1; i < n_buildings; ++i) {
            dp[i] = width[i];
            for (int k = i-1; k >= 0; --k) {
                if(height[k] > height[i]){
                    if(dp[k] + width[i] > dp[i]){
                        dp[i] = dp[k] + width[i];
                    }
                }
            }

            maxi_dec = max(maxi_dec, dp[i]);
        }

        deb("m_inc = ", maxi_inc);
        deb("maxi_dec = ", maxi_dec);


        cout << "Case " << ++count_case << ". ";
        if(maxi_inc >= maxi_dec){
            printf("Increasing (%d). Decreasing (%d).", maxi_inc, maxi_dec);
        }else{
            printf("Decreasing (%d). Increasing (%d).", maxi_dec, maxi_inc);
        }
        cout << endl;

    }

    return 0;
}