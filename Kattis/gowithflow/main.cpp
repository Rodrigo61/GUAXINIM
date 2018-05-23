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

vi words;
vector<vi> lines;

void get_lines(int width) {

    lines.clear();
    vi line;
    int line_sz = -1;

    for (auto &w : words) {
        if (line_sz + w + 1 > width) {
            lines.push_back(line);
            line.clear();
            line_sz = -1;
        }

        line.push_back(w);
        line_sz += w + 1;
    }

    if (line_sz != -1) {
        lines.push_back(line);
    }

}

int solve(int width) {

    int maxi = 0;
    vi last_line;
    vi last_line_dp;
    last_line.reserve(width);
    last_line_dp.reserve(width);

    vi current_line;
    vi current_line_dp;
    current_line.reserve(width);
    current_line_dp.reserve(width);

    int lines_sz = lines.size();

    for (int l = 0; l < lines_sz; ++l) {
        auto &line = lines[l];

        current_line.clear();
        current_line_dp.clear();

        current_line.push_back(0);
        current_line.push_back(0);
        current_line_dp.push_back(0);
        current_line_dp.push_back(0);


        int pos = -1;
        int line_sz = line.size();
        int last_pos = 0;

        for (size_t i = 0; i < line_sz - 1; i++) {
            pos += line[i] + 1;
            int left = 1, mid = 1, right = 1;

            if (!last_line.empty()) {

                while (pos >= last_line[last_pos]) { ++last_pos; }

                if (pos + 1 >= last_line[last_pos - 2]) {

                    if (last_line[last_pos - 2] == pos + 1 || last_line[last_pos - 2] == pos || last_line[last_pos - 2] == pos - 1) {
                        left = last_line_dp[last_pos - 2] + 1;
                    }

                    if (last_line[last_pos - 1] == pos + 1 || last_line[last_pos - 1] == pos || last_line[last_pos - 1] == pos - 1) {
                        mid = last_line_dp[last_pos - 1] + 1;
                    }

                    if (last_line[last_pos] == pos + 1 || last_line[last_pos] == pos || last_line[last_pos] == pos - 1) {
                        right = last_line_dp[last_pos] + 1;
                    }
                }
            }

            current_line.push_back(pos);
            int curr_max = max({left, mid, right});
            current_line_dp.push_back(curr_max);

            maxi = max(maxi, curr_max);
        }

        current_line.push_back(999999);
        current_line.push_back(999999);
        current_line_dp.push_back(0);
        current_line_dp.push_back(0);

        last_line = current_line;
        last_line_dp = current_line_dp;
    }

    return maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sz;
    cin >> sz;

    words.resize(sz);
    string str;
    for (size_t i = 0; i < sz; i++) {
        cin >> str;
        words[i] = str.size();
    }

    int max_sz = *max_element(all(words));

    int longest_river = 0;
    int best_width = max_sz;

    for (size_t i = max_sz; i < 200000; i++) {
        get_lines(i);

        if (lines.size() < longest_river) { break; }

        int river = solve(i);

        if (river > longest_river) {
            longest_river = river;
            best_width = i;
        }

    }

    printf("%d %d\n", best_width, longest_river);


    return 0;
}
