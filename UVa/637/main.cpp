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

int near4(int num){

    int mult = 4;

    while(mult < num){
        mult += 4;
    }

    return mult;
}


int main(){
    ios_base::sync_with_stdio(false);

    int n_pages;

    while(cin >> n_pages, n_pages != 0){

        vi front_left(0), front_right(0), back_left(0), back_right(0);

        int left_value, right_value;
        int near_4mult = near4(n_pages);

        deb("near_4mult = ", near_4mult);

        /* front */
        left_value = near_4mult;
        right_value = 1;

        deb("front beg left value = ", left_value);
        deb("front beg right value = ", right_value);
        while(right_value < left_value){
            deb("right_value = ", right_value);

            if(right_value <= n_pages){
                front_right.push_back(right_value);
            }else{
                front_right.push_back(-1);
            }
            right_value += 2;
            
            if(left_value <= n_pages){
                front_left.push_back(left_value);
            }else{
                front_left.push_back(-1);
            }
            left_value -=2;

        }


        left_value = 2;
        right_value = near_4mult-1;
        deb("back beg left value = ", left_value);
        deb("back beg right value = ", right_value);
        while(left_value < right_value){
            if(left_value <= n_pages){
                back_left.push_back(left_value);
            }else{
                back_left.push_back(-1);
            }
            left_value += 2;


            if(right_value <= n_pages){
                back_right.push_back(right_value);
            }else{
                back_right.push_back(-1);
            }
            right_value -= 2;
        }

        cout << "Printing order for " << n_pages << " pages:" << endl;
        for (int i = 0; i < front_right.size(); ++i) {
            cout << "Sheet " << i+1 << ", front: ";
            if(front_left[i] == -1){
                cout << "Blank, ";
            }else{
                cout << front_left[i] << ", ";
            }

            if(front_right[i] == -1){
                cout << "Blank" << endl;
            }else{
                cout << front_right[i] << endl;
            }

            int sz = back_left.size();
            deb("sz-1 = ", sz-1);

            if(i <= sz-1 && (back_left[i] != -1 || back_right[i] != -1)){
                cout << "Sheet " << i+1 << ", back : ";
                if(back_left[i] == -1){
                    cout << "Blank, ";
                }else{
                    cout << back_left[i] << ", ";
                }

                if(back_right[i] == -1){
                    cout << "Blank" << endl;
                }else{
                    cout << back_right[i] << endl;
                }
            }
        }
        
        deb("fim de caso");
    }

    return 0;
}