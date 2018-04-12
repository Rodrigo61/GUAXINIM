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
    int size;
};

class UnionFind{

private:
    vector<Node> vet_node;
    int max_size;
public:

    UnionFind(int size){
        vet_node.resize(size);
        for (int i = 0; i < size; ++i) {
            vet_node[i].parent = i;
            vet_node[i].rank = 1;
            vet_node[i].size = 1;
        }

        max_size = 1;
    }

    int find_set(int idx){

        if(vet_node[idx].parent == idx){
            return idx;
        }

        vet_node[idx].parent = find_set(vet_node[idx].parent); // path compress
        return vet_node[idx].parent;
    }

    void set_friend(int idx1, int idx2){

        int rep1 = find_set(idx1);
        int rep2 = find_set(idx2);

        deb("rep1 = ", rep1);
        deb("rep2 = ", rep2);
        if(rep1 == rep2) return;

        if(vet_node[rep1].rank > vet_node[rep2].rank){
            vet_node[rep2].parent = rep1;
            vet_node[rep1].size += vet_node[rep2].size;
            max_size = max(max_size, vet_node[rep1].size);
        }else if(vet_node[rep1].rank < vet_node[rep2].rank){
            vet_node[rep1].parent = rep2;
            vet_node[rep2].size += vet_node[rep1].size;
            max_size = max(max_size, vet_node[rep2].size);
        }else{
            vet_node[rep2].parent = rep1;
            vet_node[rep1].rank++;
            vet_node[rep1].size += vet_node[rep2].size;
            max_size = max(max_size, vet_node[rep1].size);
        }

    }

    int get_larger_group(){
        return max_size;
    }


};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {
        int n_cit, n_query;
        cin >> n_cit >> n_query;

        UnionFind uf(n_cit);

        int cit_a, cit_b;
        for (int i = 0; i < n_query; ++i) {
            cin >> cit_a >> cit_b;
            --cit_a, --cit_b;

            deb("cit_a = ", cit_a, "cit_b = ", cit_b);
            uf.set_friend(cit_a, cit_b);
        }

        cout << uf.get_larger_group() << endl;
    }

    return 0;
}