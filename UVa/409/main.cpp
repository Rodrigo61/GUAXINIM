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

void format(string &str){
    int pos;
    while(pos = str.find("."), pos != string::npos){
        str[pos] = ' ';
    }
    while(pos = str.find(","), pos != string::npos){
        str[pos] = ' ';
    }
    while(pos = str.find("!"), pos != string::npos){
        str[pos] = ' ';
    }
    while(pos = str.find("?"), pos != string::npos){
        str[pos] = ' ';
    }

    for(auto &c : str){
        c = tolower(c);
    }
}


int main(){
    ios_base::sync_with_stdio(false);

    int n_excuses;
    int n_keywords;
    int exec_set_count = 0;

    while(cin >> n_keywords >> n_excuses){

        vector<string> keyw(n_keywords);
        string exec;
        string exec_formated;

        for (int i = 0; i < n_keywords; ++i) {
            cin >> keyw[i];
        }
        cin.ignore();

        deb("aqui");

        list<string> worst_execs;
        int worst_count = 0;
        for (int i = 0; i < n_excuses; ++i) {
            getline(cin, exec);
            exec_formated = exec;
            format(exec_formated);

            deb("exec = ", exec);
            deb("exec_formated = ", exec_formated);

            int count = 0;
            for (int j = 0; j < n_keywords; ++j) {
                string exec_formated_cp = exec_formated;
                deb("keyw[j] = ", keyw[j]);
                int pos;
                while(pos = exec_formated_cp.find(keyw[j]), pos != string::npos){

                    if((pos == 0 || !isalpha(exec_formated_cp[pos-1]))
                       && (pos+keyw[j].size() >= exec_formated_cp.size() || !isalpha(exec_formated_cp[pos+keyw[j].size()]))){
                        ++count;
                    }
                    exec_formated_cp.erase(pos, keyw[j].size());
                }
            }

            deb("count = " , count);
            if(count >= worst_count){
                if(count > worst_count){
                    worst_execs.clear();
                }

                worst_execs.push_back(exec);
                worst_count = count;
            }
        }

        cout << "Excuse Set #" << ++exec_set_count << endl;
        for(auto &s : worst_execs){
            cout << s << endl;
        }
        cout << endl;

    }

    return 0;
}