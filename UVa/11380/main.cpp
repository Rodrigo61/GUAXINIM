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

#define INF 9999999

int rows, cols;
int P;
int V;

vector<vector<char>> grid;
vector<vi> nodes_id;
vector<vii> vet_adj;

int super_source;
int super_target;

bool valid (int i, int j) {
    return i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] != '~';
}

vi get_neigh(int i, int j) {

    vi result;

    if (valid(i - 1, j)) {
        result.pb(nodes_id[i - 1][j]);
    }

    if (valid(i + 1, j)) {
        result.pb(nodes_id[i + 1][j]);
    }

    if (valid(i, j - 1)) {
        result.pb(nodes_id[i][j - 1]);
    }

    if (valid(i , j + 1)) {
        result.pb(nodes_id[i][j + 1]);
    }

    return result;
}


void transform_to_mat_adj(vector<vi> &mat_adj) {

    mat_adj.clear();
    mat_adj.resize(V, vi(V, 0));

    for (int u = 0; u < V; ++u) {
        for (auto edge : vet_adj[u]) {
            mat_adj[u][edge.first] = edge.second;
        }
    }
}

int augment(int v, vi &parent, int minEdge, vector<vi> &mat_adj) {     // traverse BFS spanning tree from s to t
    
    if (parent[v] == -1) {
        return minEdge;

    } else {

        int u = parent[v];

        int curr_flow = augment(u, parent, min(minEdge, mat_adj[u][v]), mat_adj); // recursive

        mat_adj[u][v] -= curr_flow;
        mat_adj[v][u] += curr_flow;

        return curr_flow;

    }
}

int max_flow(int source, int target) {

    vector<vi> mat_adj;
    transform_to_mat_adj(mat_adj);

    print_matrix_debug(mat_adj);

    int max_flow = 0;

    while (true) {

        // Running a BFS to search augment path
        vi dist(V, INF);
        queue<int> q;

        dist[source] = 0;
        q.push(source);

        vi parent(V, -1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == target) { break; }

            for (auto edge : vet_adj[u]) {
                int v = edge.first;
                int u2v = mat_adj[u][v];

                if (u2v > 0 && dist[v] == INF) {

                    dist[v] = dist[u] + 1;
                    q.push(v);

                    parent[v] = u;
                }
            }
        }

        if (dist[target] != INF) {
            max_flow += augment(target, parent, INF, mat_adj);
        } else {
            break;
        }
    }
    
    return max_flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> rows >> cols >> P) {

        grid.clear();
        grid.resize(rows, vector<char>(cols));
        nodes_id.clear();
        nodes_id.resize(rows, vi(cols));

        int id = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> grid[i][j];
                nodes_id[i][j] = id++;
            }
        }

        print_matrix_debug(grid);


        V = 2 * rows * cols + 2;

        super_source = V - 2;
        super_target = V - 1;

        deb("V = ", V);

        vet_adj.clear();
        vet_adj.resize(V);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {

                if (grid[i][j] == '~') { continue; }

                int id_in = nodes_id[i][j];
                int id_out = id_in;

                deb("id_in = ", id_in);


                if (grid[i][j] == '*') {

                    id_out = id_in + rows * cols;
                    vet_adj[super_source].pb(mp(id_in, 1));

                    vet_adj[id_in].pb(mp(id_out, 1));

                } else if (grid[i][j] == '.') {

                    id_out = id_in + rows * cols;
                    vet_adj[id_in].pb(mp(id_out, 1));

                } else if (grid[i][j] == '#') {

                    id_out = id_in + rows * cols;
                    vet_adj[id_out].pb(mp(super_target, P));

                    vet_adj[id_in].pb(mp(id_out, P));
                }

                deb("id_out = ", id_out);

                for (auto neigh_id : get_neigh(i, j)) {

                    vet_adj[id_out].pb(mp(neigh_id, INF));
                }
            }
        }

        deb("modeling done");

        printf("%d\n", max_flow(super_source, super_target));

    }

    return 0;
}
