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

    int *vet;
    int vet_sz;
    vi tree;
    vector<char> lazy_tree;

    void lazy_update_and_propagate(pii curr_seg, int node){

        int mid = (curr_seg.first+curr_seg.second)/2;
        if(lazy_tree[node] != 'N'){
            char lazy_cmd = lazy_tree[node];
            /* There is a lazy action scheduled to be applied */
            int seg_size = curr_seg.second - curr_seg.first + 1;
            switch(lazy_cmd){
                case 'F':{ tree[node] = seg_size; break;}
                case 'E':{ tree[node] = 0; break;}
                case 'I':{
                    tree[node] = seg_size - tree[node];
                    break;
                }
            }

            if(seg_size > 1){
                /* Propagate if is not a leaf*/
                if(debug){
                    cout <<"The seq " <<  lazy_tree[node] << " command was postpone to the nodes (" <<  curr_seg.first <<  ", " << mid << ") and ("
                    << mid+1 << ", " << curr_seg.second << ")" << endl;
                }

                if(lazy_cmd == 'F' || lazy_cmd == 'E'){
                    lazy_tree[2*node+1] = lazy_cmd;
                    lazy_tree[2*node+2] = lazy_cmd;
                }else{
                    /* left children */
                    if(lazy_tree[2*node+1] == 'F'){
                        lazy_tree[2*node+1] = 'E';
                    }else if(lazy_tree[2*node+1] == 'E'){
                        lazy_tree[2*node+1] = 'F';
                    }else if(lazy_tree[2*node+1] == 'I'){
                        lazy_tree[2*node+1] = 'N';
                    }else{
                        lazy_tree[2*node+1] = 'I';
                    }

                    /* right children */
                    if(lazy_tree[2*node+2] == 'F'){
                        lazy_tree[2*node+2] = 'E';
                    }else if(lazy_tree[2*node+2] == 'E'){
                        lazy_tree[2*node+2] = 'F';
                    }else if(lazy_tree[2*node+2] == 'I'){
                        lazy_tree[2*node+2] = 'N';
                    }else{
                        lazy_tree[2*node+2] = 'I';
                    }
                }

            }
            lazy_tree[node] = 'N';
        }
    }

    int build_tree(pii curr_seg, int node){

        if(curr_seg.first == curr_seg.second){
            tree[node] = vet[curr_seg.first];
            return tree[node];
        }

        int mid = (curr_seg.first+curr_seg.second)/2;
        tree[node] =  build_tree(make_pair(curr_seg.first, mid), 2*node+1)
                    + build_tree(make_pair(mid + 1, curr_seg.second), 2*node + 2);

        return tree[node];
    }



    int value_aux(pii target_seg, pii curr_seg, int node){

        deb("curr_seg.first = ", curr_seg.first);
        deb("curr_seg.second = ", curr_seg.second);

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            /* disjoint int*/
            deb("Disjoint");
            return 0;
        }

        lazy_update_and_propagate(curr_seg, node);

        if(target_seg.first <= curr_seg.first && target_seg.second >= curr_seg.second){
            /* Contains */
            deb("Contains = ", tree[node]);
            return tree[node];
        }


        /* intersects */
        int mid = (curr_seg.first+curr_seg.second)/2;
        int todo = value_aux(target_seg, make_pair(curr_seg.first, mid), 2*node+1) +
                   value_aux(target_seg, make_pair(mid + 1, curr_seg.second), 2*node+2);;
        deb("insersect = ", todo);
        return todo;
    }



    void update_range_aux(pii range, pii curr_seg, char cmd, int node){

        deb("curr_seg.first = ", curr_seg.first);
        deb("curr_seg.second = ", curr_seg.second);

        lazy_update_and_propagate(curr_seg, node);

        if(curr_seg.second < range.first || curr_seg.first > range.second){
            /* Disjoint */
            return;
        }

        if(curr_seg.first >= range.first && curr_seg.second <= range.second){
            /* Within */
            /* Applying current update */
            deb("current_cmd = ", cmd);
            lazy_tree[node] = cmd;
            lazy_update_and_propagate(curr_seg, node);

            return;
        }

        /* Overlap */
        int mid = (curr_seg.first + curr_seg.second)/2;
        update_range_aux(range, make_pair(curr_seg.first, mid), cmd, 2*node+1);
        update_range_aux(range, make_pair(mid+1, curr_seg.second), cmd, 2*node+2);

        tree[node] = tree[2*node+1] + tree[2*node+2];
        deb("insersect(", curr_seg.first ,", ", curr_seg.second, ") =", tree[node]);
    }
public:

    SegTree(int *vet, int size){

        this->vet = vet;
        vet_sz = size;

        tree.resize(vet_sz*4);
        lazy_tree.resize(vet_sz*4, 'N');

        build_tree(make_pair(0, vet_sz-1), 0);
    }

    int value(pii seg){
        return value_aux(seg, make_pair(0, vet_sz-1), 0);
    }

    void update_range(pii range, char cmd){
        update_range_aux(range, make_pair(0, vet_sz-1), cmd, 0);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int cases;
    cin >> cases;

    int n_sets;
    int n_rep;
    int n_query;
    int query_count = 0;
    int cases_count = 0;
    char query_cmd;
    int q_i, q_j;
    string set;
    string set_concat;

    int vet_pirates[1024000+1];
    int vet_sz;

    for (int w = 0; w < cases; ++w) {

        ++cases_count;
        cout << "Case " << cases_count << ":" << endl;

        cin >> n_sets;

        set_concat = "";
        for (int i = 0; i < n_sets; ++i) {
            cin >> n_rep >> set;

            for (int j = 0; j < n_rep; ++j) {
                set_concat += set;
            }
        }

        vet_sz = set_concat.size();

        for (int i = 0; i < vet_sz; ++i) {
            if(set_concat[i] == '0'){
                vet_pirates[i] = 0;
            }else{
                vet_pirates[i] = 1;
            }
        }

        deb("Vet converted");

        SegTree t(vet_pirates, vet_sz);

        deb("Tree built");

        cin >> n_query;
        query_count = 0;
        for (int i = 0; i < n_query; ++i) {
            cin >> query_cmd >> q_i >> q_j;

            deb("query cmd = ", query_cmd,  "q_i = ", q_i,  "q_j = ", q_j);

            if(query_cmd != 'S'){
                t.update_range(make_pair(q_i, q_j), query_cmd);
            }else{
                cout << "Q" << ++query_count << ": " << t.value(make_pair(q_i, q_j)) << endl;
            }

        }

    }

    return 0;
}