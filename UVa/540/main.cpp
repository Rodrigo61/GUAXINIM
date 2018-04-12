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

int main() {

    int team_count;
    int team_size;
    int element;
    int scenario_count = 0;
    string command;
    string ENQUEUE = "ENQUEUE";
    string DEQUEUE = "DEQUEUE";
    string STOP = "STOP";

    cin >> team_count;

    while(team_count != 0){

        ++scenario_count;
        cout << "Scenario #" << scenario_count << endl;

        vector<std::list<int>> heads(team_count);
        vector<int> team_elements(1000000);
        list<int> team_order;

        deb("team_count = ", team_count);
        deb("1");
        for (int i = 0; i < team_count; ++i) {
            cin >> team_size;

            for (int j = 0; j < team_size; ++j) {
                cin >> element;
                deb("i = ", i);
                deb("element = ", element);
                team_elements[element] = i;
                deb("team_elements[element] = ", team_elements[element]);
            }
        }

        deb("2");
        cin >> command;
        while(command != STOP){

            if(command == ENQUEUE){

                cin >> element;
                int team_id = team_elements[element];

                deb("command = ", command);
                deb("team_id = ", team_id);
                if(heads[team_id].empty()){
                    team_order.push_back(team_id);
                }

                heads[team_id].push_back(element);

            }else if(command == DEQUEUE){

                int team_id = team_order.front();
                deb("command = ", command);
                deb("team_id = ", team_id);
                element = heads[team_id].front();
                cout << element << endl;
                heads[team_id].pop_front();



                if(heads[team_id].empty()){
                    team_order.pop_front();
                }
            }

            cin >> command;
        }

        deb("3");
        cout << endl;
        cin >> team_count;
    }


    return 0;
}