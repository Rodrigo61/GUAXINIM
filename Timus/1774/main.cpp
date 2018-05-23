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

vi p;
int s,t, f;
int V;
int INF = numeric_limits<int>::max();

void augment(int v, int minEdge, vector< std::list<pii> > &adj_list) {     // traverse BFS spanning tree from s to t
    if (v == s){
        f = minEdge; // record minEdge in a global variable f
        return;
    }else if (p[v] != -1){
        int *back_edge;
        for(auto &adj : adj_list[p[v]]){
            if(adj.first == v) back_edge = &adj.second;
        }
        deb("*back_edge = ", *back_edge);
        augment(p[v], min(minEdge, *back_edge), adj_list); // recursive
        *back_edge -= f;

        int *front_edge;
        bool found = false;
        for(auto &adj : adj_list[v]){
            if(adj.first == p[v]){
                front_edge = &adj.second;
                found = true;
            }
        }

        if(found){
            *front_edge += f;    // update
        }else{
            adj_list[v].push_back(mp(p[v], f));
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_recruits, magic_len;
    cin >> n_recruits >> magic_len;

    vector<pii> times(n_recruits);
    int max_time = 0;
    for (int i = 0; i < n_recruits; ++i) {
        cin >> times[i].first >> times[i].second;
        times[i].second += times[i].first;

        max_time = max(max_time, times[i].second);
    }

    V = n_recruits + max_time + 2;
    s = 0, t = V-1;
    vector< std::list<pii> > adj_list(V);

    for (int i = 0; i < n_recruits; ++i) {
        adj_list[s].push_back(mp(i+1, 2));
        for (int j = times[i].first; j < times[i].second; ++j) {
            adj_list[i+1].push_back(mp(j+n_recruits+1 ,1));
        }
    }

    for (int i = 0; i < max_time; ++i) {
        adj_list[i+n_recruits+1].push_back(mp(t, magic_len));
    }


    deb("Edmonds beg");
    int mf = 0;                                              // mf stands for max_flow
    while (1) {              // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
        f = 0;
        // run BFS, compare with the original BFS shown in Section 4.2.2
        vi dist(V, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        p.assign(V, -1);           // record the BFS spanning tree, from s to t!

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) break;      // immediately stop BFS if we already reach sink t
            deb("searching");
            for(auto &adj : adj_list[u])
                if (adj.second > 0 && dist[adj.first] == INF)
                    dist[adj.first] = dist[u] + 1, q.push(adj.first), p[adj.first] = u;
        }
        deb("pre augment");
        augment(t, INF, adj_list);     // find the min edge weight `f' along this path, if any
        if (f == 0) break;      // we cannot send any more flow (`f' = 0), terminate
        mf += f;                 // we can still send a flow, increase the max flow!
        deb("mf = ", mf);
    }



    if(mf == 2*n_recruits){
        cout << "Yes" << endl;

        vector< std::list<int> > computed_times(n_recruits);
        for (int i = 0; i < max_time; ++i) {
            deb("i = ", i);
            bool first = true;
            for(auto &adj : adj_list[i+n_recruits+1]){
                if(first){
                    first = false;
                    continue;
                }
                if(adj.second != 1) continue;

                deb("adj.first-1 = ", adj.first-1);
                deb("adj.second = ", adj.second);
                computed_times[adj.first-1].push_back(i);
                deb("val", i);
            }
        }

        for(auto &l : computed_times){
            auto it = l.begin();
            cout << *it << space;
            ++it;
            cout << *it << endl;
        }
    }else{
        cout << "No" << endl;
    }

    return 0;
}