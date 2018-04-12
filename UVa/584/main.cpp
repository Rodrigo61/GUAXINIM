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


/*
  the total number of pins knocked down in the frame, plus bonuses for strikes and spares.

  if a bowler scores a strike in a particular frame, the score for that frame is ten plus the sum
of the next two rolls.

  If a bowler scores a spare in a particular frame, the score for that frame is ten plus
the score of the next roll.

  If a bowler scores a strike in the tenth (final) frame, the bowler is allowed
two more rolls.

 Similarly, a bowler scoring a spare in the tenth frame is allowed one more roll.

 The maximum possible score in a game of bowling (strikes in all ten frames plus two extra strikes
for the tenth frame strike) is 300.
 * */

#define STRIKE 0
#define SPARE 1

int to_num(char c){
    if(c >= '0' && c <= '9')
        return c - '0';

    return 10;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char point;

    while(cin >> point, point != 'G'){

        string plays = "";
        plays += point;

        while(cin.peek() != '\n'){
            cin.ignore();
            plays += cin.get();
        }

        deb("plays = ", plays);

        int sz = plays.size();
        int score = 0;
        int int_point;
        int i;
        if(plays[sz-3] == 'X') {
            i = sz-3;
        }
        else if(plays[sz-2] == '/'){
            i = sz-2;
        }else{
            i = sz-1;
        }
        int frame = 0;
        for (; i >= 0; --i) {

            deb("plays[", i, "] = ", plays[i]);
            if(plays[i] >= '0' && plays[i] <= '9'){
                int_point = plays[i] - '0';
                deb("int_point = ", int_point);
                score += int_point;
                ++frame;
            }else if(plays[i] == '/'){
                if(i+1 <= sz-1){
                    int_point = to_num(plays[i+1]) + 10;
                }else{
                    int_point = 10;
                }
                deb("int_point = ", int_point);
                score += int_point;
                --i;
                frame += 2;
            }else{
                int_point = 0;
                if(i+2 <= sz -1)
                    int_point += to_num(plays[i+2]);
                if(i+1 <= sz -1)
                    int_point += to_num(plays[i+1]);

                if(int_point > 10 && int_point < 20){
                    int_point = 10;
                }
                int_point += 10;
                deb("int_point = ", int_point);
                score += int_point;
                frame += 2;
            }

            deb("score = ", score);
        }

        deb("frame = ", frame);
        if(frame < 20){
            if(plays[sz-3] == 'X') {
                score += to_num(plays[sz-2]);
                score += to_num(plays[sz-1]);
            }
            else if(plays[sz-2] == '/'){
                score += to_num(plays[sz-1]);
            }
        }


        cout << score << endl;

    }

    return 0;
}