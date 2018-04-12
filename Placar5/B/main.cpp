using namespace std;
bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "

typedef pair<int,int> pii;
typedef vector<int> vi;

//</editor-fold>


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vi freq(1000000,0);

    vi need_change;
    int val;
    for (int i = 0; i < N; i++) {
        cin >> val;
        if(freq[val] == 1){
            need_change.push_back(val);
        }
        freq[val] = 1;
    }

    sort(all(need_change));

    int acu = 0;
    int notUsed = 0;
    for(int i = 0; i < need_change.size(); ++i){

        int e = need_change[i];

        while(freq[notUsed] == 1 || notUsed <= e){
            ++notUsed;
        }

        acu += notUsed - e;
        freq[notUsed] = 1;

    }

    cout << acu << endl;

    return 0;
}
