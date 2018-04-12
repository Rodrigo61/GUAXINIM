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
    vector<Node> vet_nodes;

public:
    UnionFind(int size){
        vet_nodes.resize(size);
        for (int i = 0; i < size; ++i) {
            vet_nodes[i].parent = i;
            vet_nodes[i].rank = 1;
            vet_nodes[i].size = 1;
        }
    }


    int find(int id){

        if(vet_nodes[id].parent == id)
            return id;

        vet_nodes[id].parent = find(vet_nodes[id].parent);
        return vet_nodes[id].parent;
    }

    void union_by_rank(int idA, int idB){

        int repA = find(idA);
        int repB = find(idB);

        if(repA == repB) return;


        if(vet_nodes[repA].rank >= vet_nodes[repB].rank){
            vet_nodes[repB].parent = repA;
            vet_nodes[repA].size += vet_nodes[repB].size;
        }else if(vet_nodes[repA].rank < vet_nodes[repB].rank){
            vet_nodes[repA].parent = repB;
            vet_nodes[repB].size += vet_nodes[repA].size;
        }
    }

    int get_size(){
        return vet_nodes[find(0)].size;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_people, n_groups;

    while(cin >> n_people >> n_groups, n_people != 0){

        UnionFind uf(n_people);

        for (int i = 0; i < n_groups; ++i) {
            int group_sz;
            cin >> group_sz;

            int last_id;
            int id;
            cin >> last_id;
            for (int j = 0; j < group_sz-1; ++j) {
                cin >> id;
                uf.union_by_rank(last_id, id);
                last_id = id;
            }
        }

        cout << uf.get_size() << endl;

    }

    return 0;
}