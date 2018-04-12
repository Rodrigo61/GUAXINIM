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

#define INF 1000000

int mat_adj[26][26];
int dist[26];

int bfs(int s){

    deb("s = ", s);
    if(dist[s] != INF) return 0;

    int reached_count = 0;
    queue<int> q;
    dist[s] = 1;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        ++reached_count;

        for (int i = 0; i < 26; ++i) {
            if(mat_adj[u][i] == 1 && dist[i] == INF){
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }

    return reached_count;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string line;
    int v, u;
    int n_cases;
    cin >> n_cases;
    cin.ignore();


    for (int w = 0; w < n_cases; ++w) {

        memset(mat_adj, 0, sizeof(int)*26*26);
        for (int i = 0; i < 26; ++i) {
            dist[i] = INF;
        }

        print_array_debug(dist, 26);


        while(getline(cin, line), line[0] != '*'){
            v = line[1] - 'A';
            u = line[3] - 'A';

            mat_adj[u][v] = 1;
            mat_adj[v][u] = 1;
        }

        getline(cin, line);

        int tree_count = 0;
        int acorn_count = 0;
        for (int i = 0; i < line.size(); ++i) {
            if(line[i] == ',') continue;
            deb("line[i] = ", line[i]);
            int reached = bfs(line[i] - 'A');
            if( reached > 1){
                deb("tree");
                ++tree_count;
            }else if(reached == 1){
                deb("acorn");
                ++acorn_count;
            }else{
                deb("alterad reach");
            }
        }

        cout << "There are " << tree_count <<" tree(s) and " << acorn_count << " acorn(s)." << endl;
    }

    return 0;
}