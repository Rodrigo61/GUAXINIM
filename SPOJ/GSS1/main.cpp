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
#define LEFT_NODE(i) 2*i + 1
#define RIGHT_NODE(i) 2*i + 2
#define MID(i) (i.first+i.second)/2
#define LEFT_SEG(i) mp(i.first, MID(i))
#define RIGHT_SEG(i) mp(MID(i)+1, i.second)
#define INF -1000000

class SegTree{
private:
    int sz;
    vi tree;
    vi sufix_tree;
    vi best_sufix_tree;
    vi prefix_tree;
    vi best_prefix_tree;

    void build(int *vet, pii curr_seg, int node){

        if(curr_seg.first == curr_seg.second){
            tree[node] = vet[curr_seg.first];
            sufix_tree[node] = 0;
            prefix_tree[node] = 0;
            best_sufix_tree[node] = vet[curr_seg.first];
            best_prefix_tree[node] = vet[curr_seg.first];
            return;
        }

        build(vet, LEFT_SEG(curr_seg), LEFT_NODE(node));
        build(vet, RIGHT_SEG(curr_seg), RIGHT_NODE(node));

        int left = tree[LEFT_NODE(node)];
        int right = tree[RIGHT_NODE(node)];
        int left_sufix = sufix_tree[LEFT_NODE(node)];
        int left_prefix = prefix_tree[LEFT_NODE(node)];
        int left_best_prefix = best_prefix_tree[LEFT_NODE(node)];
        int left_best_sufix = best_sufix_tree[LEFT_NODE(node)];
        int right_sufix = sufix_tree[RIGHT_NODE(node)];
        int right_prefix = prefix_tree[RIGHT_NODE(node)];
        int right_best_prefix = best_prefix_tree[RIGHT_NODE(node)];
        int right_best_sufix = best_sufix_tree[RIGHT_NODE(node)];
        int join = left + right + left_sufix + right_prefix;
        int best_middle = left_best_sufix + right_best_prefix;

        if(left >= right && left >= join && left >= best_middle){
            tree[node] = left;
            prefix_tree[node] = left_prefix;
            sufix_tree[node] = left_sufix+right_prefix+right+right_sufix;
            best_prefix_tree[node] = left_best_prefix;
            vi aux = {right_best_sufix, right_sufix+right, right_sufix+right+right_prefix+left_best_sufix,
                      right_sufix+right+right_prefix+left_sufix+left};
            best_sufix_tree[node] = *max_element(all(aux));
        }else if(right >= left && right >= join && right >= best_middle){
            tree[node] = right;
            prefix_tree[node] = right_prefix+left_sufix+left+left_prefix;
            sufix_tree[node] = right_sufix;
            vi aux = {left_best_prefix, left_prefix+left, left_prefix+left+left_sufix+right_best_prefix,
                      left_prefix+left+left_sufix+right_prefix+right};
            best_prefix_tree[node] = *max_element(all(aux));
            best_sufix_tree[node] = right_best_sufix;
        }else if(best_middle >= left && best_middle >= join && best_middle >= right){
            tree[node] = best_middle;
            prefix_tree[node] = left_sufix-left_best_sufix+left+left_prefix;
            sufix_tree[node] = right_prefix-right_best_prefix+right+right_sufix;
            vi aux_bp = {left_best_prefix, left_prefix+left, left_prefix+left+left_sufix+right_prefix+right};
            best_prefix_tree[node] = *max_element(all(aux_bp));
            vi aux_bs = {right_best_sufix, right_sufix+right, right_sufix+right+right_prefix+left_sufix+left};
            best_sufix_tree[node] = *max_element(all(aux_bs));
        }else{
            tree[node] = left+left_sufix+right_prefix+right;
            prefix_tree[node] = left_prefix;
            sufix_tree[node] = right_sufix;
            best_prefix_tree[node] = left_best_prefix;
            best_sufix_tree[node] = right_best_sufix;
        }
    }

