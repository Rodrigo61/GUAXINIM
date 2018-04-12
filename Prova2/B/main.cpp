using namespace std;
bool debug = false;

//{<editor-fold desc="GUAXINIM TEMPLATE">
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
//}

#define MOD 1000000007

long long mod_sum(int a, int b){
	
	return ((a%MOD) + (b%MOD))%MOD;
}

long long mod_sub(int a, int b){
	return ((a%MOD) - (b%MOD) + MOD)%MOD;	
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  
	string orig, patt;
	int o_sz, p_sz;
	cin >> orig >> patt;
	
	o_sz = orig.size();
	p_sz = patt.size();
	
	vector<vector<long long>> dp(o_sz, vector<long long>(p_sz, 0));
	
	deb("ori = ", orig);
	deb("patt = ", patt);
	deb("o_sz = ", o_sz);
	deb("p_sz = ", p_sz);
	
	vi last_range_sum(o_sz, 0);
	for(int i = 0; i < o_sz; ++i){
		if(orig[i] == patt[p_sz-1]){
			dp[i][p_sz-1] = 1;
			if(i == 0){
				last_range_sum[i] = 0;
			}else{
				last_range_sum[i] = mod_sum(last_range_sum[i-1], 1);
			}
		}else{
			if(i == 0){
				last_range_sum[i] = 0;
			}else{
				last_range_sum[i] = last_range_sum[i-1];
			}
		}
		
	}
	
	print_matrix_debug(dp);

	
	vi curr_range_sum(o_sz, 0);
	
	for(int j = p_sz-2; j >= 0; --j){
		
		print_vector_debug(last_range_sum);
		for(int i = 0; i < o_sz; ++i){
			
				if(orig[i] == patt[j]){
					
					dp[i][j] = mod_sub(last_range_sum[o_sz-1], last_range_sum[i]);
				
				}
				
				if(i == 0){
				    curr_range_sum[i] = dp[i][j];
				}else{
					curr_range_sum[i] = mod_sum(curr_range_sum[i-1], dp[i][j]);
				}
					
				 
		}
		last_range_sum = curr_range_sum;
	}
	
	print_matrix_debug(dp);
	
	long long acu = 0;
	for(int i = 0; i < o_sz; ++i){
		deb("dp[i][0] = ", dp[i][0]);
		acu = mod_sum(acu, dp[i][0]);
	}

	
	
	cout << acu << endl;
	
    return 0;
}