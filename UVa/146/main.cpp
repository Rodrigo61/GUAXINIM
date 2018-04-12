#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string code;

    cin >> code;

    while(code.find("#") == string::npos){
        if(next_permutation(code.begin(), code.end())){
            cout << code << endl;
        }else{
            cout << "No Successor" << endl;
        }

        cin >> code;
    }

    return 0;
}