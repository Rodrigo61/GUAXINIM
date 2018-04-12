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
        cout << "[DEBUG]";
        for (auto i = t.cbegin(); i != t.cend(); ++i) {
            if ((i + 1) != t.cend()) {
                cout << *i << " ";
            } else {
                cout << *i << endl;
            }
        }
    }
}


//</editor-fold desc="GUAXINIM TEMPLATE">

int main() {
    
    int casos;
    int teste = 1;
    vector<int> A(2);
    vector<int> B(2);
    vector<int> C(2);
    vector<int> D(2);
    vector<int> E(2);
    vector<int> d1(2);
    vector<int> d2(2);
    vector<int> d3(2);
    vector<int> d4(2);
    vector<int> d5(2);
    vector<int> d6(2);
    vector< vector<int> > senha = {d1, d2, d3, d4, d5, d6};
    char letra;

    cin >> casos;
    while(casos != 0){

        deb("casos = ", casos);
        cin >> A[0]  >> A[1];
        cin >> B[0]  >> B[1];
        cin >> C[0]  >> C[1];
        cin >> D[0]  >> D[1];
        cin >> E[0]  >> E[1];

        for (int j = 0; j < senha.size(); ++j) {
            cin >> letra;

            switch(letra){
                case 'A':{
                    senha[j].assign(all(A));
                    break;
                }
                case 'B':{
                    senha[j].assign(all(B));
                    break;
                }
                case 'C':{
                    senha[j].assign(all(C));
                    break;
                }
                case 'D':{
                    senha[j].assign(all(D));
                    break;
                }
                case 'E':{
                    senha[j].assign(all(E));
                    break;
                }
            }
        }

        deb("aqui1");
        for (int i = 1; i < casos; ++i) {

            cin >> A[0]  >> A[1];
            cin >> B[0]  >> B[1];
            cin >> C[0]  >> C[1];
            cin >> D[0]  >> D[1];
            cin >> E[0]  >> E[1];

            for (int j = 0; j < senha.size(); ++j) {
                cin >> letra;

                if(senha[j].size() != 1){
                    switch(letra){
                        case 'A':{
                            if(senha[j][0] != A[0] && senha[j][0] != A[1]){
                                senha[j].erase(senha[j].begin());
                            }
                            if(senha[j][1] != A[0] && senha[j][1] != A[1]){
                                senha[j].erase(senha[j].begin()+1);
                            }
                            break;
                        }
                        case 'B':{
                            if(senha[j][0] != B[0] && senha[j][0] != B[1]){
                                senha[j].erase(senha[j].begin());
                            }
                            if(senha[j][1] != B[0] && senha[j][1] != B[1]){
                                senha[j].erase(senha[j].begin()+1);
                            }
                            break;
                        }
                        case 'C':{
                            if(senha[j][0] != C[0] && senha[j][0] != C[1]){
                                senha[j].erase(senha[j].begin());
                            }
                            if(senha[j][1] != C[0] && senha[j][1] != C[1]){
                                senha[j].erase(senha[j].begin()+1);
                            }
                            break;
                        }
                        case 'D':{
                            if(senha[j][0] != D[0] && senha[j][0] != D[1]){
                                senha[j].erase(senha[j].begin());
                            }
                            if(senha[j][1] != D[0] && senha[j][1] != D[1]){
                                senha[j].erase(senha[j].begin()+1);
                            }
                            break;
                        }
                        case 'E':{
                            if(senha[j][0] != E[0] && senha[j][0] != E[1]){
                                senha[j].erase(senha[j].begin());
                            }
                            if(senha[j][1] != E[0] && senha[j][1] != E[1]){
                                senha[j].erase(senha[j].begin()+1);
                            }
                            break;
                        }
                    }
                }
            }

        }

        cout << "Teste " << teste << endl;
        for (int k = 0; k < senha.size(); ++k) {
            cout << senha[k][0] << " ";
        }
        cout << endl;
        cout << endl;

        ++teste;
        cin >> casos;
    }
    
    return 0;
}