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

int N, K;
vector<vector<char>> grid;
bool reached_end;

bool all_stones(int stones) {

    return stones == 31;

}

int set_stone(int stone, char type) {

    switch (type) {
        case 'P': {
            stone |= (1 << 0);
            break;
        }
        case 'O': {
            stone |= (1 << 1);
            break;
        }
        case 'W': {
            stone |= (1 << 2);
            break;
        }
        case 'E': {
            stone |= (1 << 3);
            break;
        }
        case 'R': {
            stone |= (1 << 4);
            break;
        }
    }

    return stone;
}

typedef tuple<int, int, int, int, int> ti; //damage, i, j, immunity, stones

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    grid.resize(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }


    priority_queue<ti, vector<ti>, greater<ti>> pq;
    pq.push(make_tuple(0, 0, 0, 0, 0));

    bool possible = false;

    vector<vector<vector<vi>>> visited(N, vector<vector<vi>>(N, vector<vi>(K + 2, vi(32, 0))));

    while (!pq.empty()) {
        ti position = pq.top();
        pq.pop();

        int damage = get<0>(position);
        int i = get<1>(position);
        int j = get<2>(position);
        int immunity = get<3>(position);
        int stones = get<4>(position);

        if (visited[i][j][immunity][stones]) { continue; }
        visited[i][j][immunity][stones] = 1;

        if (i == N - 1 && j == N - 1) {
            printf("%d\n", damage + 1);
            possible = true;
            break;
        }

        if (grid[i][j] == '#') { continue; }

        immunity = max(immunity - 1, 0);

        if (isdigit(grid[i][j])) {

            if (!immunity) {
                damage += grid[i][j] - '0';
            }

        } else {

            stones = set_stone(stones, grid[i][j]);

            if (all_stones(stones)) {
                immunity = K + 1;
                stones = 0;
            }

        }

        if (i + 1 < N) {
            pq.push(make_tuple(damage, i + 1, j, immunity, stones));
        }
        if (j + 1 < N) {
            pq.push(make_tuple(damage, i, j + 1, immunity, stones));
        }

    }


    if (!possible) {
        printf("%d\n", -1);
    }

    return 0;
}
