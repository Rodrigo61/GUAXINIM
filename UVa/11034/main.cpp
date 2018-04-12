#include <iostream>
#include <queue>

#define LEFT true
#define RIGHT false

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int nCases;

    cin >> nCases;

    for (int w = 0; w < nCases; ++w) {
        int ferry_size;
        int car_count;

        cin >> ferry_size >> car_count;
        ferry_size *= 100;


        queue<int> left_bank_queue;
        queue<int> right_bank_queue;
        vector<int> car_size_vet(car_count);

        for (int i = 0; i < car_count; ++i) {
            int car_size;
            string side;
            cin >> car_size >> side;

            car_size_vet[i] = car_size;

            if(side == "left"){
                left_bank_queue.push(i);
            }else{
                right_bank_queue.push(i);
            }
        }

        bool where_is_ferry = LEFT;
        int travel_count = 0;
        while(!left_bank_queue.empty() || !right_bank_queue.empty()){

            if(where_is_ferry == LEFT){

                if(left_bank_queue.empty()){
                    ++travel_count;
                    where_is_ferry = RIGHT;
                }else{
                    int used_ferry_size = 0;

                    do{
                        int car_size = car_size_vet[left_bank_queue.front()];

                        if(used_ferry_size+car_size <= ferry_size){
                            used_ferry_size += car_size;
                            left_bank_queue.pop();
                        }else{
                            break;
                        }


                    }while(!left_bank_queue.empty());

                    ++travel_count;
                    where_is_ferry = RIGHT;
                }

            }else{

                if(right_bank_queue.empty()){
                    ++travel_count;
                    where_is_ferry = LEFT;
                }else{
                    int used_ferry_size = 0;

                    do{
                        int car_size = car_size_vet[right_bank_queue.front()];

                        if(used_ferry_size+car_size <= ferry_size){
                            used_ferry_size += car_size;
                            right_bank_queue.pop();
                        }else{
                            break;
                        }


                    }while(!right_bank_queue.empty());

                    ++travel_count;
                    where_is_ferry = LEFT;
                }
            }
        }


        cout << travel_count << endl;
    }
    return 0;
}