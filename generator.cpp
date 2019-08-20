#include <bits/stdc++.h>
using namespace std;

int randNum(int min, int max) {
    return rand()%(max-min + 1) + min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand (time(NULL));
    cout << 1 << endl;


    int N_MAX = 20000;
    int HEIGHT_MAX = 1000000000;

    int N = randNum(1, N_MAX);
    int K = randNum(1, N);

    cout << N << " " << K << endl;

    for (size_t i = 0; i < N; i++) {
        cout << randNum(1, HEIGHT_MAX) << " ";
    }
    cout << endl;

    return 0;
}


import os

while 1:
        os.system('./generator > gen')
        os.system('./main_alt < gen > out_alt')
        os.system('./main < gen > out')
        if open('out_alt').read() != open('out').read():
                print 'WA'
                exit(0)
c	
