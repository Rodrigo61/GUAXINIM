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

    for (int w = 0; w < n_cases; ++w) {

        int N, curr_life, K;
        cin >> N >> curr_life >> K;


        vii vet_enimies(N);
        for (int i = 0; i < N; ++i) {

            cin >> vet_enimies[i].first >> vet_enimies[i].second;
            vet_enimies[i].second *= -1;

        }

        sort(all(vet_enimies));

        vii remaining_enimies;
        for (int i = 0; i < N; ++i) {

            if (vet_enimies[i].first < curr_life && vet_enimies[i].second + vet_enimies[i].first <= 0) {

                curr_life -= vet_enimies[i].second + vet_enimies[i].first;

            } else {

                remaining_enimies.pb(vet_enimies[i]);
            }
        }

        deb("curr_life = ", curr_life);
        vet_enimies.clear();
        for (int i = 0; i < remaining_enimies.size(); ++i) {

            if (remaining_enimies[i].first >= curr_life) {

                --K;

            } else {

                vet_enimies.pb(remaining_enimies[i]);

            }
        }


        bool possible = false;

        deb("K = ", K);
        if (vet_enimies.empty()) { deb("poss1"); possible = true; }
        if (K >= vet_enimies.size()) { deb("poss2"); possible = true; }
        if (K < 0) { possible = false; }

        deb("before DP = ", possible);

        if (!possible && K >= 0) {

            int sz = vet_enimies.size();
            deb("sz = ", sz);

            int dp[sz][sz][2];
            memset(dp, 0, sizeof(dp));


            deb("K = ", K);

            vi vet_acu(sz, 0);
            vet_acu[0] = vet_enimies[0].first;

            for (int i = 1; i < sz; ++i) {

                vet_acu[i] = vet_enimies[i].first + vet_acu[i - 1];

            }
            print_vector_debug(vet_acu);

            // caso base k = 0;
            for (int i = 0; i < sz; ++i) {
                for (int j = i; j < sz; ++j) {

                    if (i > 0) {
                        dp[i][j][0] = vet_acu[j] - vet_acu[i - 1];
                    } else {
                        dp[i][j][0] = vet_acu[j];
                    }

                }
            }


            for (int k = 1; k <= K; ++k) {

                for (int of = 0; of < sz; ++of) {

                    for (int i = 0; i + of < sz; ++i) {

                        int j = i + of;


                        dp[i][j][1] = 999999;

                        for (int m = i; m <= j; ++m) {
                            int left = 999999, right = 999999;

                            if (m - 1 >= 0) {
                                left = dp[i][m - 1][0];
                            }

                            if (m + 1 < sz) {
                                right = dp[m + 1][j][0];
                            }

                            dp[i][j][1] = min(dp[i][j][1], left + right);
                        }

                    }
                }


                for (int i = 0; i < sz; ++i) {
                    for (int j = i; j < sz; ++j) {
                        dp[i][j][0] = dp[i][j][1];
                    }
                }

            }


            if (curr_life > dp[0][sz - 1][0]) {
                possible = true;
            }
        }


        if (possible) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
