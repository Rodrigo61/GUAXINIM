#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    int p_number = 0;
    int c_number;
    int diff;

    next_input:
    while(cin >> n){

        vector<bool> found_values(n);

        cin >> p_number;

        if(n > 1){

            for(int i = 1; i < n; ++i){
                cin >> c_number;
                diff = abs(c_number - p_number);
                found_values[diff] = true;
                p_number = c_number;
            }


            for(int i = 1; i < n; ++i){
                if(found_values[i] == false){
                    cout << "Not jolly" << endl;
                    goto next_input;
                }
            }

            cout << "Jolly" << endl;

        }else {
            cout << "Jolly" << endl;
        }

    }

    return 0;
}