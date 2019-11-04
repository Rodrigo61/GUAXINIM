#include <bits/stdc++.h>
using namespace std;

int randNum(int min, int max) {
    return rand()%(max-min + 1) + min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand (time(NULL));
    cout << randNum(1, 10) << endl;

    int N = randNum(1, 10);
    cout << N << endl;
    for (size_t i = 0; i < N; i++) {
        int S = randNum(1, 6);
        for (int j = 0; j < S; j++)
        {
            if (randNum(1, 2) == 1)
                printf("0");
            else
                printf("1");
        }
        printf("\n");
        
    }

    return 0;
}
