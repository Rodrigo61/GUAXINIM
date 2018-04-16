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

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "

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



vector<pii> ranged_tree;
int curr_time;
vector<vi> vet_adj;
vi corrected_salary;
vi salary_tree;

void dfs(int node) {

    corrected_salary.push_back(salary_tree[node]);
    deb("node = ", node);
    ++curr_time;
    ranged_tree[node].first = curr_time;
    for (auto &v : vet_adj[node]) {
        dfs(v);
    }
    ranged_tree[node].second = curr_time;

}

void create_ranged_tree() {

    curr_time = -1;
    dfs(0);
}

#define LEFT_NODE(i) 2*i + 1
#define RIGHT_NODE(i) 2*i + 2
#define MID(seg) (seg.first + seg.second)/2
#define LEFT_SEG(seg) mp(seg.first, MID(seg))
#define RIGHT_SEG(seg) mp(MID(seg)+1, seg.second)

typedef pair<long long, long long> pll;

class SegTree{

private:
    vll tree_sum;
    vll lazy_tree;
    vll tree_min;
    int sz;

    void create_tree(pii curr_seg, int node, vi &salary_tree) {


        if(curr_seg.first == curr_seg.second) {
            tree_sum[node] = salary_tree[curr_seg.first];
            tree_min[node] = salary_tree[curr_seg.first];
            return;
        }

        create_tree(LEFT_SEG(curr_seg), LEFT_NODE(node), salary_tree);
        create_tree(RIGHT_SEG(curr_seg), RIGHT_NODE(node), salary_tree);


        tree_sum[node] = tree_sum[LEFT_NODE(node)] + tree_sum[RIGHT_NODE(node)];
        tree_min[node] = min(tree_min[LEFT_NODE(node)], tree_min[RIGHT_NODE(node)]);

        deb("CREATE| curr_seg.first = ", curr_seg.first);
        deb("CREATE| curr_seg.second = ", curr_seg.second);
        deb("sum = ", tree_sum[node]);
    }

    void lazy_update(pii curr_seg, int node) {

        if(lazy_tree[node] != 0) {

            deb("LAZY| curr_seg.first = ", curr_seg.first);
            deb("LAZY| curr_seg.second = ", curr_seg.second);


            int seg_size = curr_seg.second - curr_seg.first + 1;

            tree_sum[node] += seg_size * lazy_tree[node];
            tree_min[node] += lazy_tree[node];

            if(curr_seg.first != curr_seg.second) {
                lazy_tree[LEFT_NODE(node)] += lazy_tree[node];
                lazy_tree[RIGHT_NODE(node)] += lazy_tree[node];
            }

            lazy_tree[node] = 0;

        }
    }

    void update_aux(pii curr_seg, pii target_seg, int node, int increment) {

        deb("UPD| curr_seg.first = ", curr_seg.first);
        deb("UPD| curr_seg.second = ", curr_seg.second);

        deb("UPD| target_seg.first = ", target_seg.first);
        deb("UPD| target_seg.second = ", target_seg.second);

        lazy_update(curr_seg, node);

        if ( curr_seg.second < target_seg.first || curr_seg.first > target_seg.second) {
            return;
        }

        if (curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second) {

            lazy_tree[node] += increment;

            lazy_update(curr_seg, node);
            deb("INCREMENT = ", increment);
            return;
        }

        update_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node), increment);
        update_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node), increment);

        tree_sum[node] = tree_sum[LEFT_NODE(node)] + tree_sum[RIGHT_NODE(node)];
        tree_min[node] = min(tree_min[LEFT_NODE(node)], tree_min[RIGHT_NODE(node)]);
    }


    long long query_aux(pii curr_seg, pii target_seg, int node) {

        lazy_update(curr_seg, node);
        deb("query| curr_seg.first = ", curr_seg.first);
        deb("query| curr_seg.second = ", curr_seg.second);

        if ( curr_seg.second < target_seg.first || curr_seg.first > target_seg.second) {
            return 0;
        }

        if (curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second) {
            deb("WITHIN = ", tree_sum[node]);
            return tree_sum[node];
        }


        long long aux = query_aux(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node))
            +  query_aux(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node));

        deb("overlap = ", aux);

        return aux;

    }

    int get_min(pii curr_seg, pii target_seg, int node) {

        lazy_update(curr_seg, node);
        deb("min| curr_seg.first = ", curr_seg.first);
        deb("min| curr_seg.second = ", curr_seg.second);

        if ( curr_seg.second < target_seg.first || curr_seg.first > target_seg.second) {
            return 9999999;
        }

        if (curr_seg.first >= target_seg.first && curr_seg.second <= target_seg.second) {
            return tree_min[node];
        }


        return min(get_min(LEFT_SEG(curr_seg), target_seg, LEFT_NODE(node)),
                   get_min(RIGHT_SEG(curr_seg), target_seg, RIGHT_NODE(node)));


    }

public:

    SegTree(vi &salary_tree) {
        sz = salary_tree.size();
        tree_sum.resize(4*sz);
        tree_min.resize(4*sz);
        lazy_tree.resize(4*sz, 0);

        create_tree(mp(0, sz-1), 0, salary_tree);
    }

    long long query(pii target_seg) {
        return query_aux(mp(0, sz-1), target_seg, 0);
    }

    void update(pii target_seg) {
        int increment = get_min(mp(0, sz-1), target_seg, 0);
        update_aux(mp(0, sz-1), target_seg, 0, min(increment, 1000));
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;
    int case_count = 0;

    for (int w = 0; w < n_cases; ++w) {

        cout << "Case " << ++case_count << ":" <<endl;
        int sz, query_count;

        cin >> sz >> query_count;

        salary_tree.clear();
        salary_tree.resize(sz);

        vet_adj.clear();
        vet_adj.resize(sz);

        corrected_salary.clear();

        ranged_tree.clear();
        ranged_tree.resize(sz);

        int parent;
        for (int i = 0; i < sz; ++i) {
            cin >> parent >> salary_tree[i];

            --parent;

            if (i != 0)
                vet_adj[parent].push_back(i);
        }

        create_ranged_tree();

        if (debug) {
            for (auto &p : ranged_tree) {
                cout << "( " << p.first << ", " << p.second << ")  ";
            }
            cout << endl;
        }

        SegTree sgtree(corrected_salary);
        deb("seg created");


        int type_query, emplo_id;
        for (int i = 0; i < query_count; ++i) {
            cin >> type_query >> emplo_id;

            --emplo_id;

            deb("type_query = ", type_query, "emplo_id = ", emplo_id);
            deb("emplo_id = ", emplo_id);
            deb("ranged_tree[emplo_id] = ", ranged_tree[emplo_id].first, ",", ranged_tree[emplo_id].second);

            if (type_query == 1) {
                cout << sgtree.query(ranged_tree[emplo_id]) << endl;
            } else {
                sgtree.update(ranged_tree[emplo_id]);
            }

        }



    }

    return 0;
}
