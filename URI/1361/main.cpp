#include <iostream>

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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {

        vi positives;
        positives.reserve(500000);
        vi negatives;
        negatives.reserve(500000);

        int n_floors;
        cin >> n_floors;

        int floor;
        for (int i = 0; i < n_floors; ++i) {
            cin >> floor;
            if(floor < 0){
                negatives.push_back(floor);
            }else{
                positives.push_back(-1 * floor);
            }
        }

        sort(all(positives));
        sort(all(negatives));


        int turn;
        int height = 0;
        int last_floor;
        int pos_idx, neg_idx;

        if(negatives[0] < positives[0]){
            turn = 1;
            height = 1;
            last_floor = negatives[0];
            neg_idx = 1;
            pos_idx = 0;
        }else{
            turn = -1;
            height = 1;
            last_floor = positives[0];
            neg_idx = 0;
            pos_idx = 1;
        }

        deb("pos: ");
        print_vector_debug(positives);
        deb("neg: ");
        print_vector_debug(negatives);

        while(true){


            if(turn == 1 && pos_idx >= positives.size()) break;
            if(turn == -1 && neg_idx >= negatives.size()) break;

            deb("last_floor = ", last_floor);
            if(turn == 1){
                if(positives[pos_idx] > last_floor){
                    last_floor = positives[pos_idx];
                    ++height;
                    turn = -1;
                    deb("positive entered");
                }

                ++pos_idx;

            }else{
                if(negatives[neg_idx] > last_floor){
                    last_floor = negatives[neg_idx];
                    ++height;

                    deb("negative entered");
                    turn = 1;
                }
                ++neg_idx;
            }
        }


        cout << height << endl;



        
    }

    return 0;
}