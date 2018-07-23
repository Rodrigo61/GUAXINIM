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

#define INF 1000000000


vector<vii> vet_adj;
vector<vi> mat_adj;
int V;


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

    int n_cases;
    cin >> n_cases;


    for (int q = 0; q < n_cases; ++q) {


        int n;
        cin >> n;

        vet_adj.clear();
        vet_adj.resize(28);

        vi is_name(28, 0);
        vector<string> vet_names(28);

        // [0] = Super source, [1] = super sink, [2-27] = iniciais, [28--] = problema + nomes

        for (int i = 0; i < n; ++i) {

            int n_names;
            cin >> n_names;

            vet_adj.resize(vet_adj.size() + 1);
            is_name.pb(0);
            vet_names.pb("");

            int problem_id = vet_adj.size() - 1;
            deb("problem_id = ", problem_id);

            //liga o super source ao problema
            vet_adj[0].pb(mp(problem_id, 1));
            vet_adj[problem_id].pb(mp(0, 0));

            for (int j = 0; j < n_names; ++j) {
                string word;
                cin >> word;

                for (auto &c : word) { c = tolower(c); }

                vet_adj.resize(vet_adj.size() + 1);
                is_name.pb(1);
                deb("word = ", word);
                vet_names.pb(word);

                char first_char = word[0];

                // liga nomes com sua inicial no grafo
                vet_adj.back().pb(mp(first_char - 'a' + 2, 1));
                vet_adj[first_char - 'a' + 2].pb(mp(vet_adj.size() - 1, 0));

                // liga o problema com o nome lido
                vet_adj[problem_id].pb(mp(vet_adj.size() - 1, 1));
                vet_adj[vet_adj.size() - 1].pb(mp(problem_id, 0));
            }


        }


        // liga as iniciais com o super sink
        for (int i = 0; i < 26; ++i) {
            vet_adj[i + 2].pb(mp(1, 1));
            vet_adj[1].pb(mp(i + 2, 0));
        }


        deb("sink adj.size = ", vet_adj[1].size());


        V = vet_adj.size();
        deb("V = ", V);
        deb("max_flow = ", max_flow(0, 1));


        vector<string> sol;
        for (int i = 29; i < vet_adj.size(); ++i) {
            if (is_name[i]) {

                bool has_back_edge = false;
                for (int j = 28; j < i; ++j) {
                    if (mat_adj[i][j]) {
                        has_back_edge = true;
                        break;
                    }
                }


                if (has_back_edge) {
                    sol.pb(vet_names[i]);
                }

            }
        }


        sort(all(sol));

        printf("Case #%d:\n", q + 1);
        for (auto &s : sol) {
            printf("%c", toupper(s[0]));
            for (int i = 1; i < s.size(); ++i) {
                printf("%c", s[i]);
            }
            printf("\n");
        }

    }

    return 0;
}
