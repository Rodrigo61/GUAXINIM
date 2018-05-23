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
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;


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
//</editor-fold>


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int sz;
    cin >> sz;

    vector<tuple<int, int, int>> vet_segs(sz);

    for (size_t i = 0; i < sz; i++) {
        cin >> get<0>(vet_segs[i]) >> get<1>(vet_segs[i]);
        get<2>(vet_segs[i]) = i;
    }

    sort(all(vet_segs), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {

        if (get<0>(a) < get<0>(b)) {
            return true;
        }

        if (get<0>(a) == get<0>(b) && get<1>(a) > get<1>(b)) {
            return true;
        }

        return false;
    });


    vii max_left(sz);

    pii prev_maxi = mp(0, 0);
    for (int i = 0; i < sz; ++i) {

        if (get<1>(vet_segs[i]) > prev_maxi.first) {
            max_left[i] = mp(get<1>(vet_segs[i]), i);
        } else {
            max_left[i] = prev_maxi;
        }

        prev_maxi = max_left[i];
    }


    if (debug) {
        for (auto &p : max_left) {
            printf("(%d %d) ", p.first, p.second);
        }
        printf("\n");
    }


    bool found = false;
    pii solution;

    for (size_t i = 1; i < sz; i++) {
        if (max_left[i - 1].first >= get<1>(vet_segs[i])) {
            found = true;
            solution = mp(get<2>(vet_segs[i]), get<2>(vet_segs[max_left[i - 1].second]));
            break;
        }
    }

    if (found) {
        printf("%d %d\n", solution.first + 1, solution.second + 1);
    } else {
        printf("-1 -1\n");
    }

    return 0;
}
