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

int R, C;
vector<vector<char>> grid;

bool valid(int i, int j) {
    return i >= 0 && i < R && j >= 0 && j < C;
}

vii get_adj(pii u) {
    int i = u.first;
    int j = u.second;

    char u_value = grid[i][j];

    vii res;
    deb("u_value = ", u_value);
    if (u_value == 'N' && valid(i - 1, j)) {
        res.push_back(mp(i - 1, j));
    } else if (u_value == 'S' && valid(i + 1, j)) {
        res.push_back(mp(i + 1, j));
        deb("aqui");
    } else if (u_value == 'W' && valid(i, j - 1)) {
        res.push_back(mp(i, j - 1));
    } else if (u_value == 'E' && valid(i, j + 1)) {
        res.push_back(mp(i, j + 1));
    }

    if (valid(i - 1, j) && grid[i - 1][j] == 'S') {
        res.push_back(mp(i - 1, j));
    }
    if (valid(i + 1, j) && grid[i + 1][j] == 'N') {
        res.push_back(mp(i + 1, j));
    }
    if (valid(i, j - 1) && grid[i][j - 1] == 'E') {
        res.push_back(mp(i, j - 1));
    }
    if (valid(i, j + 1) && grid[i][j + 1] == 'W') {
        res.push_back(mp(i, j + 1));
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> R >> C;
    grid.resize(R, vector<char>(C));


    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vi> visited(R, vi(C, 0));

    int res = 0;
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            if (!visited[i][j]) {

                ++res;

                queue<pii> q;
                q.push(mp(i, j));
                visited[i][j] = 1;

                while (!q.empty()) {
                    pii u = q.front();
                    q.pop();

                    for (auto v : get_adj(u)) {
                        if (!visited[v.first][v.second]) {
                            visited[v.first][v.second] = 1;
                            q.push(v);
                        }

                    }

                }
            }
            print_matrix_debug(grid);
        }
    }

    printf("%d\n", res);

    return 0;
}
