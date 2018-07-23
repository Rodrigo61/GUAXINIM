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

string extense_form(int i) {

    string result;

    if (i > 99) {
        int digit = i / 100;

        deb("digit 100 = ", digit);

        if (digit == 1) {
            result += "onehundred";
        } else if (digit == 2) {
            result += "twohundred";
        } else if (digit == 3) {
            result += "threehundred";
        } else if (digit == 4) {
            result += "fourhundred";
        } else if (digit == 5) {
            result += "fivehundred";
        } else if (digit == 6) {
            result += "sixhundred";
        } else if (digit == 7) {
            result += "sevenhundred";
        } else if (digit == 8) {
            result += "eighthundred";
        } else if (digit == 9) {
            result += "ninehundred";
        }
        
        i %= 100;
    }
    
    if (i > 19) {
        int digit = i / 10;
        deb("digit 10 = ", digit);

        if (digit == 2) {
            result += "twenty";
        } else if (digit == 3) {
            result += "thirty";
        } else if (digit == 4) {
            result += "forty";
        } else if (digit == 5) {
            result += "fifty";
        } else if (digit == 6) {
            result += "sixty";
        } else if (digit == 7) {
            result += "seventy";
        } else if (digit == 8) {
            result += "eighty";
        } else if (digit == 9) {
            result += "ninety";
        }

        i %= 10;
    }

    if (i > 0) {
        int digit = i;
        deb("digit 1 = ", digit);
        if (digit == 1) {
            result += "one";
        } else if (digit == 2) {
            result += "two";
        } else if (digit == 3) {
            result += "three";
        } else if (digit == 4) {
            result += "four";
        } else if (digit == 5) {
            result += "five";
        } else if (digit == 6) {
            result += "six";
        } else if (digit == 7) {
            result += "seven";
        } else if (digit == 8) {
            result += "eight";
        } else if (digit == 9) {
            result += "nine";
        } else if (digit == 10) {
            result += "ten";
        } else if (digit == 11) {
            result += "eleven";
        } else if (digit == 12) {
            result += "twelve";
        } else if (digit == 13) {
            result += "thirteen";
        } else if (digit == 14) {
            result += "fourteen";
        } else if (digit == 15) {
            result += "fifteen";
        } else if (digit == 16) {
            result += "sixteen";
        } else if (digit == 17) {
            result += "seventeen";
        } else if (digit == 18) {
            result += "eighteen";
        } else if (digit == 19) {
            result += "nineteen";
        }
    }
    
    return result;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n_words;
    cin >> n_words;

    vector<string> words(n_words);

    int total_len = 0;
    int number_pos = 0;
    for (int i = 0; i < n_words; ++i) {
        string aux;
        cin >> aux;

        deb("aux = ", aux);
        if (aux == "$") {
            number_pos = i;
        }

        words[i] = aux;
        total_len += words[i].size();
    }

    total_len--;

    deb("read");

    string number;


    for (int i = max(total_len, 1); i < 1000; ++i) {

        deb("prop i = ", i);
        number = extense_form(i);
        deb("number i = ", number);

        if (total_len + number.size() == i) {
            deb("i = ", i);
            break;
        }
    }

    for (int i = 0; i < n_words; ++i) {

        if (i != 0) {
            printf(" ");
        }

        if (i == number_pos) {
            printf("%s", number.c_str());
        } else {
            printf("%s", words[i].c_str());
        }
    }

    printf("\n");

    return 0;
}
