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

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)

#define space " "

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


map<char, char> map_reverse = {make_pair('A','A'),
                               make_pair('E','3'),
                               make_pair('3','E'),
                               make_pair('H','H'),
                               make_pair('I','I'),
                               make_pair('J','L'),
                               make_pair('L','J'),
                               make_pair('M','M'),
                               make_pair('O','O'),
                               make_pair('S','2'),
                               make_pair('2','S'),
                               make_pair('T','T'),
                               make_pair('U','U'),
                               make_pair('V','V'),
                               make_pair('W','W'),
                               make_pair('X','X'),
                               make_pair('Y','Y'),
                               make_pair('Z','5'),
                               make_pair('5','Z'),
                               make_pair('1','1'),
                               make_pair('8','8'),
};

bool is_palin(string word){

    deb("pali1");
    bool is_palin = true;

    auto beg_it = word.begin();
    auto end_it = word.end()-1;

    while(beg_it <= end_it){
        if(*beg_it != *end_it){
            is_palin = false;
        }

        ++beg_it;
        --end_it;
    }

    deb("pali2");
    return is_palin;

}

bool is_reverse(string word){

    deb("rev1");
    string reverse_word = word;
    reverse(all(reverse_word));

    for(auto &elem : reverse_word){
        if(map_reverse.find(elem) != map_reverse.end()){
            elem = map_reverse[elem];
        }else{
            return false;
        }
    }

    deb("rev2");
    return reverse_word == word;

}


int main() {

    string word;

    while(cin >> word){

        bool is_pal = is_palin(word);
        bool is_rev = is_reverse(word);

        if(is_pal && is_rev){
            cout << word << " -- is a mirrored palindrome." << endl;
        }else if(is_pal){
            cout << word << " -- is a regular palindrome." << endl;
        }else if(is_rev){
            cout << word << " -- is a mirrored string." << endl;
        }else{
            cout << word << " -- is not a palindrome." << endl;
        }

        cout << endl;

    }

    return 0;
}