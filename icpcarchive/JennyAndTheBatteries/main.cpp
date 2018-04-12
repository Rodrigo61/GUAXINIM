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


unsigned long long N, K;
vector<vi> stacks;

bool is_possible(int M){

    vector<vi> stacks_c(N, vi(3));
    for (int i = 0; i < N; ++i) {
        stacks_c[i][0] = stacks[i][1];
        stacks_c[i][1] = stacks[i][0];
        stacks_c[i][2] = stacks[i][2];
    }

    sort(all(stacks_c)); // ordered by in_cost

    auto it_best_in = stacks_c.begin();

    if(debug){
        cout << "Heights: ";
        for(auto &v : stacks_c){
            cout << v[1] << space;
        }
        cout << endl;
    }

    long long acu = 0;

    for (int i = N-1; i >= 0; --i) {
        if(stacks_c[i][1] <= M){
            continue;
        }

        deb("stacks_c[i][1] = ", stacks_c[i][1]);
        deb("i = ", i);
        while(stacks_c[i][1] > M){

            while(it_best_in != stacks_c.end() && (*it_best_in)[1] >= M){
                ++it_best_in;
            }

            if(it_best_in == stacks_c.end())
                return false;

            int best_in = (*it_best_in)[0];

            deb("best_in = ", best_in);
            int transfer_count = min(stacks_c[i][1] - M, M - (*it_best_in)[1]);

            acu += transfer_count*(stacks_c[i][2] + best_in);

            stacks_c[i][1] -= transfer_count;
            (*it_best_in)[1] += transfer_count;

            if(acu > K || acu < 0)
                return false;

        }

    }

    return true;

}

int binary_eval(){
    int lower = stacks[0][0];
    int upper = stacks[N-1][0];
    int mid = lower+(upper-lower)/2;

    deb("upper_init = ", upper);
    deb("lower_init = ", lower);
    deb("mid_init = ", mid);

    while(upper > lower){

        mid = lower+(upper-lower)/2;
        deb("upper = ", upper);
        deb("lower = ", lower);
        deb("mid = ", mid);

        if(is_possible(mid)){
            deb("up");
            upper = mid-1;
        }else{
            if(!is_possible(mid+1)) {
                deb("mid+1 = ", mid+1);
                lower = mid + 1;
                if(lower == upper){
                    mid+=1;
                }
            }else{
                deb("low2");
                break;
            }

        }

    }

    if(is_possible(mid)){
        return mid;
    }else{
        return mid+1;
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    stacks.resize(N, vi(3));

    for (int i = 0; i < N; ++i) {
        cin >> stacks[i][0] >> stacks[i][2] >> stacks[i][1];
    }

    sort(all(stacks));

    cout << binary_eval() << endl;

    return 0;
}
