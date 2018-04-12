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
    int max_sz;
    vector<Node> vet_nodes;

public:

    UnionFind(int sz){
        vet_nodes.resize(sz);
        max_sz = 1;
        for (int i = 0; i < sz; ++i) {
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

    void union_by_rank(int ida, int idb){

        deb("ida = ", ida);
        deb("idb = ", idb);
        int repa = find(ida);
        int repb = find(idb);

        deb("repa = ", repa);
        deb("repb = ", repb);

        if(repa == repb) return;

        if(vet_nodes[repa].rank > vet_nodes[repb].rank){
            vet_nodes[repb].parent = repa;
            vet_nodes[repa].size += vet_nodes[repb].size;
            max_sz = max(max_sz, vet_nodes[repa].size);
        }else if(vet_nodes[repa].rank < vet_nodes[repb].rank){
            vet_nodes[repa].parent = repb;
            vet_nodes[repb].size += vet_nodes[repa].size;
            max_sz = max(max_sz, vet_nodes[repb].size);
        }else{
            vet_nodes[repb].parent = repa;
            vet_nodes[repa].size += vet_nodes[repb].size;
            vet_nodes[repa].rank++;
            max_sz = max(max_sz, vet_nodes[repa].size);
        }


    }

    int max_size(){
        return max_sz;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V;
    int E;

    while(cin >> V >> E, V+E != 0){

        map<string, int> dict;

        UnionFind uf(V);
        string name;
        for (int i = 0; i < V; ++i) {
            cin >> name;
            dict[name] = i;
        }

        string name2;
        for (int i = 0; i < E; ++i) {
            cin >> name >> name2;
            uf.union_by_rank(dict[name], dict[name2]);
        }


        cout << uf.max_size() << endl;


    }


    return 0;
}