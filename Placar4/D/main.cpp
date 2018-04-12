using namespace std;
bool debug = true;

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
//</editor-fold>

vector<int> remove_equals(vector<int> &inversoes) {
    set<int> final;
    vector<int> v;
    v.reserve(200000);
    vi freq(200200, 0);

    for(int i=0; i < inversoes.size(); i++) {
        freq[-1 * inversoes[i]]++;
    }

    for(int i=0; i < inversoes.size(); i++) {
        if(freq[-1*inversoes[i]] % 2 == 1){
            v.push_back(inversoes[i]);
        }
    }

    return v;
}

void inverte_char(string & s, int index) {
    int size = s.size();
    int simetrico = size-1-index;

    char temp = s[index];
    s[index] = s[simetrico];
    s[simetrico] = temp;

}

void inverte_range(string & s, int start, int finish) {
    int size = s.size();

    for(int i=start; i<=finish; i++) {
        inverte_char(s, i);
    }
}

void inverte(string & s, vector<int> &inversoes) {


    sort(inversoes.begin(), inversoes.end());



    inversoes = remove_equals(inversoes);
    int m = inversoes.size();
    // for(int i=0; i < m; i++) {
    //     cout << inversoes[i] << " ";
    // }
    // cout << endl;

    if((m-1) % 2 == 0) {
        inverte_range(s, inversoes[0] * -1, (s.size()-1)/2);
    }

    for(int i=1; i<m; i++) {
        if((m-1-i) % 2 == 0) {
            inverte_range(s, inversoes[i] * - 1, (inversoes[i-1]*-1)-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // string s;
    char st[1000000];
    int M, aux;
    vector<int> inversoes;

    // cin >> s;
    scanf("%s\n", st);
    // cin.ignore();
    string s(st);
    // cout << s << endl;

    scanf("%d\n", &M);

    // cout << M << endl;

    for(int i=0; i< M; i++) {
        scanf("%d", &aux);

        inversoes.push_back(-1 * (aux-1));
    }

    // for(int i=0; i < M; i++) {
    //     cout << inversoes[i] << " ";
    // }
    // cout << endl;



    inverte(s, inversoes);

    cout << s << endl;

    return 0;
}
