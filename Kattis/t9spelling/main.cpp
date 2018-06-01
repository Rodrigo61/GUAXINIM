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

string transl(char c) {
    switch (c) {
        case 'a': {
            return "2";
            break;
        }
        case 'b': {
            return "22";
            break;
        }
        case 'c': {
            return "222";
            break;
        }
        case 'd': {
            return "3";
            break;
        }
        case 'e': {
            return "33";
            break;
        }
        case 'f': {
            return "333";
            break;
        }
        case 'g': {
            return "4";
            break;
        }
        case 'h': {
            return "44";
            break;
        }
        case 'i': {
            return "444";
            break;
        }
        case 'j': {
            return "5";
            break;
        }
        case 'k': {
            return "55";
            break;
        }
        case 'l': {
            return "555";
            break;
        }
        case 'm': {
            return "6";
            break;
        }
        case 'n': {
            return "66";
            break;
        }
        case 'o': {
            return "666";
            break;
        }
        case 'p': {
            return "7";
            break;
        }
        case 'q': {
            return "77";
            break;
        }
        case 'r': {
            return "777";
            break;
        }
        case 's': {
            return "7777";
            break;
        }
        case 't': {
            return "8";
            break;
        }
        case 'u': {
            return "88";
            break;
        }
        case 'v': {
            return "888";
            break;
        }case 'w': {
            return "9";
            break;
        }case 'x': {
            return "99";
            break;
        }case 'y': {
            return "999";
            break;
        }case 'z': {
            return "9999";
            break;
        }
        case ' ': {
            return "0";
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n_cases;
    cin >> n_cases;
    cin.ignore();

    int cases_count = 0;

    for (size_t q = 0; q < n_cases; q++) {

        printf("Case #%d:", ++cases_count);

        string line;
        getline(cin, line);

        deb("line = ", line);

        char last_char;
        bool first = true;
        for (auto &c : line) {
            deb("c = ", c);
            deb("last = ", last_char);

            if (first) {
                printf(" %s", transl(c).c_str());
                last_char = transl(c).c_str()[0];
                first = false;
            } else {
                string t = transl(c).c_str();

                if (t[0] == last_char) {
                    printf(" ");
                }

                printf("%s", transl(c).c_str());
                last_char = transl(c).c_str()[0];
            }



        }
        printf("\n");

    }


    return 0;
}
