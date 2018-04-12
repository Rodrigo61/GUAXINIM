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

#define COPAS 0
#define ESPADAS 1
#define PAUS 2
#define OUROS 3

int min_dist = 999999999;
vector<vii> sets;
int N;

vii hand;

void compare(vii &curr_hand){

    int sz = curr_hand.size();

    // LCS
    int dp[sz+1][sz+1];
    memset(dp, 0, sizeof(dp));

    for(int i = sz-1; i >= 0; --i){
        for(int j = sz-1; j >= 0; --j){
            if(hand[i] == curr_hand[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    min_dist = min(min_dist, sz - dp[0][0]);
}

void gen_and_compare(vii &curr_hand, vi &used, int empty_idx){

    if(debug){
        deb("empty_idx = ", empty_idx);
        for(auto &p : curr_hand){
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    if(empty_idx == N){
        compare(curr_hand);
        return;
    }


    for(int i = 0; i < 4; ++i){
        if(!used[i]){
            used[i] = 1;

            if(sets[i].empty()) continue;

            int idx = empty_idx;
            for (size_t j = 0; j < sets[i].size(); j++) {
                curr_hand[idx] = sets[i][j];
                ++idx;
            }
            gen_and_compare(curr_hand, used, idx);

            idx = empty_idx;
            for (int j = sets[i].size()-1; j >= 0 ; j--) {
                curr_hand[idx] = sets[i][j];
                ++idx;
            }
            gen_and_compare(curr_hand, used, idx);

            used[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    hand.resize(N);
    sets.resize(4);
    char rank, suit;
    for (size_t i = 0; i < N; i++) {
        cin >> rank >> suit;

        int irank, isuit;

        if(rank >= '2' && rank <= '9'){
            irank = rank - '0';
        }else if(rank == 'T'){
            irank = 10;
        }else if(rank == 'J'){
            irank = 11;
        }else if(rank == 'Q'){
            irank = 12;
        }else if(rank == 'K'){
            irank = 13;
        }else{
            irank = 14;
        }

        if(suit == 's'){
            isuit = ESPADAS;
            sets[ESPADAS].push_back(mp(irank, isuit));
        }else if(suit == 'h'){
            isuit = COPAS;
            sets[COPAS].push_back(mp(irank, isuit));
        }else if(suit == 'd'){
            isuit = OUROS;
            sets[OUROS].push_back(mp(irank, isuit));
        }else{
            isuit = PAUS;
            sets[PAUS].push_back(mp(irank, isuit));
        }

        hand[i] = mp(irank, isuit);
    }

    sort(all(sets[0]));
    sort(all(sets[1]));
    sort(all(sets[2]));
    sort(all(sets[3]));

    deb("SORTED");


    vii curr_hand(N);
    vi used(N, 0);
    gen_and_compare(curr_hand, used, 0);

    cout << min_dist << endl;

    return 0;
}
