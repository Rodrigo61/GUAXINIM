#include <iostream>
#define INF 20000000
using namespace std;

int main() {
    int numberPeople, budget, numberHotel, numberWeek;
    int hotelPerPerson, roomSpaceWeek;

    while(scanf("%d %d %d %d", &numberPeople, &budget, &numberHotel, &numberWeek) == 4){

        int lowestPrice = INF;

        for(int i = 0; i < numberHotel; ++i){
            scanf("%d", &hotelPerPerson);

                for(int j = 0; j < numberWeek; ++j){
                    scanf("%d", &roomSpaceWeek);

                    if((roomSpaceWeek >= numberPeople)){
                        if(numberPeople * hotelPerPerson < lowestPrice){
                            lowestPrice = numberPeople * hotelPerPerson;
                        }
                    }

                }

        }

        if(lowestPrice < budget){
            cout << lowestPrice << endl;
        }else{
            cout << "stay home" << endl;
        }
    }

    return 0;
}