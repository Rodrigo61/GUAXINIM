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
    int rows, cols;
    int sparse_count;
    int elem;

    while(cin >> rows >> cols){

        vector< std::list<int> > old_matrix_index(rows);
        vector< std::list<int> > old_matrix_values(rows);
        vector< std::list<int> > new_matrix_index(cols);
        vector< std::list<int> > new_matrix_values(cols);

        for (int i = 0; i < rows; ++i) {

            /* Reading indexes*/
            cin >> sparse_count;
            for (int j = 0; j < sparse_count; ++j) {
                cin >> elem;
                elem--;
                old_matrix_index[i].push_back(elem);
            }

            /* Reading values*/
            for (int j = 0; j < sparse_count; ++j) {
                cin >> elem;
                old_matrix_values[i].push_back(elem);
            }
        }



        /* Transposing indexes*/
        for (int i_old = 0; i_old < rows; ++i_old) {
            for(int i_old_index : old_matrix_index[i_old]){
                new_matrix_index[i_old_index].push_back(i_old);
            }
        }

        /* Transposing values*/
        for (int i_new = 0; i_new < cols; ++i_new) {
            for(int i_new_index : new_matrix_index[i_new]){
                deb("i_new_index = ", i_new_index);
                deb("old_matrix_values[i_new_index].size() = ", old_matrix_values[i_new_index].size());
                deb("old_matrix_values[i_new_index].front() = ", old_matrix_values[i_new_index].front());
                new_matrix_values[i_new].push_back(old_matrix_values[i_new_index].front());
                old_matrix_values[i_new_index].pop_front();
            }
        }

        /* Printing transposted matrix*/
        cout << cols << " " << rows << endl;

        for (int i = 0; i < cols; ++i) {

            if(!new_matrix_index[i].empty()){

                cout << new_matrix_index[i].size() << " ";

                auto it = new_matrix_index[i].begin();
                for (int j = 0; j < new_matrix_index[i].size(); ++j) {
                    cout << (*it)+1;
                    if(j != new_matrix_index[i].size()-1){
                        cout << " ";
                    }else{
                        cout << endl;
                    }
                    ++it;
                }

                it = new_matrix_values[i].begin();
                for (int j = 0; j < new_matrix_values[i].size(); ++j) {
                    cout << (*it);
                    if(j != new_matrix_values[i].size()-1){
                        cout << " ";
                    }else{
                        cout << endl;
                    }
                    ++it;
                }

            }else{
                cout << "0\n" << endl;
            }

        }
    }

    return 0;
}