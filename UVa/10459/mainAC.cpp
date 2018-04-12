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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;

    while(cin >> N){

        vector< std::list<int> > vet_adj(N);
        vi degree(N, 0);

        int K, v;
        for (int i = 0; i < N; ++i) {
            cin >> K;
            degree[i] = K;
            for (int j = 0; j < K; ++j) {
                cin >> v;
                --v;
                deb("i = ", i, "v = ", v);
                vet_adj[i].push_back(v);
            }
        }

        deb("adj");

        /*Getting roots*/
        int removed_count = 0;
        list<int> current_lower_degree;

        for (int i = 0; i < N; ++i) {
            if(degree[i] == 1){
                ++removed_count;
                current_lower_degree.push_back(i);
            }
        }

        while(removed_count < N){
            print_vector_debug(degree);
            int sz = current_lower_degree.size();
            auto it = current_lower_degree.begin();
            for(int i = 0; i < sz; ++i){
                auto u = *it;
                for(auto &v: vet_adj[u]){
                    degree[v]--;
                    if(degree[v] == 1){
                        current_lower_degree.push_back(v);
                        ++removed_count;
                    }
                }
                it = current_lower_degree.erase(it);
            }
        }


        if(debug){
            for(auto &i : current_lower_degree){
                cout << i << " ";
            }cout << endl;
        }

        list<int> worst;
        for(auto &i : current_lower_degree){

            deb("i = ", i);
            vi visited(N,0);
            vi dist(N,0);

            visited[i] = 1;
            dist[i] = 1;

            stack<int> s;
            s.push(i);

            while(!s.empty()){
                auto u = s.top();
                s.pop();

                deb("u = ", u);
                deb("dist[u] = ", dist[u]);

                for(auto &v : vet_adj[u]){
                    if(!visited[v]){
                        deb("v = ", v);
                        deb("uu = ", u);
                        deb("dist[u] = ", dist[u]);
                        dist[v] = dist[u]+1;
                        deb("dist[v] = ", dist[v]);
                        visited[v] = 1;
                        s.push(v);
                    }
                }

            }

            int max_dist = *max_element(all(dist));

            print_vector_debug(dist);
            for (int j = 0; j < N; ++j) {
                if (dist[j] == max_dist) {
                    worst.push_back(j);
                }
            }
        }

        vi best_vector;
        best_vector.reserve(current_lower_degree.size());
        for(auto &u : current_lower_degree){
            best_vector.push_back(u);
        }
        sort(all(best_vector));

        vi worst_vector;
        best_vector.reserve(worst.size());
        for(auto &u : worst){
            worst_vector.push_back(u);
        }
        sort(all(worst_vector));

        cout << "Best Roots  :";
        for(auto &u : best_vector){
            cout << " " << u+1;
        }cout << endl;

        cout << "Worst Roots :";
        for(auto &u : worst_vector){
            cout << " " << u+1;
        }cout << endl;


    }

    return 0;
}