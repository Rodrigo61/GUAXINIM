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

vi factors(100000000);
set<int> set_order;
vi order;

void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        factors[2] += 1;
        set_order.insert(2);
        n = n/2;
    }

    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            factors[i] += 1;
            set_order.insert(i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2) {
        factors[n] += 1;
        set_order.insert(n);
    }

}

ll L, R, x, y;
vi gcd_factor, lcm_factor;

int solve(int idx, ll value) {

    if (value > R) { return 0; }

    if (idx == order.size()) {

        if (value >= L && value <= R) {
            return 1;
        } else {
            return 0;
        }
    }


    int res = 0;
    deb("idx = ", idx);
    deb("gcd_factor[order[idx]] = ", gcd_factor[order[idx]]);
    deb(" lcm_factor[order[idx]] = ",  lcm_factor[order[idx]]);
    for (int i = gcd_factor[order[idx]]; i <= lcm_factor[order[idx]] ; ++i) {
        res += solve(idx + 1, value + pow(order[idx], i));
    }

    return res;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> L >> R >> x >> y;


    if (x != y) {
        ll xy = x * y;
        ll counter = 0;

        factors.assign(100000000, 0);
        set_order.clear();

        primeFactors(x);
        gcd_factor = factors;

        factors.assign(100000000, 0);
        primeFactors(y);
        lcm_factor = factors;

        for (auto &e : set_order) {
            order.pb(e);
        }

        deb("order.size() = ", order.size());

        printf("%lld\n", 2 * solve(0, 1));
    } else {
        printf("1\n");
    }

    return 0;
}
