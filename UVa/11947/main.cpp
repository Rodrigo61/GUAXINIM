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


void check_neigh(vector<vector<char>> &board, int i, int j, vector< vector<int> > &f_board, char &num, int &f_num){

    int n = board.size();
    int m = board[0].size();


    if(i >= 0 && i <n && j >= 0 && j < m){
        if(num != 'F'){
            if(board[i][j] == 'F'){
                --num;
            }
        }else{
            if(board[i][j] == 'F'){
                f_num++;
            }
            f_board[i][j]++;
        }
    }
}


bool valid(vector<vector<char>> &board, int i, int j, vector< vector<int> > &f_board){

    int n = board.size();
    int m = board[0].size();

    char num = board[i][j];
    int f_num = 0;

    deb("num = ", num);

    if(num != 'F') num = num - '0';

    check_neigh(board, i-1, j-1, f_board, num, f_num);
    check_neigh(board, i-1, j, f_board, num, f_num);
    check_neigh(board, i-1, j+1, f_board, num, f_num);
    check_neigh(board, i+1, j-1, f_board, num, f_num);
    check_neigh(board, i+1, j, f_board, num, f_num);
    check_neigh(board, i+1, j+1, f_board, num, f_num);
    check_neigh(board, i, j-1, f_board, num, f_num);
    check_neigh(board, i, j+1, f_board, num, f_num);

    if(num == 'F'){
        return true;
    }else{
        return num == 0;

    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n_cases;
    int n, m;
    cin >> n_cases;

    for(int w = 0; w < n_cases; ++w){

        cin >> n >> m;
        vector< vector<char> > board(n, vector<char>(m));
        vector< vector<int> > f_board(n, vector<int>(m, 0));

        deb("awqui232");
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> board[i][j];
            }
        }
        deb("awqui");

        print_2Darray_debug(board, n, m);


        bool val = true;
        bool all_f = true;
        for(int i = 0; i < n && val; ++i){
            deb("oi");
            for(int j = 0; j < m; ++j){
                deb("i = ", i, "j = ", j);
                deb("m = ", m);
                if(board[i][j] != 'F') all_f = false;
                if(!valid(board, i, j, f_board)){
                    val = false;
                    break;
                }
            }
        }



/*
        for(int i = 0; i < n && val; ++i){

            for(int j = 0; j < m; ++j){

                if(board[i][j] == 'F') continue;

                if(board[i][j] - '0' != f_board[i][j]) val = false;
            }

        }
*/
        if(val && !all_f){
            cout << "Well done Clark!" << endl;
        }else{
            cout << "Please sweep the mine again!" << endl;
        }

    }

    return 0;
}
