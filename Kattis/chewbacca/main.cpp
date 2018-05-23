bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include "bits/stdc++.h"
using namespace std;
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "
#define push_back pb

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

ll N, K, Q;

double logK(ll a) {
    return log(a)/log(K);
}

ll get_height(ll a) {
    return ceil(logK(((K-1) * a + 1)) - 1);
}

ll get_center(ll a) {

    if (a % K == 0) { return a; }

    ll L = (a/K) * K;
    ll R = ((a/K) + 1) * K;

    if (a == 1) { return 1; }
    if (L == 0) { return K; }

    if (a > L + 1) {
        return R;
    } else {
        return L;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> N >> K >> Q;

    ll a, b;
    for (size_t i = 0; i < Q; i++) {
        cin >> a >> b;
        ll acu = 0;

        if (K == 1) {
            printf("%lld\n", abs(a - b));
            continue;
        }

        ll a_height = get_height(a);
        ll b_height = get_height(b);


        while (a != b) {

            if (a_height > b_height) {
                a = get_center(a);
                a /= K;
                --a_height;
                ++acu;
            } else if (a_height < b_height) {
                b = get_center(b);
                b /= K;
                --b_height;
                ++acu;
            } else {
                a = get_center(a);
                a /= K;
                --a_height;
                ++acu;

                b = get_center(b);
                b /= K;
                --b_height;
                ++acu;
            }

        }

        printf("%lld\n", acu);

    }

    return 0;
}
