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

vi primes;

void get_primes_fact(int num, vi &vet){

    int original_num = num;

    for(auto &prime : primes){

        if(prime >= original_num) break;

        while(num % prime == 0){
            num /= prime;
            vet.push_back(prime);
        }
    }
}

set<vi> ans;
int num;


void get_all_forms(vi &factors){

    if(factors.size() == 0){
        return;
    }

    sort(all(factors));

    if(ans.find(factors) != ans.end()){
        return;
    }
    ans.insert(factors);

    if(factors.size() == 1){
        return;
    }

    for (int i = 0; i < factors.size(); ++i) {
        for (int j = i+1; j < factors.size(); ++j) {
            vi new_form = factors;
            new_form[i] *= new_form[j];
            if(new_form[i] < num){
                new_form.erase(new_form.begin()+j);
                get_all_forms(new_form);
            }
        }
    }
}

bool is_prime(int num){

    if(num != 2 && num % 2 == 0)return false;

    for(int i = 3; i <= sqrt(num); i += 2){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

void pre_calc(){


    for(int i = 2; i <= 2000000/2; ++i){

        if(is_prime(i)){
            primes.push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pre_calc();
    vi primes_fact;
    primes_fact.reserve(500);

    while(cin >> num, num != 0){

        ans.clear();
        primes_fact.clear();

        get_primes_fact(num, primes_fact);
        deb("here");

        get_all_forms(primes_fact);
        deb("here2");

        deb("num = ", num);
        cout << ans.size() << endl;
        for(auto &v : ans){
            for (int i = 0; i < v.size(); ++i) {
                cout << v[i];
                if(i != v.size()-1){
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}