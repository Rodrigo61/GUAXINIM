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

int N, A;
int fullmask;
vector<vector<vi>> vet_grids;
vector<vector< pair<int, pair<int, int>> > > memo;

vector<vi> dist;
vi on_count;

pair<int, pair<int, int>> solve(int idx, int mask) {

//    deb("mask = ", mask);
//    deb("idx = ", idx);

    auto &res = memo[idx][mask];

    if (mask == fullmask) {
        res = mp(0, mp(-1, 0));
        return res;
    }


    if (res.first != -1) return res;

    res.first = 999999;

    for (int i = 0; i < N; ++i) {

        if (i != idx && !(mask & (1 << i))) {

            auto subproblem = solve(i, mask | (1 << i));


            if (dist[idx][i] + subproblem.first < res.first) {

                res.first = dist[idx][i] + subproblem.first;
                res.second = mp(i, 0);
            }

            if (A + on_count[i] + subproblem.first < res.first) {

                res.first = A + on_count[i] + subproblem.first;
                res.second = mp(i, 1);

            }

        }
    }

    return res;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> A;


    vet_grids.resize(N);
    on_count.resize(N);
    for (int k = 0; k < N; ++k) {

        vet_grids[k].resize(21);

        for (int i = 0; i < 21; ++i) {
            vet_grids[k][i].resize(21);

            for (int j = 0; j < 21; ++j) {

                char c;
                cin >> c;
                vet_grids[k][i][j] = c - '0';

                if (vet_grids[k][i][j]) {
                    on_count[k]++;
                }

            }
        }
    }

    dist.resize(N, vi(N));

    for (int k = 0; k < N; ++k) {
        for (int l = k + 1; l < N; ++l) {

            int diff = 0;

            for (int i = 0; i < 21; ++i) {
                for (int j = 0; j < 21; ++j) {

                    if (vet_grids[k][i][j] != vet_grids[l][i][j]) {
                        ++diff;
                    }
                }
            }

            dist[k][l] = dist[l][k] = diff;
        }
    }



    fullmask = (2 << (N - 1)) - 1;
    memo.resize(N, vector<pair<int, pair<int, int>>>(fullmask + 1, mp(-1, mp(0 , 0))));

    int mini = 999999999;
    int idx_mini = 0;
    for (int i = 0; i < N; ++i) {

        auto sol = solve(i, 0 | (1 << i));
        sol.first += + on_count[i];

        if (sol.first < mini) {
            mini = sol.first;
            idx_mini = i;
        }

    }

    printf("%d\n", mini);

    int curr_idx = idx_mini;
    int mask = 0 | (1 << idx_mini);
//
//    deb("mask = ", mask);
//    deb("curr_idx = ", curr_idx);

    while (1) {

//        deb("mask = ", mask);
//        deb("curr_idx = ", curr_idx);
        printf("%d\n", curr_idx + 1);

        if (memo[curr_idx][mask].second.second) {
            printf("*\n");
        }

        curr_idx = memo[curr_idx][mask].second.first;

//        deb("new curr_idx = ", curr_idx);
        if (curr_idx == -1) break;
        mask |= 1 << curr_idx;
    }

    return 0;
}
