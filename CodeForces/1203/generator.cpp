#include <bits/stdc++.h>
using namespace std;

int randNum(int min, int max) {
    return rand()%(max-min + 1) + min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand (time(NULL));

    int T = randNum(5, 35);

	string t;
    for (size_t i = 0; i < T; i++) {
        t += (char)randNum('a', 'z');
    }
    string p;
    for (int i = 0; i < T; i++)
	{
		if (randNum(1, 100) % 2 == 0)
		{
			p += t[i];
		}
	}
	
    cout << t << endl;
    cout << p << endl;

    return 0;
}

