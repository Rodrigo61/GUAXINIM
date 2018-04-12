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



#define MAX_V 38 // 0 source, 1..26 Apps, 27..36 PCs, 37 target
#define INF 1000000000
#define SOURCE_ID 0
#define TARGET_ID 37

int get_pc_id(char raw_pc_id){
    return raw_pc_id - '0' + 27;
}

int get_app_id(char raw_app_id){

    return raw_app_id - 'A' + 1;
}

int res[MAX_V][MAX_V], mf, f, s = SOURCE_ID, t = TARGET_ID;                          // global variables
vi p;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
    if (v == s){
        f = minEdge; // record minEdge in a global variable f
        return;
    }else if (p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v])); // recursive
        res[p[v]][v] -= f; res[v][p[v]] += f;    // update
    }
}

char get_name_app(int app_id){

    return app_id - 1 + 'A';
}

int main() {

    string job;
    bool end;

    while (true) {

        if(!getline(cin, job)) return 0;

        memset(res, 0, MAX_V*MAX_V*sizeof(int));
        int acu_jobs = 0;

        while(!job.empty()){

            int app_id = get_app_id(job[0]);
            int brought_count = job[1] - '0';
            int pc_id;

            acu_jobs += brought_count;
            deb("app_id = ", app_id);
            deb("brought_count = ", brought_count);
            for (int i = 3; job[i] != ';'; ++i) {
                pc_id = get_pc_id(job[i]);
                deb("pc_id = ", pc_id);
                res[app_id][pc_id] = 1;
                res[pc_id][TARGET_ID] = 1;
            }

            res[SOURCE_ID][app_id] = brought_count;
            getline(cin, job);
        }
        deb("Graph prepared");
        print_2Darray_debug(res, 38, 38);

        mf = 0;                                              // mf stands for max_flow
        while (1) {              // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
            f = 0;
            // run BFS, compare with the original BFS shown in Section 4.2.2
            vi dist(MAX_V, INF);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(MAX_V, -1);           // record the BFS spanning tree, from s to t!

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == t) break;      // immediately stop BFS if we already reach sink t
                for (int v = 0; v < MAX_V; v++)                 // note: this part is slow
                    if (res[u][v] > 0 && dist[v] == INF)
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
            }
            augment(t, INF);     // find the min edge weight `f' along this path, if any
            if (f == 0) break;      // we cannot send any more flow (`f' = 0), terminate
            mf += f;                 // we can still send a flow, increase the max flow!
            deb("mf = ", mf);
        }


        if(mf == acu_jobs){
            int app_id;
            for (int i = 27; i < TARGET_ID; ++i) {
                app_id = -1;
                for (int j = 1; j < 27; ++j) {
                    if(res[i][j] == 1){
                       app_id = j;
                        break;
                    }
                }

                if(app_id == -1){
                    cout << "_";
                }else{
                    cout << get_name_app(app_id);
                }

            }cout << endl;
        }else{
            cout << "!" << endl;
        }

    }


    return 0;
}









