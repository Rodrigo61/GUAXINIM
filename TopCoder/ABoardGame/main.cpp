#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ABoardGame{
public:

    string whoWins(vector<string> board){
        int Ndimension = board.size()/2;
        vector<int> regionPointsBob(Ndimension);
        vector<int> regionPointsAlice(Ndimension);
        int currentRegion;

        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board.size(); ++j){

                if(board[i][j] != '.'){

                    currentRegion = 1;
                    while(true){
                        if((i >= Ndimension-currentRegion && i <= Ndimension+currentRegion-1)
                         &&(j >= Ndimension-currentRegion && j <= Ndimension+currentRegion-1)){

                            if(board[i][j] == 'B'){
                                ++regionPointsBob[currentRegion-1];
                            }else{
                                ++regionPointsAlice[currentRegion-1];
                            }

                            break;
                        }

                        ++currentRegion;
                    }
                }
            }
        }

        for(int i = 0; i < Ndimension; ++i){
            if(regionPointsBob[i] > regionPointsAlice[i]){
                return "Bob";
            }
            if(regionPointsBob[i] < regionPointsAlice[i]){
                return "Alice";
            }
        }

        return "Draw";
    }
};

int main() {
    ABoardGame cls;
    vector<string> arg = {"AAAA", "A.BA", "A..A", "AAAA"};

    cout << cls.whoWins(arg) << endl;
    return 0;
}