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

int numeric_val(char raw){

    if(raw >= '0' && raw <= '9'){
        return raw - '0';
    }

    if(raw >= 'A' && raw <= 'C'){
        return 2;
    }
    if(raw >= 'D' && raw <= 'F'){
        return 3;
    }
    if(raw >= 'G' && raw <= 'I'){
        return 4;
    }
    if(raw >= 'J' && raw <= 'L'){
        return 5;
    }
    if(raw >= 'M' && raw <= 'O'){
        return 6;
    }
    if(raw >= 'P' && raw <= 'S'){
        return 7;
    }
    if(raw >= 'T' && raw <= 'V'){
        return 8;
    }
    if(raw >= 'W' && raw <= 'Y'){
        return 9;
    }
}

string vet2int(vector<int> vet){

    string res = "";

    for (int i = 0; i < vet.size(); ++i) {
        res += to_string(vet[i]);
    }

    return res;
}

string std_format(string num){

    num.insert(3, 1, '-');

    return num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    string line;
    int n_cases;
    cin >> n_cases;
    cin.ignore();
    getline(cin, line);


    for (int w = 0; w < n_cases; ++w) {

        int n_phones;
        cin >> n_phones;
        cin.ignore();
        vector<string> vet_numeric_phones(n_phones);

        for (int i = 0; i < n_phones; ++i) {

            string phone;
            getline(cin, phone);
            int n_alfnum = 0;
            vector<int> numeric_phone(7);

            deb("phone.size() = ", phone.size());

            for (int j = 0; j < phone.size() && n_alfnum < 7; ++j) {
                if(phone[j] != '-'){
                    numeric_phone[n_alfnum] = numeric_val(phone[j]);
                    deb("numeric_phone[n_alfnum] = ", numeric_phone[n_alfnum]);
                    ++n_alfnum;
                }
            }

            print_vector_debug(numeric_phone);
            vet_numeric_phones[i] = vet2int(numeric_phone);
        }

        sort(all(vet_numeric_phones));


        bool no_dup = true;
        for (int i = 0; i < n_phones; ++i) {

            int count = 1;
            while(i+1 < n_phones &&  vet_numeric_phones[i+1] == vet_numeric_phones[i]){
                ++i;
                ++count;
            }

            if(count != 1){
                no_dup = false;
                cout << std_format(vet_numeric_phones[i]) << space << count << endl;
            }
        }

        if(no_dup) cout << "No duplicates." << endl;

        if(w != n_cases-1) cout << endl;
    }

    return 0;
}