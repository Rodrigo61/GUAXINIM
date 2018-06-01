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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (size_t i = 0; i < n_cases; i++) {

        int V, E, n_soldiers;

        cin >> V >> E >> n_soldiers;

        deb("V = ", V);
        deb("E = ", E);
        deb("n_soldier = ", n_soldiers);

        vector<vi> vet_adj(V);
        for (size_t i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;

            deb("u = ", u, "v = ", v);
            vet_adj[u].pb(v);
            vet_adj[v].pb(u);
        }


        vi visited(V, -1);
        vi dist(V, 99999);
        bool optimum = true;
        for (size_t i = 0; i < n_soldiers; i++) {
            int s, str;
            cin >> s >> str;
            --s;

            deb("s = ", s);
            print_vector_debug(visited);

            if (!optimum) { continue; }

            if (visited[s] != -1) {
                optimum = false;
                continue;
            }

            visited[s] = i;
            dist[s] = 0;
            queue<int> q;
            q.push(s);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                if (dist[u] == str) { continue; }

                for (auto v : vet_adj[u]) {
                    if (visited[v] != i && visited[v] != -1) {
                        optimum = false;
                        break;
                    } else if (visited[v] == -1){
                        dist[v] = dist[u] + 1;
                        visited[v] = i;
                        q.push(v);
                    }
                }

                if (!optimum) { break; }
            }
            print_vector_debug(visited);

        }

        for (size_t i = 0; i < V; i++) {
            if (visited[i] == -1) {
                optimum = false;
                break;
            }
        }


        if (!optimum) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }

    }

    return 0;
}
