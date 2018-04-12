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


void extract_words(string &line, pair<vector<string>, vector<string>> &p_vet){

    string curr_word = "";

    for (auto i = line.begin(); i < line.end(); ++i) {

        if(*i == ' '){
            p_vet.first.push_back(curr_word);
            p_vet.second.push_back(curr_word);
            curr_word = "";
        }else{
            curr_word += *i;
        }
    }

    if(!curr_word.empty()){
        p_vet.first.push_back(curr_word);
        p_vet.second.push_back(curr_word);
    }

    sort(all(p_vet.first));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string ign_str;
    vector<string> ignore_vet;
    ignore_vet.reserve(55);


    while(cin >> ign_str, ign_str != "::"){
        for(auto &c : ign_str) c = tolower(c);
        ignore_vet.push_back(ign_str);
    }

    sort(all(ignore_vet));
    deb("IGNORE VECT");
    print_vector_debug(ignore_vet);


    vector< pair< pair< vector<string>, vector<string> >, string> > titles;
    titles.reserve(205);
    set<string> keywords;

    string line;
    while(getline(cin, line)){

        deb("reading lines");
        for(auto &c: line) c = tolower(c);
        deb("line transformed = ", line);
        pair< pair< vector<string>, vector<string> >, string>  new_pair;

        new_pair.second = line;

        new_pair.first.first.reserve(20);
        new_pair.first.second.reserve(20);
        extract_words(line, new_pair.first);

        for(auto &str : new_pair.first.first){
            deb("str = ", str);
            if(*lower_bound(all(ignore_vet), str) != str){
                deb("new keyword = ", str);
                keywords.insert(str);
            }
        }

        titles.push_back(new_pair);
    }


    for(auto &str : keywords){

        deb("keyword = ", str);
        for(auto &p : titles){
            auto it = lower_bound(all(p.first.first), str);


            int count = 0;
            int key_count = 0;
            while(it != p.first.first.end() && *it == str){
                deb("*it = ", *it);
                key_count = 0;

                int title_size = p.first.second.size();
                deb("title_size = ", title_size);
                for (int i = 0; i < title_size; ++i) {

                    string word = p.first.second[i];
                    if(word == str){
                        if(key_count == count){
                            for(auto &c : word) c = toupper(c);
                        }
                        ++key_count;
                    }

                    cout << word;
                    if(i != title_size - 1){
                        cout << space;
                    }else{
                        cout << endl;
                    }
                }
                ++count;
                ++it;
            }
        }
    }

    return 0;
}