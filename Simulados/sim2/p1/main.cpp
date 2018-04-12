#include <iostream>

using namespace std;

int main() {
    int maximum = 0;
    int current_lenght = 0;
    long int prev = -1;

    int array_size;
    cin >> array_size;

    if(array_size == 1){
        cout << 1 << endl;
        }else{

        for (int i = 0; i < array_size; ++i) {
            int current_number;
            cin >> current_number;
            if(current_number > prev){
                ++current_lenght;
            }else{
                maximum = max(maximum, current_lenght);
                current_lenght = 1;
            }

            prev = current_number;
        }

        maximum = max(maximum, current_lenght);
        cout << maximum << endl;
    }


    return 0;
}