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

#define MID(seg) (seg.first+seg.second)/2
#define LEFT_SEG(seg) mp(seg.first, MID(seg))
#define RIGHT_SEG(seg) mp(MID(seg) + 1, seg.second)


struct Node {
    int value;

    Node *left, *right;

    Node() {}
    Node(Node* l, Node* r, int v) {
        left = l;
        right = r;
        value = v;
    }
};

class Persistent_Segtree {

private:
    int sz;

    void build(pii curr_seg, Node* curr_node) {

        if (curr_seg.first == curr_seg.second) {
            curr_node->value = 0;
            return;
        }

        curr_node->left = new Node(NULL, NULL, 0);
        curr_node->right = new Node(NULL, NULL, 0);
        build(LEFT_SEG(curr_seg), curr_node->left);
        build(RIGHT_SEG(curr_seg), curr_node->right);
    }

    void update(int index, pii curr_seg, Node *prev_node, Node *curr_node) {

        if (curr_seg.first == curr_seg.second) {
            curr_node->value = 1;
            return;
        }

        if (index <= MID(curr_seg)) {
            curr_node->right = prev_node->right;
            Node *new_left = new Node(NULL, NULL, 0);
            curr_node->left = new_left;

            update(index, LEFT_SEG(curr_seg), prev_node->left, new_left);
        } else {
            curr_node->left = prev_node->left;
            Node *new_right = new Node(NULL, NULL, 0);
            curr_node->right = new_right;

            update(index, RIGHT_SEG(curr_seg), prev_node->right, new_right);
        }

        curr_node->value = curr_node->left->value + curr_node->right->value;
    }

    int query_aux(Node *curr_root, pii target_seg, pii curr_seg) {

        if (curr_seg.second < target_seg.first || curr_seg.first > target_seg.second) {
            return 0;
        }

        if (curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second) {
            return curr_root->value;
        }

        return query_aux(curr_root->left, target_seg, LEFT_SEG(curr_seg))
             + query_aux(curr_root->right, target_seg, RIGHT_SEG(curr_seg));
    }

public:

    vector<Node*> gen_versions(vi &vet){

        sz = vet.size();
        vi indexes(sz);

        // Vetor que guarda a posicao dos 0..N-1 numeros no vetor original
        for (size_t i = 0; i < sz; i++) {
            indexes[vet[i]] = i;
        }

        // Criando a arvore base, todos os valores zerados.
        Node *prev_root = new Node(NULL, NULL, 0);
        build(mp(0, sz - 1), prev_root);

        vector<Node*> result;

        for (size_t i = 0; i < sz; i++) {
            Node *new_root = new Node(NULL, NULL, 0);
            update(indexes[i], mp(0, sz - 1), prev_root, new_root);
            result.pb(new_root);
            prev_root = new_root;
        }

        return result;
    }

    int query(Node *version_root, pii target_seg) {
        return query_aux(version_root, target_seg, mp(0, sz - 1));
    }

};

int main(){

    int sz;
    scanf("%d", &sz);
    vii values(sz);

    for (size_t i = 0; i < sz; i++) {
        scanf("%d", &values[i].first);
        values[i].second = i;
    }

    vii values_copy = values;
    sort(all(values), greater<pii>());

    vi sorted_values(sz);
    vi sorted_indexes(sz);
    for (size_t i = 0; i < sz; i++) {
        sorted_values[i] = values[i].first;
        sorted_indexes[i] = values[i].second;
    }

    Persistent_Segtree pers_segtree;
    vector<Node*> versions = pers_segtree.gen_versions(sorted_indexes);


    print_vector_debug(sorted_values);
    ll acu = 0;
    for (size_t i = 0; i < sz; i++) {
        int K = values_copy[i].first;

        int R_tree = distance(upper_bound(sorted_values.rbegin(), sorted_values.rend(), K, less<int>()), sorted_values.rend()) - 1;
        int L_tree = 0;
        ll left_bigger = pers_segtree.query(versions[i], mp(L_tree, R_tree));

        R_tree = sz - 1;
        L_tree = distance(lower_bound(sorted_values.rbegin(), sorted_values.rend(), K, less<int>()) + 1, sorted_values.rend()) + 1 ;
        ll right_smaller;
        if (i == 0) {
            right_smaller = pers_segtree.query(versions[sz - 1], mp(L_tree, R_tree));
        } else {
            right_smaller = pers_segtree.query(versions[sz - 1], mp(L_tree, R_tree)) - pers_segtree.query(versions[i - 1], mp(L_tree, R_tree));
        }

        acu += right_smaller * left_bigger;
    }

    printf("%lld\n", acu);

    return 0;
}
