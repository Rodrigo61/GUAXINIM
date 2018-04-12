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

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
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

#define LEFT_NODE(node) 2*node+1
#define RIGHT_NODE(node) 2*node+2

vi tree_val;
vector<pii> tree_childs;
vi in, post;

void make_tree(pii curr_seg, int node){

    deb("cf = ", curr_seg.first);
    deb("cs = ", curr_seg.second);

    if(curr_seg.first > curr_seg.second) return;

    if(curr_seg.first == curr_seg.second){
        tree_val[node] = in[curr_seg.first];
        tree_childs[node].first = -1;
        tree_childs[node].second = -1;
        return;
    }

    int last_pos = -1;
    int in_pos = -1;
    for (int i = curr_seg.first; i <= curr_seg.second; ++i) {
        for (int j = 0; j < post.size(); ++j) {
            if(in[i] == post[j]){
                if(j > last_pos){
                    last_pos = j;
                    in_pos = i;
                }
            }
        }
    }

    if(in_pos == -1){ cout << "InvalidInput" << endl; exit(1);}

    deb("in_pos = ", in_pos);
    deb("last_pos = ", last_pos);
    deb("post.sz = ", post.size());
    deb("node = ", node);
    tree_val[node] = post[last_pos];

    tree_val.push_back(-1);
    tree_val.push_back(-1);
    tree_childs.push_back(mp(-1,-1));
    tree_childs.push_back(mp(-1,-1));

    tree_childs[node].first = tree_val.size()-2;
    tree_childs[node].second = tree_val.size()-1;
    make_tree(mp(curr_seg.first, in_pos-1), tree_val.size()-2);
    make_tree(mp(in_pos+1, curr_seg.second), tree_val.size()-1);



}

void print_bfs(){

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(tree_val[node] == -1) continue;
        cout << tree_val[node] << ",";
        if(tree_childs[node].first != -1) q.push(tree_childs[node].first);
        if(tree_childs[node].second != -1) q.push(tree_childs[node].second);
    }

    cout << endl;
}
int main(){

    int size;
    cin >> size;

    int num;
    for (int i = 0; i < size; ++i) {
        cin >> num;
        in.push_back(num);
    }

    for (int i = 0; i < size; ++i) {
        cin >> num;
        post.push_back(num);
    }

    print_vector_debug(in);
    print_vector_debug(post);

    if(in.size() != post.size()){
        cout << "InvalidInput" << endl;
        return 0;
    }

    tree_val.push_back(1);
    tree_childs.push_back(mp(0,0));
    //print_vector_debug(tree);

    make_tree(mp(0, in.size()-1), 0);
    deb("print");
    print_bfs();
    return 0;

    erro:
    cout << "InvalidInput" << endl;
    return 0;
}