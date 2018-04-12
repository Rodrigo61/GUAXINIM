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
//</editor-fold>

class Node{
public:
    int parent;
    int rank;
    int size;
};

class UnionFind{
private:
    vector<Node> vet_nodes;
public:

    UnionFind(int sz){
        sz = 100000;
        vet_nodes.resize(sz);
        for (size_t i = 0; i < sz; i++) {
            vet_nodes[i].parent = i;
            vet_nodes[i].rank = 1;
            vet_nodes[i].size = 1;
        }
    }

    int find(int idx){

        if(vet_nodes[idx].parent == idx){
            return idx;
        }

        vet_nodes[idx].parent = find(vet_nodes[idx].parent);
        return vet_nodes[idx].parent;
    }

    void union_by_rank(int idxa, int idxb){
        int repa = find(idxa);
        int repb = find(idxb);

        deb("repa = ", repa);
        deb("repb = ", repb);
        deb("repa sz = ", vet_nodes[repa].size);
        deb("repa sz = ", vet_nodes[repb].size);
        if(repa == repb){
            cout << vet_nodes[repa].size << endl;
            return;}

        if(vet_nodes[repa].rank > vet_nodes[repb].rank){
            vet_nodes[repb].parent = repa;
            vet_nodes[repa].size += vet_nodes[repb].size;
            cout << vet_nodes[repa].size << endl;
        }else if(vet_nodes[repa].rank < vet_nodes[repb].rank){
            vet_nodes[repa].parent = repb;
            vet_nodes[repb].size += vet_nodes[repa].size;
            cout << vet_nodes[repb].size << endl;
        }else{
            vet_nodes[repb].parent = repa;
            vet_nodes[repa].size += vet_nodes[repb].size;
            vet_nodes[repa].rank++;
            cout << vet_nodes[repa].size << endl;
        }
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (size_t q = 0; q < n_cases; q++) {
        int F;
        cin >> F;

        map<string, int> ids;
        UnionFind uf(F);

        int curr_id = 0;
        for (size_t i = 0; i < F; i++) {
            string name1, name2;

            cin >> name1 >> name2;

            if(ids.find(name1) == ids.end()){
                ids[name1] = curr_id;
                ++curr_id;
            }

            if(ids.find(name2) == ids.end()){
                ids[name2] = curr_id;
                ++curr_id;
            }


            int id1 = ids[name1];
            int id2 = ids[name2];
            deb("id1 = ", id1);
            deb("id2 = ", id2);

            uf.union_by_rank(id1, id2);
        }

    }


    return 0;
}
