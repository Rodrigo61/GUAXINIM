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

class UnionFind {
private:
    vi rep, rank, set_sz;
    map<int, int> dict;
    int n_sets;
public:

    UnionFind(vi &vet_vertex) {

        int N = vet_vertex.size();
        for (int i = 0; i < N; ++i) {
            dict[vet_vertex[i]] = i;
        }

        set_sz.assign(vet_vertex.size(), 1);
        n_sets = N;
        rank.assign(N, 0);
        rep.assign(N, 0);

        for (int i = 0; i < N; i++) {
            rep[i] = i;
        }
    }

    int find_set(int i) {
        i = dict[i];

        return find_set_aux(i);
    }

    int find_set_aux(int i) {

        if (rep[i] == i) {
            return i;
        }

        rep[i] = find_set_aux(rep[i]);

        return rep[i];

    }

    bool is_same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }

    void union_by_rank(int i, int j) {
        if (!is_same_set(i, j)) {

            n_sets--;
            int rep_i = find_set(i);
            int rep_j = find_set(j);


            if (rank[rep_i] > rank[rep_j]) {

                rep[rep_j] = rep_i;
                set_sz[rep_i] += set_sz[rep_j];

            } else {

                rep[rep_i] = rep_j;
                set_sz[rep_j] += set_sz[rep_i];

                if (rank[rep_i] == rank[rep_j]) {
                    rank[rep_j]++;
                }

            }
        }
    }

    int sets_count() {
        return n_sets;
    }

};

struct Edge{
    int u, v;
    int weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight){};

    bool operator < (Edge const& other) const {
        return this->weight < other.weight;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;

    cin >> V >> E;

    vector<vii> vet_adj(V);

    for (int i = 0; i < E; ++i) {

        int u, v, u2v;
        cin >> u >> v >> u2v;

        --u, --v;

        vet_adj[u].pb(mp(v, u2v));
        vet_adj[v].pb(mp(u, u2v));
    }
    deb("d1");

    vi visited(V, 0);
    double min_mst_cost = 99999999;
    int res_idx = 0;
    for (int i = V - 1; i >= 0; --i) {

        deb("d2");
        if (!visited[i]) {

            deb("i = ", i);
            visited[i] = 1;

            vector<Edge> edge_list;

            queue<int> q;
            q.push(i);

            vi vet_vertex;

            while (!q.empty()) {

                int u = q.front();
                q.pop();

                deb("u = ", u);

                vet_vertex.pb(u);

                for (auto &e : vet_adj[u]) {

                    Edge new_edge(u, e.first, e.second);
                    edge_list.pb(new_edge);

                    if (!visited[e.first]) {

                        visited[e.first] = 1;

                        q.push(e.first);
                    }
                }
            }


            UnionFind UF(vet_vertex);
            print_vector_debug(vet_vertex);

            sort(all(edge_list));
            deb("d3");

            double mst_cost = 0;
            auto it = edge_list.begin();  // already sorted
            while (UF.sets_count() > 1) {
                Edge curr_edge = *(it++);
                deb("curr_edge.u2v = ", curr_edge.weight);
//                deb("curr_edge.u = ", curr_edge.u);
//                deb("curr_edge.v = ", curr_edge.v);
                if (!UF.is_same_set(curr_edge.u, curr_edge.v)) {
                    mst_cost += curr_edge.weight;
                    UF.union_by_rank(curr_edge.u, curr_edge.v);
                }
                deb("mst_cost inside = ", mst_cost);
            }

            if (vet_vertex.size() - 1 != 0)
                mst_cost /= (vet_vertex.size() - 1);

            deb("mst_cost = ", mst_cost);

            if (mst_cost < min_mst_cost) {
                min_mst_cost = mst_cost;
                res_idx = i;
            }

        }
    }

    printf("%d\n", res_idx + 1);


    return 0;
}
