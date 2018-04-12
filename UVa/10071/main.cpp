#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int v, t;

    while(cin >> v >> t){
        cout << v*t*2 << endl;
    }

    return 0;
}