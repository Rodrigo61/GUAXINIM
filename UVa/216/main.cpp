using namespace std;
bool debug = true;

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

int V;
int full_mask;
vii vertices;
int last_connected_vertice;
vector<vector<double>> memo;
vector<vector<vi>> memo_path;

double dist(int u, int v) {

    pii pu = vertices[u];
    pii pv = vertices[v];

    return sqrt(pow(pu.first - pv.first, 2) + pow(pu.second - pv.second, 2)) + 16;
}

double solve(int curr_vertice, int mask) {

    //deb("mask = ", mask);
    if (mask == full_mask) {
        return 0;
    }

    double &res = memo[curr_vertice][mask];

    if (res != 0) {
        return res;
    }


    res = 99999;
    int next_vertice;
    for (size_t i = 0; i < V; i++) {
        if (!(mask & (1 << i))) {
            //deb("res = ", res);
            //deb("dist(curr_vertice, i) = ", dist(curr_vertice, i));
            //deb("curr_cost + dist(curr_vertice, i) = ", curr_cost + dist(curr_vertice, i));
            //deb("solve(i, curr_cost + dist(curr_vertice, i), mask |= (1 << i)) = ", solve(i, curr_cost + dist(curr_vertice, i), mask |= (1 << i)));

            double aux = solve(i, mask | (1 << i)) + dist(curr_vertice, i);

            if (aux < res) {
                res = aux;
                next_vertice = i;
            }

        }
    }

    memo_path[curr_vertice][mask] = memo_path[next_vertice][mask | (1 << next_vertice)];
    memo_path[curr_vertice][mask].push_back(next_vertice);

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);

    int cases_count = 0;

    while (cin >> V, V) {

        vertices.clear();
        vertices.resize(V);

        for (size_t i = 0; i < V; i++) {
            cin >> vertices[i].first >> vertices[i].second;
        }

        full_mask = pow(2, V) - 1;

        memo.clear();
        memo.resize(V, vector<double>(full_mask + 1));
        memo_path.clear();
        memo_path.resize(V, vector<vi>(full_mask + 1));

        for (size_t i = 0; i < V; i++) {
            for (size_t j = 0; j < full_mask + 1; j++) {
                memo[i][j] = 0;
            }
        }

        double mini = 999999999;
        vi *mini_path;

        for (size_t i = 0; i < V; i++) {
            double aux = solve(i, 0 | (1 << i));

            if (aux < mini) {
                mini = aux;
                mini_path = &memo_path[i][0 | (1 << i)];
                mini_path->push_back(i);
            }
        }

        printf("**********************************************************\n");
        printf("Network #%d\n", ++cases_count);

        for (size_t i = 0; i < mini_path->size() - 1; i++) {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
                        vertices[(*mini_path)[i]].first,
                        vertices[(*mini_path)[i]].second,
                        vertices[(*mini_path)[i + 1]].first,
                        vertices[(*mini_path)[i + 1]].second,
                        dist((*mini_path)[i], (*mini_path)[i + 1]));
        }

        printf("Number of feet of cable required is %.2lf.\n", mini);


    }


    return 0;
}
