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

int value(char i) {
    if (i == '0')
        return - 9999999;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;
    cin.ignore();

    string line;
    getline(cin, line);

    for (size_t q = 0; q < n_cases; q++) {

        vector<string> str_grid;

        while(getline(cin, line), !line.empty()) {
            str_grid.push_back(line);
        }

        int R = str_grid.size();
        int C = str_grid[0].size();

        ll acu_grid[R][C];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {

                acu_grid[i][j] = value(str_grid[i][j]);

                if (i - 1 >= 0) {
                    acu_grid[i][j] += acu_grid[i - 1][j];
                }

                if (j - 1 >= 0) {
                    acu_grid[i][j] += acu_grid[i][j - 1];
                }

                if (i - 1 >= 0 && j - 1 >= 0) {
                    acu_grid[i][j] -= acu_grid[i - 1][j - 1];
                }
            }
        }


        ll maxi = 0;
        for (int i_0 = 0; i_0 < R; i_0++) {
            for (int j_0 = 0; j_0 < C; j_0++) {

                for (int i_f = i_0; i_f < R; i_f++) {
                    for (int j_f = j_0; j_f < C; j_f++) {


                        ll area = acu_grid[i_f][j_f];

                        if (i_0 - 1 >= 0) {
                            area -= acu_grid[i_0 - 1][j_f];
                        }

                        if (j_0 - 1 >= 0) {
                            area -= acu_grid[i_f][j_0 - 1];
                        }

                        if (i_0 - 1 >= 0 && j_0 - 1 >= 0) {
                            area += acu_grid[i_0 - 1][j_0 - 1];
                        }

                        maxi = max(maxi, area);
                    }
                }
            }
        }

        cout << maxi << endl;

        if (q != n_cases - 1) {
            cout << endl;
        }


    }

    return 0;
}
