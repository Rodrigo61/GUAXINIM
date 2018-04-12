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

#define INF 9999999



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int R, C, j_start, i_start;
    i_start = 0;

    while(cin >> R >> C >> j_start, R != 0){

        --j_start;

        vector<vector<char>> grid(R, vector<char>(C));

        for (size_t i = 0; i < R; i++) {
            for (size_t j = 0; j < C; j++) {
                cin >> grid[i][j];
            }
        }

        deb("all read");
        vector<vi> dist(R, vi(C, INF));

        deb("starting BFS");
        dist[i_start][j_start] = 0;
        queue<pii> q;
        q.push(mp(i_start, j_start));

        int steps_to_exit = 0;
        int circuit_len = 0;

        while(!q.empty()){
            pii u = q.front();
            q.pop();

            ++steps_to_exit;
            pii adj;
            if(grid[u.first][u.second] == 'N'){
                adj = mp(u.first-1, u.second);
            }else if(grid[u.first][u.second] == 'S'){
                adj = mp(u.first+1, u.second);
            }else if(grid[u.first][u.second] == 'W'){
                adj = mp(u.first, u.second-1);
            }else if(grid[u.first][u.second] == 'E'){
                adj = mp(u.first, u.second+1);
            }

            if(adj.first < 0 || adj.first >= R || adj.second < 0 || adj.second >= C){
                break;
            }

            if(dist[adj.first][adj.second] != INF){
                circuit_len = dist[u.first][u.second] + 1 - dist[adj.first][adj.second];
                steps_to_exit -= circuit_len;
                break;
            }

            dist[adj.first][adj.second] = dist[u.first][u.second] + 1;
            q.push(adj);
        }

        if(circuit_len == 0){
            cout << steps_to_exit << " step(s) to exit" << endl;
        }else{
            cout << steps_to_exit << " step(s) before a loop of " << circuit_len << " step(s)" << endl;
        }

    }

    return 0;
}
