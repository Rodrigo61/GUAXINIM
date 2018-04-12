#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    long int H, O;

    while(cin.peek()!= EOF){

        cin >> H >> O;

        cout << abs(O - H) << endl;

        cin.get();
    }

    return 0;
}