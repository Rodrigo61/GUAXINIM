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
//</editor-fold>

#define FUEL 0
#define LEAK 1
#define GAS 2
#define MECH 3
#define GOAL 4

vector<vi> events;
int total_distance;

bool is_possible(double tank){

    double fuel_consu = events[0][2]/100.0;
    int leak_acu = 0;
    double curr_tank = tank;
    auto it_curr_event = events.begin()+1;

    for (size_t i = 0; i < total_distance; i++) {

        if(curr_tank <= 0){
            return false;
        }

        deb("fuel_consu = ", fuel_consu);
        deb("leak_acu = ", leak_acu);
        deb("curr_tank = ", curr_tank);
        deb("i = ", i);
        while(it_curr_event != events.end() && (*it_curr_event)[1] <= i){
            if((*it_curr_event)[0] == FUEL){
                fuel_consu = (*it_curr_event)[2]/100.0;
                ++it_curr_event;
            }else if((*it_curr_event)[0] == LEAK){
                ++leak_acu;
                ++it_curr_event;
            }else if((*it_curr_event)[0] == MECH){
                leak_acu = 0;
                ++it_curr_event;
            }else if((*it_curr_event)[0] == GAS){
                curr_tank = tank;
                ++it_curr_event;
            }
        }

        curr_tank -= fuel_consu;
        curr_tank -= leak_acu;
    }

    if(curr_tank <= 0)
        return false;

    return true;

}

double solve(){
    double upper = 100000;
    double lower = total_distance*0.01;
    double mid = (lower+upper)/2.0;

    while(abs(upper - lower) > 0.00000001){
        mid = lower + (upper-lower)/2.0;
        deb("lower = ", lower);
        deb("upper = ", upper);
        deb("mid = ", mid);


        if(is_possible(mid)){
            upper = mid;
        }else{
            lower = mid+0.0001;
        }
    }

    return mid;

}

int main(){

    string cmd1, cmd2;
    int arg1;
    int dist;


    while(true){

        cin >> dist >> cmd1 >> cmd2 >> arg1;

        if(arg1 == 0)
            break;


        events.clear();
        events.push_back(vi(3) = {FUEL, 0, arg1});
        while(true){
            cin >> dist >> cmd1;

            if(cmd1 == "Fuel"){
                cin >> cmd2 >> arg1;
                events.push_back(vi(3) = {FUEL, dist, arg1});
            }else if(cmd1 == "Leak"){
                events.push_back(vi(3) = {LEAK, dist, 0});
            }else if(cmd1 == "Gas"){
                cin >> cmd2;
                events.push_back(vi(3) = {GAS, dist, 0});
            }else if(cmd1 == "Mechanic"){
                events.push_back(vi(3) = {MECH, dist, 0});
            }else{
                events.push_back(vi(3) = {GOAL, dist, 0});
                total_distance = dist;
                break;
            }
        }

        if(debug){
            for(auto &v : events){
                cout << "[0] = " << v[0] << endl;
                cout << "[1] = " << v[1] << endl;
                cout << "[2] = " << v[2] << endl;
                cout << "----------------------" << endl;
            }
        }

        printf("%.3f\n", solve());
        deb("Fim de ds");

    }



    return 0;
}
