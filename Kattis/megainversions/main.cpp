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
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;


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

#define LEFT_NODE(i) i+i+1
#define RIGHT_NODE(i) i+i+2
#define MID(seg) (seg.first+seg.second)/2
#define LEFT_SEG(seg) mp(seg.first, MID(seg))
#define RIGHT_SEG(seg) mp(MID(seg) + 1, seg.second)

class SegTree{

private:

    vi max_tree;
    int sz;

    void update_aux(pii curr_seg, int index, int node){

        if (curr_seg.first == curr_seg.second) {
            ++max_tree[node];
            return;
        }

        if (index <= MID(curr_seg)) {
            update_aux(LEFT_SEG(curr_seg), index, LEFT_NODE(node));
        } else {
            update_aux(RIGHT_SEG(curr_seg), index, RIGHT_NODE(node));
        }

        max_tree[node] = max_tree[LEFT_NODE(node)] + max_tree[RIGHT_NODE(node)];
    }

    int query_aux(pii curr_seg, pii target_seg, int node){

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            return 0;
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            return max_tree[node];
        }

        return query_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node))
               + query_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));
    }

public:

    SegTree(int size){
        sz = size;
        max_tree.resize(4 * sz, 0);
    }

    int query(pii target_seg){
        return query_aux(mp(0, sz - 1), target_seg, 0);
    }

    void update(int index) {
        update_aux(mp(0, sz - 1), index, 0);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sz;
    cin >> sz;

    vi values(sz);
    for (size_t i = 0; i < sz; i++) {
        cin >> values[i];
    }

    SegTree sum_freq(sz + 2);
    vi left_bigger(sz);
    for (size_t i = 0; i < sz; i++) {
        sum_freq.update(values[i]);
        left_bigger[i] = sum_freq.query(mp(values[i] + 1, sz));
    }

    SegTree sum_freq_rev(sz + 2);
    vi right_smaller(sz);
    for (int i = sz - 1; i >= 0; --i) {
        sum_freq_rev.update(values[i]);
        right_smaller[i] = sum_freq_rev.query(mp(0, values[i] - 1));
    }

    ll acu = 0;
    for (size_t i = 0; i < sz; i++) {
        acu += (ll)right_smaller[i] * (ll)left_bigger[i];
    }

    printf("%lld\n", acu);

    return 0;
}
