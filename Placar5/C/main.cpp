using namespace std;
bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "

typedef pair<int,int> pii;
typedef vector<int> vi;



//</editor-fold>

#define MOD 1000000007


long long pow_mod(long long base, long long exp){

    if(exp == 0) return 1;
    if(exp == 1) return base%MOD;

    long long left, right;
    if(exp % 2 == 0){
        left = pow_mod(base, exp/2);
        right = left;
    }else{
        left = pow_mod(base, exp/2);
        right = (left * base)%MOD;
    }

    return (left * right)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N;
    cin >> N;

    if(N == 0){
        cout << 1 << endl;
    }else{
        cout << (pow_mod(2, N-1) + ((pow_mod(4, N-1) * 2) %MOD) ) %MOD << endl;
    }


    return 0;
}
