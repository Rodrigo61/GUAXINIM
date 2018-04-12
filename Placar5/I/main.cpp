using namespace std;
bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "

typedef pair<int,int> pii;
typedef vector<int> vi;


int N, M;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int debts[N][N];
    memset(debts, 0, sizeof(debts));

    int a, b, d;
    for (size_t i = 0; i < M; i++) {
        cin >> a >> b >> d;
        --a, --b;

        debts[a][b] = d;
    }

    int acu = 0;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            for (size_t k = 0; k < N; k++) {

                int aux = min(debts[i][j], debts[j][k]);

                if(debts[i][j] > 0 && debts[j][k] > 0){
                    debts[i][j] -= aux;
                    debts[i][k] += aux;
                    debts[j][k] -= aux;
                }
            }

            acu += debts[i][j];
        }
    }



    cout << acu << endl;

    return 0;
}
