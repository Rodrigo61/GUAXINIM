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
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
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
typedef long long int lli;

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
#define RIGHT_SEG(seg) mp(MID(seg) + 1, seg.second)

vi vet_divisors(1000001, 0);

int divisors(int num){


    if(vet_divisors[num] == 0){
        int acu = 0;
        int max = sqrt(num);
        for(int i = 1; i <= max; i++)
        {
            if(num % i == 0)
            {
                ++acu;
                int d = num/i;
                if(d!=i)
                    ++acu;
            }
        }

        vet_divisors[num] = acu;
        return acu;
    }else{
        return vet_divisors[num];
    }

}


class SegTree{

private:

    vector<long long int> tree;
    vi max_tree;
    int sz;

    void build(int *vet, pii curr_seg, int node){

        if(curr_seg.first == curr_seg.second){
            tree[node] = vet[curr_seg.first];
            max_tree[node] = vet[curr_seg.first];
            return;
        }

        int mid = (curr_seg.first+curr_seg.second)/2;
        build(vet, LEFT_SEG(curr_seg), LEFT_NODE(node));
        build(vet, RIGHT_SEG(curr_seg), RIGHT_NODE(node));

        tree[node] = tree[LEFT_NODE(node)] + tree[RIGHT_NODE(node)];
        max_tree[node] = max(max_tree[LEFT_NODE(node)], max_tree[RIGHT_NODE(node)]);
    }

    lli value_aux(pii curr_seg, pii target_seg, int node){

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            return 0;
        }

        if(curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second){
            return tree[node];
        }

        int mid = (curr_seg.first+curr_seg.second)/2;
        return value_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node))
               + value_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));
    }

    void update_aux(pii curr_seg, pii target_seg, int node){

        if(curr_seg.second < target_seg.first || curr_seg.first > target_seg.second){
            return ;
        }

        if(max_tree[node] <= 2){
            return;
        }

        if(curr_seg.first == curr_seg.second){
            deb("num = ", tree[node]);
            tree[node] = divisors(tree[node]);
            deb("sum = ", tree[node]);
            max_tree[node] = tree[node];
            return;
        }

        int mid = (curr_seg.first+curr_seg.second)/2;
        update_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node));
        update_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));

        tree[node] = tree[LEFT_NODE(node)] + tree[RIGHT_NODE(node)];
        max_tree[node] = max(max_tree[LEFT_NODE(node)], max_tree[RIGHT_NODE(node)]);
    }

public:

    SegTree(int *vet, int size){

        sz = size;

        tree.resize(4*sz);
        max_tree.resize(4*sz);

        build(vet, mp(0, sz-1), 0);
    }

    lli value(pii target_seg){
        return value_aux(mp(0, sz-1), target_seg, 0);
    }

    void update(pii target_seg){
        update_aux(mp(0, sz-1), target_seg, 0);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int sz;
    int n_query;

    cin >> sz >> n_query;

    int vet[sz];

    for (int i = 0; i < sz; ++i) {
        cin >> vet[i];
    }

    SegTree t(vet, sz);

    int cmd;
    int a, b;
    for (int i = 0; i < n_query; ++i) {
        cin >> cmd >> a >> b;
        --a, --b;

        if(cmd == 1){
            t.update(mp(a,b));
        }else{
            cout << t.value(mp(a,b)) << endl;
        }
    }

    return 0;
}