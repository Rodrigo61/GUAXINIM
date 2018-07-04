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

#define INF 1e9

vector<vector<char>> grid;

bool valid (int i, int j) {

    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != '#';

}

vii get_adj(pii u) {

    vii res;

    if (valid(u.first - 1, u.second)) {
        res.pb(mp(u.first - 1, u.second));
    }
    if (valid(u.first + 1, u.second)) {
        res.pb(mp(u.first + 1, u.second));
    }
    if (valid(u.first, u.second + 1)) {
        res.pb(mp(u.first, u.second + 1));
    }
    if (valid(u.first, u.second - 1)) {
        res.pb(mp(u.first, u.second - 1));
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {

        int N, M;
        cin >> N >> M;

        queue<pii> q;
        vector<vi> fire_reachs(N, vi(M, INF));

        grid.clear();
        grid.resize(N, vector<char>(M));


        pii source, target;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {

                cin >> grid[i][j];

                if (grid[i][j] == 'S') {

                    source = mp(i, j);

                } else if (grid[i][j] == 'E') {

                    target = mp(i, j);

                } else if (grid[i][j] == 'F') {

                    fire_reachs[i][j] = 0;
                    q.push(mp(i, j));

                }
            }
        }


        while (!q.empty()) {

            pii u = q.front();
            q.pop();

            for (pii v : get_adj(u)) {

                if (fire_reachs[v.first][v.second] == INF) {

                    fire_reachs[v.first][v.second] = fire_reachs[u.first][u.second] + 1;

                    q.push(v);
                }
            }

        }

        print_matrix_debug(fire_reachs);
        deb("source = ", source.first, ", ", source.second);
        deb("target = ", target.first, ", ", target.second);



        vector<vi> dist(N, vi(M, INF));

        q.push(source);
        dist[source.first][source.second] = 0;

        bool possible = false;

        while (!q.empty()) {

            pii u = q.front();
            q.pop();

            if (u == target) {
                possible = true;
                break;
            }

            deb("u = ", u.first, ", ", u.second);

            for (pii v : get_adj(u)) {

                deb("v.first = ", v.first, "v.second = ", v.second);
                if (dist[v.first][v.second] == INF && fire_reachs[v.first][v.second] > dist[u.first][u.second] + 1) {

                    deb("dist[u.first][u.second] + 1 = ", dist[u.first][u.second] + 1);
                    deb("dist[v.first][v.second] = ", dist[v.first][v.second]);
                    deb("fire_reachs[v.first][v.second] = ", fire_reachs[v.first][v.second]);

                    dist[v.first][v.second] = dist[u.first][u.second] + 1;
                    q.push(v);
                }
            }
        }


        if (possible) {

            printf("Y\n");

        } else {

            printf("N\n");

        }


    }

    return 0;
}
