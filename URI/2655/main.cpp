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


void toogle_BIT(vi &BIT, vi &values_BIT, int pos) {

    int diff = values_BIT[pos] ? -1:1;

    values_BIT[pos] = !((bool)values_BIT[pos]);

    pos++;

    while (pos < BIT.size()) {

        BIT[pos] += diff;
        pos += (pos & (-pos));

    }
}


int sum_bit(vi &BIT, int pos) {

    int res = 0;

    if (pos < 0) return 0;

    ++pos;

    while (pos > 0) {

        res += BIT[pos];
        pos -= (pos & (-pos));

    }

    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q, M;
    cin >> N >> Q >> M;

    vector<vi> vet_BIT(M, vi(N + 1));
    vector<vi> values_BIT(M, vi(N + 1));


    for (int i = 0; i < N; ++i) {

        int monster;
        cin >> monster;

        --monster;

        toogle_BIT(vet_BIT[monster], values_BIT[monster], i);
    }


    int cmd, arg1, arg2;
    for (int i = 0; i < Q; ++i) {

        cin >> cmd >> arg1 >> arg2;
        --arg1, --arg2;


        if (cmd == 1) {


            int count_distinct = 0;
            for (int j = 0; j < M; ++j) {

                count_distinct += (bool)(sum_bit(vet_BIT[j], arg2) - sum_bit(vet_BIT[j], arg1 - 1));

            }

            printf("%d\n", count_distinct);

        } else {


            for (int j = 0; j < M; ++j) {

                if (values_BIT[j][arg1]) {

                    toogle_BIT(vet_BIT[j], values_BIT[j], arg1);
                    break;

                }

            }

            toogle_BIT(vet_BIT[arg2], values_BIT[arg2], arg1);

        }
    }

    return 0;
}
