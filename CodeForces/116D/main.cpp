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

#define RIGHT 1
#define LEFT 2

int n, m;
int n_last_weed;
vi L, R;
vector<vector<vi>> memo;

int dist(int i, int j) {
    return abs(i - j);
}

int solve(int i, int j, int face) {

    if (i > n_last_weed) return 0;

    if (i == n_last_weed) {

        if (face == RIGHT) {
            return dist(j, R[i]);
        } else {
            return dist(j, L[i]);
        }

    }

    int &res = memo[i][j][face];
    if (res != -1) return res;

    res = 9999999;

    if (L[i + 1] != -1) {

        if (face == RIGHT) {

            int j_down = max(R[i], R[i + 1]);

            res = dist(j, j_down) + 1 + solve(i + 1, j_down, LEFT);

        } else {

            int j_down;

            if (L[i] != -1) {

                j_down = min(L[i], L[i + 1]);

            } else {

                j_down = L[i + 1];
            }

            res = dist(j, j_down) + 1 + solve(i + 1, j_down, RIGHT);

        }

    } else {

        if (face == RIGHT) {

            for (int j_down = max(0, R[i]); j_down < m; ++j_down) {

                res = min(res, dist(j, j_down) + 1 + solve(i + 1, j_down, LEFT));

            }

        } else {

            int min_L;

            if (L[i] != -1) {

                min_L = L[i];

            } else {

                min_L = m - 1;
            }

            for (int j_down = min_L; j_down >= 0; --j_down) {

                res = min(res, dist(j, j_down) + 1 + solve(i + 1, j_down, RIGHT));

            }

        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    L.resize(n);
    R.resize(n);

    n_last_weed = -1;

    string line;
    for (int i = 0; i < n; ++i) {
        cin >> line;

        deb("line = ", line);
        L[i] = R[i] = -1;

        for (int j = 0; j < line.size(); ++j) {
            if (line[j] == 'W') {
                L[i] = j;
                break;
            }
        }

        for (int j = line.size() - 1; j >= 0; --j) {
            if (line[j] == 'W') {
                R[i] = j;
                break;
            }
        }

        if (L[i] != -1) {
            n_last_weed = i;
        }
    }


    memo.resize(n + 1, vector<vi>(m + 1, vi(3, -1)));
    printf("%d\n", solve(0, 0, RIGHT));
    return 0;
}