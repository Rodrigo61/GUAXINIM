#include <iostream>

using namespace std;

int main() {


    int transform = '1' - '*';
    char c;
    cin.unsetf(cin.skipws);

    while(cin >> c){

        if(c != '\n'){
            c = c - transform;
        }

        cout << c;

    }

    return 0;
}