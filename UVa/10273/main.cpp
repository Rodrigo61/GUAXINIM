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

    for (size_t q = 0; q < n_cases; q++) {

        int n_cows;
        cin >> n_cows;

        vector<vi> vet_cycles(n_cows);
        for (size_t i = 0; i < n_cows; i++) {
            int cycle_sz;
            cin >> cycle_sz;

            vet_cycles[i].resize(cycle_sz);
            for (size_t j = 0; j < cycle_sz; j++) {
                cin >> vet_cycles[i][j];
            }
        }


        vi alive(n_cows, 1);
        set<string> used_config;

        string curr_config;
        for (size_t i = 0; i < n_cows; i++) {
            curr_config += "_" + to_string(vet_cycles[i][0]);
        }


        int time = 0;
        int last_kill = 0;
        while (used_config.find(curr_config) == used_config.end()) {

            used_config.insert(curr_config);
            deb("time = ", time);
            deb("curr_config = ", curr_config);
            int min_produce = 9999;
            for (int i = 0; i < n_cows; ++i) {
                if (alive[i]) {
                    int cycle_index = time % vet_cycles[i].size();
                    min_produce = min(min_produce, vet_cycles[i][cycle_index]);
                }
            }

            int min_count = 0;
            for (int i = 0; i < n_cows; ++i) {
                if (alive[i]) {
                    int cycle_index = time % vet_cycles[i].size();
                    if (vet_cycles[i][cycle_index] == min_produce) {
                        ++min_count;
                    }
                }
            }

            deb("min_produce = ", min_produce);
            deb("min_count = ", min_count);
            if (min_count == 1) {
                for (int i = 0; i < n_cows; ++i) {
                    if (alive[i]) {
                        int cycle_index = time % vet_cycles[i].size();
                        if (vet_cycles[i][cycle_index] == min_produce) {
                            alive[i] = 0;
                            last_kill = time;
                            break;
                        }
                    }
                }
            }

            ++time;
            curr_config.clear();
            for (int i = 0; i < n_cows; ++i) {
                if (alive[i]) {
                    int cycle_index = time % vet_cycles[i].size();
                    curr_config += '_' + to_string(vet_cycles[i][cycle_index]);
                }
            }
            deb("curr_config after = ", curr_config);
        }


        printf("%d %d\n", (int)count(all(alive), 1), last_kill + 1);
    }
    return 0;
}
