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


long long count_lowers(string num, vi &digits){

    deb("num before= ", num);
    while(num[0] == '0'){
        num.erase(0,1);
    }
    deb("num after= ", num);

    deb("num = ", num);
    print_vector_debug(digits);
    int sz = num.size();
    int dig_count = digits.size();
    long long acu = 0;

    if(num.empty()) return 0;

    if(sz <= 2){

        deb("stoi(num) = ", stoi(num));
        for (int i = 0; i < dig_count; ++i) {
            if(digits[i] != 0){
                if(digits[i]  <= stoi(num)){
                    ++acu;
                }
            }
        }

        if(sz == 1){
            deb("base = ", acu);
            return acu;
        }

        for (int i = 0; i < dig_count; ++i) {
            for (int j = 0; j < dig_count; ++j) {
                if(digits[i] != 0 && (digits[i] != 0 || digits[j] != 0)){
                    int val = stoi(to_string(digits[i]) + to_string(digits[j]));
                    if(val <= stoi(num)){
                        ++acu;
                    }
                }
            }
        }
        deb("base = ", acu);
        return acu;
    }


    for (int i = 1; i <= sz-1; ++i) {
        long long acu_pow = 1;
        for (int j = 0; j < i; ++j) {
            if(j == 0 && digits[0] == 0){
                acu_pow *= dig_count-1;
            }else{
                acu_pow *= dig_count;
            }
        }
        deb("acu_pow1 = ", acu_pow);
        acu += acu_pow;
    }
    deb("acu de k-1 ou menos = ", acu);

    string A0 = num.substr(1, num.size()-1);
    deb("A0 = ",A0);
    long long A0_val = count_lowers(A0, digits);


    if(digits[0] != 0 && !A0.empty()){
        for (int i = 1; i <= A0.size()-1; ++i) {

            long long acu_pow = 1;
            for (int j = 0; j < i; ++j) {
                if(j == 0 && digits[0] == 0){
                    acu_pow *= dig_count-1;
                }else{
                    acu_pow *= dig_count;
                }
            }
            deb("acu_pow2 = ", acu_pow);
            acu -= acu_pow;
        }
    }else{
        deb("Digit 0");
        deb("A0 = ", A0);

        if(find(all(digits), num[0] - '0') != digits.end()){
            for (int i = 0; i < A0.size(); ++i) {
                if(A0[i] != '0') acu += 1;
            }
        }
    }

    acu += A0_val;
    deb("HI2 = ", acu);


    int first_digit_pos;
    for (first_digit_pos = 0; first_digit_pos < dig_count && digits[first_digit_pos] <= num[0] - '0'; ++first_digit_pos);
    --first_digit_pos;
    deb("first_digit_pos = ", first_digit_pos);

    for (int i = first_digit_pos-1; digits[i] != 0 && i >= 0; --i) {
        deb("acu I= ", acu);
        acu += pow(dig_count, sz-1);
    }


    deb("acu = ", acu);
    return acu;

}

string convert_base(long long num, int base){
    string res = "";

    int remain;
    while(num >= base){
        remain = num%base;
        num = (num-remain)/base;
        res += to_string(remain);
    }

    res += to_string(num);
    reverse(all(res));

    deb("converted = ", res);
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long L,R;
    int B;
    string str;
    vector<int> C;

    while(cin >> L >> R >> B >> str, L != -1){

        deb("L = ", L, "R = ", R, "B = ", B);
        C.clear();
        for (int i = 0; i < B; ++i) {
            if(str[i] == 'S')
                C.push_back(i);
        }

        string upper, lower;
        upper = convert_base(R, B);
        lower = convert_base(L, B);

        deb("upper = ", upper);
        deb("lower = ", lower);
        deb("upper.size() = ", upper.size());
        deb("lower.size() = ", lower.size());
        long long upper_val = count_lowers(upper, C);
        deb("upper_val = ", upper_val);

        bool lower_dec = 1;
        for(auto &i : lower){
            if(find(all(C), i-'0') == C.end()){
                lower_dec = 0;
                break;
            }
        }

        long long lower_val = count_lowers(lower, C);
        deb("lower_val = ", lower_val);

        cout << upper_val - (lower_val-lower_dec) << endl;
        //return 0;
    }

    return 0;
}