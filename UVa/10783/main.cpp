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

#define LEFT_NODE(node)  2*node+1
#define RIGHT_NODE(node)  2*node+2
#define MID(curr_seg) (curr_seg.first+curr_seg.second)/2
#define LEFT_SEG(curr_seg) make_pair(curr_seg.first, MID(curr_seg))
#define RIGHT_SEG(curr_seg) make_pair(MID(curr_seg) + 1, curr_seg.second)

class SegTree{

private:
    vi tree;
    int size = 101;

    void build(pii curr_seg, int node){

        if(curr_seg.first == curr_seg.second){
            /* Leaf */
            if(curr_seg.first % 2 == 0){
                tree[node] = 0;
            }else{
                tree[node] = curr_seg.first;
            }
            return;
        }

        build(LEFT_SEG(curr_seg), LEFT_NODE(node));
        build(RIGHT_SEG(curr_seg), RIGHT_NODE(node));

        tree[node] = tree[LEFT_NODE(node)] + tree[RIGHT_NODE(node)];
    }


    int value_aux(pii curr_seg, pii target_seg, int node){

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            /* Disjoint */
            return 0;
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            /* Within */
            return tree[node];
        }

        /* Overlap */
        return value_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node))
               + value_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));
    }

public:

    SegTree(){
        tree.resize(4*size);
        build(make_pair(0, size-1), 0);
    }

    int value(pii target_seg){
        return value_aux(make_pair(0, size-1), target_seg, 0);
    }

};

int main(){
    ios_base::sync_with_stdio(false);


    int n_cases;
    int count_cases = 0;
    cin >> n_cases;
    int a, b;
    SegTree t;

    for (int w = 0; w < n_cases; ++w) {
        cin >> a >> b;

        ++count_cases;
        cout << "Case " << count_cases << ": " << t.value(make_pair(a,b))<< endl;
    }

    return 0;
}