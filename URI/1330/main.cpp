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

pii null_pair = mp(-1, -1);

vector<vii> match;
vector<vi> visited;
vector<vi> grid;

int R, C;

bool valid (int i, int j) {

    return i >= 0 && i < R && j >= 0 && j < C && grid[i][j];
}

vii get_adj (pii u) {

    vii res;

    if (valid(u.first - 1, u.second)) {
        res.pb(mp(u.first - 1, u.second));
    }
    if (valid(u.first + 1, u.second)) {
        res.pb(mp(u.first + 1, u.second));
    }
    if (valid(u.first, u.second - 1)) {
        res.pb(mp(u.first, u.second - 1));
    }
    if (valid(u.first, u.second + 1)) {
        res.pb(mp(u.first, u.second + 1));
    }

    return res;
}

bool aug(pii u) {

    if (visited[u.first][u.second])
        return false;

    visited[u.first][u.second] = 1;

    for (auto &v : get_adj(u)) {

        if (match[v.first][v.second] == null_pair || aug(match[v.first][v.second])) {
            match[v.first][v.second] = u;
            return true;
        }
    }


    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (cin >> R >> C, R) {

        grid.clear();
        grid.resize(R, vi(C, 1));

        int n_lakes;
        cin >> n_lakes;

        for (int k = 0; k < n_lakes; ++k) {
            int i, j;
            cin >> i >> j;
            --i, --j;

            grid[i][j] = 0;
        }

        print_matrix_debug(grid);


        bool turn = true;
        int MCBM = 0;
        match.clear();
        match.resize(R, vii(C, null_pair));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {

                if (turn && grid[i][j]) {
                    visited.clear();
                    visited.resize(R, vi(C, 0));
                    int aux  = aug(mp(i, j));
                    MCBM += aux;
                }

                turn = !turn;
            }

            if (C % 2 == 0) {
                turn = !turn;
            }

        }

        printf("%d\n", MCBM);

    }

    return 0;
}
