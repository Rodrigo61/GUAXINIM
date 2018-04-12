#include <iostream>

using namespace std;
bool debug = true;

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


int get_height(vector<vi> blocks){

    sort(all(blocks), [](vi &v1, vi &v2){
        return v1[1]*v1[2] >= v2[1]*v2[2];
    });

    int idx = 1;
    int height = blocks[0][0];
    pii last_base = mp(blocks[0][1], blocks[0][2]);

    for (; idx < blocks.size(); ++idx) {
        if(blocks[idx][1] <= last_base.first && blocks[idx][2] <= last_base.second){
            last_base = mp(blocks[idx][1], blocks[idx][2]);
            height += blocks[idx][0];
        }
    }

    return height;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {

        int n_blocks;
        cin >> n_blocks;

        
        vector< vector< vi > > possibilities(n_blocks, vector<vi>(3));

        int X,Y,Z;
        for (int i = 0; i < n_blocks; ++i) {
            cin >> X >> Y >> Z;

            if(Y > Z){
                possibilities[i][0] = {X,Y,Z};
            }else{
                possibilities[i][0] = {X,Z,Y};
            }

            if(X > Z){
                possibilities[i][1] = {Y,X,Z};
            }else{
                possibilities[i][1] = {Y,Z,X};
            }

            if(X > Y){
                possibilities[i][2] = {Z,X,Y};
            }else{
                possibilities[i][2] = {Z,Y,X};
            }

        }


        vi indices(n_blocks, 0);
        int best_hight = 0;

        while(indices[0] < 3){

            vector<vi> test;

            deb("NOVO CONJUNTO DE POSSIBILIDADE! ");
            for (int i = 0; i < n_blocks; ++i) {
                print_vector_debug(possibilities[i][indices[i]]);
                test.push_back(possibilities[i][indices[i]]);
            }
            deb("FIM CONJUNTO ------------------");

            best_hight = max(best_hight, get_height(test));

            for (int i = n_blocks-1; i >= 0; --i) {
                if(i == n_blocks - 1){
                    ++indices[i];
                }

                if(indices[i] == 3){
                    if(i == 0) break;
                    ++indices[i-1];
                    indices[i] = 0;
                }
            }
        }

        cout << best_hight << endl;
    }



    return 0;
}