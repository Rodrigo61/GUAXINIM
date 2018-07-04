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

vector<vi> mat_adj_young;
vector<vi> mat_adj_elder;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int E;
    while (cin >> E, E) {

        char cmd1, cmd2;
        char u, v;
        int len;

        mat_adj_young.clear();
        mat_adj_young.resize(26, vi(26, INF));
        for (size_t i = 0; i < 26; i++) { mat_adj_young[i][i] = 0; }
        mat_adj_elder.clear();
        mat_adj_elder.resize(26, vi(26, INF));
        for (size_t i = 0; i < 26; i++) { mat_adj_elder[i][i] = 0; }


        for (size_t i = 0; i < E; i++) {
            cin >> cmd1 >> cmd2 >> u >> v >> len;


            if (cmd1 == 'Y') {

                mat_adj_young[u - 'A'][v - 'A'] = min(len, mat_adj_young[u - 'A'][v - 'A']);

                if (cmd2 == 'B') {
                    mat_adj_young[v - 'A'][u - 'A'] = min(len, mat_adj_young[v - 'A'][u - 'A']);
                }

            } else {

                mat_adj_elder[u - 'A'][v - 'A'] = min(len, mat_adj_elder[u - 'A'][v - 'A']);

                if (cmd2 == 'B') {
                    mat_adj_elder[v - 'A'][u - 'A'] = min(len, mat_adj_elder[v - 'A'][u - 'A']);
                }

            }
        }


        for (int k = 0; k < 26; k++)
	        for (int i = 0; i < 26; i++)
			    for (int j = 0; j < 26; j++){
        		    mat_adj_young[i][j] = min(mat_adj_young[i][j], mat_adj_young[i][k] + mat_adj_young[k][j]);
                    mat_adj_elder[i][j] = min(mat_adj_elder[i][j], mat_adj_elder[i][k] + mat_adj_elder[k][j]);
                }


        char source, target;
        cin >> source >> target;

        int min_dist = INF;
        for (size_t i = 0; i < 26; i++) {
            min_dist = min(min_dist, mat_adj_young[source - 'A'][i] + mat_adj_elder[target - 'A'][i]);
        }

        if (min_dist >= INF) {
            printf("You will never meet.\n");
        } else {
            printf("%d", min_dist);
            for (int i = 0; i < 26; i++) {
                if (mat_adj_young[source - 'A'][i] + mat_adj_elder[target - 'A'][i] == min_dist) {
                     printf(" %c", i + 'A');
                }
            }
            printf("\n");
        }

    }

    return 0;
}
