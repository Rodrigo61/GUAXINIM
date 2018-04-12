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

    std::ios_base::sync_with_stdio(false);
    int sz, count_query;

    deb("oi");
    int vet_range[1000001];
    int vet_index[1000001];

    vector<int> vet_pos(100001);
    vector<int> vet_elem(100001);
    vector<int> vet_elem_sorted(100001);

    while(cin >> sz >> count_query) {

        for (int i = 0; i < sz; ++i) {
            cin >> vet_elem[i];
            vet_elem_sorted[i] = vet_elem[i];
        }
        sort(vet_elem_sorted.begin(), vet_elem_sorted.begin()+sz);


        int last_elem = vet_elem_sorted[0];
        int current_elem;
        vet_range[last_elem] = 0;
        vet_index[last_elem] = 0;
        for (int i = 1; i < sz; ++i) {

            current_elem = vet_elem_sorted[i];
            if(last_elem != current_elem){
                vet_range[current_elem] = i;
                vet_index[current_elem] = i;

                deb("elem = ", current_elem, " begin = ", i);
            }

            last_elem = vet_elem_sorted[i];

        }


        for(int i = 0; i < sz; ++i){
            vet_pos[vet_index[vet_elem[i]]] = i+1;
            ++vet_index[vet_elem[i]];
        }


         int pos;
         int elem;
         for (int i = 0; i < count_query; ++i) {
             cin >> pos >> elem;

             deb("pos = ", pos, " elem = ", elem);
             if(pos <= vet_index[elem] - vet_range[elem]){
                 cout << vet_pos[vet_range[elem] + pos - 1] << endl;
             }else{
                 cout << 0 << endl;
             }
         }

    }
    return 0;
}