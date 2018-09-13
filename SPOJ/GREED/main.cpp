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

#define INF (ll)100000000

struct Edge{
    int dest;
    ll capacity;
    ll max_capacity;
    ll cost;
    int cancel_edge; // id da reverse edge associada

    Edge(int x, ll y, ll c, int z) : dest(x), capacity(y), max_capacity(y), cost(c), cancel_edge(z){}
};

vector<vector<Edge>> edge_list;
int V;

void put_edge(int u, int v, ll capacity, ll cost) {

    edge_list[u].push_back(Edge(v, capacity, cost, edge_list[v].size()));
    edge_list[v].push_back(Edge(u, 0, -cost, edge_list[u].size() - 1));
}

ll augment(int v, vi &parent, vi &prev_edge, ll minEdge) {

    if (parent[v] == -1) {
        return minEdge;

    } else {

        int u = parent[v];
        Edge &edge = edge_list[u][prev_edge[v]];

        ll curr_flow = augment(u, parent, prev_edge, min(minEdge, edge.capacity));

        edge.capacity -= curr_flow;
        edge_list[v][edge.cancel_edge].capacity += curr_flow;

        return curr_flow;

    }
}

pair<ll, ll> mcmf(int source, int target) {

    ll max_flow = 0;

    ll source_flow = 0;
    for (auto &edge : edge_list[source]) {
        source_flow += edge.capacity;
    }

    while (true) {

        vi dist(V, INF);
        dist[source] = 0;
        vi parent(V, -1);
        vi prev_edge(V, -1);
        vi in_queue(V, 0);

        queue<int> q;
        q.push(source);
        in_queue[source] = 1;

        //SPFA
        while (!q.empty()) {

            int u = q.front();
            q.pop();
            in_queue[u] = 0;

            for (int e = 0; e < edge_list[u].size(); ++e) {

                auto &edge  = edge_list[u][e];
                int v = edge.dest;

                if (edge.capacity > 0 && dist[u] + edge.cost < dist[v]) {

                    dist[v] = dist[u] + edge.cost; // relax
                    parent[v] = u;
                    prev_edge[v] = e;

                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = 1;
                    }

                }
            }
        }


        if (dist[target] != INF) {
            max_flow += augment(target, parent, prev_edge, INF);
        } else {
            break;
        }
    }
        
	ll cost = 0;
	for (int i = 0; i < V; i++)
	{
		for (auto &edge : edge_list[i])
		{
			if (edge.cost > 0)
			{
				cost += edge.cost * (edge.max_capacity - edge.capacity);
			}
		}
	}

    return {max_flow, cost};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {

        int n_cards;
        cin >> n_cards;

        vi cards(n_cards);
        for (int i = 0; i < n_cards; ++i) {
            cin >> cards[i];
        }

        int allowed_exchanges;
        cin >> allowed_exchanges;


        int adj_matrix[n_cards + 1][n_cards + 1];
        for (int i = 0; i < n_cards + 1; ++i) {
            for (int j = 0; j < n_cards + 1; ++j) {
                adj_matrix[i][j] = INF;
            }
        }
        for (int i = 0; i < n_cards + 1; ++i) { adj_matrix[i][i] = 0; }


        for (int i = 0; i < allowed_exchanges; ++i) {
            int u, v;
            cin >> u >> v;

            adj_matrix[u][v] = adj_matrix[v][u] = 1;
        }




        for (int k = 0; k < n_cards + 1; k++)
            for (int i = 0; i < n_cards + 1; i++)
                for (int j = 0; j < n_cards + 1; j++)
                    adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);


//        if (debug) {
//            for (int i = 0; i < n_cards + 1; ++i) {
//                for (int j = 0; j < n_cards + 1; ++j) {
//                    printf("%d ", adj_matrix[i][j]);
//                }
//                printf("\n");
//            }
//        }

        edge_list.clear();
        edge_list.resize(2 * n_cards + 2);
        // [0, n_cards-1] = left side; [n_cards, 2 * n_cards - 1] = right side;
        // [2*n_cards] = source; [2* n_cards + 1] = target


        for (int i = 0; i < n_cards; ++i) {

            put_edge(2 * n_cards, i, 1, 0);


            for (int j = 1; j <= n_cards; ++j) {

                put_edge(i, j + n_cards - 1, 1, adj_matrix[cards[i]][j]);
            }


            put_edge(i + n_cards, 2 * n_cards + 1, 1, 0);
        }


        V = edge_list.size();
        auto res = mcmf(2 * n_cards, 2 * n_cards + 1);


        //~ int total_cost = 0;

        //~ for (int i = 0; i < n_cards; ++i) {

            //~ for (auto &edge : edge_list[i]) {

//~ //                deb("i = ", i);
//~ //                deb("edge.capacity = ", edge.capacity);
//~ //                deb("edge.dest = ", edge.dest);

                //~ if (edge.dest < 2 * n_cards && edge.capacity == 0) {
                    //~ total_cost += edge.cost;
//~ //                    deb("used, total cost = ", total_cost);
                //~ }
            //~ }
        //~ }

        printf("%lld\n", res.second);
    }

    return 0;
}
