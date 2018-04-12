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


int get_n_comp(vector<std::list<int>> &vet_adj){

    int V = vet_adj.size();
    vi visited(V, 0);
    vi discovered(V, -1);

    int acu = 0;
    for (int i = 0; i < V; ++i) {
        if(visited[i]) continue;

        queue<int> q;
        q.push(i);

        deb("i = ", i);
        bool is_tree = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            deb("u = ", u);

            visited[u] = 1;

            for(auto &v : vet_adj[u]){
                deb("v = ", v);
                if(discovered[u] !=v && visited[v]){
                    is_tree = false;
                }else{
                    if(!visited[v]){
                        q.push(v);
                        discovered[v] = u;
                    }
                }
            }
        }

        if(is_tree) acu++;
    }

    return acu;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    int case_count = 0;

    while(cin >> V >> E,  E+V != 0){

        vector<std::list<int>> vet_adj(V);

        int u, v;
        for (int i = 0; i < E; ++i) {
            cin >> u >> v;
            --u,--v;

            vet_adj[u].push_back(v);
            vet_adj[v].push_back(u);
        }

        int n_comp = get_n_comp(vet_adj);


        cout << "Case "  << ++case_count << ":";
        if(n_comp == 0){
            cout << " No trees." << endl;
        }else if(n_comp == 1){
            cout << " There is one tree." << endl;
        }else{
            cout << " A forest of "<< n_comp << " trees."<< endl;
        }

    }

    return 0;
}