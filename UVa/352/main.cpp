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

bool valid (int i, int j, vector<vi> &grid) {

    return i < grid.size() && i >= 0 && j < grid.size() && j >= 0 && grid[i][j] == 1;
}

vii get_adjs(pii u, vector<vi> &grid) {

    vii result;

    if (valid(u.first - 1, u.second - 1, grid)) {
        result.pb(mp(u.first - 1, u.second - 1));
    }
    if (valid(u.first - 1, u.second, grid)) {
        result.pb(mp(u.first - 1, u.second));
    }
    if (valid(u.first - 1, u.second + 1, grid)) {
        result.pb(mp(u.first - 1, u.second + 1));
    }

    if (valid(u.first, u.second - 1, grid)) {
        result.pb(mp(u.first, u.second - 1));
    }
    if (valid(u.first, u.second + 1, grid)) {
        result.pb(mp(u.first, u.second + 1));
    }

    if (valid(u.first + 1, u.second - 1, grid)) {
        result.pb(mp(u.first + 1, u.second - 1));
    }
    if (valid(u.first + 1, u.second, grid)) {
        result.pb(mp(u.first + 1, u.second));
    }
    if (valid(u.first + 1, u.second + 1, grid)) {
        result.pb(mp(u.first + 1, u.second + 1));
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int image_number = 0;

    while (cin >> N) {

        vector<vi> grid(N, vi(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                char c;
                cin >> c;
                grid[i][j] = c - '0';
            }
        }


        vector<vi> visited(N, vi(N, 0));

        int components_count = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {

                if (!visited[i][j] && grid[i][j] == 1) {


                    ++components_count;

                    queue<pii> q;

                    q.push(mp(i, j));
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        pii u = q.front();
                        q.pop();

                        for (auto &v : get_adjs(u, grid)) {
                            if (!visited[v.first][v.second]) {
                                visited[v.first][v.second] = 1;
                                q.push(v);
                            }
                        }
                    }

                }
            }
        }

        printf("Image number %d contains %d war eagles.\n", ++image_number, components_count);
    }

    return 0;
}
