#include <iostream>
#include <vector>
#include <algorithm>
#define LIMITH 5*60*60
using namespace std;

void printTime(int timeSeconds){
    int hour, min, sec;

    hour = (timeSeconds / 3600);
    min = (timeSeconds % 3600)/60;
    sec = ((timeSeconds % 3600)%60);
    string hour_str = "";
    string min_str = "";
    string sec_str = "";

    if(hour < 10){
        hour_str = "0";
    }
    hour_str += to_string(hour);
    if(min < 10){
        min_str = "0";
    }
    min_str += to_string(min);
    if(sec < 10){
        sec_str = "0";
    }
    sec_str += to_string(sec);

    cout << hour_str << ":" << min_str << ":" << sec_str << endl;

}

int main() {


    while(true){
        int cycleArray[102];
        int cycleArraySize = 0;

        cin >> cycleArray[cycleArraySize];
        while(cycleArray[cycleArraySize] != 0){
            ++cycleArraySize;
            cin >> cycleArray[cycleArraySize];
        }

        if(cycleArraySize == 0){
            break; // fim de prog
        }


        vector<int> stateVector(cycleArray, cycleArray+cycleArraySize);

        // indo pra t=0
        auto minCycle = min_element(stateVector.begin(), stateVector.end());
        int minCycleValue = *minCycle;
        for_each(stateVector.begin(), stateVector.end(), [=](int &i){ i-=(minCycleValue-5);});
        *minCycle = 5;


        int timeSeconds;
        for(timeSeconds = minCycleValue-5+1; timeSeconds <= LIMITH; ++timeSeconds){
            bool allGreen = true;
            for_each(stateVector.begin(), stateVector.end(), [&](int &i){
                i-=1;
                if(i == 0){
                    i = cycleArray[(&i) - &(*stateVector.begin())]*2;
                }

                if(i <= 5 || i > cycleArray[(&i) - &(*stateVector.begin())]){
                    allGreen = false;
                }
            });

            if(allGreen){
                break;
            }

        }

        if(timeSeconds <= LIMITH){
            printTime(timeSeconds);
        }else{
            cout << "Signals fail to synchronise in 5 hours" << endl;
        }

    }


    return 0;
}