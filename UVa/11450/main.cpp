//<editor-fold desc="GUAXINIM TEMPLATE">
/// Containers Start
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
/// C Header Files
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
/// Containers End


/// Constants
#define space ' '
/// Constants End


using namespace std;


/// Extra
#define all(x)                (x).begin(), (x).end()
/// Extra End

/// Debug Start
template<class T1>
void debub(T1 e1) {
    cout << e1 << endl;
}

template<class T1, class T2>
void debug(T1 e1, T2 e2) {
    cout << e1 << space << e2 << endl;
}

template<class T1, class T2, class T3>
void debug(T1 e1, T2 e2, T3 e3) {
    cout << e1 << space << e2 << space << e3 << endl;
}

template<class T1, class T2, class T3, class T4>
void debug(T1 e1, T2 e2, T3 e3, T4 e4) {
    cout << e1 << space << e2 << space << e3 << space << e4 << endl;
}

template<class T1, class T2, class T3, class T4, class T5>
void debug(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
    cout << e1 << space << e2 << space << e3 << space << e4 << space << e5 << endl;
}

template<class T1, class T2, class T3, class T4, class T5, class T6>
void debug(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
    cout << e1 << space << e2 << space << e3 << space << e4 << space << e5 << space << e6 << endl;
}
/// Debug End

/// TypeDef Start
typedef long long int ll;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef map<int, string> mis;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<pii> vii;
/// TypeDef End


/// I/O Start
#define sf                    scanf
#define pf                    printf
/// I/O End

//</editor-fold desc="GUAXINIM TEMPLATE">


int maxi(vi itens, int n, int m, vector<pair<int, int>> chunks){

    vector<vi> dp(n, vi(m+1));

    /*Preenchendo o caso base, o ultimo chunck independe dos demais*/
    for (int i = chunks.back().second; i >= chunks.back().first; --i) {
        for (int j = 0; j <= m; ++j) {
            if(itens[i] > j){
                dp[i][j] = -1;      /*Muito caro*/
            }else{
                dp[i][j] = itens[i]; /*da pra levar*/
            }
        }
    }


/*
    debub("DP apos caso base");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m+1; ++j) {
            cout << dp[i][j] << space;
        }
        cout << endl;
    }*/




    /*Preenchimento dinamico*/
    for (int l = chunks.size()-2; l >= 0; --l) { // itera sobre os chunks

        pair<int, int> chunk = chunks[l];
        for (int i = chunk.first; i <= chunk.second; ++i) { // itera sobre o intervalo do chunck

            pair<int, int> next_chunk = chunks[l+1];

            for(int w = 0; w <= m; ++w){
                dp[i][w] = -1;
                if(itens[i] <= w){
                    for (int k = next_chunk.first; k <= next_chunk.second; ++k) {
                        //printf("i = %d,  w = %d,  k = %d\n", i, w, k);
                        if(w-itens[i] >= 0 && dp[k][w-itens[i]] != -1){
                            dp[i][w] = max(dp[i][w], itens[i]+dp[k][w-itens[i]]);
                        }
                    }

                }
            }
        }
    }

    /*debub("DP apos preenchimento");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m+1; ++j) {
            cout << dp[i][j] << space;
        }
        cout << endl << endl << endl;
    }*/


    int ans = -1;
    for (int i = chunks[0].first; i <= chunks[0].second; ++i) {
        ans = max(ans, dp[i][m]);
    }

    return ans;

}

int main(){

    int W;
    int M, C;
    int n;
    vi  itens(400);

    cin >> W;

    for (int k = 0; k < W; ++k) {
        cin >> M >> C;


        n = 0;
        vector<pair<int, int>>  chunks(C); // armazena intervalo
        int last_chunck = -1;
        for (int i = 0; i < C; ++i) {
            int K;
            cin >> K;

            chunks[i] = make_pair(last_chunck+1, last_chunck + K);
            last_chunck = last_chunck + K;

            for (int j = 0; j < K; ++j) {
                cin >> itens[n];
                ++n;
            }
        }

        /*cout << "Itens: ";
        for (int l = 0; l < n; ++l) {
            cout << itens[l] << space;
        }
        cout << endl;

        cout << "chunks: ";
        for (int l = 0; l < chunks.size(); ++l) {
            cout << chunks[l].first << "|" << chunks[l].second << space;
        }
        cout << endl;*/


        int ans = maxi(itens, n, M, chunks);
        if(ans != -1){
            cout << ans << endl;
        }else{
            cout << "no solution" << endl;
        }

    }

    return 0;
}
