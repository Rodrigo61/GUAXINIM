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

vector<vector<char>> grid;
int cols;
bool solved;
vi clicks;
pii EMPTY_PAIR = mp(-1, -1);

vii neighs;

void get_neighs(int i, int j) {

    neighs = {EMPTY_PAIR, EMPTY_PAIR};

    if (grid[max (i - 1, 0)][j + 1] == '.') {
        neighs[0] = (mp( max(i - 1, 0), j + 1) );
    }

    if (grid[min(i + 1, 9)][j + 1] == '.') {
        neighs[1] = (mp( min(i + 1, 9), j + 1) );
    }


}

void solve(int i, int j) {

    if (solved) { return; }

    if (j == cols - 1) {

        int count = 0;
        for (int k = 0; k < clicks.size(); ++k) {
            if (clicks[k]) {
                ++count;
            }
        }

        printf("%d\n", count);
        for (int k = 0; k < clicks.size(); ++k) {
            if (clicks[k]) {
                printf("%d 1\n", k);
            }
        }

        solved = true;
        return;
    }

    get_neighs(i, j);
    if (neighs[1] != EMPTY_PAIR) {
        grid[neighs[1].first][neighs[1].second] = 'X';
        clicks.pb(0);
        solve(neighs[1].first, neighs[1].second);
        clicks.pop_back();
    }

    get_neighs(i, j);
    if (neighs[0] != EMPTY_PAIR) {
        grid[neighs[0].first][neighs[0].second] = 'X';
        clicks.pb(1);
        solve(neighs[0].first, neighs[0].second);
        clicks.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> cols;

    grid.resize(10, vector<char>(cols));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    neighs.resize(2);
    clicks.reserve(200000);
    solved = false;
    solve(9, 0);

    return 0;
}