    vi value_aux(pii curr_seg, pii target_seg, int node){

        vi res(5);

        if(curr_seg.first > target_seg.second || curr_seg.second < target_seg.first){
            res[0] = INF;
            return res;
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            res[0] = tree[node];
            res[1] = prefix_tree[node];
            res[2] = sufix_tree[node];
            res[3] = best_prefix_tree[node];
            res[4] = best_sufix_tree[node];

            return res;
        }

        auto left_seg = value_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node));
        auto right_seg = value_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));

        if(left_seg[0] == INF) return right_seg;
        if(right_seg[0] == INF) return left_seg;


        int left = left_seg[0];
        int right = right_seg[0];
        int left_sufix = left_seg[2];
        int left_prefix = left_seg[1];
        int right_sufix = right_seg[2];
        int right_prefix = right_seg[1];
        int join = left + right + left_sufix + right_prefix;
        int left_best_prefix = left_seg[3];
        int left_best_sufix = left_seg[4];
        int right_best_prefix = right_seg[3];
        int right_best_sufix = right_seg[4];
        int best_middle = left_best_sufix + right_best_prefix;

        if(left_best_sufix != INF && right_best_prefix == INF){
            best_middle = left_best_sufix;
        }else if(left_best_sufix == INF && right_best_prefix != INF){
            best_middle = right_best_sufix;
        }

        if(left >= right && left >= join && left >= best_middle){
            res[0] = left;
            res[1] = left_prefix;
            res[2] = left_sufix+right_prefix+right+right_sufix;
            res[3] = left_best_prefix;
            vi aux = {right_best_sufix, right_sufix+right, right_sufix+right+right_prefix+left_best_sufix};
            res[4] = *max_element(all(aux));
        }else if(right >= left && right >= join && right >= best_middle){
            res[0] = right;
            res[1] = right_prefix+left_sufix+left+left_prefix;
            res[2] = right_sufix;
            vi aux = {left_best_prefix, left_prefix+left, left_prefix+left+left_sufix+right_best_prefix};
            res[3] = *max_element(all(aux));
            res[4] = right_best_sufix;
        }else if(best_middle >= left && best_middle >= join && best_middle >= right){
            res[0] = best_middle;
            res[1] = left_sufix-left_best_sufix+left+left_prefix;
            res[2] = right_prefix-right_best_prefix+right+right_sufix;
            vi aux_bp = {left_best_prefix, left_prefix+left, left_prefix+left+left_sufix+right_prefix+right};
            res[3] = *max_element(all(aux_bp));
            vi aux_bs = {right_best_sufix, right_sufix+right, right_sufix+right+right_prefix+left_sufix+left};
            res[4] = *max_element(all(aux_bs));
        }else{
            res[0] = left+left_sufix+right_prefix+right;
            res[1] = left_prefix;
            res[2] = right_sufix;
            res[3] = left_best_prefix;
            res[4] = right_best_sufix;
        }

        deb("res[0] = ", res[0]);
        deb("res[1] = ", res[1]);
        deb("res[2] = ", res[2]);
        deb("res[3] = ", res[3]);
        deb("res[4] = ", res[4]);
        return  res;
    }
public:
    SegTree(int *vet, int size){
        sz = size;
        tree.resize(4*sz);
        prefix_tree.resize(4*sz);
        sufix_tree.resize(4*sz);
        best_sufix_tree.resize(4*sz);
        best_prefix_tree.resize(4*sz);
        build(vet, mp(0, sz-1), 0);
        print_vector_debug(tree);
    }

    int value(pii target_seg){
        return value_aux(mp(0,sz-1), target_seg, 0)[0];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sz;
    cin >> sz;

    int vet[sz];
    for (int i = 0; i < sz; ++i) {
        cin >> vet[i];
    }
    SegTree t(vet, sz);
    int n_query;
    cin >> n_query;
    int x,y;
    for (int i = 0; i < n_query; ++i) {
        cin >> x >> y;
        --x, --y;

        cout << t.value(mp(x,y)) << endl;
    }
    return 0;
}