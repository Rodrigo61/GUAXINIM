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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, M;
    cin >> n >> M;

    vi values(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }
    values[0] = 0;
    values[n + 1] = M;


    vi acu_sum_ant(n + 2, 0), acu_sum_pos(n + 2, 0);


    acu_sum_ant[0] = 0;
    acu_sum_pos[0] = 0;

    bool L = true;

    for (int i = 1; i <= n + 1 ; i ++) {

        if (L) {
            acu_sum_ant[i] = acu_sum_ant[i - 1] + values[i] - values[i - 1];
            acu_sum_pos[i] = acu_sum_pos[i - 1];

        } else {
            acu_sum_pos[i] = acu_sum_pos[i - 1] + values[i] - values[i - 1];
            acu_sum_ant[i] = acu_sum_ant[i - 1];
        }

        L = !L;

    }

    print_vector_debug(values);
    print_vector_debug(acu_sum_ant);
    print_vector_debug(acu_sum_pos);


    int maxi = acu_sum_ant[n + 1];
    int last_elem;

    if (n % 2 == 0) {
        last_elem = n;
    } else {
        last_elem = n + 1;
    }

    for (int i = 0; i <= n ; ++i) {

        int new_value;

        deb("i = ", i);
        deb("values[i] = ", values[i]);
        if (values[i + 1] - values[i] == 1) continue;

        if (i % 2 == 0) { // L

            deb("L insert = ", values[i + 1] - 1);

            new_value = ((values[i + 1] - 1) - values[i]) + acu_sum_ant[i] + acu_sum_pos[last_elem] - acu_sum_pos[i + 1];

        } else {

            deb("D insert = ", values[i] + 1);
            new_value = (values[i + 1] - (values[i] + 1)) + acu_sum_ant[i] + acu_sum_pos[last_elem] - acu_sum_pos[i + 1];

        }

        deb("new_value = ", new_value);
        maxi = max(maxi, new_value);
    }


    printf("%d\n", maxi);



    return 0;
}