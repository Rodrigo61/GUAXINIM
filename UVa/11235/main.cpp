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

class Segtree{

private:

    typedef struct node_info{
        int freq_ext_left, freq_max, freq_ext_right;
    } node;

    vector<node> tree;
    int vet_size;
    vector<int> vet;

    void build_tree(pii seg, int root){

        if(seg.first == seg.second){
            tree[root].freq_ext_left = 1;
            tree[root].freq_ext_right = 1;
            tree[root].freq_max = 1;
        }else{

            int mid = (seg.first + seg.second)/2;
            build_tree(make_pair(seg.first, mid), 2*root+1);
            build_tree(make_pair(mid+1, seg.second), 2*root+2);

            auto &left  = tree[2*root+1];
            auto &right = tree[2*root+2];

            /* Freq max of this node*/
            if(vet[mid] == vet[mid+1]){
                if(left.freq_ext_right + right.freq_ext_left > left.freq_max
                   && left.freq_ext_right + right.freq_ext_left > right.freq_max){

                    /* Max in middle*/
                    deb("max in mid");
                    tree[root].freq_max = left.freq_ext_right + right.freq_ext_left;
                }else{
                    /* Max on extremes*/
                    deb("max on ext");
                    tree[root].freq_max = max(left.freq_max, right.freq_max);
                }
            }else{
                /* Max on extremes*/
                deb("max on ext");
                tree[root].freq_max = max(left.freq_max, right.freq_max);
            }


            /* Freq ext left of this node*/
            if(left.freq_max == mid-seg.first+1 && vet[mid] == vet[mid+1]){
                tree[root].freq_ext_left = left.freq_max + right.freq_ext_left;
            }else{
                tree[root].freq_ext_left = left.freq_ext_left;
            }


            /* Freq ext right of this node*/
            if(right.freq_max == seg.second - (mid+1) + 1 && vet[mid] == vet[mid+1]){
                    tree[root].freq_ext_right = right.freq_max + left.freq_ext_right;
            }else{
                tree[root].freq_ext_right = right.freq_ext_right;
            }

            deb("build_tree");
            deb("seg.first = ", seg.first);
            deb("seg.second = ", seg.second);
            deb("max = ", tree[root].freq_max);
            deb("max_esq = ", tree[root].freq_ext_left);
            deb("max_dir = ", tree[root].freq_ext_right);
            deb("vet[mid] = ", vet[mid]);
            deb("vet[mid+1] = ", vet[mid+1]);
            deb("--------------------------");

        }


    }

    node value_aux(pii seg_target, pii seg_current, int root){

        deb("value_aux");
        deb("seg_target.first = ", seg_target.first);
        deb("seg_target.second = ", seg_target.second);
        deb("seg_current.first = ", seg_current.first);
        deb("seg_current.second = ", seg_current.second);

        if(seg_current.first >= seg_target.first && seg_current.second <= seg_target.second){
            /* target contains current seg */
            deb("target contains = ", tree[root].freq_max);
            return tree[root];
        }

        if(seg_current.second < seg_target.first || seg_current.first > seg_target.second){
            /* Disjoint segs */
            deb("Disjoint segs");
            node null;
            null.freq_max = -1;
            null.freq_ext_left = -2;
            null.freq_ext_right = -2;
            return null;
        }

        deb("intersects");
        int mid = (seg_current.first + seg_current.second)/2;
        auto left = value_aux(seg_target, make_pair(seg_current.first, mid), 2*root+1);
        auto right = value_aux(seg_target, make_pair(mid+1, seg_current.second), 2*root+2);

        if(left.freq_max == -1){
            return right;
        }

        if(right.freq_max == -1){
            return left;
        }


        node new_node;
        /* Freq max of this node*/
        if(vet[mid] == vet[mid+1]){
            if(left.freq_ext_right + right.freq_ext_left > left.freq_max
               && left.freq_ext_right + right.freq_ext_left > right.freq_max){

                /* Max in middle*/
                new_node.freq_max = left.freq_ext_right + right.freq_ext_left;
            }else{
                /* Max on extremes*/
                new_node.freq_max = max(left.freq_max, right.freq_max);
            }
        }else{
            /* Max on extremes*/
            new_node.freq_max = max(left.freq_max, right.freq_max);
        }


        /* Freq ext left of this node*/
        if(left.freq_max == mid-seg_current.first+1 && vet[mid] == vet[mid+1]){
            new_node.freq_ext_left = left.freq_max + right.freq_ext_left;
        }else{
            new_node.freq_ext_left = left.freq_ext_left;
        }


        /* Freq ext right of this node*/
        if(right.freq_max == seg_current.second - (mid+1) + 1 && vet[mid] == vet[mid+1]){
            new_node.freq_ext_right = right.freq_max + left.freq_ext_right;
        }else{
            new_node.freq_ext_right = right.freq_ext_right;
        }

        return new_node;

    }

public:


    Segtree(vector<int> &vet){

        vet_size = vet.size();
        tree.resize(vet_size*4);

        this->vet = vet;

        build_tree(make_pair(0, vet.size()-1), 0);
    }

    int value(pii seg){
        return value_aux(seg, make_pair(0, vet_size-1), 0).freq_max;
    }

};


int main() {
    std::ios_base::sync_with_stdio(false);

    int vet_sz, n_query;
    int q_i, q_j;

    cin >> vet_sz >> n_query;
    while(vet_sz != 0){

        vector<int> vet(vet_sz);
        for (int i = 0; i < vet_sz; ++i) {
            cin >> vet[i];
        }

        print_vector_debug(vet);

        Segtree t(vet);

        for (int i = 0; i < n_query; ++i) {
            cin >> q_i >> q_j;
            q_i--;
            q_j--;

            cout << t.value(make_pair(q_i, q_j)) << endl;

        }

        cin >> vet_sz >> n_query;
    }
    return 0;
}