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

#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2

class SegTree{

private:
    int *vet;
    int vet_sz;
    vi tree;
    vector< std::list<pii> > lazy_tree;

    int build(pii curr_seg, int node){

        if(curr_seg.first == curr_seg.second){
            tree[node] = vet[curr_seg.first];
            return tree[node];
        }

        int mid = (curr_seg.first + curr_seg.second)/2;

        tree[node] = build(make_pair(curr_seg.first, mid), LEFT(node))
                     + build(make_pair(mid + 1, curr_seg.second), RIGHT(node));

        return tree[node];

    }


    void lazy_update(pii curr_seg, int node){
        if(!lazy_tree[node].empty()){

            deb("-----------");
            deb("Being update");
            deb("curr_seg.first = ", curr_seg.first);
            deb("curr_seg.second = ", curr_seg.second);

            for(auto &lazy_info : lazy_tree[node]){

                int lazy_value = lazy_info.second;
                int pos = lazy_info.first;

                deb("lazy_value = ", lazy_value);
                deb("BEFORE tree[node] = ", tree[node]);
                tree[node] += lazy_value;
                deb("AFTER tree[node] = ", tree[node]);

                if(curr_seg.first != curr_seg.second){
                    /* Propagate, not a leaf */
                    int mid = (curr_seg.first+curr_seg.second)/2;
                    if(pos <= mid){
                        deb("lazyvalue postpone to range(LEFT) = (", curr_seg.first, ", ", mid, ")");
                        lazy_tree[LEFT(node)].push_back(make_pair(pos, lazy_value));
                    }else{
                        deb("lazyvalue postpone to range(RIGHT) = (", mid+1, ", ", curr_seg.second, ")");
                        lazy_tree[RIGHT(node)].push_back(make_pair(pos, lazy_value));
                    }
                }
            }

            lazy_tree[node].clear();
            deb("-----------");
        }
    }


    int update_aux(pii curr_seg, int pos, int diff, int node){

        lazy_update(curr_seg, node);

        if(curr_seg.first > pos || curr_seg.second < pos){
            /* Disjoint */
            return tree[node];
        }

        if(curr_seg.first <= pos && curr_seg.second >= pos){
            /* Within */

            lazy_tree[node].push_back(make_pair(pos, diff));
            lazy_update(curr_seg, node);

            return tree[node];
        }

    }


    int value_aux(pii curr_seg, pii target_seg, int node){

        lazy_update(curr_seg, node);

        deb("curr_seg.first = ", curr_seg.first);
        deb("curr_seg.second = ", curr_seg.second);

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            /* Disjoint */
            deb("disjo = 0");
            return 0;
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            /* Within */
            deb("within =", tree[node]);
            return tree[node];
        }

        /* Overlap */
        deb("over");
        int mid = (curr_seg.first+curr_seg.second)/2;
        return  value_aux(make_pair(curr_seg.first, mid), target_seg, LEFT(node))
                +value_aux(make_pair(mid + 1, curr_seg.second), target_seg, RIGHT(node));
    }

public:

    SegTree(int *vet, int size){

        vet_sz = size;
        this->vet = vet;
        tree.resize(4*vet_sz);
        lazy_tree.resize(4*vet_sz);

        build(make_pair(0, vet_sz-1), 0);
        deb("build");

        if(debug){
            for (int i = 0; i < 4*vet_sz; ++i) {
                cout << tree[i] << " ";
            }cout << endl;
        }


    }

    void update(int pos, int value){

        int diff = value - vet[pos];
        deb("vet[pos] = ", vet[pos]);
        vet[pos] = value;
        deb("value = ", value);
        deb("diff = ", diff);

        update_aux(make_pair(0, vet_sz-1), pos, diff, 0);
    }

    int value(pii seg){
        return value_aux(make_pair(0, vet_sz-1), seg, 0);
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);

    int n_res;
    int case_count = 0;
    int vet_res[200000];
    int cmd_p1;
    int cmd_p2;
    string tree_cmd;

    cin >> n_res;

    bool first = true;
    while(n_res != 0){

        if(!first){
            cout << endl;
        }else{
            first = false;
        }

        ++case_count;
        cout << "Case " << case_count << ":" << endl;

        for (int i = 0; i < n_res; ++i) {
            cin >> vet_res[i];
        }

        SegTree t(vet_res, n_res);

        cin >> tree_cmd;
        while(tree_cmd != "END"){
            deb("*** tree_cmd = ", tree_cmd);

            cin >> cmd_p1 >> cmd_p2;
            deb("cmd_p1 = ", cmd_p1);
            deb("cmd_p2 = ", cmd_p2);

            if(tree_cmd[0] == 'S'){
                cmd_p1--;
                t.update(cmd_p1, cmd_p2);
            }else{
                cmd_p1--;
                cmd_p2--;
                cout << t.value(make_pair(cmd_p1, cmd_p2)) << endl;
            }

            cin >> tree_cmd;
        }

        cin >> n_res;
    }

    return 0;
}