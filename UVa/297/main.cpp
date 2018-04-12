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

int count(const string &str, int *idx, int lvl_value){

    deb("*idx = ", *idx);
    deb("str[idx] = ", str[*idx]);

    if(str[*idx] != 'p'){
        if(str[*idx] == 'f'){
            deb("returned =", lvl_value);
            return lvl_value;
        }else{
            deb("returned =", 0);
            return 0;
        }
    }

    int res = 0;
    int new_value = lvl_value/4;
    (*idx) += 1;
    res += count(str, idx, new_value);
    (*idx) += 1;
    res += count(str, idx, new_value);
    (*idx) += 1;
    res += count(str, idx, new_value);
    (*idx) += 1;
    res += count(str, idx, new_value);


    return res;
}

string union_img(const string &img1, const string &img2, int *idx_img1, int *idx_img2){

    deb("*idx_img1 = ", *idx_img1);
    deb("*idx_img2 = ", *idx_img2);
    deb("img1[*idx_img1] = ", img1[*idx_img1]);
    deb("img2[*idx_img1] = ", img2[*idx_img2]);

    string res;

    if(*idx_img1 == img1.size() || *idx_img2 == img2.size()){
        res = "";
        return res;
    }

    if(img1[*idx_img1] == 'p' && img2[*idx_img2] == 'p'){

        *idx_img1 += 1;
        *idx_img2 += 1;
        res = union_img(img1, img2, idx_img1, idx_img2);
        return 'p'+res;
    }

    if(img1[*idx_img1] == 'p' && img2[*idx_img2] == 'e'){

        res.assign(img1.substr(*idx_img1, 5).c_str());
        *idx_img1 += 5;
        *idx_img2 += 1;
        res += union_img(img1, img2, idx_img1, idx_img2);
        return res;
    }

    if(img1[*idx_img1] == 'p' && img2[*idx_img2] == 'f'){

        *idx_img1 += 5;
        *idx_img2 += 1;
        res = union_img(img1, img2, idx_img1, idx_img2);
        return 'f'+res;
    }

    if(img1[*idx_img1] == 'e' && img2[*idx_img2] == 'p'){

        res.assign(img2.substr(*idx_img2, 5).c_str());
        *idx_img1 += 1;
        *idx_img2 += 5;
        res += union_img(img1, img2, idx_img1, idx_img2);
        return res;
    }

    if(img1[*idx_img1] == 'f' && img2[*idx_img2] == 'p'){

        *idx_img1 += 1;
        *idx_img2 += 5;
        res = union_img(img1, img2, idx_img1, idx_img2);
        return 'f'+res;
    }

    if(img1[*idx_img1] == 'f'){

        *idx_img1 += 1;
        *idx_img2 += 1;
        res = union_img(img1, img2, idx_img1, idx_img2);
        return 'f'+res;
    }

    if(img2[*idx_img2] == 'f'){

        *idx_img1 += 1;
        *idx_img2 += 1;
        res = union_img(img1, img2, idx_img1, idx_img2);
        return 'f'+res;
    }

    *idx_img1 += 1;
    *idx_img2 += 1;
    res = union_img(img1, img2, idx_img1, idx_img2);
    return 'e'+res;



}

int main(){
    ios_base::sync_with_stdio(false);

    int n_cases;
    string img1, img2;
    int sum;
    int idx, idx_img1, idx_img2;

    cin >> n_cases;
    for (int w = 0; w < n_cases; ++w) {
        cin >> img1 >> img2;

        idx = 0;
        idx_img1 = 0;
        idx_img2 = 0;
        /*img1 = union_img(img1, img2, &idx_img1, &idx_img2);
        cout << "union = " << img1 << endl;*/
        sum = count(union_img(img1, img2, &idx_img1, &idx_img2), &idx, 1024);

        cout << "There are " << sum << " black pixels." << endl;
    }

    return 0;
}