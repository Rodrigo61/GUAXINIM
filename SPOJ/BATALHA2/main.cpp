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

vector<vector<char>> grid;
int R, C;

bool valid(int i, int j) {

    return i >= 0 && i < R && j >= 0 && j < C && grid[i][j] == '#';
}

vii get_adj (pii u) {

    vii result;

    if (valid(u.first + 1, u.second)) {
        result.pb(mp(u.first + 1, u.second));
    }
    if (valid(u.first - 1, u.second)) {
        result.pb(mp(u.first - 1, u.second));
    }
    if (valid(u.first, u.second + 1)) {
        result.pb(mp(u.first, u.second + 1));
    }
    if (valid(u.first, u.second - 1)) {
        result.pb(mp(u.first, u.second - 1));
    }

    return result;
}



class Node{
public:
    Node *parent;
    int set_sz;
    int rank;
    int size;
    int i, j;

    Node(){
        parent = nullptr;
        set_sz = 1;
        rank = 0;
    }
};

class UnionFind{

private:

    vector<vector<Node>> nodes_matrix;
public:

    UnionFind (int R, int C) {
        nodes_matrix.resize(R, vector<Node>(C));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                nodes_matrix[i][j].i = i;
                nodes_matrix[i][j].j = j;

                if (grid[i][j] == '.') {
                    nodes_matrix[i][j].set_sz = -1;
                }
            }
        }

    }

    Node* find_set(pii node_id){

        Node *n = &nodes_matrix[node_id.first][node_id.second];

        if(n->parent == nullptr){
            return n;
        }

        n->parent = find_set(mp(n->parent->i, n->parent->j)); // path compress
        return n->parent;
    }

    void union_by_rank(pii pos1, pii pos2){

        Node *rep1 = find_set(pos1);
        Node *rep2 = find_set(pos2);

        if(rep1 != rep2){
            if(rep1->rank > rep2->rank){
                rep2->parent = rep1;
                rep1->set_sz += rep2->set_sz;
            }else if(rep1->rank < rep2->rank){
                rep1->parent = rep2;
                rep2->set_sz += rep1->set_sz;
            }else{
                rep2->parent = rep1;
                rep1->set_sz += rep2->set_sz;
                ++rep1->rank;
            }
        }
    }

    void destroy_position(pii pos) {
        Node *rep = find_set(pos);
        rep->set_sz--;
    }

    int get_count_destroyed() {

        int R = nodes_matrix.size();
        int C = nodes_matrix[0].size();

        vector<vi> visited(R, vi(C, 0));
        int result = 0;

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {

                Node *rep = find_set(mp(i, j));

                if (!visited[rep->i][rep->j] && rep->set_sz == 0) {
                    visited[rep->i][rep->j] = 1;
                    deb("[rep->i][rep->j] = ", rep->i, rep->j);
                    ++result;
                }
            }
        }

        return result;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> R >> C;

    grid.resize(R, vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }


    UnionFind uf(R, C);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {

            if (grid[i][j] == '.') { continue; }

            if (valid(i - 1, j)) {
                uf.union_by_rank(mp(i, j), mp(i - 1, j));
            }

            if (valid(i, j - 1)) {
                uf.union_by_rank(mp(i, j), mp(i, j - 1));
            }
        }
    }

//
//    for (int i = 0; i < R; ++i) {
//        for (int j = 0; j < C; ++j) {
//
//            Node *rep = uf.find_set(mp(i, j));
//
//            printf("  %d/%d  ", rep->i, rep->j);
//        }
//        printf("\n");
//    }


    int n_fires;
    cin >> n_fires;

    deb("n_fires = ", n_fires);
    for (int k = 0; k < n_fires; ++k) {
        int i, j;
        cin >> i >> j;
        --i, --j;

        uf.destroy_position(mp(i, j));
    }


    printf("%d\n", uf.get_count_destroyed());

    return 0;
}
