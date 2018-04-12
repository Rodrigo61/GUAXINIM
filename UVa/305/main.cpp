#include <iostream>

using namespace std;


int main() {
    int k;

    cin >> k;

    while(k != 0){

        int steps;
        for(steps = k; ; ++steps){
            int pos = 0;
            bool found = true;

            for(int j = 0; j < k; ++j){
                pos = (pos + steps) % ((2*k) - j);

                if(pos < k){
                    found = false;
                    break;
                }
            }

            if(found){
                break;
            }

        }
        cout << steps+1 << endl;
        cin >> k;
    }
    return 0;
}



