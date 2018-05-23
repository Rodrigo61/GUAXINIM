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

typedef tuple<int, int, int> tiii;

int R, C;
int i_s, j_s;
int K;
vector<vector<char>> grid;
vector<vi> dist;

bool valid(int i, int j) {
    return i >= 0 && i < R && j >= 0 && j < C && grid[i][j] == '.';
}

bool solve(int i, int j, int acu_steps) {

    if (i == i_s && j == j_s && acu_steps > 0) {
        return acu_steps >= K;
    }

    if (valid(i - 1, j)) {
        grid[i - 1][j] = '*';
        if (solve(i - 1, j, acu_steps + 1)) {
            return true;
        }
        grid[i - 1][j] = '.';
    }

    if (valid(i + 1, j)) {
        grid[i + 1][j] = '*';
        if (solve(i + 1, j, acu_steps + 1)) {
            return true;
        }
        grid[i + 1][j] = '.';
    }

    if (valid(i, j - 1)) {
        grid[i][j - 1] = '*';
        if (solve(i, j - 1, acu_steps + 1)) {
            return true;
        }
        grid[i][j - 1] = '.';
    }

    if (valid(i, j + 1)) {
        grid[i][j + 1] = '*';
        if (solve(i, j + 1, acu_steps + 1)) {
            return true;
        }
        grid[i][j + 1] = '.';
    }

    return false;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;

    cin >> K;

    cin >> i_s >> j_s;
    --i_s, --j_s;

    grid.resize(R, vector<char>(C));
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    print_matrix_debug(grid);


    if (solve(i_s, j_s, 0)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
