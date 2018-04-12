#include <iostream>

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


#define LEFT_NODE(i) i+i+1
#define RIGHT_NODE(i) i+i+2
#define MID(seg) (seg.first+seg.second)/2
#define LEFT_SEG(seg) mp(seg.first, MID(seg))
#define RIGHT_SEG(seg) mp(MID(seg)+1, seg.second)


class SegTree{

private:
    vector<pair<long long, int>> tree;
    int sz;

    void build(long long *vet, pii curr_seg, int node){

        if(curr_seg.first == curr_seg.second){
            tree[node].first = vet[curr_seg.first];
            tree[node].second = curr_seg.first;
            return;
        }

        build(vet, LEFT_SEG(curr_seg), LEFT_NODE(node));
        build(vet, RIGHT_SEG(curr_seg), RIGHT_NODE(node));
        tree[node] = min(tree[LEFT_NODE(node)], tree[RIGHT_NODE(node)]);
    }


    pair<long long, int> value_aux(pii curr_seg, pii target_seg, int node){

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            return mp(numeric_limits<long long>::max(),0);
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            return tree[node];
        }

        return min(value_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node)),
                   value_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node)));
    }
public:

    SegTree(long long *vet, int size){
        sz = size;
        tree.resize(4*sz);
        build(vet, mp(0,sz-1), 0);
    }

    int value(pii target_seg){
        return value_aux(mp(0,sz-1), target_seg, 0).second;
    }
};

void max_area(long long *vet, pii curr_seg, SegTree &t, long long &maxi){

    if(curr_seg.first > curr_seg.second) return;

    if(curr_seg.first == curr_seg.second){
        maxi = max(maxi, vet[curr_seg.second]);
        return;
    }

    int min_idx = t.value(curr_seg);
    int seg_size = curr_seg.second - curr_seg.first + 1;

    maxi = max(maxi, seg_size*vet[min_idx]);
    max_area(vet, mp(curr_seg.first, min_idx-1), t, maxi);
    max_area(vet, mp(min_idx+1, curr_seg.second), t, maxi);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_blocks;

    while(cin >> n_blocks, n_blocks != 0){

        long long vet[n_blocks];

        for (int i = 0; i < n_blocks; ++i) {
            cin >> vet[i];
        }

        SegTree t(vet, n_blocks);

        long long maxi = 0;
        max_area(vet, mp(0,n_blocks-1), t, maxi);

        cout << maxi << endl;


    }

    return 0;
}