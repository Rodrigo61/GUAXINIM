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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int curr_id = 0;
    map<string, int> map_word_id;
    map<int, int> map_comma_position;
    vector<vi> vet_adj(2000002);
    int offset = 1000000;
    string word;
    vector<string> original_ordered_words;

    bool new_sentence = true;

    int last_word_id;
    while (cin >> word) {

        original_ordered_words.push_back(word);

        deb("word = ", word);

        bool contains_comma = false;
        bool contains_period = false;
        if (word.back() == ',' || word.back() == '.') {
            if (word.back() == ',') {
                contains_comma = true;
            } else {
                contains_period = true;
            }
            word.erase(word.end() - 1);
        }


        if (map_word_id.find(word) == map_word_id.end()) {
            map_word_id[word] = curr_id;
            ++curr_id;
        }

        int word_id = map_word_id[word];

        if (!new_sentence) {
            vet_adj[last_word_id + offset].push_back(word_id);
            vet_adj[word_id].push_back(last_word_id + offset);
        }

        new_sentence = false;

        if (contains_comma) {
            map_comma_position[word_id + offset] = 1;
        } else if (contains_period) {
            new_sentence = true;
        }

        last_word_id = word_id;
    }

    deb("DOING BFS");
    vi visited(2000002, 0);
    for (auto &p : map_comma_position) {
        if (p.second == 1) {
            int root = p.first;
            deb("root = ", root);
            queue<int> q;

            q.push(root);
            visited[root] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                deb("u = ", u);
                for (auto &v : vet_adj[u]) {
                    deb("v = ", v);
                    if (!visited[v]) {
                        visited[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }

    for (int i = 0; i < original_ordered_words.size(); ++i){
        auto &word = original_ordered_words[i];

        if (word.back() == ',' || word.back() == '.') {
            cout << word;

            if (i != original_ordered_words.size() - 1) {
                cout << " ";
            }

        } else {

            cout << word;

            int word_id = map_word_id[word];
            if (visited[word_id + offset]) {
                cout << ", ";
            } else {
                cout << " ";
            }
        }

    }

    return 0;
}
