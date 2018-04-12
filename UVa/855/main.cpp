#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int nCases;

    cin >> nCases;

    for(int w = 0; w < nCases; ++w){
        int street, avenue, friends;

        cin >> street >> avenue >> friends;

        int maxX = 0,  minX = 9999999, maxY = 0, minY = 999999;
        vector<pair<int, int>> friendsHome(friends);
        for(int i = 0; i < friends; ++i){
            int st, av;
            cin >> st >> av;

            maxX = max(maxX, st);
            minX = min(minX, st);
            maxY = max(maxY, av);
            minY = min(minY, av);
            
            friendsHome[i] = make_pair(st-1, av-1);
        }


        int minPath = 999999999;
        int stPoint = 0, avPoint = 0;

        int maxI = 50;
        int maxJ = 50;

        auto median = make_pair(((maxX + minX) / 2), ((maxY + minY) / 2));

        int i = median.first - maxI >= 0 ? median.first - maxI:0;
        int iLimit = median.first + maxI < street ? median.first + maxI:street-1;

        for(; i <= iLimit; ++i){

            int j = median.second - maxJ >= 0 ? median.second - maxJ:0;
            int jLimit = median.second + maxJ < avenue ? median.second + maxJ:avenue-1;
            for(; j <= jLimit; ++j){

                int currentPointDistance = 0;
                for(int k = 0; k < friends; ++k){
                    int personDistance = 0;
                    auto person = friendsHome[k];


                    personDistance += abs(i - person.first);
                    personDistance += abs(j - person.second);

                    currentPointDistance += personDistance;

                    if(currentPointDistance > minPath){
                        break;
                    }
                }

                if(currentPointDistance < minPath){
                    minPath = currentPointDistance;
                    stPoint = i;
                    avPoint = j;
                }
            }

        }

        printf("(Street: %d, Avenue: %d)\n", stPoint+1, avPoint+1);

    }
    return 0;
}