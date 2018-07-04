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

pii EMPTY_PAIR = mp(-1, -1);

vector<vii> match;
vector<vi> vet_adj;
vector<vi> visited;

vector<vi> grid;
int rows, cols;

bool valid(int i, int j) {
    return i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] != -1;
}

vii get_adj(pii i) {

    vii res;

    if (valid(i.first - 1, i.second) && grid[i.first][i.second] != grid[i.first - 1][i.second]) {
        res.pb(mp(i.first - 1, i.second));
    }

    if (valid(i.first, i.second - 1) && grid[i.first][i.second] != grid[i.first][i.second - 1]) {
        res.pb(mp(i.first, i.second - 1));
    }

    if (valid(i.first + 1, i.second) && grid[i.first][i.second] != grid[i.first + 1][i.second]) {
        res.pb(mp(i.first + 1, i.second));
    }

    if (valid(i.first, i.second + 1) && grid[i.first][i.second] != grid[i.first][i.second + 1]) {
        res.pb(mp(i.first, i.second + 1));
    }

    return res;
}

bool aug(pii u) {

    if (visited[u.first][u.second])
        return false;

    visited[u.first][u.second] = 1;

    for (auto &v : get_adj(u)) {


        if (debug) {
            printf("viizinho de u = (%d, %d)\n", u.first, u.second);
            for (auto &i : get_adj(u)) {

                printf(" (%d %d)", i.first, i.second);
            }

            printf("\n");
        }

        if (match[v.first][v.second] == EMPTY_PAIR || aug(match[v.first][v.second])) {
            match[v.first][v.second] = u;
            return true;
        }
    }


    return false;  /* Esse retorno depende do que se pede. Se queremos contar apenas vertices que se ligaram com o lado direito
					 ele deve ser false*/
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {

        cin >> rows >> cols;

        grid.clear();
        grid.resize(rows, vi(cols));

        bool turn = true;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                char c;
                cin >> c;

                if (c == 'o') {
                    grid[i][j] = -1;
                } else {
                    grid[i][j] = turn;
                }

                turn = !turn;
            }

            if (cols % 2 == 0) {
                turn = !turn;
            }
        }
        print_matrix_debug(grid);


        match.clear();
        match.resize(rows, vii(cols, EMPTY_PAIR));

        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {

                if (grid[i][j] == 1) {
                    deb("i = ", i, "j = ",j);
                    visited.clear();
                    visited.resize(rows, vi(cols, 0));
                    ans += aug(mp(i, j));
                    deb("ans after = ", ans);
                }

            }

        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {

                if (grid[i][j] == 0 && match[i][j] != EMPTY_PAIR) {
                    grid[i][j] = -1;
                    grid[match[i][j].first][match[i][j].second] = -1;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != -1) {
                    ++ans;
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
