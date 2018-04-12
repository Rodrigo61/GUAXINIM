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

long long get_subthreeng_count(string &str){

    int sz = str.size();
    vi num(sz);

    for(int i = 0; i < sz; ++i){
        num[i] = str[i] - '0';
    }

    vi vet_acu(sz+1);

    vet_acu[0] = 0;
    for (int i = 1; i < sz+1; ++i) {
        vet_acu[i] = vet_acu[i-1] + num[i-1];
    }

    for (int i = 0; i < sz+1; ++i) {
        vet_acu[i] = vet_acu[i] % 3;
    }

    vector<long long> count(3, 0);
    for (int i = 0; i < sz+1; ++i) {
        count[vet_acu[i]]++;
    }

    long long result = 0;

    for (int i = 0; i < 3; ++i) {
        deb("count[i] = ", count[i]);
        deb("count[i]-1 = ", count[i]-1);
        result += (count[i]*(count[i]-1))/2;
    }

    return result;
}

void get_numbers(string &str, vector<string> &numbers){

    string curr_num = "";

    for (int i = 0; i < str.size(); ++i) {
        if(str[i] >= '0' && str[i] <= '9'){
            curr_num += str[i];
        }else if(!curr_num.empty()){
            numbers.push_back(curr_num);
            curr_num = "";
        }
    }

    if(!curr_num.empty()){
        numbers.push_back(curr_num);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long v = 1000001;
    v = v*(v+1);
    deb("v = ",v);


    string str;

    while(cin >> str){

        vector<string> numbers;
        numbers.reserve(1000000);

        get_numbers(str, numbers);

        long long acu = 0;
        for(auto &s : numbers){
            acu += get_subthreeng_count(s);
            deb("acu = ", acu);
        }
        cout << acu << endl;
    }
    return 0;
}