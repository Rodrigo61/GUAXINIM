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

#define MOD 100000000
#define SOLDIER 1
#define HORSEMAN 2

int n1, n2, k1, k2;

vector<vector<vector<vi>>> memo;


int solve(int last, int seq, int n_soldier, int idx) {

    if (idx == n1 + n2) {
        return 1;
    }

    int n_horseman = idx - n_soldier;

//    deb("idx = ", idx);
//    deb("last = ", last);
//    deb("seq = ", seq);
//    deb("n_soldier = ", n_soldier);
//    deb("n_horseman = ", n_horseman);
//    deb(" ");

    int &res = memo[last][seq][n_soldier][idx];

    if (res != -1) return res;

    res = 0;

    if (n_soldier < n1) {

        if (last == SOLDIER && seq < k1) {

            res = (res + solve(SOLDIER, seq + 1, n_soldier + 1, idx + 1)) % MOD;

        } else if (last != SOLDIER) {

            res = (res + solve(SOLDIER, 1, n_soldier + 1, idx + 1)) % MOD;
        }

    }

    if (n_horseman < n2) {

        if (last == HORSEMAN && seq < k2) {

            res = (res + solve(HORSEMAN, seq + 1, n_soldier, idx + 1)) % MOD;

        } else if (last != HORSEMAN) {

            res = (res + solve(HORSEMAN, 1, n_soldier, idx + 1)) % MOD;
        }

    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n1 >> n2 >> k1 >> k2;

    memo.resize(3, vector<vector<vi>>(max(k1, k2) + 1, vector<vi>(n1 + 1, vi(n1 + n2 + 1, -1))));
    printf("%d\n", solve(0, 0, 0, 0));

    return 0;
}
