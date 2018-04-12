#include <iostream>

using namespace std;

int main() {
    int well_height;
    int climb_distance;
    int slide_distance;
    int fatigue_factor;

    cin >> well_height >> climb_distance >> slide_distance >> fatigue_factor;


    while(well_height != 0){
        int current_height = 0;
        int current_day = 0;

        well_height *= 100;
        climb_distance *= 100;
        slide_distance *= 100;
        int fatigue_discount = (climb_distance * fatigue_factor)/100;

        bool on_middle = true;
        while(on_middle){

            ++current_day;

            current_height += climb_distance;
            climb_distance -= fatigue_discount;
            if(climb_distance < 0){
                climb_distance = 0;
            }

            if(current_height > well_height){
                cout << "success on day " << current_day << endl;
                on_middle = false;
            }else{
                current_height -= slide_distance;

                if(current_height < 0){
                    cout << "failure on day " << current_day << endl;
                    on_middle = false;
                }

            }

        }

        cin >> well_height >> climb_distance >> slide_distance >> fatigue_factor;
    }

    return 0;
}