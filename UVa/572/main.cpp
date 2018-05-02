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


vii get_neighbors(pii root, int R, int C) {

    vii res;

    if (root.first - 1 >= 0) {

        if (root.second - 1 >= 0) {
            res.push_back(mp(root.first - 1, root.second - 1));
        }

        res.push_back(mp(root.first - 1, root.second));

        if (root.second + 1 < C) {
            res.push_back(mp(root.first - 1, root.second + 1));
        }
    }

    if (root.second - 1 >= 0) {
        res.push_back(mp(root.first, root.second - 1));
    }

    if (root.second + 1 < C) {
        res.push_back(mp(root.first, root.second + 1));
    }


    if (root.first + 1 < R) {

        if (root.second - 1 >= 0) {
            res.push_back(mp(root.first + 1, root.second - 1));
        }

        res.push_back(mp(root.first + 1, root.second));

        if (root.second + 1 < C) {
            res.push_back(mp(root.first + 1, root.second + 1));
        }
    }

    return res;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int R, C;

    while (cin >> R >> C, R) {

        vector<vi> grid(R, vi(C));

        char cell;
        for (size_t i = 0; i < R; i++) {
            for (size_t j = 0; j < C; j++) {
                cin >> cell;

                if (cell == '@') {
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = 1;
                }
            }
        }

        int ans = 0;

        for (size_t i = 0; i < R; i++) {
            for (size_t j = 0; j < C; j++) {
                if (!grid[i][j]) {

                    ++ans;
                    queue<pii> q;
                    q.push(mp(i,j));

                    grid[i][j] = 1;

                    while (!q.empty()) {
                        pii u = q.front();
                        q.pop();

                        for (auto v : get_neighbors(u, R, C)) {

                            if (!grid[v.first][v.second]) {
                                grid[v.first][v.second] = 1;
                                q.push(v);
                            }
                        }
                    }
                }
            }
        }


        cout << ans << endl;
    }


    return 0;
}
