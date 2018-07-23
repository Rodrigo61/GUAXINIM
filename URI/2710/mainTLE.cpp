bool debug = true;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include "bits/stdc++.h"
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


#define LEFT_NODE(node) 2*node+1
#define RIGHT_NODE(node) 2*node+2
#define MID(seg) (seg.first+seg.second)/2
#define LEFT_SEG(seg) make_pair(seg.first, MID(seg))
#define RIGHT_SEG(seg) make_pair(MID(seg) + 1, seg.second)

class SegTree{
private:

    vector<int> tree;
    vector<int> lazy_tree;
    int sz;

    void lazy_update(pii curr_seg, int node){

        if(lazy_tree[node] != 0){

            int seg_sz = curr_seg.second - curr_seg.first + 1;
            int value = lazy_tree[node];

            tree[node] += seg_sz*value;

            if(curr_seg.first != curr_seg.second){
                /* Propagate, not a leaf */
                lazy_tree[LEFT_NODE(node)] += value;
                lazy_tree[RIGHT_NODE(node)] += value;
            }

            lazy_tree[node] = 0;
        }
    }


    void update_aux(pii curr_seg, pii target_seg, int value, int node){

        lazy_update(curr_seg, node);

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            /* Disjoint */
            return;
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            /* Within */
            lazy_tree[node] += value;
            lazy_update(curr_seg, node);
            return;
        }

        /*Overlap*/
        update_aux(LEFT_SEG(curr_seg), target_seg, value, LEFT_NODE(node));
        update_aux(RIGHT_SEG(curr_seg), target_seg, value, RIGHT_NODE(node));

        tree[node] = tree[LEFT_NODE(node)] + tree[RIGHT_NODE(node)];

    }

    int value_aux(pii curr_seg, pii target_seg, int node){

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

    void update(pii target_seg, int value){
        update_aux(make_pair(0, sz-1), target_seg, value, 0);
    }

    int value(pii target_seg){
        return value_aux(make_pair(0, sz - 1), target_seg, 0);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    vector<SegTree> mat_segtree(500, SegTree(500));

    int Q;
    cin >> Q;

    char cmd;
    int arg1, arg2, arg3, arg4, arg5;

    for (int i = 0; i < Q; ++i) {

        cin >> cmd;

        if (cmd == 'U') {

            cin >> arg1 >> arg2 >> arg3 >> arg4 >> arg5;

            --arg1, --arg2, --arg3, --arg4;
            for (int i = arg1; i <= arg3; ++i) {

                mat_segtree[i].update(mp(arg2, arg4), arg5);

            }

        } else {

            cin >> arg1 >> arg2;
            --arg1, --arg2;
            printf("%d\n", mat_segtree[arg1].value(mp(arg2, arg2)));

        }
    }


    return 0;
}
