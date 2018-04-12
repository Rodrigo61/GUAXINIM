#include <iostream>
#include <set>
#include <list>
using namespace std;

int main() {
    int nCases;

    cin >> nCases;

    for(int w = 0; w < nCases; ++w){
        multiset<int> greenArmy;
        multiset<int> blueArmy;

        int bfCount, gSize, bSize;

        cin >> bfCount >> gSize >> bSize;

        for(int i = 0; i < gSize; ++i){
            int power;
            cin >> power;
            greenArmy.insert(power);
        }

        for(int i = 0; i < bSize; ++i){
            int power;
            cin >> power;
            blueArmy.insert(power);
        }


        while(greenArmy.size() > 0 && blueArmy.size() > 0){

            int greenArmySize = greenArmy.size();
            int blueArmySize = blueArmy.size();

            list<int> backSoldierGreen;
            list<int> backSoldierBlue;

            for(int i = 1; i <= bfCount; ++i){

                if(greenArmySize < i || blueArmySize < i){
                    break; // sem exercito pra esse campo
                }

                auto soldierGreen = prev(greenArmy.end(), 1);
                auto soldierBlue = prev(blueArmy.end(), 1);

                int weaker = min(*soldierGreen, *soldierBlue);

                int soldierGreenPow = *soldierGreen - weaker;
                int soldierBluePow = *soldierBlue - weaker;

                greenArmy.erase(soldierGreen);
                blueArmy.erase(soldierBlue);

                if(soldierGreenPow > 0){
                    backSoldierGreen.push_back(soldierGreenPow);
                }

                if(soldierBluePow > 0){
                    backSoldierBlue.push_back(soldierBluePow);
                }

            }

            greenArmy.insert(backSoldierGreen.begin(), backSoldierGreen.end());
            blueArmy.insert(backSoldierBlue.begin(), backSoldierBlue.end());
        }

        if(greenArmy.size() == blueArmy.size()){
            cout << "green and blue died" << endl;
        }else if(greenArmy.size() == 0){
            cout << "blue wins" << endl;
            for(auto it = (--blueArmy.end()); ; --it){
                cout << *it << endl;
                if(it == blueArmy.begin()){
                    break;
                }
            }
        }else {
            cout << "green wins" << endl;
            for (auto it = (--greenArmy.end()); ; --it) {
                cout << *it << endl;
                if(it == greenArmy.begin()){
                    break;
                }
            }
        }

        if(w != nCases-1)
        cout << endl;
    }


    return 0;
}