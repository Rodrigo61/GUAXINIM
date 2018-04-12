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

class Node{
public:
    int parent;
    int rank;
    int own;
};

class UnionFind{
private:
    vector<Node> vet_nodes;
public:

    UnionFind(int size, int *vet_own){
        vet_nodes.resize(size);
        deb("size = ", size);
        for (int i = 0; i < size; ++i) {
            vet_nodes[i].parent = i;
            vet_nodes[i].rank = 1;
            vet_nodes[i].own = vet_own[i];
        }
    }

    void add_friends(int idx_a, int idx_b){

        int rep_a_idx = find(idx_a);
        int rep_b_idx = find(idx_b);

        deb("rep_a_idx = ", rep_a_idx);
        deb("rep_b_idx = ", rep_b_idx);

        if(rep_a_idx == rep_b_idx) return;

        if(vet_nodes[rep_a_idx].rank > vet_nodes[rep_b_idx].rank){
            vet_nodes[rep_b_idx].parent = rep_a_idx;
            vet_nodes[rep_a_idx].own += vet_nodes[rep_b_idx].own;
        }else if(vet_nodes[rep_a_idx].rank < vet_nodes[rep_b_idx].rank){
            vet_nodes[rep_a_idx].parent = rep_b_idx;
            vet_nodes[rep_b_idx].own += vet_nodes[rep_a_idx].own;
        }else{
            vet_nodes[rep_b_idx].parent = rep_a_idx;
            vet_nodes[rep_a_idx].own += vet_nodes[rep_b_idx].own;
            vet_nodes[rep_a_idx].rank++;
        }
    }

    int find(int idx){

        deb("vet_nodes[idx].parent= ", vet_nodes[idx].parent);
        deb("idx = ", idx);
        if(vet_nodes[idx].parent == idx) return idx;

        vet_nodes[idx].parent = find(vet_nodes[idx].parent);
        return vet_nodes[idx].parent;
    }

    bool possible(){

        for (int i = 0; i < vet_nodes.size(); ++i) {
            if(vet_nodes[find(vet_nodes[i].parent)].own != 0){
                return false;
            }
        }

        return true;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {
        int n_friends, n_query;

        cin >> n_friends >> n_query;
        int vet_own[n_friends];

        for (int i = 0; i < n_friends; ++i) {
            cin >> vet_own[i];
        }

        UnionFind uf(n_friends, vet_own);
        int a, b;
        for (int i = 0; i < n_query; ++i) {
            cin >> a >> b;

            deb("a = ", a, "b = ", b);
            uf.add_friends(a, b);
        }

        if(uf.possible()){
            cout << "POSSIBLE" << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}