bool debug = true;

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
map<string, set<string>> map_friends;

bool are_friends(string &str1, string &str2) {

    return map_friends[str1].find(str2) != map_friends[str1].end();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_pairs;
    int n_cases = 0;

    bool first = true;

    while (cin >> n_pairs, n_pairs != -1) {

        if (!first) {
            printf("\n");
        } first = false;


        vector<string> names(6);
        for (int i = 0; i < 6; ++i) {
            cin >> names[i];
        }

        sort(all(names));

        map_friends.clear();

        for (int i = 0; i < n_pairs; ++i) {

            string str1, str2;

            cin >> str1 >> str2;

            map_friends[str1].insert(str2);
            map_friends[str2].insert(str1);
        }


        printf("Instancia %d\n", ++n_cases);

        for (int i = 0; i < 6; ++i) {
            for (int j = i + 1; j < 6; ++j) {
                for (int k = j + 1; k < 6; ++k) {

                    bool friend_ij = are_friends(names[i], names[j]);
                    bool friend_jk = are_friends(names[j], names[k]);
                    bool friend_ki = are_friends(names[k], names[i]);

                    if (friend_ij && friend_jk && friend_ki) {

                        printf("%s %s %s sao amigos\n", names[i].c_str(), names[j].c_str(), names[k].c_str());

                    } else if (!friend_ij && !friend_jk && !friend_ki) {

                        printf("%s %s %s sao inimigos\n", names[i].c_str(), names[j].c_str(), names[k].c_str());

                    }

                }
            }
        }

    }

    return 0;
}
