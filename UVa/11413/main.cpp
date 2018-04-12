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
//</editor-fold>

int n_pots, n_containers;
vi vet_pot_sz;
int total_milk;
int max_vol;

bool possible(int M){

    if(M < max_vol) return false;

    int curr_container = 0;
    int container_count = 1;

    for(auto &vol : vet_pot_sz){
        if(curr_container + vol > M){
            ++container_count;
            curr_container = 0;
        }
        curr_container += vol;
    }

    deb("container_count = ", container_count);
    return container_count <= n_containers;
}

int solve(){
    int upper = 1000000*1000/n_containers + 1;
    int lower = 0;
    int mid = lower + (upper-lower)/2;

    while(lower < upper){
        mid = lower + (upper-lower)/2;
        deb("mid = ", mid);
        deb("upper = ", upper);
        deb("lower = ", lower);
        if(possible(mid)){
            upper = mid;
        }else{
            lower = mid+1;
        }
    }

    deb("possible(mid) = ", possible(mid));
    return lower;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n_pots >> n_containers) {

        deb("n_pots = ", n_pots);
        deb("n_containers = ", n_containers);
        vet_pot_sz.clear();
        vet_pot_sz.resize(n_pots);
        total_milk = 0;
        max_vol = 0;

        for (size_t i = 0; i < n_pots; i++) {
            cin >> vet_pot_sz[i];
            total_milk += vet_pot_sz[i];
            max_vol = max(max_vol, vet_pot_sz[i]);
        }

        deb("total_milk = ", total_milk);

        cout << solve() << endl;
    }

    return 0;
}
