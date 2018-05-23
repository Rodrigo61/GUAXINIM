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

int sz, dist;
vi stones;
vector<char> stones_type;

bool possible(int leap) {

    vi stones_cpy = stones;
    vector<char> stones_types_cpy = stones_type;

    int curr_pos = 0;

    while (curr_pos < dist - leap) {

        int pos = distance(stones_cpy.begin(), upper_bound(all(stones_cpy), curr_pos + leap));
        --pos;

        if (stones_cpy.begin() == stones_cpy.end() || pos < 0 || pos >= stones_cpy.size()) {
            return false;
        }

        deb("indo pos = ", pos);
        deb("stones_cpy[pos] = ", stones_cpy[pos]);
        if (stones_cpy[pos] == curr_pos) {
            return false;
        }

        curr_pos = stones_cpy[pos];

        if (stones_types_cpy[pos] == 'S') {
            deb("apagando");
            stones_cpy.erase(stones_cpy.begin() + pos);
            stones_types_cpy.erase(stones_types_cpy.begin() + pos);
            print_vector_debug(stones_cpy);
        }
    }

    deb("antes da volta");
    print_vector_debug(stones_cpy);
    curr_pos = dist;
    deb("curr_pos = ", curr_pos);
    while (curr_pos > leap) {

        int pos = distance(stones_cpy.begin(), lower_bound(all(stones_cpy), curr_pos - leap));

        if (stones_cpy.begin() == stones_cpy.end() || pos < 0 || pos >= stones_cpy.size()) {
            return false;
        }

        deb("voltando pos = ", pos);
        deb("stones_cpy[pos] = ", stones_cpy[pos]);
        if (stones_cpy[pos] == curr_pos) {
            return false;
        }

        curr_pos = stones_cpy[pos];
    }

    return true;
}

int solve() {
    int upper = 1000000000;
    int lower = 1;
    int mid;

    while (lower < upper) {
        mid = lower + (upper - lower)/2;

        deb("upper = ", upper);
        deb("lower = ", lower);
        deb("mid = ", mid);

        if (possible(mid)) {
            upper = mid;
        } else {
            lower = mid + 1;
        }
    }

    return lower;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;
    int cases_count = 0;

    for (size_t q = 0; q < n_cases; q++) {

        cin >> sz >> dist;
        stones.clear();
        stones.resize(sz);
        stones_type.clear();
        stones_type.resize(sz);

        for (int i = 0; i < sz; ++i) {
            cin >> stones_type[i];
            cin.ignore();
            cin >> stones[i];
        }

        print_vector_debug(stones);
        print_vector_debug(stones_type);

        printf("Case %d: %d\n", ++cases_count, solve());
    }

    return 0;
}
