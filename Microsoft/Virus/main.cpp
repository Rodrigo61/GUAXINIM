using namespace std;
bool debug = true;

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

double len_LCS(string &dna, string &virus){

    int dna_sz = dna.size();
    int virus_sz = virus.size();

    vector<vi> dp(dna_sz+1, vi(virus_sz+1));

    for (int i = 1; i <= dna_sz; ++i) {
        for (int j = 1; j <= virus_sz; ++j) {
            if( j == 0 || i == 0){
                dp[i][j] = 0;
            }else if(dna[i-1] == virus[j-1]){
                int maxi = 0;
                int k = 1;
                while(j-k >= 0){
                    maxi = max(maxi, dp[i-1][j-k]);
                    ++k;
                }


                dp[i][j] = maxi + 1;
            }else{
                dp[i][j] = 0;
            }
        }
    }

    print_matrix_debug(dp);
    int maxi = 0;
    for (int j = 0; j <= virus_sz; ++j) {
        for (int i = 0; i <= dna_sz; ++i) {
            maxi = max(maxi, dp[i][j]);
        }
    }
    return maxi;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double dna_sz, virus_sz;
    int n_cit;
    string seq;
    vector<string> vet_dna;
    string virus;

    cin >> n_cit >> dna_sz >> virus_sz;
    cin.ignore();
    cout.precision(2);
    for (int i = 0; i < n_cit; ++i) {
        seq = "";
        for (int j = 0; j < dna_sz; ++j) {
            char c;
            while(c = cin.get(), c == '\n');
            cin.putback(c);
            seq += cin.get();
        }
        vet_dna.push_back(seq);
    }

    char c;
    while(c = cin.get(), c == '\n');
    cin.putback(c);
    virus = "";
    for (int j = 0; j < virus_sz; ++j) {
        virus += cin.get();
    }


    vector<pair<double, int>> ord_cit;

    for (int i = 0; i < n_cit; ++i) {
        deb("virus = ", virus);
        deb("vet_dna[i] = ", vet_dna[i]);
        ord_cit.push_back(mp(len_LCS(vet_dna[i], virus)/virus_sz, i));
    }

    sort(all(ord_cit));


    vi pos(n_cit);
    int curr_pos = 0;
    double last_prob = 2;
    for (int i = n_cit-1; i >= 0; --i) {
        deb("ord_cit[i].first = ", ord_cit[i].first);
        deb("ord_cit[i].second = ", ord_cit[i].second);
        deb("last_prob = ", last_prob);
        if(ord_cit[i].first < last_prob){
            ++curr_pos;
        }

        pos[ord_cit[i].second] = curr_pos;
        last_prob = ord_cit[i].first;

    }

    for (int i = 0; i < n_cit; ++i) {
        cout << "Person #" << i << ": " << pos[i] << "." << endl;
    }


    return 0;
}