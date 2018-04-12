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



int main(){
    //ios_base::sync_with_stdio(false);

    int n_req, n_prop;
    double best_price;
    int best_met;
    string best_emp;
    string line;
    string curr_emp;
    double curr_price;
    int curr_met;
    int rfp_count = 0;
    bool first = true;

    cin >> n_req >> n_prop;
    while(n_req != 0 || n_prop != 0){

        if(first){
            first = false;
        }else{
            cout << endl;
        }

        deb("aqui1");
        best_met = -1;

        cin.ignore();
        for (int i = 0; i < n_req; ++i) {
            getline(cin, line);
            deb("line = ", line);
        }
        deb("aqui2");

        for (int i = 0; i < n_prop; ++i) {
            getline(cin, curr_emp);
            //cin.ignore();
            scanf("%lf %d", &curr_price, &curr_met);
            //cin >> curr_price >> curr_met;

            deb("curr_emp = ", curr_emp);
            deb("curr_price = ", curr_price);
            deb("curr_met = ", curr_met);
            deb("best_met = ", best_met);
            if(curr_met >= best_met){
                if(curr_met > best_met || curr_price < best_price) {
                    best_met = curr_met;
                    best_price = curr_price;
                    best_emp = curr_emp;
                    deb("new best = ", curr_met);
                }
            }

            cin.ignore();
            for (int j = 0; j < curr_met; ++j) {
                getline(cin, line);
            }
        }

        ++rfp_count;
        cout << "RFP #" << rfp_count << endl;
        cout << best_emp << endl;


        cin >> n_req >> n_prop;
    }

    return 0;
}