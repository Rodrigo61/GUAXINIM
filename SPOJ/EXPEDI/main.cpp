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
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;


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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (size_t q = 0; q < n_cases; q++) {

        int n_stops;
        cin >> n_stops;

        vi stops(n_stops);
        vi stops_value(n_stops);

        vii aux(n_stops);
        for (int i = n_stops - 1; i >= 0; --i) {
            cin >> aux[i].first >> aux[i].second;
        }

        sort(all(aux));
        reverse(all(aux));

        for (size_t i = 0; i < n_stops; i++) {
            stops[i] = aux[i].first;
            stops_value[i] = aux[i].second;
        }

        int dist;
        int fuel;

        cin >> dist >> fuel;

        for (auto &stop : stops) {
            stop = dist - stop;
        }



        stops.insert(stops.begin(), 0);
        stops_value.insert(stops_value.begin(), 0);
        stops.push_back(dist);
        stops_value.push_back(100000000);

        print_vector_debug(stops);

        int pos = 0;
        int possible = true;

        int res = 0;
        priority_queue<int, vi, less<int>> pq;

        while (possible && stops[pos] + fuel < dist) {

            deb("stops[pos] = ", stops[pos]);
            int max_reach_pos = distance(stops.begin(), upper_bound(all(stops), stops[pos] + fuel));

            deb("pos = ", pos);
            deb("max_reach_pos = ", max_reach_pos);
            if (pos + 1 == max_reach_pos) {

                if (!pq.empty()) {
                    fuel += pq.top();
                    deb("back and push = ", pq.top());
                    ++res;
                    pq.pop();
                } else {
                    deb("run out gas");
                    possible = false;
                }

                continue;
            }

            for (int i = pos + 1; i < max_reach_pos; ++i) {
                pq.push(stops_value[i]);
            }

            fuel = fuel - (stops[max_reach_pos - 1] - stops[pos]);
            pos = max_reach_pos - 1;

            deb("pos end = ", pos);
            deb("fuel end = ", fuel);

        }

        if (possible) {
            printf("%d\n", res);
        } else {
            printf("-1\n");
        }


    }


    return 0;
}
