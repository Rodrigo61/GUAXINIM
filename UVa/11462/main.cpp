#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int nSize;

    cin >> nSize;
    while(nSize != 0){

        vector<int> vet(nSize);
        for(int i = 0; i < nSize; ++i){
             cin >> vet[i];
        }

        sort(vet.begin(), vet.end());

        for(int i = 0; i < nSize; ++i){

            cout << vet[i];

            if(i != nSize-1){
                cout << " ";
            }

        }
        cout << endl;

        cin >> nSize;
    }

    return 0;
}