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

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)

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
#define LEFT_SEG(seg) make_pair(seg.first, MID(seg))
#define RIGHT_SEG(seg) make_pair(MID(seg) + 1, seg.second)

class SegTree{
private:

    vector<long long int> tree;
    vector<long long int> lazy_tree;
    int sz;

    void lazy_update(pii curr_seg, int node){

        if(lazy_tree[node] != 0){

            int seg_sz = curr_seg.second - curr_seg.first + 1;
            long long int value = lazy_tree[node];

            tree[node] += seg_sz*value;

            if(curr_seg.first != curr_seg.second){
                /* Propagate, not a leaf */
                lazy_tree[LEFT_NODE(node)] += value;
                lazy_tree[RIGHT_NODE(node)] += value;
            }

            lazy_tree[node] = 0;
        }
    }


    void update_aux(pii curr_seg, pii target_seg, long long int value, int node){

        lazy_update(curr_seg, node);

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            /* Disjoint */
            return;
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            /* Within */
            lazy_tree[node] = value;
            lazy_update(curr_seg, node);
            return;
        }

        /*Overlap*/
        update_aux(LEFT_SEG(curr_seg), target_seg, value, LEFT_NODE(node));
        update_aux(RIGHT_SEG(curr_seg), target_seg, value, RIGHT_NODE(node));

        tree[node] = tree[LEFT_NODE(node)] + tree[RIGHT_NODE(node)];

    }

    long long int value_aux(pii curr_seg, pii target_seg, int node){

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            /* Disjoint */
            return 0;
        }

        lazy_update(curr_seg, node);

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            /* Within */
            return tree[node];
        }

        return value_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node))
                + value_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));

    }

public:

    SegTree(int size){
        sz = size;
        tree.resize(4*sz, 0);
        lazy_tree.resize(4*sz, 0);
    }

    void update(pii target_seg, long long int value){
        update_aux(make_pair(0, sz-1), target_seg, value, 0);
    }

    long long int value(pii target_seg){
        return value_aux(make_pair(0, sz - 1), target_seg, 0);
    }
};


int main(){
    ios_base::sync_with_stdio(false);

    int n_cases;
    cin >> n_cases;
    int size;
    int n_query;
    int cmd;
    long long int a, b, c;

    for (int w = 0; w < n_cases; ++w) {

        cin >> size >> n_query;
        deb("size = ", size, "n_query =", n_query);
        SegTree t(size);

        for (int i = 0; i < n_query; ++i) {
            cin >> cmd;
            if(cmd == 0){
                cin >> a >> b >> c;
                --a;
                --b;
                deb("a = ", a, " b = ", b, "c = ", c);
                t.update(make_pair(a,b), c);
            }else{
                cin >> a >> b;
                deb("a = ", a, " b = ", b);
                --a;
                --b;
                cout << t.value(make_pair(a,b)) << endl;
            }
        }
    }
    return 0;
}
