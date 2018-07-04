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

int N, M;

vector<vi> grid_BIT;

void update(int i, int j) {

    while (i < grid_BIT.size()) {

        int aux_j = j;
        while (aux_j < grid_BIT[i].size()) {

            grid_BIT[i][aux_j] += 1;

            aux_j += (aux_j & (-aux_j));
        }

        i += (i & (-i));
    }
}


int sum(int i, int j) {

    if (i < 0 || j < 0) return 0;

    int res = 0;

    while (i > 0) {

        int aux_j = j;
        while (aux_j > 0) {

            res += grid_BIT[i][aux_j];

            aux_j -= (aux_j & (-aux_j));
        }

        i -= (i & (-i));
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (cin >> N >> M) {

        grid_BIT.clear();
        grid_BIT.resize(N + 1, vi(N + 1));

        int val;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {

                cin >> val;

                if (val) {
                    update(i + 1, j + 1);
                }

            }
        }


        for (int i = 0; i < M; ++i) {
            int xs, ys, xf, yf;

            cin >> xs >> ys;

            update(xs, ys);

            cin >> xs >> ys >> xf >> yf;


            int total = sum(xf, yf) - sum(xs - 1, yf) - sum(xf, ys - 1) + sum (xs - 1, ys - 1);

            printf("%d\n", total);


        }


    }

    return 0;
}
