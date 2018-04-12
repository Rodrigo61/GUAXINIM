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

int get_time(int day, int hour, int minute){
    return day*24*60 + hour*60 + minute;
}

class info{
public:
    string action;
    int km;
    int day;
    int hour;
    int minute;

    bool operator<(const info &other) const {
        return get_time(day, hour, minute) < get_time(other.day, other.hour, other.minute);
    }
};

string ENTER = "enter";
string EXIT = "exit";


int main() {

    int cases;
    cin >> cases;

    for (int w = 0; w < cases; ++w) {


        vector<int> rates(24);
        for (int i = 0; i < 24; ++i) {
            cin >> rates[i];
        }
        cin.ignore();

        print_vector_debug(rates);


        map<string, vector<info>> map_trips;
        map_trips.clear();

        char car_id_raw[21];
        char action_raw[10];
        int hour;
        int day;
        int km;
        int minute;
        bool end_case = false;
        int month;


        while(!end_case){

            std::string line;
            std::getline(std::cin, line);
            sscanf(line.c_str(), "%s %2d:%2d:%2d:%2d %s %d\n", car_id_raw, &month, &day, &hour, &minute, action_raw, &km);

            string car_id = car_id_raw;
            string action = action_raw;

            //create info
            info new_info;
            new_info.km = km;
            new_info.day = day;
            new_info.hour = hour;
            new_info.minute = minute;
            if(action == ENTER){
                new_info.action = ENTER;
            }else{
                new_info.action = EXIT;
            }

            //add on map
            map_trips[car_id].push_back(new_info);

            char c2 = cin.peek();
            if (c2 == '\n' || c2 == EOF){
                end_case = true;
            }


        }


        for(auto &elem : map_trips){

            sort(all(elem.second));

            auto it = elem.second.begin()+1;
            auto it_last = elem.second.begin();
            int bill = 0;

            for (int i = 1; it != elem.second.end() && it_last != elem.second.end(); ++i) {

                if(it->action == EXIT && it_last->action == ENTER){
                    int rate;
                    if(it->action == ENTER){
                        rate = rates[it->hour];
                    }else{
                        rate = rates[it_last->hour];
                    }

                    bill += abs(it->km - it_last->km) * rate + 100;

                    ++it;
                    ++it_last;
                }

                ++it;
                ++it_last;
            }

            if(bill != 0){
                bill += 200;

                int bill_int = bill / 100;
                int bill_dec = bill % 100;

                if(bill_dec >= 10){
                    cout << elem.first << " $" << bill_int << "." << bill_dec << endl;
                }else{
                    cout << elem.first << " $" << bill_int << ".0" << bill_dec << endl;
                }
            }

        }


        if( w != cases - 1){
            cout << endl;
        }
    }

    return 0;
}