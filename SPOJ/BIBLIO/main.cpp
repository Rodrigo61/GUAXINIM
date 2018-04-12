using namespace std;
bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;


//</editor-fold>

int N;
vi w;
int root;
vector< vector<vi> > memo;

// int solve(int i, int j, int n){
//
//     int &res = memo[i][j][n];
//
//     if(res != -1) return res;
//
//     res = 9999999;
//     int aux;
//     for (int k = i; k <= j; k++) {
//         aux = w[k]*n;
//         if(k-1 >= i){
//             aux += solve(i, k-1, n+1);
//         }
//         if(k+1 <= j){
//             aux += solve(k+1, j, n+1);
//         }
//
//         res = min(res, aux);
//     }
//
//     return res;
// }

int solve(){

    int dp[N][N][N];
    memset(dp, 999999, sizeof(dp));

    for (int i = 0; i < N; i++) {
        for (int n = 0; n < N; n++) {
            dp[i][i][n] = w[i]*n;
        }
    }

    for (int l = 1; l < N; l++) {
        for (int i = 0; i+l < N; i++) {
            int j = i+l;
            for (int n = 0; n < N-1; n++) {

                dp[i][j][n] = 9999999;
                int aux;
                for (int k = i; k <= j; k++) {
                    aux = w[k]*n;
                    if(k-1 >= i){
                        aux += dp[i][k-1][n+1];
                    }
                    if(k+1 <= j){
                        aux += dp[k+1][j][n+1];
                    }

                    dp[i][j][n] = min(dp[i][j][n], aux);
                }


            }
        }
    }

    return dp[0][N-1][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cases_count = 0;

    while(cin >> N, N != 0){

        w.clear();
        w.resize(N);
        for (size_t i = 0; i < N; i++) {
            cin >> w[i];
        }


        memo.clear();
        memo.resize(N+1, vector<vi>(N+1, vi(N+1, -1)));

        cout << "Teste " << ++cases_count << endl;
        // cout << solve(0, N-1, 0) << endl;
        cout << solve() << endl;
        cout << endl;
    }

    return 0;
}
