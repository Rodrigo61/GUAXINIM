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


pair<int, int> maxi(int m, int n, int t){

    vector< pair<int, int> > dp(t+1);

    if(m > t && n > t){
        return make_pair(0, t);
    }
    /*Base*/
    for (int i = 0; i < min(n,m); ++i) {
        dp[i] = make_pair(0, i);
    }

    /*Preenchimento dinamico*/
    for (int i = min(n,m); i <= t; ++i) {
        if(i-m < 0){
            dp[i].first = dp[i-n].first + 1;
            dp[i].second = dp[i-n].second;
        }else if(i-n < 0){
            dp[i].first = dp[i-m].first + 1;
            dp[i].second = dp[i-m].second;
        }else{
            pair<int, int> eat_n = dp[i-n];
            pair<int, int> eat_m = dp[i-m];
            if(eat_n.second < eat_m.second){
                dp[i].first = eat_n.first + 1;
                dp[i].second = eat_n.second;
            }else if(eat_n.second > eat_m.second){
                dp[i].first = eat_m.first + 1;
                dp[i].second = eat_m.second;
            }else if(eat_n.first > eat_m.first){
                dp[i].first = eat_n.first + 1;
                dp[i].second = eat_n.second;
            }else{
                dp[i].first = eat_m.first + 1;
                dp[i].second = eat_m.second;
            }
        }
    }

    return dp.back();

}

int main(){

    int m,n,t;

    while(cin >> m >> n >> t){
        /*debug("m = ", m, "n= ", n, "t = ", t);*/

        /*auto r = maxi(m,n,t);
        cout << r.first;
        if(r.second != 0){
            cout << " " << r.second;
        }
        cout << endl;*/

        int maxi = max(m,n);
        int mini = min(m,n);

        int menor_resto = 99999;
        int I, J;

        int comb_linear = 0;
        for (int i = 0; i <= t / maxi; ++i) {
            int resto = t - i*maxi;

            if(resto % mini == 0){
                cout << i + (resto/mini) << endl;
                comb_linear = 1;
                break;
            }else{
                if(resto%mini < menor_resto){
                    menor_resto = resto%mini;
                    I = i;
                    J = resto/mini;
                }
            }
        }

        if(!comb_linear){
            cout << I + J << " " << menor_resto << endl;
        }

    }

    return 0;
}