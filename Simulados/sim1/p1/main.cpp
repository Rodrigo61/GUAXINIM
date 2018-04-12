#include <iostream>

using namespace std;

int main() {
    int n;

    string hate = "I hate ";
    string love = "I love ";
    string that = "that ";

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        if(i % 2 != 0){
            cout << hate;
        }else{
            cout << love;
        }

        if(i != n){
            cout << that;
        }else{
            cout << "it";
        }
    }

    cout << flush;


    return 0;
}