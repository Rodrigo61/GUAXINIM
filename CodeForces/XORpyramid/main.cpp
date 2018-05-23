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
                cout << *(*(arr + i) + j) << space;
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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sz;
    cin >> sz;

    int dp[sz][sz];
    memset(dp, 0, sizeof(dp));

    for (size_t i = 0; i < sz; i++) {
        cin >> dp[0][i];
    }

    for (size_t i = 1; i < sz; i++) {
        for (int j = sz - 2; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j] ^ dp[i - 1][j + 1];
        }
    }

    if (debug) {
        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int dp2[sz][sz];
    memset(dp2, 0, sizeof(dp2));

    for (size_t i = 0; i < sz; i++) {
        dp2[i][i] = dp[0][i];
    }

    for (int t = 1; t < sz; ++t) {
        for (int l = 0; l + t < sz; ++l) {
            int r = l + t;
            int len = r - l + 1;

            dp2[l][r] = max({dp2[l][l + len - 2], dp2[l + 1][r], dp[len - 1][l]});
        }
    }

    if (debug) {
        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz; j++) {
                cout << dp2[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int n_query;
    cin >> n_query;

    int L, R;
    for (size_t i = 0; i < n_query; i++) {
        cin >> L >> R;
        --L, --R;

        printf("%d\n", dp2[L][R]);
    }

    return 0;
}
