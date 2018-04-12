#include <iostream>
#include <vector>

using namespace std;

void addNeighbors(vector<vector<int>> &board, int y, int x){
    int xOffsetBeg = x-1 >= 0 ? x-1:0;
    int xOffsetEnd = x+1 < board[0].size() ? x+1:x;
    int yOffsetBeg = y-1 >= 0 ? y-1:0;
    int yOffsetEnd = y+1 < board.size() ? y+1:y;

    for(int i = yOffsetBeg; i <= yOffsetEnd; ++i){
        for(int j = xOffsetBeg; j <= xOffsetEnd; ++j){
            if(board[i][j] != -1){
                ++board[i][j];
            }
        }
    }

}

int main() {
    int lin, col;
    int caseNumber = 1;

    cin >> lin >> col;
    while(col != 0 || lin != 0){
        vector<vector<int>> board(lin);
        for(int i =0; i < board.size(); ++i){
            board[i].resize(col);
        }

        char field;
        for(int i = 0; i < lin; ++i){
            for(int j = 0; j < col; ++j){
                cin >> field;
                if(field == '*'){
                    board[i][j] = -1;
                    addNeighbors(board, i, j);
                }
            }
        }


        printf("Field #%d:\n", caseNumber);
        for(int i = 0; i < lin; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == -1){
                    cout << "*";
                }else{
                    cout << board[i][j];
                }
            }
            cout << endl;
        }

        ++caseNumber;
        cin >> lin >> col;
        if(col != 0 || lin != 0){
            cout << endl;
        }

    }

    return 0;
}