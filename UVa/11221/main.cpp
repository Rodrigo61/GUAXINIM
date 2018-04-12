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
    while(pos = str.find(" "), pos != string::npos){
        str.erase(pos, 1);
    }
    while(pos = str.find(","), pos != string::npos){
        str.erase(pos, 1);
    }
    while(pos = str.find("."), pos != string::npos){
        str.erase(pos, 1);
    }
    while(pos = str.find("?"), pos != string::npos){
        str.erase(pos, 1);
    }
    while(pos = str.find("!"), pos != string::npos){
        str.erase(pos, 1);
    }
    while(pos = str.find("("), pos != string::npos){
        str.erase(pos, 1);
    }
    while(pos = str.find(")"), pos != string::npos){
        str.erase(pos, 1);
    }
}

bool perfect_square(int num){
    deb("sqrt(num) = ", sqrt(num));
    deb("ceil(sqrt(num) = ", ceil(sqrt(num)));
    return sqrt(num) == ceil(sqrt(num));
}

int main(){
    ios_base::sync_with_stdio(false);

    int case_count = 0;
    int n_cases;
    cin >> n_cases;
    cin.ignore();

    for (int w = 0; w < n_cases; ++w) {

        ++case_count;
        cout << "Case #" << case_count << ":" << endl;

        string line;
        getline(cin, line);
        format(line);

        deb("formated: ", line);

        if(perfect_square(line.size())){

            int sqr = sqrt(line.size());

            char mat[sqr][sqr];

            auto it = line.begin();
            for (int i = 0; i < sqr; ++i) {
                for (int j = 0; j < sqr; ++j) {
                    mat[i][j] = *it;
                    ++it;
                }
            }

            bool is_magic = true;

            it = line.begin();
            for (int i = 0; i < sqr && is_magic; ++i) {
                for (int j = 0; j < sqr; ++j) {
                    if(mat[i][j] != *it){
                        is_magic = false;
                    }
                    ++it;
                }
            }

            it = line.begin();
            for (int j = 0; j < sqr && is_magic; ++j) {
                for (int i = 0; i < sqr; ++i) {
                    if(mat[i][j] != *it){
                        is_magic = false;
                    }
                    ++it;
                }
            }

            it = line.begin();
            for (int i = sqr-1; i >= 0 && is_magic; --i) {
                for (int j = sqr-1; j >= 0; --j) {
                    if(mat[i][j] != *it){
                        is_magic = false;
                    }
                    ++it;
                }
            }

            it = line.begin();
            for (int j = sqr-1; j >= 0 && is_magic; --j) {
                for (int i = sqr-1; i >= 0; --i) {
                    if(mat[i][j] != *it){
                        is_magic = false;
                    }
                    ++it;
                }
            }


            if(is_magic){
                cout << sqr << endl;
            }else{
                cout << "No magic :(" << endl;
            }
        }else{
            cout << "No magic :(" << endl;
        }

    }

    return 0;
}