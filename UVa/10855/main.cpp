#include <iostream>

using namespace std;
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

typedef pair<int,int> pii;
typedef vector<int> vi;


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


void rotate90(vector< vector<char> > &mat){

    deb("ROTATE 90");
    deb("BEFORE");
    print_matrix_debug(mat);
    int size = mat.size();
    vector< vector<char> > aux_mat(size, vector<char>(size));

    for (int j = 0; j < size; ++j) {
        for (int i = size -1; i  >= 0; --i) {
            aux_mat[j][size-1 - i] = mat[i][j];
        }
    }

    deb("AFTER");

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            mat[i][j] = aux_mat[i][j];
        }
    }
    print_matrix_debug(aux_mat);
}

bool equals(vector< vector<char> > &mat1, vector< vector<char> > &mat2){

    int sz = mat1.size();

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            if(mat1[i][j] != mat2[i][j]){
                return false;
            }
        }
    }

    return true;
}

int check(vector< vector<char> > &big, vector< vector<char> > &little){

    int big_sz = big.size();
    int little_sz = little.size();
    vector< vector<char> > sub_mat(little_sz, vector<char>(little_sz));
    int result = 0;

    for (int i = 0; i < big_sz; ++i) {
        for (int j = 0; j < big_sz; ++j) {

            //deb("i + little_sz -1 = ", i + little_sz -1);
            if(i + little_sz -1 < big_sz && j + little_sz - 1 < big_sz){
                /* Quadrado interno valido */
                deb("Quad valido, i = ", i, " j = ", j);
                for (int k = i; k < i+little_sz; ++k) {
                    for (int l = j; l < j+little_sz; ++l) {
                        sub_mat[k-i][l-j] = big[k][l];
                    }
                }

                deb("sub_mat:");
                print_matrix_debug(sub_mat);
                deb("\n");

                if(equals(little, sub_mat)){
                    deb("CONTEM");

                    ++result;
                }
            }
        }
    }

    return result;

}


int main(){
    ios_base::sync_with_stdio(false);

    int N, n;

    cin >> N >> n;

    while(N != 0 && n != 0){

        vector< vector<char> > big(N, vector<char>(N));
        vector< vector<char> > little(n, vector<char>(n));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> big[i][j];
            }
        }

        deb("BIG:");
        print_matrix_debug(big);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> little[i][j];
            }
        }

        deb("LITTLE:");
        print_matrix_debug(little);


        cout << check(big, little) << " ";
        rotate90(little);
        cout << check(big, little) << " ";
        rotate90(little);
        cout << check(big, little) << " ";
        rotate90(little);
        cout << check(big, little) << endl;


        cin >> N >> n;
    }
    return 0;
}