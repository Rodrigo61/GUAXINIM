#include <iostream>
#include <map>

using namespace std;

int main() {

    int party_number;
    int guess_number;

    map<string, int> map_party;

    scanf("%d%d", &party_number, &guess_number);

    for (int i = 0; i < party_number; ++i) {
        char party_name[21];
        double party_percent_double;

        scanf("%s %lf", party_name, &party_percent_double);

        map_party[party_name] = int(party_percent_double * 10);

    }


    for (int i = 0; i < guess_number; ++i) {
        int percent_total = 0;
        bool guess = false;

        while(true){
            string party_name;
            string operator_char;
            cin >> party_name >> operator_char;

            percent_total += map_party[party_name];

            if(operator_char != "+"){
                int guess_percent;
                cin >> guess_percent;

                guess_percent *= 10;

                if(operator_char == "<"  &&  percent_total < guess_percent ){
                    guess = true;
                }else if(operator_char == "<=" && percent_total <= guess_percent){
                    guess = true;
                }else if(operator_char == ">" && percent_total > guess_percent){
                    guess = true;
                }else if(operator_char == ">=" && percent_total >= guess_percent){
                    guess = true;
                }else if(operator_char == "=" && percent_total == guess_percent){
                    guess = true;
                }

                break;
            }
        }

        if(guess){
            printf("Guess #%d was correct.\n", i+1);
        }else{
            printf("Guess #%d was incorrect.\n", i+1);
        }
    }

    return 0;
}