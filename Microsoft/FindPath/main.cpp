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


void get_path(string &word, vector<string> &grid, int word_id, vector<pii> &path){

    if(word_id == word.size()-1){
        return;
    }

    if(debug) {
        deb("teste");
        for (auto &p : path) {
            cout << "( " << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    pii curr_point = *(path.end()-1);

    deb("curr_point = ", curr_point.first, curr_point.second);

    int i, j;

    for (int k = -1; k <= 1; ++k) {
        for (int l = -1; l <= 1; ++l) {
            if((k == 0 && l == 0) || (k != 0 && l != 0)) continue;

            i = curr_point.first+k;
            j = curr_point.second+l;
            deb("NOT FILT i = ", i, "j = ", j);
            deb("word[word_id+1] = ", word[word_id+1]);
            deb("grid.size() = ", grid.size());
            deb("grid[0].size() = ", grid[0].size());
            if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()){

                deb("grid[i][j] = ", grid[i][j]);
                if(grid[i][j] == word[word_id+1]){
                    deb("i = ", i, "j = ", j);
                    auto aux_path = path;
                    aux_path.push_back(mp(i,j));
                    get_path(word, grid, word_id+1, aux_path);

                    if(aux_path.size() == word.size()){
                        path = aux_path;
                    }
                }
            }
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string word;
    vector<string> grid;

    cin >> word;
    cin.ignore();
    string row;
    while(getline(cin, row)){
        grid.push_back(row);
    };

    print_matrix_debug(grid);

    vector<pii> path;
    path.push_back(mp(0,0));

    get_path(word, grid, 0 , path);

    if(debug){
        for(auto &p : path){
            cout << "( " << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    vector<string> final_grid = grid;

    for (int i = 0; i < final_grid.size(); ++i) {
        for (int j = 0; j < final_grid[0].size(); ++j) {
            final_grid[i][j] = '.';
        }
    }

    for(auto &p : path){
        final_grid[p.first][p.second] = grid[p.first][p.second];
    }

    for (int i = 0; i < final_grid.size(); ++i) {
        for (int j = 0; j < final_grid[0].size(); ++j) {
            cout << final_grid[i][j];
        }
        cout << endl;
    }

    return 0;
}