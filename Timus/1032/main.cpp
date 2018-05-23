using namespace std;
bool debug = false;

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


vi subsum(int sum, vector<pii> vet_num){

    vi res;
    if(vet_num[0].first == sum){
        res.push_back(sum);
        return res;
    }

    int vet_sz = vet_num.size();
    vector<vi> dp(vet_sz, vi(sum+1, 0));


    dp[vet_sz-1][sum-vet_num[vet_sz-1].first] = 1;
    for (int i = vet_sz-2; i >= 0; --i) {
        for (int j = 0; j <= sum; ++j) {
            if(j+vet_num[i].first == sum){
                dp[i][j] = 1;
            }else if(j+vet_num[i].first <= sum){
                dp[i][j] = (bool)max(dp[i+1][j+vet_num[i].first], dp[i+1][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }

    print_matrix_debug(dp);

    int root_path = -1;
    for (int i = 0; i < vet_sz; ++i) {
        if(dp[i][0] == 1){
            root_path = i;
            break;
        }
    }

    if(root_path == -1) return res;

    deb("de boa");
    int acu = 0;
    bool end = false;
    for (int i = root_path; !end && i < vet_sz-1; ++i) {
        if(acu+vet_num[i].first == sum){
            res.push_back(vet_num[i].second);
            end = true;
        }else if(acu+vet_num[i].first <= sum && dp[i+1][acu+vet_num[i].first] == 1){
            acu += vet_num[i].first;
            res.push_back(vet_num[i].second);
        }
    }

    if(!end){
        res.push_back(vet_num[vet_sz-1].second);
    }

    print_vector_debug(res);
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  
    int N;
    cin >> N;

    vector<pii> nums(N);
    vi last_idx_of_remainder(10000, -1);

    int num;
    int acu = 0;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        acu += num;
        nums[i].first = acu%N;
        nums[i].second = num;
        if(num != 0 && num%N == 0){
            cout << 1 << space << num << endl;
            return 0;
        }
    }


    last_idx_of_remainder[0] = 0;
    for (int i = 0; i < N; ++i) {
        if(last_idx_of_remainder[nums[i].first] == -1){
            last_idx_of_remainder[nums[i].first] = i+1;
        }else{
            cout << i - last_idx_of_remainder[nums[i].first] + 1 << endl;
            for (int j = last_idx_of_remainder[nums[i].first]; j <= i; ++j) {
                cout << nums[j].second << endl;
            }
            break;
        }
    }



    /*//print_vector_debug(nums);
    vi res = subsum(N, nums);

    if(res.empty()){
        cout << 0 << endl;
    }else{
        cout << res.size() << endl;
        int proof = 0;
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
            proof += res[i];
            if(i != res.size()-1){
                cout << endl;
            }
        }
        cout << endl;
        cout << "proof%N = " << proof%N;
    }*/
    return 0;
}