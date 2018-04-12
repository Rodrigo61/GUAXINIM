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


#define posx 1
#define negx 2
#define posy 3
#define negy 4
#define posz 5
#define negz 6

int main(){
    ios_base::sync_with_stdio(false);

    int L;
    string cmd;


    while(cin >> L, L) {
        int dir = posx;

        for (int i = 0; i < L - 1; ++i) {
            cin >> cmd;

            if (cmd == "No") {
                continue;
            }

            if(dir == posx){
                if(cmd == "+z"){
                    dir = posz;
                }else if(cmd == "-z"){
                    dir = negz;
                }else if(cmd == "+y"){
                    dir = posy;
                }else if(cmd == "-y"){
                    dir = negy;
                }
            }else if(dir == negx){
                if(cmd == "+z"){
                    dir = negz;
                }else if(cmd == "-z"){
                    dir = posz;
                }else if(cmd == "+y"){
                    dir = negy;
                }else if(cmd == "-y"){
                    dir = posy;
                }
            }else if(dir == posy){
                if(cmd == "+z"){
                    dir = posy;
                }else if(cmd == "-z"){
                    dir = posy;
                }else if(cmd == "+y"){
                    dir = negx;
                }else if(cmd == "-y"){
                    dir = posx;
                }
            }else if(dir == negy) {
                if (cmd == "+z") {
                    dir = negy;
                }else if(cmd == "-z") {
                    dir = negy;
                }else if(cmd == "+y") {
                    dir = posx;
                }else if(cmd == "-y") {
                    dir = negx;
                }
            }else if(dir == posz){
                if(cmd == "+z"){
                    dir = negx;
                }else if(cmd == "-z"){
                    dir = posx;
                }else if(cmd == "+y"){
                    dir = posz;
                }else if(cmd == "-y"){
                    dir = posz;
                }
            }else if(dir == negz) {
                if (cmd == "+z") {
                    dir = posx;
                }else if(cmd == "-z") {
                    dir = negx;
                }else if(cmd == "+y") {
                    dir = negz;
                }else if(cmd == "-y") {
                    dir = negz;
                }
            }
        }


        switch (dir){
            case posx:{
                cout << "+x" << endl;
                break;
            }
            case negx:{
                cout << "-x" << endl;
                break;
            }
            case posy:{
                cout << "+y" << endl;
                break;
            }
            case negy:{
                cout << "-y" << endl;
                break;
            }
            case posz:{
                cout << "+z" << endl;
                break;
            }
            case negz:{
                cout << "-z" << endl;
                break;
            }
        }

    }



    return 0;
}