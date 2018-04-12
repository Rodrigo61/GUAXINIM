#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int nCases;

    cin >> nCases;

    for(int w = 1; w <= nCases; ++w){

        int row, col;
        int M, N;
        vector<int> regionCount(255);

        cin >> row >> col >> M >> N;

        vector<char> img(row*col);
        for(int i = 0; i < row * col; ++i){
            char region;
            cin >> region;

            img[i] = region;
            ++regionCount[region];
        }

        int maxReg = *max_element(regionCount.begin(), regionCount.end());

        int imgSize = 0;

        for(char i : img){
            if(regionCount[i] == maxReg){
                imgSize += M;
            }else{
                imgSize += N;
            }
        }

        cout << "Case " << w << ": " << imgSize << endl;

    }
    return 0;
}