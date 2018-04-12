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


void find_seq(stack<char> pilha, string anagram, int size, string current_seq,
              string current_str, string word, int num_i, int num_o){


    /*Base*/
    if(num_i == num_o && num_i == size){

        deb("current_str = ", current_str);
        deb("anagram = ", anagram);

        if(current_str == anagram){
            current_seq.erase(0,1);
            cout << current_seq << endl;
          //  deb("ret1");
            return;
        }
    }
    if(num_i > size || num_o > size){
       // deb("num_i = ", num_i, "num_o = ", num_o);
       // deb("ret2");
        return;
    }
    if(num_o > num_i){
        //deb("ret3");
        return;
    }


    if(num_i <= size){
        string::iterator it_word = word.begin();
        stack<char> copy_pilha = pilha;
        int copy_num_i = num_i;
        string copy_current_seq = current_seq;
        copy_current_seq += " i";

        deb("copy_current_seq = ", copy_current_seq);

        copy_pilha.push(*(it_word+num_i));
        ++copy_num_i;

        //deb("copy_num_i = ", copy_num_i , "  num_i = ", num_i);
        find_seq(copy_pilha, anagram, size, copy_current_seq, current_str, word, copy_num_i, num_o);
    }


    if(!pilha.empty() && num_o <= size){

        current_str.push_back(pilha.top());
        pilha.pop();
        ++num_o;
        current_seq += " o";

        auto res = std::mismatch(current_str.begin(), current_str.end(), anagram.begin());
        if (res.first == current_str.end())
        {
           // deb("entrou, num_i = ", num_i, "num_o = ", num_o);
            find_seq(pilha, anagram, size, current_seq, current_str, word, num_i, num_o);
        }

    }

}

int main(){

    string word, anagram;
    int size;

    while(cin >> word >> anagram){

        size = word.size();
        stack<char> pilha;
        string current_seq, current_str;

        cout << "[" << endl;
        find_seq(pilha, anagram, size, current_seq, current_str, word, 0, 0);
        cout << "]" << endl;

    }

    return 0;
}