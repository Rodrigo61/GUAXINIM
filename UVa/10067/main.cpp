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


list<int> get_neighbors(int node){

    list<int> ret;
    int a,b,c,d;

    d = node % 10;
    c = (node % 100)/10;
    b = (node % 1000)/100;
    a = node / 1000;

    /*deb("node = ", node);
    deb("a = ", a);
    deb("b = ", b);
    deb("c = ", c);
    deb("d = ", d);
*/
    ret.push_back(a*1000 + b*100 + c*10 + ((d+1)%10));
    if(d != 0){
        ret.push_back(a*1000 + b*100 + c*10 + d-1);
    }else{
        ret.push_back(a*1000 + b*100 + c*10 + 9);
    }


    ret.push_back(a*1000 + b*100 + ((c+1)%10)*10 + d);
    if(c != 0){
        ret.push_back(a*1000 + b*100 + (c-1)*10 + d);
    }else{
        ret.push_back(a*1000 + b*100 + 9*10 + d);
    }


    ret.push_back(a*1000 + ((b+1)%10)*100 + c*10 + d);
    if(b != 0){
        ret.push_back(a*1000 + (b-1)*100 + c*10 + d);
    }else{
        ret.push_back(a*1000 + 9*100 + c*10 + d);
    }


    ret.push_back(((a+1)%10)*1000 + b*100 + c*10 + d);
    if(a != 0){
        ret.push_back((a-1)*1000 + b*100 + c*10 + d);
    }else{
        ret.push_back(9*1000 + b*100 + c*10 + d);
    }


    return ret;

}


int main(){
    ios_base::sync_with_stdio(false);

    int n_cases;
    cin >> n_cases;


    for (int w = 0; w < n_cases; ++w) {
        vi visited(100000, 0);
        vi dist(100000, numeric_limits<int>::max());

        int a,b,c,d;

        cin >> a >> b >> c >> d;
        int source = a*1000 + b*100 + c*10 + d;
        deb("source = ", source);

        cin >> a >> b >> c >> d;
        int target = a*1000 + b*100 + c*10 + d;
        deb("target = ", target);

        int n_forb;
        cin >> n_forb;

        for (int i = 0; i < n_forb; ++i) {
            cin >> a >> b >> c >> d;
            int forb = a*1000 + b*100 + c*10 + d;

            visited[forb] = 1;
            deb("forb = ", forb);
        }


        queue<int> q;
        q.push(source);
        visited[source] = 1;
        dist[source] = 0;

        while(!q.empty()){

            int curr_node = q.front();
            q.pop();
            deb("curr_node = ", curr_node);
            deb("dist[curr_node] = ", dist[curr_node]);
            list<int> list_neigh = get_neighbors(curr_node);

            if(debug){
                cout << "list_neigh: ";
                for(auto &i: list_neigh){
                    cout << i << " ";
                }cout << endl;
            }

            for(int neigh_node : list_neigh){
                if(visited[neigh_node] == 0){
                    visited[neigh_node] = 1;
                    deb("neight_node = ", neigh_node);
                    dist[neigh_node] = dist[curr_node] + 1;
                    deb("dist[neigh_node] = ", dist[neigh_node]);
                    q.push(neigh_node);
                }
            }
        }

        if(dist[target] != numeric_limits<int>::max()){
            cout << dist[target] << endl;
        }else{
            cout << -1 << endl;
        }


    }


    return 0;
}