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

int R, C;
char land_char;
vector<vector<char>> grid;

bool valid (int i, int j) {

    return i >= 0 && i < R && j >= 0 && j < C && grid[i][j] == land_char;
}

vii neighs(int i, int j) {

    vii res;

    int next_j = j + 1;
    int last_j = j - 1;
    int next_i = i + 1;
    int last_i = i - 1;

    if (next_j == C) {
        next_j = 0;
    }

    if (last_j == -1) {
        last_j = C - 1;
    }


//    if (valid(last_i, last_j)) {
//        res.pb(mp(last_i, last_j));
//    }
    if (valid(last_i, j)) {
        res.pb(mp(last_i, j));
    }
//    if (valid(last_i, next_j)) {
//        res.pb(mp(last_i, next_j));
//    }


    if (valid(i, last_j)) {
        res.pb(mp(i, last_j));
    }
    if (valid(i, next_j)) {
        res.pb(mp(i, next_j));
    }


//    if (valid(next_i, last_j)) {
//        res.pb(mp(next_i, last_j));
//    }
    if (valid(next_i, j)) {
        res.pb(mp(next_i, j));
    }
//    if (valid(next_i, next_j)) {
//        res.pb(mp(next_i, next_j));
//    }


    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (cin >> R >> C) {

        grid.clear();
        grid.resize(R, vector<char>(C));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> grid[i][j];
            }
        }
        deb("d1");


        int i_s, j_s;
        cin >> i_s >> j_s;

        land_char = grid[i_s][j_s];

        deb("d2");
        vector<vi> visited(R, vi(C, 0));
        queue<pii> q;

        visited[i_s][j_s] = 1;
        q.push(mp(i_s, j_s));

        deb("d3");
        while (!q.empty()) {
            int u_i = q.front().first;
            int u_j = q.front().second;
            q.pop();


            for (auto &v : neighs(u_i, u_j)) {
                if (!visited[v.first][v.second]) {
                    visited[v.first][v.second] = 1;
                    q.push(v);
                }
            }
        }
        deb("d4");

        int maxi = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (!visited[i][j] && grid[i][j] == land_char) {

                    int component_size = 0;

                    visited[i][j] = 1;
                    q.push(mp(i, j));
                    ++component_size;

                    while (!q.empty()) {
                        int u_i = q.front().first;
                        int u_j = q.front().second;
                        q.pop();

                        deb("u_i = ", u_i, "u_j = ", u_j);

                        for (auto &v : neighs(u_i, u_j)) {
                            if (!visited[v.first][v.second]) {
                                deb("v.first = ", v.first, "v.second = ", v.second);
                                visited[v.first][v.second] = 1;
                                q.push(v);
                                ++component_size;
                            }
                        }
                    }

                    maxi = max(maxi, component_size);
                }
            }
        }

        printf("%d\n", maxi);

    }

    return 0;
}
