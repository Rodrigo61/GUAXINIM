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

vector<pii> vet_turtle;
vector<vi> memo;
int min_weight;

int top_down_memo(int i_turtle, int curr_cap){

    deb("i_turtle  = ", i_turtle);
    deb("curr_cap  = ", curr_cap);

    if(i_turtle == vet_turtle.size())
        return 0;

    if(curr_cap < min_weight)
	return 0;

    if(memo[i_turtle][curr_cap] != -1){
        deb("MEMO");
        return memo[i_turtle][curr_cap];
    }

    if(curr_cap >= vet_turtle[i_turtle].second){
        int new_cap = min(curr_cap-vet_turtle[i_turtle].second, -vet_turtle[i_turtle].first);
        memo[i_turtle][curr_cap] = max(top_down_memo(i_turtle+1, curr_cap), top_down_memo(i_turtle+1, new_cap) + 1);
    }else{
        memo[i_turtle][curr_cap] = top_down_memo(i_turtle+1, curr_cap);
    }

    return memo[i_turtle][curr_cap];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int w, s;



    int max_cap = 0, min_weight = 10000000;
    while(cin >> w >> s){
        max_cap = max(max_cap, s-w);
        min_weight = min(min_weight, w);
        vet_turtle.push_back(mp(w-s, w));
    }


    sort(all(vet_turtle));
    vet_turtle[0].second = 0;
    memo.resize(vet_turtle.size(), vi(max_cap+1, -1));

    if(debug){
        for(auto &p : vet_turtle){
            cout <<"(" << p.first << ", " << p.second << ")  ";
        }
        cout << endl;
    }

    cout << top_down_memo(0, max_cap)<< endl;
    return 0;
}
