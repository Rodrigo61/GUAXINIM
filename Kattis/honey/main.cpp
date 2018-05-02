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

int acu;
int memo[30][30][30][30];

int solve(int level, int col, int row, int remaining_steps) {

    if (remaining_steps == 0 && level == 0) {
        return 1;
    } else if (remaining_steps == 0) {
        return 0;
    }

    int &res = memo[level][col][row][remaining_steps];

    if (res != -1) return res;

    int mult_row = row < 0 ? -1:1;
    int mult_col = col < 0 ? -1:1;

    res = 0;
    if (level >= 1 && (abs(2*row) == abs(col) || col == 0)) {

        //  Outter vertice

        if (col == 0) {
            res +=solve(level + 1, -2, row + (1 * mult_row), remaining_steps - 1);
            res += solve(level + 1, 2 , row + (1 * mult_row), remaining_steps - 1);
            res += solve(level + 1, 0 , row + (2 * mult_row), remaining_steps - 1);

            res += solve(level, -2, row - (1 * mult_row), remaining_steps - 1);
            res += solve(level, 2 , row - (1 * mult_row), remaining_steps - 1);

            res += solve(level - 1, 0, row - (2 * mult_row), remaining_steps - 1);
        } else {

            res += solve(level + 1, col + (2 * mult_col), row + (1 * mult_row), remaining_steps - 1);
            res += solve(level + 1, col + (2 * mult_col), row - (1 * mult_row), remaining_steps - 1);
            res += solve(level + 1, col                 , row + (2 * mult_row), remaining_steps - 1);

            res += solve(level - 1, col - (2 * mult_col), row - (1 * mult_row), remaining_steps - 1);

            res += solve(level, col - (2 * mult_col), row + (1 * mult_row), remaining_steps - 1);
            res += solve(level, col                 , row - (2 * mult_row), remaining_steps - 1);

        }

    } else if (level >= 1) {

        // Inner vertice
        if (abs(col) != level*2) {
            res += solve(level + 1, col                 , row + (2 * mult_row), remaining_steps - 1);
            res += solve(level + 1, col + (2 * mult_col), row + (1 * mult_row), remaining_steps - 1);

            res += solve(level - 1, col                 , row - (2 * mult_row), remaining_steps - 1);
            res += solve(level - 1, col - (2 * mult_col), row - (1 * mult_row), remaining_steps - 1);

            res += solve(level, col - (2 * mult_col), row + (1 * mult_row), remaining_steps - 1);
            res += solve(level, col + (2 * mult_col), row - (1 * mult_row), remaining_steps - 1);
        } else {
            res += solve(level + 1, col + (2* mult_col), row + (1 * mult_row), remaining_steps - 1);
            res += solve(level + 1, col + (2* mult_col), row - (1 * mult_row), remaining_steps - 1);

            res += solve(level - 1, col - (2* mult_col), row + (1 * mult_row), remaining_steps - 1);
            res += solve(level - 1, col - (2* mult_col), row - (1 * mult_row), remaining_steps - 1);

            res += solve(level, col, row + (2 * mult_row), remaining_steps - 1);
            res += solve(level, col, row - (2 * mult_row), remaining_steps - 1);
        }

    } else {
        res += solve(level + 1, 0, 2, remaining_steps - 1);
        res += solve(level + 1, 2, 1, remaining_steps - 1);
        res += solve(level + 1, 2, -1, remaining_steps - 1);
        res += solve(level + 1, 0, -2, remaining_steps - 1);
        res += solve(level + 1, -2, -1, remaining_steps - 1);
        res += solve(level + 1, -2, 1, remaining_steps - 1);
    }

    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n_cases;
    cin >> n_cases;

    for (size_t q = 0; q < n_cases; q++) {

        int steps;
        cin >> steps;

        deb("steps = ", steps);

        for (size_t i = 0; i < 30; i++) {
            for (size_t j = 0; j < 30; j++) {
                for (size_t k = 0; k < 30; k++) {
                    for (size_t l = 0; l < 30; l++) {
                        memo[i][j][k][l] = -1;
                    }
                }
            }
        }

        cout << solve(0, 0, 0, steps) << endl;
    }
    return 0;
}
