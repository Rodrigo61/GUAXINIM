#include <bits/stdc++.h>
using namespace std;

int randNum(int min, int max) {
    return rand()%(max-min + 1) + min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand (time(NULL));


    int N_MAX = 100000;
	int Q_MAX = 1000000;
	long long A_MAX = 1e9;
	long long B_MAX = 1e18;
    
    int N = randNum(1, N_MAX);
    int Q = randNum(1, Q_MAX);

    cout << N << endl;

    for (size_t i = 0; i < N; i++) {
        cout << randNum(1, A_MAX) << " " << randNum(1, B_MAX) << endl;
    }
    
	cout << Q << endl;
	for (size_t i = 0; i < Q; i++) {
		int cmd = randNum(1, 2);
		cout << cmd << " ";
		if (cmd == 1)
		{
			cout << randNum(1, 1^18) << endl;
		}
		else
		{
			cout << randNum(1, A_MAX) << " " << randNum(1, B_MAX) << " " << randNum(1, N) << endl;
		}
    }
}
