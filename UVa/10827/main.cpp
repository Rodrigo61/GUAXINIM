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



int max_sum(vector<vi> &mat){

    vector<vi> acu = mat;
    int large_side = max(mat.size(), mat[0].size());

    for (int i = 0; i < acu.size(); ++i) {
        for (int j = 0; j < acu[0].size(); ++j) {
            if(i == 0 && j == 0) continue;

            acu[i][j] = mat[i][j];
            if(i-1 >= 0){
                acu[i][j] += acu[i-1][j];
            }
            if(j-1 >= 0){
                acu[i][j] += acu[i][j-1];
            }
            if(j-1 >= 0 && i-1 >= 0){
                acu[i][j] -= acu[i-1][j-1];
            }
        }
    }

    print_matrix_debug(acu);

    deb("acu[0].size()+1)/2 = ", (acu[0].size()+1)/2);
    int maxi = numeric_limits<int>::min();
    for (int i0 = 0; i0 < acu.size(); ++i0) {
        for (int j0 = 0; j0 < acu[i0].size(); ++j0) {
            for (int it = i0; it < acu.size(); ++it) {
                for (int jt = j0; jt < acu[it].size(); ++jt) {

                    int curr_val = acu[it][jt];
                    if(it >= i0+(large_side+1)/2 || jt >= j0+(large_side+1)/2) continue;

                    if(i0-1 >= 0) curr_val -= acu[i0-1][jt];
                    if(j0-1 >= 0) curr_val -= acu[it][j0-1];
                    if(i0-1 >= 0 && j0-1 >= 0) curr_val += acu[i0-1][j0-1];

                    maxi = max(maxi, curr_val);

                }
            }
        }
    }

    deb("CALC DONE = ", maxi);

    return maxi;
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {
        int N;
        cin >> N;

        vector<vi> mat(N, vi(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> mat[i][j];
            }
        }


        vector<vi> aux(N, vi(N*2-1));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                aux[i][j] = mat[i][j];
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N-1; ++j) {
                aux[i][j+N] = mat[i][j];
            }
        }
        int max_hor = max_sum(aux);
        deb("max_hor = ", max_hor);

        vector<vi> aux2(N*2-1, vi(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                aux2[i][j] = mat[i][j];
            }
        }
        for (int i = 0; i < N-1; ++i) {
            for (int j = 0; j < N; ++j) {
                aux2[i+N][j] = mat[i][j];
            }
        }
        print_matrix_debug(aux2);
        int max_vert = max_sum(aux2);
        deb("max_vert = ", max_vert);


    }
    return 0;
}