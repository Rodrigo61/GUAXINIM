#include <bits/stdc++.h>
using namespace std;

int randNum(int min, int max) {
    return rand()%(max-min + 1) + min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand (time(NULL));
    
    int N_MAX = 10;

    int N = randNum(1, N_MAX);

    cout << N << endl;
    set<pair<int, int>> s;

    for (size_t i = 0; i < N; i++) {
        int x, y;
        while (x = randNum(1, N_MAX), y = randNum(1, N_MAX), s.find({x, y}) != s.end());
        s.insert({x, y});
        cout << x << " " << y << endl;;
    }
    cout << endl;

    return 0;
}
