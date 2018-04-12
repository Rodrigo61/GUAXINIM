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

#define LEFT(node) (node<<1)|1
#define RIGHT(node) 2*node+2


class SegTree{
private:
    vector<long long int> max_tree;
    vector<long long int> min_tree;
    vector< pair<pii, long long int> > max_tree_lazy;
    vector< pair<pii, long long int> > min_tree_lazy;
    int vet_sz;


    void update_range_aux(pii curr_seg, pii target_seg, long long int value, int node){


        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            /* Disjoint */
            return;
        }

        lazy_update_and_propagation(curr_seg, node);

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            /* Within */
            max_tree_lazy[node] = make_pair(target_seg, value);
            min_tree_lazy[node] = make_pair(target_seg, value);
            lazy_update_and_propagation(curr_seg, node);
            return;
        }

        /* Overlap */
        int mid = (curr_seg.first+curr_seg.second)/2;
        update_range_aux(make_pair(curr_seg.first, mid), target_seg, value, LEFT(node));
        update_range_aux(make_pair(mid + 1, curr_seg.second), target_seg, value, RIGHT(node));

        max_tree[node] = max(max_tree[LEFT(node)], max_tree[RIGHT(node)]);
        min_tree[node] = min(min_tree[LEFT(node)], min_tree[RIGHT(node)]);

    }

    void lazy_update_and_propagation(pii curr_seg, int node){

        /* Max tree */
        long long int lazy_value = max_tree_lazy[node].second;
        pii target_seg = max_tree_lazy[node].first;

        if(lazy_value != -1){


            max_tree[node] = max(max_tree[node], lazy_value);

            if(curr_seg.first != curr_seg.second){
                /* Not a leaf, so propagate */
                int mid = (curr_seg.first + curr_seg.second)/2;

                if(mid >= target_seg.first) {
                    if (max_tree_lazy[LEFT(node)].second < lazy_value) {
                        max_tree_lazy[LEFT(node)] = max_tree_lazy[node];
                    }
                }
                if(mid+1 <= target_seg.second) {
                    if(max_tree_lazy[RIGHT(node)].second < lazy_value){
                        max_tree_lazy[RIGHT(node)] = max_tree_lazy[node];
                    }
                }
            }

            max_tree_lazy[node] = make_pair(make_pair(0,0),-1);
        }


        /* Min tree */
        lazy_value = min_tree_lazy[node].second;
        target_seg = min_tree_lazy[node].first;
        if(lazy_value != -1){

            min_tree[node] = max(min_tree[node], lazy_value);

            if(curr_seg.first != curr_seg.second){
                /* Not a leaf, so propagate */
                int mid = (curr_seg.first + curr_seg.second)/2;

                if(mid >= target_seg.first) {
                    min_tree_lazy[LEFT(node)] = min_tree_lazy[node];
                }
                if(mid+1 <= target_seg.second) {
                    min_tree_lazy[RIGHT(node)] = min_tree_lazy[node];
                }
            }

            min_tree_lazy[node] = make_pair(make_pair(0,0),-1);
        }
    }

    int overlap_aux(pii curr_seg, pii target_seg, long long int value, int node){


        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            /* Disjoint */
            return 0;
        }

        lazy_update_and_propagation(curr_seg, node);

        if(curr_seg.first == curr_seg.second){
            /* Within leaf */
            if(max_tree[node] <= value){
                return 1;
            }else{
                return 0;
            }
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second) {
            /* Within */

            if(max_tree[node] <= value){
                return curr_seg.second - curr_seg.first + 1;
            }else if(min_tree[node] <= value){
                int mid = (curr_seg.first + curr_seg.second)/2;
                return overlap_aux(make_pair(curr_seg.first, mid), target_seg, value, LEFT(node))
                        + overlap_aux(make_pair(mid + 1, curr_seg.second), target_seg, value, RIGHT(node));
            }else{
                return 0;
            }
        }

        /* Overlap */
        int mid = (curr_seg.first + curr_seg.second)/2;
        return overlap_aux(make_pair(curr_seg.first, mid), target_seg, value, LEFT(node))
               + overlap_aux(make_pair(mid + 1, curr_seg.second), target_seg, value, RIGHT(node));

    }
public:

    SegTree(int size){
        vet_sz = size;

        max_tree.resize(4*vet_sz);
        min_tree.resize(4*vet_sz);
        max_tree_lazy.resize(4*vet_sz, make_pair(make_pair(0,0),-1));
        min_tree_lazy.resize(4*vet_sz, make_pair(make_pair(0,0),-1));

    }

    void update_range(pii target_seg, long long int value){
        update_range_aux(make_pair(0, vet_sz-1), target_seg, value, 0);
    }

    int overlap(pii target_seg, long long int value){
        return overlap_aux(make_pair(0, vet_sz-1), target_seg, value, 0);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int cases;
    cin >> cases;

    int n_building;
    long long int h;
    int r, l;
    int overlap;

    for (int w = 0; w < cases; ++w) {

        overlap = 0;
        cin >> n_building;

        SegTree t(100001);
        for (int i = 0; i < n_building; ++i) {
            cin >> l >> r >> h;

            overlap += t.overlap(make_pair(l,r-1), h);
            t.update_range(make_pair(l,r-1), h);
        }

        cout << overlap << endl;
    }

    cin >> overlap;


    return 0;
}