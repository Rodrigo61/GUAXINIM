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

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
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
//</editor-fold desc="GUAXINIM TEMPLATE">


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long sz, val;

    while(cin >> sz >> val, sz+val != 0){

        long long quad;
        for (quad = 1; pow(quad,2) < val; quad+=2);


        deb("val = ", val);
        deb("quad = ", quad);
        long long c_value = quad*quad;
        pii c_pos = mp(sz - (sz-quad)/2, sz - (sz-quad)/2);

        deb("c_pos = ", c_pos.first, ", ", c_pos.second);

        if(c_value == val) goto ans;
        /*down*/
        for (long long j = 1; j < quad; ++j) {
            c_pos.first -= 1;
            c_value -=1;
            deb("down");
            deb("c_pos = ", c_pos.first, ", ", c_pos.second);
            if(c_value == val) goto ans;
        }

        /*left*/
        for (long long j = 1; j < quad; ++j) {
            c_pos.second -= 1;
            c_value -= 1;
            deb("left");
            deb("c_pos = ", c_pos.first, ", ", c_pos.second);
            if(c_value == val) goto ans;
        }

        /*up*/
        for (long long j = 1; j < quad; ++j) {
            c_pos.first += 1;
            c_value -= 1;
            deb("up");
            deb("c_pos = ", c_pos.first, ", ", c_pos.second);
            if(c_value == val) goto ans;
        }

        /*right*/
        for (long long j = 1; j < quad; ++j) {
            c_pos.second += 1;
            c_value -= 1;
            deb("right");
            deb("c_pos = ", c_pos.first, ", ", c_pos.second);
            if(c_value == val) goto ans;
        }

        ans:
        cout << "Line = " << c_pos.first << ", column = " << c_pos.second << "."<< endl;

    }
    return 0;
}