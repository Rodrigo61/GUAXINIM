#include <iostream>

using namespace std;

int main() {

    int acu;
    for(int i = 0; i < 101; ++i){
        acu = i;
        for(int j = 0; j < 101; ++j){

            if(j <= i){
                cout << 0;
            } else{
                if(j%2 != 0){
                    acu += j;
                }
                cout << acu;
            }

            if(j != 100 || i != 100){
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}