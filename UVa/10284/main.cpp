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


char board[8][8];
int free_space = 64;


bool play(int i, int j){

    deb("play i = ", i , " j = ", j);
    if(i >= 0 && i <= 7 && j >= 0 && j <= 7){
        if(board[i][j] == '0'){
            board[i][j] = 1;
            --free_space;
            deb("free_space = ", free_space);
            return true;
        }

        if(board[i][j] == 1){
            return true;
        }
    }

    return false;
}


int main(){
    ios_base::sync_with_stdio(false);

    string FEN;

    while(cin >> FEN){

        auto it = FEN.begin();
        memset(board, '0', 64*sizeof(int));
        free_space = 64;

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if(it == FEN.end()) break;
                if(*it >= '1' && *it <= '8'){
                    --(*it);
                    if(*it == '0') ++it;
                    continue;
                }

                if(*it == '/'){
                    ++it;
                    --j;
                    continue;
                }else{
                    board[i][j] = *it;
                    --free_space;
                    ++it;
                }



            }
        }

        print_2Darray_debug(board, 8, 8);

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {

                deb("board[i][j] = ", board[i][j]);
                if(board[i][j] != '0' && board[i][j] != 1){
                    switch(board[i][j]){
                        case 'p':{
                            play(i+1, j+1);
                            play(i+1, j-1);
                            break;
                        }
                        case 'P':{
                            play(i-1, j+1);
                            play(i-1, j-1);
                            break;
                        }
                        case 'K':
                        case 'k':{
                            deb("case kK");
                            play(i-1, j-1);
                            play(i-1, j);
                            play(i-1, j+1);
                            play(i, j-1);
                            play(i, j+1);
                            play(i+1, j-1);
                            play(i+1, j);
                            play(i+1, j+1);
                            break;
                        }
                        case 'N':
                        case 'n':{
                            play(i-2, j-1);
                            play(i-2, j+1);
                            play(i+2, j-1);
                            play(i+2, j+1);
                            play(i-1, j-2);
                            play(i-1, j+2);
                            play(i+1, j-2);
                            play(i+1, j+2);
                            break;
                        }
                        case 'B':
                        case 'b':{
                            for (int k = 1; k <= 8; ++k) {
                                if(!play(i-k, j-k))break;
                            }
                            for (int k = 1; k <= 8; ++k) {
                                if(!play(i-k, j+k))break;
                            }
                            for (int k = 1; k <= 8; ++k) {
                                if(!play(i+k, j-k))break;
                            }
                            for (int k = 1; k <= 8; ++k) {
                                if(!play(i+k, j+k))break;
                            }
                            break;
                        }
                        case 'Q':
                        case 'q':{
                            deb("case qQ");
                            for (int k = 1; k <= 8; ++k) {
                                if(!play(i-k, j-k))break;
                            }
                            for (int k = 1; k <= 8; ++k) {
                                if(!play(i-k, j+k))break;
                            }
                            for (int k = 1; k <= 8; ++k) {
                                if(!play(i+k, j-k))break;
                            }
                            for (int k = 1; k <= 8; ++k) {
                                if(!play(i+k, j+k))break;
                            }
                            for(int _i = i-1; _i >= 0; --_i){
                                if(!play(_i, j))break;
                            }
                            for(int _i = i+1; _i <= 7; ++_i){
                                if(!play(_i, j))break;
                            }
                            for(int _j = j-1; _j >= 0; --_j){
                                if(!play(i, _j))break;
                            }
                            for(int _j = j+1; _j <= 7; ++_j){
                                if(!play(i, _j))break;
                            }
                            break;
                        }
                        case 'r':
                        case 'R':{
                            for(int _i = i-1; _i >= 0; --_i){
                                if(!play(_i, j))break;
                            }
                            for(int _i = i+1; _i <= 7; ++_i){
                                if(!play(_i, j))break;
                            }
                            for(int _j = j-1; _j >= 0; --_j){
                                if(!play(i, _j))break;
                            }
                            for(int _j = j+1; _j <= 7; ++_j){
                                if(!play(i, _j))break;
                            }
                            break;
                        }
                    }
                }
            }



        }
        deb("Freespace");
        cout << free_space << endl;

        /*for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if(board[i][j] != '0'){
                    cout << '*' << space;
                }else{
                    cout << '0' << space;
                }
            }
            cout << endl;
        }*/

    }


    return 0;
}