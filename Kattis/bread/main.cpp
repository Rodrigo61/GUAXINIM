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


int count_inversions(vi &vet, int begin, int end) {

    if (begin == end) {
        return 0;
    }

    int mid = (begin+end)/2;
    int left_inv  = count_inversions(vet, begin, mid);
    int right_inv = count_inversions(vet, mid + 1, end);

    vi aux_vet;
    int total_inv = left_inv + right_inv;

    int left_pos = begin;
    int right_pos = mid + 1;

    while (left_pos <= (begin+end)/2 && right_pos <= end) {
        if (vet[right_pos] < vet[left_pos]) {
            total_inv += mid - begin + 1 - (left_pos - begin);
            aux_vet.push_back(vet[right_pos]);
            ++right_pos;
        } else {
            aux_vet.push_back(vet[left_pos]);
            ++left_pos;
        }
    }

    while (left_pos <= (begin+end)/2) {
        aux_vet.push_back(vet[left_pos]);
        ++left_pos;
    }

    while (right_pos <= end) {
        aux_vet.push_back(vet[right_pos]);
        ++right_pos;
    }

    for (size_t i = begin; i <= end; i++) {
        vet[i] = aux_vet[i - begin];
    }

    return total_inv;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sz;
    cin >> sz;

    vi vet_a(sz), vet_b(sz);

    for (size_t i = 0; i < sz; i++) {
        cin >> vet_a[i];
    }
    for (size_t i = 0; i < sz; i++) {
        cin >> vet_b[i];
    }

    if (count_inversions(vet_a, 0, vet_a.size() - 1) % 2 == count_inversions(vet_b, 0, vet_b.size() - 1) % 2) {
        printf("Possible\n");
    } else {
        printf("Impossible\n");
    }
    return 0;
}
