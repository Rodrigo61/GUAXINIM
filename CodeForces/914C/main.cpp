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

#define MOD 1000000007

vector<vector<vi>> memo;

// Funcao de combinatoria que calcula quantos numeros binarios com exatamente remaining_sets de bits ligados existem e
// sao menores que o numero representado pelo source.
int solve(string &source, int idx, int freedom, int remaining_sets) {

    if (remaining_sets < 0) {
        return 0;
    }


    if (idx == source.size()) {

        if (remaining_sets == 0) {
            return 1;
        }

        return 0;
    }

    int &res = memo[idx][freedom][remaining_sets];

    if (res != -1) return res;

    if (freedom) {
        res = (solve(source, idx + 1, 1, remaining_sets) + solve(source, idx + 1, 1, remaining_sets - 1)) % MOD;
    } else {

        if (source[idx] == '0') {
            res = solve(source, idx + 1, 0, remaining_sets);
        } else {
            res = (solve(source, idx + 1, 1, remaining_sets) + solve(source, idx + 1, 0, remaining_sets - 1)) % MOD;
        }

    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int dp[1001];
    dp[1] = 0;
    dp[0] = -1;


    for (int i = 2; i <= 1000; ++i) {
        dp[i] = (dp[__builtin_popcount(i)] + 1) % MOD;
    }

    string in;
    cin >> in;

    int k;
    cin >> k;

    if (in == "1") {
        if (k == 0) {
            printf("1\n");
        } else {
            printf("0\n");
        }

        return 0;
    }

    int c = in.size();

    memo.clear();
    memo.resize(1001, vector<vi>(2, vi(1001, -1)));

    int ans = 0;
    for (int i = 0; i <= 1000 ; ++i) {

        if (k != 1 && dp[i] == k - 1) {
            int tmp = solve(in, 0, 0, i);
            ans = (ans + tmp) % MOD;

        } else if (k == 1 && dp[i] == k - 1) {

            // Se k == 1, entao vamos procurar dp[i] = 0 que é apenas dp[1] que tem esse valor.
            // A funcao solve vai calcular todas as possibilidades onde existe apenas 1 bit ligado. Mas devemos ignorar
            // a possibilidade de o unico bit ligado ser o ultimo, pois nesse caso já teremos o proprio valor 1. Essa opcao
            // invariavelmente vai aparecer para qualquer valor de n, entao sempre retiramos -1 do resultado.
            int tmp = solve(in, 0, 0, i);
            ans = (ans + tmp) % MOD;
            ans = (ans - 1 + MOD) % MOD;
        }
    }

    printf("%d\n", ans);

    return 0;
}
