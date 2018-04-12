#include <iostream>

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

#define LEFT_NODE(node) 2*node+1
#define RIGHT_NODE(node) 2*node+2
#define MID(seg) (seg.first+seg.second)/2
#define LEFT_SEG(seg) mp(seg.first, MID(seg))
#define RIGHT_SEG(seg) mp(MID(seg) + 1, seg.second)

class SegTree{
private:
    vi max_tree, min_tree;
    int sz;
    int *vet;

    void build(pii curr_seg, int node){

        if(curr_seg.first == curr_seg.second){
            max_tree[node] = vet[curr_seg.first];
            min_tree[node] = vet[curr_seg.first];
            return;
        }

        build(LEFT_SEG(curr_seg), LEFT_NODE(node));
        build(RIGHT_SEG(curr_seg), RIGHT_NODE(node));
        
        max_tree[node] = max(max_tree[LEFT_NODE(node)], max_tree[RIGHT_NODE(node)]);
        min_tree[node] = min(min_tree[LEFT_NODE(node)], min_tree[RIGHT_NODE(node)]);
    }

    void update_aux(pii curr_seg, int pos, int value, int node){

        if(pos < curr_seg.first || pos > curr_seg.second){
            return;
        }

        if(curr_seg.first == curr_seg.second){
            vet[pos] = value;
            max_tree[node] = value;
            min_tree[node] = value;
            return;
        }
        
        update_aux(LEFT_SEG(curr_seg), pos, value, LEFT_NODE(node));
        update_aux(RIGHT_SEG(curr_seg), pos, value, RIGHT_NODE(node));

        max_tree[node] = max(max_tree[LEFT_NODE(node)], max_tree[RIGHT_NODE(node)]);
        min_tree[node] = min(min_tree[LEFT_NODE(node)], min_tree[RIGHT_NODE(node)]);
    }


    pii query_aux(pii curr_seg, pii target_seg, int node){

        if(target_seg.second < curr_seg.first || target_seg.first > curr_seg.second){
            return mp(-1, numeric_limits<int>::max());
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            return mp(max_tree[node], min_tree[node]);
        }

        auto L = query_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node));
        auto R = query_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));

        return mp(max(L.first, R.first), min(L.second, R.second));
    }

public:

    SegTree(int *vet, int size){
        sz = size;
        this->vet = vet;
        max_tree.resize(4*sz);
        min_tree.resize(4*sz);

        build(mp(0, sz-1), 0);
    }

    void update(int pos, int value){
        update_aux(mp(0, sz-1), pos, value, 0);
    }

    pii query(pii target_seg){
        return query_aux(mp(0, sz-1), target_seg, 0);
    }
};


int main(){
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    int **mat = (int**) malloc(sizeof(int*) * N);
    vector<SegTree> st_lines;
    st_lines.reserve(N);

    for (int i = 0; i < N; ++i) {
        mat[i] = (int*) malloc(sizeof(int) * N);

        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
        }

        print_array_debug(mat[i], N);
        SegTree t(mat[i], N);
        st_lines.push_back(t);
    }


    int Q;
    char cmd;
    int a1, a2, a3, a4;
    int maxi, mini;
    pii query_res;

    cin >> Q;
    for (int i = 0; i < Q; ++i) {

        cin >> cmd;
        deb("cmd = ", cmd);
        if(cmd == 'q'){
            cin >> a1 >> a2 >> a3 >> a4;
            --a1, --a2, --a3, --a4;
            deb("a1 = ", a1);
            deb("a2 = ", a2);
            deb("a3 = ", a3);
            deb("a4 = ", a4);

            maxi = -1, mini = numeric_limits<int>::max();
            for (int i = a1; i <= a3; ++i) {
                query_res = st_lines[i].query(mp(a2, a4));
                deb("query_res.first = ", query_res.first);
                deb("query_res.second = ", query_res.second);
                maxi = max(maxi, query_res.first);
                mini = min(mini, query_res.second);
            }

            cout << maxi << space << mini << endl;
        }else{
            cin >> a1 >> a2 >> a3;
            --a1, --a2;
            deb("a1 = ", a1);
            deb("a2 = ", a2);
            deb("a3 = ", a3);

            st_lines[a1].update(a2, a3);
        }
    }




    return 0;
}