bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include "bits/stdc++.h"
using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "
#define pb push_back

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

vector<vector<char>> grid;
int rows, cols;


char turn_left(int o) {

    switch (o) {
        case 'O': return 'S';
        case 'N': return 'O';
        case 'L': return 'N';
        case 'S': return 'L';
    }
}

char turn_right(int o) {

    switch (o) {
        case 'O': return 'N';
        case 'N': return 'L';
        case 'L': return 'S';
        case 'S': return 'O';
    }
}

bool valid(int i, int j) {

    return i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] != '#';
}

void go_front(int &i, int &j, int orientation) {

    deb("front");
    if (orientation == 'N' && valid(i - 1, j)) {
        i = i - 1;
    } else if (orientation == 'S' && valid(i + 1, j)) {
        i = i + 1;
    } else if (orientation == 'O' && valid(i, j - 1)) {
        j = j - 1;
    } else if (orientation == 'L' && valid(i, j + 1)) {
        j = j + 1;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int seq_sz;

    while (cin >> rows >> cols >> seq_sz, rows) {

        char orientation;
        int pos_i, pos_j;

        grid.clear();
        grid.resize(rows, vector<char>(cols));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> grid[i][j];

                if (grid[i][j] == 'N' || grid[i][j] == 'O' || grid[i][j] == 'L' || grid[i][j] == 'S') {
                    pos_i = i;
                    pos_j = j;

                    orientation = grid[i][j];
                    grid[i][j] = '.';
                }
            }
        }


        int counter = 0;

        for (int i = 0; i < seq_sz; ++i) {
            char cmd;
            cin >> cmd;

            deb("pos_i = ", pos_i, "pos_j = ", pos_j);
            deb("orientation = ", orientation);
            if (cmd == 'E') {
                orientation = turn_left(orientation);
            } else if (cmd == 'D') {
                orientation = turn_right(orientation);
            } else {
                go_front(pos_i, pos_j, orientation);
            }

//            deb("grid[pos_i][pos_j] = after", grid[pos_i][pos_j]);
            if (grid[pos_i][pos_j] == '*') {
                ++counter;
                grid[pos_i][pos_j] = '.';
            }
        }

        printf("%d\n", counter);

    }

    return 0;
}
