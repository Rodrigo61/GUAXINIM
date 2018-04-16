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

int N;
int bitmask_full;
vi is_prime = {0, 1, 2, 3, 0, 5, 0, 7, 0, 0, 0, 11, 0, 13, 0 ,0, 0, 17, 0, 19, 0 ,0 ,0, 23, 0, 0, 0, 0, 0, 29, 0, 31};
vector< vector <vector<vi>> > memo;
vector< vi> memo_check;

vector<vi> top_down(int curr_num, int bitmask) {

    //deb("bitmask = ", bitmask);

    vector<vi> &res = memo[curr_num][bitmask];

    if(memo_check[curr_num][bitmask]) {
        return res;
    }

    memo_check[curr_num][bitmask] = 1;

    if (bitmask == bitmask_full) {

        if (is_prime[curr_num + 1]) {
            vi _res;
            _res.push_back(curr_num);
            res.push_back(_res);
        }

        return res;

    }

    for (size_t i = 1; i <= N; i++) {
        if (!(bitmask & (1 << i)) && is_prime[curr_num + i]) {

            auto rec_res = top_down(i, bitmask | (1 << i));

            if (!rec_res.empty()) {
                for (auto &vet :  rec_res) {
                    vet.push_back(curr_num);
                }

                res.insert(res.end(), all(rec_res));

            }

        }
    }


    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cases_count = 0;


    bool first =  true;

    while (cin >> N) {

        if (!first) {
            cout << endl;
        }



        first = false;
        bitmask_full = pow(2, N+1) - 2;


        deb("bitmask_full = ", bitmask_full);
        deb("N+1 = ", N+1);
        memo.clear();
        memo.resize(N+1, vector< vector<vi> >(bitmask_full + 1));
        memo_check.clear();
        memo_check.resize(N+1, vi(bitmask_full + 1));



        auto ans = top_down(1, 0 | (1 << 1));


        cout << "Case " << ++cases_count << ":" << endl;
        for (auto &vet : ans) {

            for (int i = vet.size() - 1; i >= 0; --i) {
                cout << vet[i];
                if (i != 0) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }

        }
    }
    return 0;
}
