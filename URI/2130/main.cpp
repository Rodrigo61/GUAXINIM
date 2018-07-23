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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    int n_cases = 0;

    while (cin >> V >> E) {


        int adj_mat[V][V];
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                adj_mat[i][j] = INF;
            }

            adj_mat[i][i] = 0;
        }


        for (int i = 0; i < E; ++i) {

            int u, v, u2v;
            cin >> u >> v >> u2v;

            --u, --v;

            deb("u = ", u, "v = ", v, "u2v = ", u2v);
            adj_mat[u][v] = min(adj_mat[u][v], u2v);
        }


        int n_query;
        cin >> n_query;

        vector<pair<int, pair<pii, int>>> vet_querys(n_query);

        for (int i = 0; i < n_query; ++i) {
            cin >> vet_querys[i].second.first.first >> vet_querys[i].second.first.second >> vet_querys[i].first ;

            --vet_querys[i].second.first.first;
            --vet_querys[i].second.first.second;

            vet_querys[i].second.second = i;
        }

        sort(all(vet_querys));


        vi vet_ans(n_query);
        int last_k = 0;
        for (auto &query : vet_querys) {

            deb("K = ", query.first);
            if (last_k != query.first) {

                deb("new K");

                for (int k = last_k; k < query.first; ++k) {

                    for (int i = 0; i < V; i++)
                        for (int j = 0; j < V; j++)
                            adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
                }

                last_k = query.first;


            }

            int source = query.second.first.first;
            int target = query.second.first.second;
            int query_id = query.second.second;

            deb("source = ", source);
            deb("target = ", target);
            deb("query_id = ", query_id);
            deb("adj_mat[source][target] = ", adj_mat[source][target]);



            if (adj_mat[source][target] != INF) {
                vet_ans[query_id] = adj_mat[source][target];
            } else {
                vet_ans[query_id] = -1;
            }
        }


        printf("Instancia %d\n", ++n_cases);
        for (auto &e : vet_ans) {
            printf("%d\n", e);
        }
        printf("\n");

    }

    return 0;
}
