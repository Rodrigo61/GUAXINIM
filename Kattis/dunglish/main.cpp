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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sz;
    cin >> sz;

    vector<string> vet_words(sz);
    for (int i = 0; i < sz; ++i) {
        cin >> vet_words[i];
    }


    int sz_dict;
    cin >> sz_dict;


    map<string, int> dict_correct, dict_incorrect;
    map<string, string> only_translation;

    string word, trans, type;

    for (int i = 0; i < sz_dict; ++i) {
        cin >> word >> trans >> type;

        if (type == "correct") {

            if (dict_correct.find(word) == dict_correct.end()) {
                dict_correct[word] = 0;
            }

            dict_correct[word]++;

        } else {

            if (dict_incorrect.find(word) == dict_incorrect.end()) {
                dict_incorrect[word] = 0;
            }

            dict_incorrect[word]++;

        }

        only_translation[word] = trans;
    }


    ll correct_count = 0;
    if (dict_correct.find(vet_words[0]) != dict_correct.end()) {
        correct_count = dict_correct[vet_words[0]];
    }

    for (int i = 1; i < sz; ++i) {

        if (dict_correct.find(word) != dict_correct.end()) {
            correct_count *= dict_correct[vet_words[i]];
        } else {
            correct_count = 0;
            break;
        }

    }


    ll total = 1;
    for (auto &word : vet_words) {
        total *= dict_correct[word] + dict_incorrect[word];
    }

    ll incorrect_count = total - correct_count;

    deb("correct count = ", correct_count);
    deb("incorrect_count = ", incorrect_count);
    deb("total count = ", total);

    if (correct_count > 1 || incorrect_count > 1) {
        printf("%lld correct\n", correct_count);
        printf("%lld incorrect\n", incorrect_count);
    }

    if (correct_count == 1 && incorrect_count == 0) {
        for (int i = 0; i < sz; ++i) {
            printf("%s", only_translation[vet_words[i]].c_str());

            if (i != sz - 1) {
                printf(" ");
            }
        }
        printf("\n correct\n");
    }

    if (correct_count == 0 && incorrect_count == 1) {
        for (int i = 0; i < sz; ++i) {
            printf("%s", only_translation[vet_words[i]].c_str());

            if (i != sz - 1) {
                printf(" ");
            }
        }
        printf("\nincorrect\n");
    }

    return 0;
}
