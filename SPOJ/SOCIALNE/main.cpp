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

    int n_cases;
    cin >> n_cases;


    for (size_t q = 0; q < n_cases; q++) {
        string line;
        cin >> line;

        int M = line.size();

        vector<vi> grid(M, vi(M));

        for (size_t j = 0; j < M; j++) {
            if (line[j] == 'Y') {
                grid[0][j] = 1;
            } else {
                grid[0][j] = 0;
            }
        }

        for (size_t i = 1; i < M; i++) {
            for (size_t j = 0; j < M; j++) {
                char c;
                cin >> c;

                if (c == 'Y') {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = 0;
                }
            }
        }

        print_matrix_debug(grid);

        int maxi = 0;
        int maxi_id = 0;
        for (size_t i = 0; i < M; i++) {
            int curr_poss_friends = 0;

            for (size_t j = 0; j < M; j++) {

                if (i == j) { continue; }

                if (grid[i][j] == 0) {

                    for (size_t k = 0; k < M; k++) {
                        if (k == i || k == j) { continue; }

                        if (grid[i][k] == 1 && grid[k][j] == 1) {
                            ++curr_poss_friends;
                            break;
                        }
                    }


                }
            }

            if (curr_poss_friends > maxi) {
                maxi = curr_poss_friends;
                maxi_id = i;
            }
        }

        printf("%d %d\n", maxi_id, maxi);
    }

    return 0;
}
