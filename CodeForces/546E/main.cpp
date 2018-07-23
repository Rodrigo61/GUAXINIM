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

#define INF 1000000000

struct Edge{
    int dest;
    ll capacity;
    int cancel_edge; // id da reverse edge associada

    Edge(int x, ll y, int z) : dest(x), capacity(y),  cancel_edge(z){}
};

vector<vector<Edge>> edge_list;
int V;

void put_edge(int u, int v, ll capacity) {

    edge_list[u].push_back(Edge(v, capacity, edge_list[v].size()));
    edge_list[v].push_back(Edge(u, 0, edge_list[u].size() - 1));

}

void put_edge_undirected(int u, int v, ll capacity) {

    edge_list[u].push_back(Edge(v, capacity, edge_list[v].size()));
    edge_list[v].push_back(Edge(u, capacity, edge_list[u].size() - 1));

}


ll augment(int v, vi &prev_vertex, vi &prev_edge, ll min_edge) {

    if (prev_vertex[v] == -1) {

        return min_edge;

    } else {

        int u = prev_vertex[v];
        Edge &edge = edge_list[u][prev_edge[v]];

        ll curr_flow = augment(u, prev_vertex, prev_edge, min(min_edge, edge.capacity)); // recursive

        edge.capacity -= curr_flow;
        edge_list[v][edge.cancel_edge].capacity += curr_flow;

        return curr_flow;

    }

}

ll max_flow(int source, int target) {

    ll max_flow = 0;

    while (true) {

        vi dist(V, INF);
        queue<int> q;
        vi prev_vertex(V, -1);
        vi prev_edge(V, -1);

        dist[source] = 0;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == target) { break; }

            for (int i = 0; i < edge_list[u].size(); ++i) {
                auto &edge = edge_list[u][i];

                if (edge.capacity > 0 && dist[edge.dest] == INF) {

                    dist[edge.dest] = dist[u] + 1;
                    q.push(edge.dest);

                    prev_vertex[edge.dest] = u;
                    prev_edge[edge.dest] = i;
                }
            }
        }

        if (dist[target] != INF) {
            max_flow += augment(target, prev_vertex, prev_edge, INF);
        } else {
            break;
        }
    }

    return max_flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    edge_list.resize(2 * n + 2);


    int total_soldier_before = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        total_soldier_before += a;
        put_edge(0, i + 2, a);
    }

    int total_soldier = 0;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;

        total_soldier += b;
        put_edge(i + 2 + n, 1, b);
    }

    for (int i = 0; i < n; ++i) {
        put_edge(i + 2, i + 2 + n, INF);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        put_edge(u + 1, v + 1 + n, INF);
        put_edge(v + 1, u + 1 + n, INF);
    }

    V = edge_list.size();

    if (total_soldier == total_soldier_before && max_flow(0, 1) == total_soldier) {
        printf("YES\n");

        vector<vi> mat_sol(n, vi(n, 0));

        for (int i = 2 + n; i < V; ++i) {

            for (auto &edge : edge_list[i]) {

                if (edge.dest != 1) {
                    mat_sol[edge.dest - 2][i - 2 - n] += edge.capacity;
                }

            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d", mat_sol[i][j]);

                if (j != n - 1) {
                    printf(" ");
                }
            }

            printf("\n");
        }

    } else {
        printf("NO\n");
    }
    return 0;
}
