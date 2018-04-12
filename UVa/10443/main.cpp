#include <iostream>

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

#define valid(i,j) (i >= 0 && i < rows && j >= 0 && j < cols)

char winner(char c1, char c2){
    if(c1 == 'R'){
        if(c2 == 'S') return true;
    }
    if(c1 == 'S'){
        if(c2 == 'P') return true;
    }
    if(c1 == 'P'){
        if(c2 == 'R') return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {
        int rows, cols, rounds;
        cin >> rows >> cols >> rounds;

        char board[rows][cols];
        char board_cp[rows][cols];

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> board[i][j];
            }
        }

        for (int k = 0; k < rounds; ++k) {

            memcpy(board_cp, board, rows*cols*sizeof(char));

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {

                    if(valid(i-1, j) && winner(board_cp[i][j], board_cp[i-1][j])){
                        deb("i-1 = ", i-1, "j = ", j);
                        board[i-1][j] = board_cp[i][j];
                    }
                    if(valid(i+1, j) && winner(board_cp[i][j], board_cp[i+1][j])){
                        deb("i+1 = ", i+1, "j = ", j);
                        board[i+1][j] = board_cp[i][j];
                    }
                    if(valid(i, j-1) && winner(board_cp[i][j], board_cp[i][j-1])){
                        deb("i = ", i, "j-1 = ", j-1);
                        board[i][j-1] = board_cp[i][j];
                    }
                    if(valid(i, j+1) && winner(board_cp[i][j], board_cp[i][j+1])){
                        deb("i = ", i, "j+1 = ", j+1);
                        board[i][j+1] = board_cp[i][j];
                    }
                    
                }
            }

            if(debug){
                deb("round = ", k);
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        cout << board[i][j];
                    }
                    cout << endl;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << board[i][j];
            }
            cout << endl;
        }

        if(w!= n_cases-1)
            cout << endl;

    }

    return 0;
}