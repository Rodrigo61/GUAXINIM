bool debug = false;
//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)

#define space " "

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


//</editor-fold desc="GUAXINIM TEMPLATE">



int main() {
    ios::sync_with_stdio(false);
    int menor = -1, maior = -1;
    int count_joias = -1;
    int count_task = 0;

    cin >> menor >> maior >> count_joias;
    int dp[5005][110];
    int vet_joias[110];


    while(menor > 0 && maior > 0 && count_joias > 0){

        ++count_task;
        cout << "Teste " << count_task << endl;

        if(menor >= maior){
            swap(menor, maior);
        }

        int sum_items = 0;
        for (int i = 0; i < count_joias; ++i) {
            cin >> vet_joias[i];
            sum_items += vet_joias[i];
        }

        int sum_total = menor + maior + sum_items;

        if(sum_total % 2 == 0){
            int max_diff_maior = sum_total/2 - menor;
            int sz = max_diff_maior+1;

            // Base
            for (int i = 1; i < sz; ++i) {
                dp[i][count_joias] = 0;
            }
            dp[0][count_joias] = 1;
            //end Base

            // DP
            int ab;
            int joia;
            for (int j = count_joias-1; j >= 0; --j) {
                for (int i = 0; i < sz; ++i) {

                    joia = vet_joias[j];
                    ab = abs(i - joia);

                    if(ab < sz && (i + joia) < sz){
                        dp[i][j] = bool(dp[i + joia][j+1] + dp[ab][j+1]);
                    }else if(ab < sz){
                        dp[i][j] = dp[ab][j+1];
                    }else{
                        dp[i][j] = dp[i + joia][j+1];
                    }
                }
            }


            bool ans;
            if(maior-menor < sz){
                ans = dp[maior-menor][0];
            }else{
                ans = false;
            }


            if(ans){
                cout << "S\n" << endl;
            }else{
                cout << "N\n" << endl;
            }


        }else{
            // Soma total impar, impossivel dividir
            cout << "N\n" << endl;
        }

        cin >> menor >> maior >> count_joias;
    }
    return 0;
}