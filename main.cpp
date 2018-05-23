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
int n_vertice;
vector<vi> vet_adj;
vi vis, match;
pii null_pair = mp(-1, -1);
 
bool valid(int i, int j) {
    return i >= 0 && i < R && j >= 0 && j < C;
}
 
 
int Aug(int l) {                 // return 1 if an augmenting path is found
    if (vis[l]) return 0;                               // return 0 otherwise
 
    vis[l] = 1;
 
    for (int j = 0; j < (int)vet_adj[l].size(); j++) {
        int r = vet_adj[l][j];
        if (match[r] == -1 || Aug(match[r])) {
            match[r] = l;
            return 1;                           // found 1 matching
        }
    }
 
 
  return 0;                                                  // no matching
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> R >> C;
 
    vector<vi> grid;
    grid.resize(R, vi(C));
 
    n_vertice = R * C;
 
    int id_count = 0;
    vector<vi> map_id(R, vi(C));
 
    vii id2coord(n_vertice);
 
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            cin >> grid[i][j];
            map_id[i][j] = id_count;
            id2coord[id_count] = mp(i, j);
            ++id_count;
        }
    }
 
    print_matrix_debug(map_id);
    deb("read input");
 
    vet_adj.resize(n_vertice);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
 
            if (valid(i - 1, j) && grid[i - 1][j] != grid[i][j]) {
                vet_adj[map_id[i][j]].pb(n_vertice + map_id[i - 1][j]);
            }
            if (valid(i + 1, j) && grid[i + 1][j] != grid[i][j]) {
                vet_adj[map_id[i][j]].pb(n_vertice + map_id[i + 1][j]);
            }
            if (valid(i, j - 1) && grid[i][j - 1] != grid[i][j]) {
                vet_adj[map_id[i][j]].pb(n_vertice + map_id[i][j - 1]);
            }
            if (valid(i, j + 1) && grid[i][j + 1] != grid[i][j]) {
                vet_adj[map_id[i][j]].pb(n_vertice + map_id[i][j + 1]);
            }
 
        }
    }
 
    deb("created graph");
 
    int MCBM = 0;
    match.resize(2 * n_vertice, -1);
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {

	        vis.clear();
		vis.resize(n_vertice, 0);
		MCBM += Aug(map_id[i][j]);
		deb("MCBM current = ", MCBM);
 
        }
    }
 
    deb("MCBM = ", MCBM);
 
    if (debug) {
        for (size_t i = 0; i < R; i++) {
            for (size_t j = 0; j < C; j++) {
                printf("(%d) ", match[n_vertice + map_id[i][j]]);
            }
            printf("\n");
        }
    }
 
    vector<vi> final_grid(R, vi(C, -1));
    int counter = 1;
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            pii pair = id2coord[match[n_vertice + map_id[i][j]]];
            if (final_grid[i][j] == -1 && final_grid[pair.first][pair.second] == -1) {
                final_grid[i][j] = counter;
                final_grid[pair.first][pair.second] = counter;
                ++counter;
            }
        }
    }
 
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            printf("%d", final_grid[i][j]);
            if (j != C - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
