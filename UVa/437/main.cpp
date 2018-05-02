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

struct Block{

    int larger_base, shorter_base;
    int height;

    Block(int base1, int base2, int height) {
        larger_base = max(base1, base2);
        shorter_base = min(base1, base2);

        this->height = height;
    }

    bool supports(Block const& other) {
        return this->larger_base > other.larger_base && this->shorter_base > other.shorter_base;
    }

    bool operator < (Block const& other) {

        if (this->larger_base > other.larger_base) {
            return true;
        }

        if (this->larger_base == other.larger_base && this->shorter_base > other.shorter_base) {
            return true;
        }

        return false;
    }

    void print() {
        cout << "|larger = " << larger_base << " shorter = " << shorter_base << " height = " << height << "|" << endl;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int cases_count = 0;

    while(cin >> N, N) {

        vector<Block> vet_blocks;

        int a, b, c;
        for (size_t i = 0; i < N; i++) {
            cin >> a >> b >> c;

            Block block1(a, b, c);
            Block block2(a, c, b);
            Block block3(b, c, a);

            vet_blocks.push_back(block1);
            vet_blocks.push_back(block2);
            vet_blocks.push_back(block3);
        }

        N *= 3;

        sort(all(vet_blocks));

        if (debug) {
            for (auto &block: vet_blocks) {
                block.print();
            }
        }

        ll dp[N];
        dp[0] = vet_blocks[0].height;

        ll maxi = dp[0];
        for (int i = 1; i < N; i++) {

            deb("I  =", i);
            dp[i] = 0;
            for (int j = i - 1; j >= 0; j--) {
                deb("i = ", i, "j = ", j);
                if (vet_blocks[j].supports(vet_blocks[i])) {
                    deb("supported");
                    dp[i] = max(dp[i], dp[j]);
                }
            }

            dp[i] += vet_blocks[i].height;

            maxi = max(maxi, dp[i]);
        }


        cout << "Case " << ++cases_count <<": maximum height = " << maxi << endl;
    }

    return 0;
}
