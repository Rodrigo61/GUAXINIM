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

int V;
vector<set<int>> vet_adj;

void SCC_aux(int u, int &dfs_time, vi &visited, vi &visit_order, vi &discovery_time, vi &lowest_discovery_reachable, vector<vi> &SCCs) {

    discovery_time[u] = ++dfs_time;
    lowest_discovery_reachable[u] = discovery_time[u];

    visit_order.push_back(u);

    visited[u] = 1;

    for (auto v : vet_adj[u]) {

        if (discovery_time[v] == 0) {
            SCC_aux(v, dfs_time, visited, visit_order, discovery_time, lowest_discovery_reachable, SCCs);
        }

        if (visited[v]) {
            lowest_discovery_reachable[u] = min(lowest_discovery_reachable[u], lowest_discovery_reachable[v]);
        }
    }


    if (discovery_time[u] == lowest_discovery_reachable[u]) {

        vi new_scc;
        SCCs.pb(new_scc);
        int v;

        do {
            v = visit_order.back();
            visit_order.pop_back();
            visited[v] = 0;
            SCCs.back().pb(v);
        } while (u != v);

    }

}

void SCC(vector<vi> &SCCs) {

    SCCs.clear(); // Para recuperar de fato o cada SCC

    vi visit_order;

    vi discovery_time(V, 0);
    vi lowest_discovery_reachable(V, 0);

    vi visited(V, 0);
    int dfs_time = 0;


    for (int i = 0; i < V; ++i) {
        if (discovery_time[i] == 0) {
            SCC_aux(i, dfs_time, visited, visit_order, discovery_time, lowest_discovery_reachable, SCCs);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int n_cases = 0;

    while (cin >> N) {

        vet_adj.clear();
        vet_adj.resize(30000);

        map<string, int> name2id;
        int curr_id = 0;

        V = 0;

        string str1, str2;
        for (int i = 0; i < N; ++i) {

            cin >> str1 >> str2;
            int neg1 = 0, neg2 = 0;

            if (str1[0] == '!') {
                str1 = str1.substr(1, str1.size() - 1);
                neg1 = 1;
            }

            if (str2[0] == '!') {
                str2 = str2.substr(1, str2.size() - 1);
                neg2 = 1;
            }


            if (name2id.find(str1) == name2id.end()) {
                name2id[str1] = curr_id;
                curr_id += 2;
                V += 2;
            }
            if (name2id.find(str2) == name2id.end()) {
                name2id[str2] = curr_id;
                curr_id += 2;
                V += 2;
            }

            vet_adj[name2id[str1] + !neg1].insert(name2id[str2] + neg2);
            vet_adj[name2id[str2] + !neg2].insert(name2id[str1] + neg1);

        }


        vector<vi> SCCs;
        SCC(SCCs);

        vi which_component(V);
        for (int i = 0; i < SCCs.size(); ++i) {
            for (auto &j : SCCs[i]) {
                which_component[j] = i;
            }
        }


        bool possible = true;
        for (int i = 0; i < V; i += 2) {

            if (which_component[i] == which_component[i + 1]) {
                possible = false;
                break;
            }
        }


        printf("Instancia %d\n", ++n_cases);
        if (possible) {
            printf("sim\n\n");
        } else {
            printf("nao\n\n");
        }

    }

    return 0;
}
