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

#define LEFT_TYPE 0
#define RIGHT_TYPE 1

vector<vi> vet_adj;
vi match;
vi matched; // will track left vertex that did not matched
vi visited;
int rows, cols, N;

bool aug(int u) {

    if (visited[u])
		return false;
    visited[u] = 1;

	for (auto &v : vet_adj[u]) {

        if (match[v] == -1 || aug(match[v])) {
            match[v] = u;
            return true;
        }
    }

	return false;  /* Esse retorno depende do que se pede. Se queremos contar apenas vertices que se ligaram com o lado direito
					 ele deve ser false*/
}

void alternate_dfs_aux(int u, int type) {

    if (type == LEFT_TYPE) {

        for (auto v : vet_adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                alternate_dfs_aux(v, RIGHT_TYPE);
            }
        }

    } else {

        if (!visited[match[u]]) {
            visited[match[u]] = 1;
            alternate_dfs_aux(match[u], LEFT_TYPE);
        }

    }

}

void alternate_dfs() {

    visited.assign(rows + cols, 0);

    for (int i = 0; i < rows; ++i) {
        if (!matched[i]) {
            visited[i] = 1;
            alternate_dfs_aux(i, LEFT_TYPE);
        }
    }
}

vi min_vertex_cover() {

    match.assign(rows + cols, -1);
    for (int l = 0; l < rows; l++) {
        visited.assign(rows, 0); //reset
        aug(l);
    }

    matched.assign(rows, 0);
    for (int u : match) {
        if (u != - 1) {
            matched[u] = 1;
        }
    }

    alternate_dfs();

    vi result;

    for (size_t i = 0; i < rows; i++) {
        if (!visited[i]) {
            result.pb(i);
        }
    }

    for (size_t i = 0; i < cols; i++) {
        if (visited[i + rows]) {
            result.pb(i + rows);
        }
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (cin >> rows >> cols >> N, rows + cols + N) {

        vet_adj.clear();
        vet_adj.resize(rows);

        for (size_t i = 0; i < N; i++) {
            int r, c;
            cin >> r >> c;

            --r, --c;

            vet_adj[r].pb(c + rows);
        }

        vi min_cover = min_vertex_cover();

        printf("%d", min_cover.size());
        for (auto &u : min_cover) {
            if (u < rows) {
                printf(" r%d", u + 1);
            } else {
                printf(" c%d", u - rows + 1);
            }
        }
        printf("\n");


    }

    return 0;
}
