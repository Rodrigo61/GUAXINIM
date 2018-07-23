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

ll sz;
ll m;

ll min_move(ll source, ll target) {

    ll move;

    if (source > target) {
        move = (m - 1) - source + target + 1;
    } else {

        move = target - source;
    }

    return move;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> sz >> m;
    vi values(sz);
    vll original_values(sz);
    vi freq(m, 0);


    for (int i = 0; i < sz; ++i) {
        cin >> values[i];

        original_values[i] = values[i];

        values[i] %= m;

        freq[values[i]]++;
    }


    int not_completed = 0;
    ll target = sz/m;
    ll moves = 0;

    set<int> not_completed_set;
    for (int i = 0; i < m; ++i) {

        if (freq[i] < target) {
            not_completed_set.insert(i);
        }

    }


    for (int i = 0; i < sz; ++i) {

        if (freq[values[i]] <= target) {
            continue;
        }


        auto it = not_completed_set.lower_bound(values[i]);

        if (it == not_completed_set.end()) {
            not_completed = *not_completed_set.begin();
        } else {
            not_completed = *it;
        }


        ll min_moves = min_move(values[i], not_completed);
        moves += min_moves;

        freq[values[i]]--;
        freq[not_completed]++;

        if (freq[not_completed] == target) {
            not_completed_set.erase(not_completed);
        }

        original_values[i] += min_moves;

    }




    printf("%lld\n", moves);
    for(auto &e: original_values) {
        printf("%lld ", e);
    }

    return 0;
}