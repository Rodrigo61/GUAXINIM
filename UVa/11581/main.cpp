#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void transformGrid(vector<vector<int>> &grid){
    vector<vector<int>> originalGrid(grid.begin(), grid.end());

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            int sum = 0;
            if(i-1 >= 0)
                sum += originalGrid[i-1][j];
            if(i+1 < 3)
                sum += originalGrid[i+1][j];
            if(j-1 >= 0)
                sum += originalGrid[i][j-1];
            if(j+1 < 3)
                sum += originalGrid[i][j+1];

            grid[i][j] = sum % 2;
        }
    }
}

int main() {
    int nCases;

    cin >>  nCases;
    for(int w = 0; w < nCases; ++w){
        scanf("\n");

        vector<vector<int>> grid(3);
        for(int i = 0; i < 3; ++i){
            grid[i].resize(3);
            for(int j = 0; j < 3; ++j){
                char c;
                cin >> c;
                grid[i][j] = c-'0';
            }
        }

        int index = -1;

        vector<vector<int>> prevGrid(grid.begin(), grid.end());
        transformGrid(grid);
        while(!equal(grid.begin(), grid.end(), prevGrid.begin())){
            ++index;
            prevGrid = grid;
            transformGrid(grid);
        }

        cout << index << endl;

    }
    return 0;
}