bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include "bits/stdc++.h"
using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "
#define push_back pb

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

    int n_cases;
    cin >> n_cases;

    for (size_t q = 0; q < n_cases; q++) {

        string str;
        cin >> str;

        int sz = str.size();
        str += " ";

        bool match = true;

        deb("sz = ", sz);
        for (size_t i = 0; i < sz && match;) {

            match = false;
            char aux;
            deb("i = ", i);

            if (sz - i >= 9) {
                aux = str[i + 9];
                str[i + 9] = 0;

                if (strcmp(str.c_str() + i, "outputone") == 0) {
                    deb("match outputone");
                    match = true;
                    str[i + 9] = aux;
                    i += 9;
                    continue;
                }

                str[i + 9] = aux;
            }

            if (sz - i >= 8) {
                aux = str[i + 8];
                str[i + 8] = 0;

                if (strcmp(str.c_str() + i, "outputon") == 0) {
                    deb("match outputon");
                    match = true;
                    str[i + 8] = aux;
                    i += 8;
                    continue;
                }

                if (strcmp(str.c_str() + i, "inputone") == 0) {
                    deb("match intputone");
                    match = true;
                    str[i + 8] = aux;
                    i += 8;
                    continue;
                }

                str[i + 8] = aux;
            }

            if (sz - i >= 7) {
                aux = str[i + 7];
                str[i + 7] = 0;

                if (strcmp(str.c_str() + i, "inputon") == 0) {
                    deb("match outputon");
                    match = true;
                    str[i + 7] = aux;
                    i += 7;
                    continue;
                }

                str[i + 7] = aux;
            }

            if (sz - i >= 6) {
                aux = str[i + 6];
                str[i + 6] = 0;

                if (strcmp(str.c_str() + i, "output") == 0) {
                    deb("match output");
                    match = true;
                    str[i + 6] = aux;
                    i += 6;
                    continue;
                }

                str[i + 6] = aux;
            }

            if (sz - i >= 5) {
                aux = str[i + 5];
                str[i + 5] = 0;

                if (strcmp(str.c_str() + i, "input") == 0) {
                    deb("match input");
                    match = true;
                    str[i + 5] = aux;
                    i += 5;
                    continue;
                }

                if (strcmp(str.c_str() + i, "puton") == 0) {
                    deb("match puton");
                    match = true;
                    str[i + 5] = aux;
                    i += 5;
                    continue;
                }

                str[i + 5] = aux;
            }

            if (sz - i >= 2) {
                aux = str[i + 2];
                str[i + 2] = 0;

                if (strcmp(str.c_str() + i, "in") == 0) {
                    deb("match in");
                    match = true;
                    str[i + 2] = aux;
                    i += 2;
                    continue;
                }

                str[i + 2] = aux;
            }


            if (sz - i >= 3) {
                aux = str[i + 3];
                str[i + 3] = 0;

                if (strcmp(str.c_str() + i, "out") == 0) {
                    deb("match out");
                    match = true;
                    str[i + 3] = aux;
                    i += 3;
                    continue;
                }

                if (strcmp(str.c_str() + i, "one") == 0) {
                    deb("match one");
                    match = true;
                    str[i + 3] = aux;
                    i += 3;
                    continue;
                }

                str[i + 3] = aux;
            }

        }

        if (match) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }


    return 0;
}
