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


/// Typedefs
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


class SegTree{

private:

    vector<int> tree;
    vector<int> vet;
    vector<pii> tree_index;
    vi lazy_tree;

    int value_aux(int range_begin, int range_end, int tree_node){

        int cur_range_begin = tree_index[tree_node].first;
        int cur_range_end = tree_index[tree_node].second;

        if(range_begin > cur_range_end || range_end < cur_range_begin){
            // out of range
            return std::numeric_limits<int>::max();
        }

        if(range_begin <= cur_range_begin && range_end >= cur_range_end){
            // contains

            if(lazy_tree[tree_node] != -1){
                /* The Lazy update that was scheduled, must be applied */
                tree[tree_node] = min(tree[tree_node], lazy_tree[tree_node]);

                /* Lazy mark to childs */
                lazy_tree[2*tree_node+1] = lazy_tree[tree_node];
                lazy_tree[2*tree_node+2] = lazy_tree[tree_node];
                lazy_tree[tree_node] = -1;
            }

            return tree[tree_node];
        }

        if(cur_range_begin == cur_range_end){
            //leaf node
            return tree[tree_node];
        }

        return min(value_aux(range_begin, range_end, tree_node*2 + 1), value_aux(range_begin, range_end, tree_node*2 + 2));

    }

    int build_tree(pair<int, int> tree_range, int this_tree_root){

        tree_index[this_tree_root] = make_pair(tree_range.first, tree_range.second);

        if(tree_range.first == tree_range.second){
            tree[this_tree_root] = vet[tree_range.first];
            return vet[tree_range.first];
        }

        int mid = (tree_range.first + tree_range.second) / 2;

        tree[this_tree_root] = min(build_tree(make_pair(tree_range.first, mid), 2 * this_tree_root + 1),
                                   build_tree(make_pair(mid + 1, tree_range.second), 2 * this_tree_root + 2));

        return tree[this_tree_root];
    }

    int update_aux(pair<int, int> tree_range, int pos, int root){

        if(tree_range.first == tree_range.second){
            tree[root] = vet[pos];
            return vet[pos];
        }else{

            int mid = (tree_range.first + tree_range.second) / 2;
            if(pos <= mid){
                tree[root] = min(tree[root], update_aux(make_pair(tree_range.first, mid), pos, 2*root+1));
            }else{
                tree[root] = min(tree[root], update_aux(make_pair(mid + 1, tree_range.second), pos, 2*root+2));
            }

            return tree[root];
        }
    }

    void update_range_aux(pii range, pii curr_seg, int value, int node){

        if(curr_seg.second < range.first || curr_seg.first > range.second){
            /*Disjoint*/
            return;
        }

        if(curr_seg.first == curr_seg.second){
            /* Leaf */
            tree[node] = value;
            return;
        }


        int mid = (curr_seg.first + curr_seg.second)/2;
        update_range_aux(range, make_pair(curr_seg.first, mid), value, 2*node+1);
        update_range_aux(range, make_pair(mid + 1, curr_seg.second), value, 2*node+2);

        tree[node] = min(tree[2*node+1], tree[2*node+2]);

    }

    void update_range_lazy_aux(pii range, pii curr_seg, int value, int node){

        if(curr_seg.second < range.first || curr_seg.first > range.second){
            /*Disjoint*/
            return;
        }

        if(curr_seg.first >= range.first && curr_seg.second <= range.second){
            /* Contains */
            if(lazy_tree[node] != -1){
                /* The Lazy update that was scheduled, must be applied */
                tree[node] = min(tree[node], lazy_tree[node]);

                /* Lazy mark to childs */
                lazy_tree[2*node+1] = lazy_tree[node];
                lazy_tree[2*node+2] = lazy_tree[node];
                lazy_tree[node] = -1;
            }

            /* Apply current update */
            tree[node] = min(tree[node], value);

            return;
        }


        /* Overlap */
        int mid = (curr_seg.first + curr_seg.second)/2;
        update_range_aux(range, make_pair(curr_seg.first, mid), value, 2*node+1);
        update_range_aux(range, make_pair(mid + 1, curr_seg.second), value, 2*node+2);

        tree[node] = min(tree[2*node+1], tree[2*node+2]);

    }

public:

    SegTree(vector<int> &vet){
        this->vet = vet;

        tree.resize(vet.size()*4);
        lazy_tree.resize(vet.size()*4, -1);
        tree_index.resize(vet.size()*4);

        build_tree(make_pair(0, vet.size()-1), 0);

    }

    int value(int range_begin, int range_end){
        return value_aux(range_begin, range_end, 0);
    }

    void update(int value, int pos){

        vet[pos] = value;

        update_aux(make_pair(0, vet.size()-1), pos, 0);
    }

    int update_range(pii range, int value){
        update_range_aux(range, make_pair(0, vet.size()-1), value, 0);
    }

    int update_range_lazy(pii range, int value){
        update_range_lazy_aux(range, make_pair(0, vet.size()-1), value, 0);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    vector<int> A = {10, 2, 47, 3, 7, 9, 1, 98, 21, 37};
    SegTree t(A);

    cout << "RQM(3,4) = " << t.value(3,4) << endl;
    cout << "RQM(5,7) = " << t.value(5,7) << endl;
    cout << "RQM(5,9) = " << t.value(5,9) << endl;
    cout << "RQM(1,1) = " << t.value(1,1) << endl;
    cout << "RQM(1,4) = " << t.value(1,4) << endl;

    t.update(-1, 2);
    cout << "after updt RQM(1,4) = " << t.value(1,4) << endl;

    t.update_range_lazy(make_pair(1,5), 1);
    cout << "Range (1,5) updated to 1";
    cout << "RQM(3,4) = " << t.value(3,4) << endl;
    cout << "RQM(5,7) = " << t.value(5,7) << endl;
    cout << "RQM(5,9) = " << t.value(5,9) << endl;
    cout << "RQM(1,1) = " << t.value(1,1) << endl;
    cout << "RQM(1,4) = " << t.value(1,4) << endl;
    cout << "RQM(8,9) = " << t.value(8,9) << endl;


    return 0;
}
