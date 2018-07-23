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

bool valid(int i, int j) {

    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int mat_adj[8][8];
    memset(mat_adj, 0, sizeof(mat_adj));

    int idx_map[8][8];
    int idx = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            idx_map[i][j] = idx;
            ++idx;
        }
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%d ", idx_map[i][j]);
        }
        printf("\n");
    }

    deb("idx_map[2][1] = ", idx_map[2][1]);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {


            if (valid(i - 2, j - 1)) {
                deb("idx_map[i][j] = ", idx_map[i][j]);
                deb("idx_map[i - 2][j - 1] = ", idx_map[i - 2][j - 1]);
                deb("i = ", i, "j = ", j);

                mat_adj[idx_map[i][j]][idx_map[i - 2][j - 1]] = 1;
                mat_adj[idx_map[i - 2][j - 1]][idx_map[i][j]] = 1;
            }

            if (valid(i - 2, j + 1)) {
                mat_adj[idx_map[i][j]][idx_map[i - 2][j + 1]] = 1;
                mat_adj[idx_map[i - 2][j + 1]][idx_map[i][j]] = 1;
            }

            if (valid(i + 2, j - 1)) {
                mat_adj[idx_map[i][j]][idx_map[i + 2][j - 1]] = 1;
                mat_adj[idx_map[i + 2][j - 1]][idx_map[i][j]] = 1;
            }

            if (valid(i + 2, j + 1)) {
                mat_adj[idx_map[i][j]][idx_map[i + 2][j + 1]] = 1;
                mat_adj[idx_map[i + 2][j + 1]][idx_map[i][j]] = 1;
            }

        }
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%d ", mat_adj[i][j]);
        }
        printf("\n");
    }
    
    
    //floyd
    for (int k = 0; k < 8; ++k) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                mat_adj[i][j] = min(mat_adj[i][j], mat_adj[i][k] + mat_adj[k][j]);
            }
        }
    }



    string pos1, pos2;

    while (cin >> pos1 >> pos2) {

        deb("lido");
        int col1 = pos1[0] - 'a';
        int col2 = pos2[0] - 'a';
        int row1 = pos1[1] - '0';
        int row2 = pos2[1] - '0';



        int dist = mat_adj[idx_map[row1][col1]][idx_map[row2][col2]];
        printf("To get from %s to %s takes %d knight moves.\n", pos1.c_str(), pos2.c_str(), dist);
    }
    return 0;
}
