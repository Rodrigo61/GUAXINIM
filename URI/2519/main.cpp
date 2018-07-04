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
int BIT_grid[1005][1005];


void update(int x, int y, int delta) {

    while (x < N + 1) {

        int aux_y = y;

        while (aux_y < M + 1) {

            BIT_grid[x][aux_y] += delta;

            aux_y += aux_y & -aux_y;
        }

        x += x & -x;
    }
}


int sum (int x, int y) {

    int res = 0;
    while (x > 0) {

        int aux_y = y;

        while (aux_y > 0) {

            res += BIT_grid[x][aux_y];

            aux_y -= aux_y & -aux_y;
        }

        x -= x & -x;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (cin >> N >> M) {

        memset(BIT_grid, 0, sizeof(BIT_grid));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {

                int val;
                cin >> val;

                if (val)
                    update(i + 1, j + 1, 1);
            }
        }

        int Q;
        cin >> Q;

        int R, xs, ys, xf, yf;
        for (int i = 0; i < Q; ++i) {

            cin >> R >> xs >> ys >> xf >> yf;

            if (!R) {

                update(xs, ys, -1);
                update(xf, yf, 1);

            } else {

                int total = sum(xf, yf) - sum(xs - 1, yf) - sum(xf, ys - 1) + sum(xs - 1, ys - 1);
                printf("%d\n", total);

            }
        }

    }

    return 0;
}
