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


#define INF numeric_limits<int>::max()

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int P, C;
    int case_count = 0;

    while(cin >> P >> C, P != 0){

        ++case_count;
        cout << "Case " << case_count << ":" <<endl;

        deb("P = ", P,  " C = ", C);
        list<pii> queue;
        queue.push_back(mp(1, P));

        char cmd;
        int arg1;
        for (int i = 0; i < C; ++i) {

            cin >> cmd;
            deb("cmd = ", cmd);

            if(cmd == 'N'){
                pii &front = queue.front();
                if(front.first == INF){
                    cout << front.second << endl;
                    queue.pop_front();
                    queue.push_back(front);
                }else{
                    cout << front.first << endl;
                    queue.push_back(mp(INF, front.first));
                    front.first++;
                    if(front.first == front.second){
                        front.first = INF;
                    }
                }

            }else{
                cin >> arg1;
                deb("arg1 = ", arg1);

                for (auto it = queue.begin(); it != queue.end(); ++it) {
                    if(it->first == INF && it->second == arg1){
                        deb("avulso");
                        pii aux = *it;
                        queue.erase(it);
                        queue.push_front(aux);
                    }else if(arg1 >= it->first && arg1 <= it->second){

                        deb("compactado");
                        if(it->first <= arg1-1){
                            if(it->first < arg1-1){
                                pii left = mp(it->first, arg1-1);
                                deb("left = ", it->first, arg1-1);
                                queue.insert(it, left);
                            }else{
                                pii left = mp(INF, arg1-1);
                                deb("left = ", "INF", arg1-1);
                                queue.insert(it, left);
                            }
                        }

                        if(arg1+1 <= it->second){
                            if(arg1+1 < it->second){
                                pii right = mp(arg1+1, it->second);
                                deb("right = ", arg1+1, it->second);
                                queue.insert(it, right);
                            }else{
                                pii right = mp(INF, arg1+1);
                                deb("right = ", "INF", arg1+1);
                                queue.insert(it, right);
                            }
                        }

                        pii aux = mp(INF, arg1);
                        queue.erase(it);
                        queue.push_front(aux);
                    }
                }
            }
        }

    }

    return 0;
}