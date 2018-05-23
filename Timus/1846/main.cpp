bool debug = false;

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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

#define LEFT_NODE(i) i+i+1
#define RIGHT_NODE(i) i+i+2
#define MID(seg) (seg.first+seg.second)/2
#define LEFT_SEG(seg) mp(seg.first, MID(seg))
#define RIGHT_SEG(seg) mp(MID(seg) + 1, seg.second)

class SegTree{

private:

    vi gcd_tree;

    void update_aux(pii curr_seg, int index, int value, int node){

        if (curr_seg.first == curr_seg.second) {
            gcd_tree[node] = value;
            deb("gcd_tree[curr_seg.first] = ", gcd_tree[curr_seg.first]);
            deb("curr_seg.first = ", curr_seg.first);
            deb("index = ", index);
            return;
        }

        if (index <= MID(curr_seg)) {
            update_aux(LEFT_SEG(curr_seg), index, value, LEFT_NODE(node));
        } else {
            update_aux(RIGHT_SEG(curr_seg), index, value, RIGHT_NODE(node));
        }

        gcd_tree[node] = gcd(gcd_tree[LEFT_NODE(node)], gcd_tree[RIGHT_NODE(node)]);
        deb("curr_seg.first = ", curr_seg.first);
        deb("curr_seg.second = ", curr_seg.second);
        deb("LEFT_NODE = ", LEFT_NODE(node));
        deb("gcd_tree[LEFT_NODE(node)] = ", gcd_tree[LEFT_NODE(node)]);
        deb("gcd_tree[RIGHT_NODE(node)] = ", gcd_tree[RIGHT_NODE(node)]);
        deb("gcd_tree[node] = ", gcd_tree[node]);
    }

public:

    SegTree(){
        gcd_tree.resize(4*200000, 0);
    }

    void update(int index, int value) {
        update_aux(mp(0, 200000 - 1), index, value, 0);
    }

    int query(){
        return gcd_tree[0];
    }
};


int main(){
//    ios_base::sync_with_stdio(false);
    //cin.tie(0);


    int n_op;
    cin >> n_op;

    SegTree tree;

    char cmd;
    int num;
    int new_index = 0;
    vi values;
    map<int, list<int>> map_valores;

    for (size_t i = 0; i < n_op; i++) {
        cin >> cmd >> num;

        if (num != 0) {
            if (cmd == '+') {
                if (map_valores.find(num) == map_valores.end()) {
                    list<int> l;
                    map_valores[num] = l;
                }

                map_valores[num].push_back(new_index);
                tree.update(new_index, num);
                ++new_index;

            } else {
                int pos = map_valores[num].back();
                map_valores[num].pop_back();
                tree.update(pos, 0);
            }
        }

        int ans = tree.query();
        if (ans != 0) {
            printf("%d\n", ans);
        } else {
            printf("1\n");
        }
    }

    return 0;
}
