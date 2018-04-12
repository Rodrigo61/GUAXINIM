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


int N, M;
vector<vi> mat;
vector<vi> visited;
vi row_visited;
int max_candy;

void deep_search(int curr_candy){

    for (int i = 0; i < N; i++) {

        if(row_visited[i] == 1) continue;

        int last_row , next_row;
        if(i-1 >= 0){
            last_row = row_visited[i-1];
            row_visited[i-1] = 1;
        }
        if(i+1 < N){
            next_row = row_visited[i+1];
            row_visited[i+1] = 1;
        }

        for (int j = 0; j < M; j++) {
            if(!visited[i][j]){
                int left = -1, right = -1;

                if(j-1 >= 0){
                    left = visited[i][j-1];
                    visited[i][j-1] = 1;
                }
                if(j+1 < M){
                    right = visited[i][j+1];
                    visited[i][j+1] = 1;
                }

                visited[i][j] = 1;
                deep_search(curr_candy + mat[i][j]);
                visited[i][j] = 0;

                if(j-1 >= 0){
                    visited[i][j-1] = left;
                }
                if(j+1 < M){
                    visited[i][j+1] = right;
                }
            }
        }

        if(i-1 >= 0){
            row_visited[i-1] = last_row;
        }
        if(i+1 < N){
            row_visited[i+1] = next_row;
        }
    }

    max_candy = max(max_candy, curr_candy);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> N >> M, N+M != 0){
        mat.clear();
        mat.resize(N, vi(M));
        visited.clear();
        visited.resize(N, vi(M, 0));

        row_visited.clear();
        row_visited.resize(N, 0);

        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < M; j++) {
                cin >> mat[i][j];
            }
        }

        deb("MAT LOADED");

        max_candy = 0;
        deep_search(0);

        cout << max_candy << endl;
    }

    return 0;
}
