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


char grid[505][505];
char grid_cpy[505][505];
bool conquered_something;
int R,C;

void clone_grid(){
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            grid_cpy[i][j] = grid[i][j];
        }
    }
}

void conquer_area(int i, int j, char c){
    if(i < 0 || i >= R || j < 0 || j >= C)
        return;

    if(grid_cpy[i][j] != '.')
        return;

    conquered_something = true;
    if(grid[i][j] != '.' && grid[i][j] != c){
        grid[i][j] = '*';
    }else{
        grid[i][j] = c;
    }
}

void conquer(int i, int j){




  /*  conquer_area(i+1, j, grid_cpy[i][j]);
    conquer_area(i-1, j, grid_cpy[i][j]);
    conquer_area(i, j-1, grid_cpy[i][j]);
    conquer_area(i, j+1, grid_cpy[i][j]);*/
}


int main(){
    ios::sync_with_stdio(false);

    int n_cases;
    scanf("%d", &n_cases);

    for (int w = 0; w < n_cases; ++w) {

        scanf("%d%d", &R, &C);

        char row[C+1];
        for (int i = 0; i < R; ++i) {
            //cin >> row;
            scanf("%s", row);
            for (int j = 0; j < C; ++j) {
                grid[i][j] = row[j];
            }
        }



        conquered_something = true;
        while(conquered_something){

            print_2Darray_debug(grid, R, C);
            conquered_something = false;
            clone_grid();

            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {

                    if((grid_cpy[i][j] < 'a' || grid_cpy[i][j] > 'z'))
                        continue;

                    char c = grid_cpy[i][j];

                    if(i+1 < R && grid_cpy[i+1][j] == '.'){
                        conquered_something = true;
                        if(grid[i+1][j] != '.' && grid[i+1][j] != c){
                            grid[i+1][j] = '*';
                        }else{
                            grid[i+1][j] = c;
                        }
                    }

                    if(i-1 >= 0 && grid_cpy[i-1][j] == '.'){
                        conquered_something = true;
                        if(grid[i-1][j] != '.' && grid[i-1][j] != c){
                            grid[i-1][j] = '*';
                        }else{
                            grid[i-1][j] = c;
                        }
                    }

                    if(j+1 < C && grid_cpy[i][j+1] == '.'){
                        conquered_something = true;
                        char c = grid_cpy[i][j];
                        if(grid[i][j+1] != '.' && grid[i][j+1] != c){
                            grid[i][j+1] = '*';
                        }else{
                            grid[i][j+1] = c;
                        }
                    }

                    if(j-1 >= 0 && grid_cpy[i][j-1] == '.'){
                        conquered_something = true;
                        char c = grid_cpy[i][j];
                        if(grid[i][j-1] != '.' && grid[i][j-1] != c){
                            grid[i][j-1] = '*';
                        }else{
                            grid[i][j-1] = c;
                        }
                    }
                }
            }

            print_2Darray_debug(grid, R, C);
        }



        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");


    }


    return 0;
}