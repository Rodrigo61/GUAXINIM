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

    int cases_count = 0;

    int V;


    while (cin >> V) {

        map<string, int> name2id;
        map<int, string> id2name;
        name2id.clear();
        id2name.clear();
        int id = 0;


        string vertice;
        for (int i = 0; i < V; ++i) {
            cin >> vertice;
            name2id[vertice] = id;
            id2name[id] = vertice;
            deb("name = ", vertice, "id = ", id);
            ++id;
        }

        vector<set<int>> vet_adj;
        vet_adj.resize(V);
        int E;
        cin >> E;
        for (int i = 0; i < E; ++i) {
            string u, v;
            cin >> u >> v;

            deb("name2id[u] = ", name2id[u], " name2id[v] = ", name2id[v]);
            vet_adj[name2id[u]].insert(name2id[v]);
        }


        vi degree(V, 0);
        for (int i = 0; i < V; ++i) {
            deb("i = ", i);
            for (auto v : vet_adj[i]) {
                deb("v = ", v);
                degree[v]++;
            }
        }
        print_vector_debug(degree);

        set<int> q;
        for (int i = 0; i < V; ++i) {
            if (degree[i] == 0) {
                q.insert(i);
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", ++cases_count);

        while (!q.empty()) {
            int u = *q.begin();
            q.erase(q.begin());


            degree[u] = -1;
            printf(" %s", id2name[u].c_str());

            for (auto v : vet_adj[u]) {
                --degree[v];

                if (degree[v] == 0) {
                    q.insert(v);
                }
            }

            /*if (q.empty()) {
                for (int i = 0; i < V; ++i) {
                    if (degree[i] == 0) {
                        q.push(i);
                    }
                }
            }*/

        }

        printf(".\n\n");
    }

    return 0;
}