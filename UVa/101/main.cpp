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

vi where_is(25);
vector< std::list<int> > positions(25);


void onto(int block){

    int pos = where_is[block];

    bool found = false;
    for (auto it = positions[pos].begin(); it != positions[pos].end();) {

        if(*it == block){
            found = true;
            ++it;
            continue;
        }

        if(found){
            deb("a1");
            int val = *it;
            it = positions[pos].erase(it);
            positions[val].push_back(val);
            where_is[val] = val;
            deb("a2");
            deb("a3");
        }else{
            ++it;
        }
    }

    deb("onto finished");
}

void cut_paste(int a, int b){

    deb("cut_paste beg");
    int pos_a, pos_b;
    pos_a = where_is[a];
    pos_b = where_is[b];

    deb("pos_a", pos_a);
    deb("pos_b", pos_b);

    bool found = false;
    for (auto it = positions[pos_a].begin(); it != positions[pos_a].end();) {

        if(*it == a) found = true;

        if(found){
            deb("cut found");
            positions[pos_b].push_back(*it);
            where_is[*it] = pos_b;
            it = positions[pos_a].erase(it);
        }else{
            ++it;
        }
    }

    deb("cut_paste end");
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_blocks;
    cin >> n_blocks;

    for (int i = 0; i < n_blocks; ++i) {
        positions[i].push_back(i);
        where_is[i] = i;
    }

    string cmd1, cmd2;
    int arg1, arg2;

    while(cin >> cmd1, cmd1 != "quit"){

        cin >> arg1 >> cmd2 >> arg2;

        if(where_is[arg1] == where_is[arg2]) continue;

        deb(cmd1, cmd2, arg1, arg2);
        if(cmd2 == "onto"){
            onto(arg2);
        }

        if(cmd1 == "move"){
            onto(arg1);
        }

        cut_paste(arg1, arg2);

        if(debug){
            for (int i = 0; i < n_blocks; ++i) {
                cout << i << ":";
                if(!positions[i].empty()){
                    for(auto &e : positions[i]){
                        cout << " " << e;
                    }
                }

                cout << endl;
            }
        }
    }

    for (int i = 0; i < n_blocks; ++i) {
        cout << i << ":";
        if(!positions[i].empty()){
            for(auto &e : positions[i]){
                cout << " " << e;
            }
        }

        cout << endl;
    }

    return 0;
}