#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> pow2 = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};

int main() {

    ios::sync_with_stdio(false);
    int lenght;
    cin >> lenght;

    vector<int> vet(lenght);

    int number;
    for (int i = 0; i < lenght; ++i) {
        cin >> number;
        vet[i] = number;
    }
    sort(vet.begin(), vet.end());

    int key;
    int total = 0;
    int pow2_sz = pow2.size();
    int current_number;
    for (int i = lenght-1; i >= 0; --i) {
        current_number = vet[i];
        vet.pop_back();

        for (int j = 0; j < pow2_sz; ++j) {
            key = pow2[j] - current_number;

            if(key > 0){

                auto it = lower_bound(vet.begin(), vet.end(), key);
                while(it != vet.end() && *it == key){
                    total++;
                    it++;
                }
            }
        }
    }

    cout << total << endl;
    return 0;
}