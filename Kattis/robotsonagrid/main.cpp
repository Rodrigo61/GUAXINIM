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

#define MOD 2147483647

ll N;
vector<vector<char>> grid;

bool valid(int i, int j) {
    return i >= 0 && i < N && j >=0 && j < N && grid[i][j] != '#';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    grid.resize(N, vector<char>(N));
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vll> dp(N, vll(N, 0));

    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i - 1 >= 0) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            if (j - 1 >= 0) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }

            if (grid[i][j] == '#') {
                dp[i][j] = 0;
            }
        }
    }


    if (dp[N - 1][N - 1] != 0) {
        printf("%lld\n", dp[N - 1][N - 1]);
    } else {
        vector<vi> dist(N, vi(N, -1));

        queue<pii> q;
        dist[0][0] = 0;
        q.push(mp(0, 0));

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (valid(i - 1, j) && dist[i - 1][j] == -1) {
                dist[i - 1][j] = dist[i][j] + 1;
                q.push(mp(i - 1, j));
            }

            if (valid(i + 1, j) && dist[i + 1][j] == -1) {
                dist[i + 1][j] = dist[i][j] + 1;
                q.push(mp(i + 1, j));
            }

            if (valid(i, j - 1) && dist[i][j - 1] == -1) {
                dist[i][j - 1] = dist[i][j] + 1;
                q.push(mp(i, j - 1));
            }

            if (valid(i, j + 1) && dist[i][j + 1] == -1) {
                dist[i][j + 1] = dist[i][j] + 1;
                q.push(mp(i, j + 1));
            }
        }


        if (dist[N - 1][N - 1] != -1) {
            printf("THE GAME IS A LIE\n");
        } else {
            printf("INCONCEIVABLE\n");
        }
    }

    return 0;
}
