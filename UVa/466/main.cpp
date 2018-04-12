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


void rotate90(vector<string> &in, vector<string> &out){

    int sz = in.size();
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            out[j][sz-i-1] = in[i][j];
        }
    }
}

void rotate180(vector<string> &in, vector<string> &out){
    rotate90(in, out);
    auto aux = out;
    rotate90(aux, out);
}

void rotate270(vector<string> &in, vector<string> &out){
    rotate90(in, out);
    auto aux = out;
    rotate90(aux, out);
    aux = out;
    rotate90(aux, out);
}

void ver_refle(vector<string> &in, vector<string> &out){

    int sz = in.size();

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            out[sz-i-1][j] = in[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int count_cases = 0;

    while(cin >> N){


        vector<string> old_pattern(N), new_pattern(N), aux(N);

        for (int i = 0; i < N; ++i) {
            cin >> old_pattern[i] >> new_pattern[i];
        }

        print_matrix_debug(old_pattern);
        print_matrix_debug(new_pattern);

        cout << "Pattern " << ++count_cases << " was";

        if(old_pattern == new_pattern){
            cout << " preserved." << endl;
            continue;
        }

        aux = new_pattern;

        rotate90(old_pattern, aux);
        if(aux == new_pattern){
            cout << " rotated 90 degrees." << endl;
            continue;
        }

        rotate180(old_pattern, aux);
        if(aux == new_pattern){
            cout << " rotated 180 degrees." << endl;
            continue;
        }

        rotate270(old_pattern, aux);
        if(aux == new_pattern){
            cout << " rotated 270 degrees." << endl;
            continue;
        }

        ver_refle(old_pattern, aux);
        if(aux == new_pattern){
            cout << " reflected vertically." << endl;
            continue;
        }

        ver_refle(old_pattern, aux);
        auto aux2 = aux;
        rotate90(aux2, aux);
        if(aux == new_pattern){
            cout << " reflected vertically and rotated 90 degrees." << endl;
            continue;
        }

        ver_refle(old_pattern, aux);
        aux2 = aux;
        rotate180(aux2, aux);
        if(aux == new_pattern){
            cout << " reflected vertically and rotated 180 degrees." << endl;
            continue;
        }

        ver_refle(old_pattern, aux);
        aux2 = aux;
        rotate270(aux2, aux);
        if(aux == new_pattern){
            cout << " reflected vertically and rotated 270 degrees." << endl;
            continue;
        }


        cout << " improperly transformed." << endl;


    }

    return 0;
}