#include <bits/stdc++.h>
using namespace std;

int randNum(int min, int max) {
    return rand()%(max-min + 1) + min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand (time(NULL));

    int MAX_NAMES = 5;
    int MAX_DOC = 15;
    int MAX_K = 5;

    int N = randNum(1, MAX_DOC);

    int A = randNum(0, MAX_NAMES);
    cout << A << " ";
    int B = randNum(0, MAX_NAMES);
    while (B == A) B = randNum(0, MAX_NAMES);
    cout << B << endl;

    cout << N << endl;

    for (size_t i = 0; i < N; i++) {
        int k = randNum(1, MAX_K);
        cout << k << endl;
        for (int j = 0; j < k; j++)
        {
            A = randNum(0, MAX_NAMES);
            B = randNum(0, MAX_NAMES);
            while (B == A) B = randNum(0, MAX_NAMES);
            cout << A << " " << B << endl;
        }
    }
    cout << endl;

    return 0;
}
