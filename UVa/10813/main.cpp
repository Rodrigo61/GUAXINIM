#include <iostream>

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
//</editor-fold desc="GUAXINIM TEMPLATE">

int board[5][5];

bool victory(){

    /*check rows*/
    bool win = true;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(board[i][j] == 0)
                win = false;
        }
        if(win) return true;
        win = true;
    }


    /*check columns*/
    win = true;
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 5; ++i) {
            if(board[i][j] == 0)
                win = false;
        }
        if(win) return true;
        win = true;
    }


    /*check left diagonal */
    win = true;
    for (int i = 0; i < 5; ++i) {
        if(board[i][i] == 0)
            win = false;
    }
    if(win) return true;


    /*check right diagonal */
    win = true;
    for (int i = 4; i >= 0; --i) {
        if(board[4-i][i] == 0)
            win = false;
    }

    return win;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {

        int num;
        vector<pii> position(76, mp(-1,-1));

        memset(board, 0, sizeof(int)*25);
        board[2][2] = 1;

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {

                if(i == 2 && j == 2) continue;

                cin >> num;
                position[num] = mp(i,j);
            }
        }

        bool won = false;
        for (int i = 0; i < 75; ++i) {
            cin >> num;


            if(!won){
                if(position[num].first != -1){
                    board[position[num].first][position[num].second] = 1;

                    if(victory()){
                        cout << "BINGO after " << i+1 << " numbers announced" << endl;
                        won = true;
                    }
                }
            }

        }


    }

    return 0;
}