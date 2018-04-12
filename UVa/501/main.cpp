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

/*
 * Esse desafio é interessante para treinar a invalidacao de iteradores. O link a seguir mostra um guia sobre
 * o comportamento dos iteradores em eventos especificos:
 *              https://stackoverflow.com/questions/6438086/iterator-invalidation-rules
 *
 * A sacada desse lab foi compreender que a iteracao dos iteradores pode ser custosa, e por isso devemos nos
 * aproveitar do fato de que os iteradores de um MULTISET não sao afetados pela insercao e, por isso, fica facil
 * manter seu estado. Neste caso, como basta reparar que a posicao desejada só se altera quando um numero menor do
 * que o apontado pelo iterador atual é inserido.
 * */


int main() {


    int ds_count;
    cin >> ds_count;

    for (int w = 0; w < ds_count; ++w) {

        int elem_count = 0;
        int get_count = 0;
        int current_get = 0;


        cin >> elem_count >> get_count;
        vector<int> vet_elements(elem_count);
        multiset<int> black_box;


        for (int i = 0; i < elem_count; ++i) {
            cin >> vet_elements[i];
        }

        auto it_elem = vet_elements.begin();
        multiset<int>::iterator it_bb;
        bool first = true;


        for (int i = 0; i < get_count; ++i) {
            cin >> current_get;

            while(black_box.size() < current_get){
                deb("inserted_elem = ",*it_elem);
                black_box.insert(*it_elem);
                if(!first && *it_elem < *it_bb){
                    deb("*it_elem < *it_bb");
                    it_bb--;
                }

                it_elem++;
            }

            if(first){
                it_bb = black_box.begin();
                first = false;
            }else{
                it_bb++;
            }

            cout << *it_bb << endl;

        }

        if(w!= ds_count-1){
            cout << endl;
        }


    }

    return 0;
}