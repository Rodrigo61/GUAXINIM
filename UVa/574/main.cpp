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

int N, T;
bool solution_found;
vi values;

vector<string> solve(int curr_idx, int acu_sum, list<int> &curr_subset) {

    deb("curr_idx = ", curr_idx);
    deb("curr_subset.size() = ", curr_subset.size());
    deb("acu_sum = ", acu_sum);

    vector<string> res;

    if (curr_idx == N + 1) {
        return res;
    }

    if (acu_sum == T) {
        solution_found = true;
        int count = curr_subset.size();
        string subset_str;
        for (auto i = curr_subset.begin(); i != curr_subset.end(); ++i) {
            subset_str += to_string(*i);

            if (count > 1) {
                subset_str += "+";
            }

            --count;
        }

        res.push_back(subset_str);
        return res;
    }

    curr_subset.push_back(values[curr_idx]);
    auto take_solution = solve(curr_idx + 1, acu_sum + values[curr_idx], curr_subset);
    curr_subset.pop_back();

    auto not_take_solution = solve(curr_idx + 1, acu_sum, curr_subset);

    res.insert(res.begin(), all(not_take_solution));
    res.insert(res.begin(), all(take_solution));


    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (cin >> T >> N, N + T != 0) {

        values.clear();
        values.resize(N);

        for (size_t i = 0; i < N; i++) {
            cin >> values[i];
        }

        print_vector_debug(values);
        printf("Sums of %d:\n", T);

        solution_found = false;

        sort(all(values));
        reverse(all(values));

        list<int> list_aux;
        auto ans = solve(0, 0, list_aux);

        for (auto it = ans.begin(); it != ans.end(); ++it) {
            for (auto it2 = it + 1; it2 != ans.end(); ++it2) {

                if (*it == *it2) {
                    it2 = ans.erase(it2);
                    --it2;
                }
            }
        }

        if (ans.empty()) {
            printf("NONE\n");
        } else {
            for (auto &elem : ans) {
                printf("%s\n", elem.c_str());
            }
        }



    }



    return 0;
}
