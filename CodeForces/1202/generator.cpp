#include <bits/stdc++.h>
using namespace std;

int randNum(int min, int max) {
    return rand()%(max-min + 1) + min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand (time(NULL));

    printf("0");
    for (int i = 0; i < 4; i++)
    {
        printf("%d", randNum(0, 9));
    }

    return 0;
}