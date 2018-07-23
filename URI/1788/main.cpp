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

int L, C, K;
char mode;
vector<vi> grid;
vector<vector<vi>> memo;

vi memo_prime;

bool valid(int i, int j) {
    return i >= 0 && i < L && j >= 0 && j < C;
}

bool prime(int num) {

    int &res = memo_prime[num];

    if (res != -1) return res;

    if (num == 2) {

        res = 1;

    } else if (num % 2 == 0 || num == 1) {

        res = 0;

    } else {

        res = 1;
        int sqr = sqrt(num);
        for (int i = 3; i <= sqr + 1; i += 2) {

            if (num % i == 0) {
                res = 0;
                break;
            }
        }

    }

    return res;
}

int solve(int i, int j, int k) {

    int &res = memo[i][j][k];

    if (res) return res;

    res = 1;

    if (mode == 'N') {

        if (valid(i - 1, j)) {

            if (grid[i - 1][j] < grid[i][j]) {

                res = max(res, solve(i - 1, j, k) + 1);

            } else if (k && prime(grid[i][j])) {

                res = max(res, solve(i - 1, j, k - 1) + 1);
            }

        }

        if (valid(i, j + 1)) {

            if (grid[i][j + 1] < grid[i][j]) {

                res = max(res, solve(i, j + 1, k) + 1);

            } else if (k && prime(grid[i][j])) {

                res = max(res, solve(i, j + 1, k - 1) + 1);
            }

        }

    } else {

        if (valid(i + 1, j)) {

            if (grid[i + 1][j] < grid[i][j]) {

                res = max(res, solve(i + 1, j, k) + 1);

            } else if (k && prime(grid[i][j])) {

                res = max(res, solve(i + 1, j, k - 1) + 1);
            }

        }

        if (valid(i, j - 1)) {

            if (grid[i][j - 1] < grid[i][j]) {

                res = max(res, solve(i, j - 1, k) + 1);

            } else if (k && prime(grid[i][j])) {

                res = max(res, solve(i, j - 1, k - 1) + 1);
            }

        }

    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memo_prime.resize(10000001, -1);

    while (cin >> L >> C >> K, L) {

        cin >> mode;

        grid.clear();
        grid.resize(L, vi(C));

        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> grid[i][j];
            }
        }

        memo.clear();
        memo.resize(L, vector<vi>(C, vi(K + 1)));

        int maxi = 0;
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < C; ++j) {
                maxi = max(maxi, solve(i, j, K));
            }
        }

        printf("%d\n", maxi);

    }
    return 0;
}
