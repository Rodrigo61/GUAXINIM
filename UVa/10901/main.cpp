#include <iostream>
#include <queue>

#define LEFT true
#define RIGHT false
using namespace std;

int main() {
    int nCases;

    cin >> nCases;

    for (int w = 0; w < nCases; ++w) {
        int max_car;
        int travel_time;
        int m;

        cin >> max_car >> travel_time >> m;

        vector<int> car_reach_time_vet(m);
        queue<int> left_queue;
        queue<int> right_queue;

        for (int i = 0; i < m; ++i) {
            int time;
            string side;
            cin >> time >> side;

            car_reach_time_vet[i] = time;
            if(side == "left"){
                left_queue.push(i);
            }else{
                right_queue.push(i);
            }
        }


        bool where_is_ferry = LEFT;
        queue<int> ferry_queue;
        int current_time = 0;
        while(!left_queue.empty() || !right_queue.empty()){

            //unload
            while(!ferry_queue.empty()){
                int car_id = ferry_queue.front();
                ferry_queue.pop();

                car_reach_time_vet[car_id] = current_time;

            }

            int next_car_arrive_bank;
            bool next_car_arrive_side;
            if(right_queue.empty()){
                next_car_arrive_bank = car_reach_time_vet[left_queue.front()];
                next_car_arrive_side = LEFT;
            }else if(left_queue.empty()){
                next_car_arrive_bank = car_reach_time_vet[right_queue.front()];
                next_car_arrive_side = RIGHT;
            }else{
                if(where_is_ferry == LEFT && current_time >= car_reach_time_vet[left_queue.front()]){
                    next_car_arrive_bank = current_time;
                    next_car_arrive_side = LEFT;
                }else if(where_is_ferry == RIGHT && current_time >= car_reach_time_vet[right_queue.front()]){
                    next_car_arrive_bank = current_time;
                    next_car_arrive_side = RIGHT;
                }else{
                    if(car_reach_time_vet[left_queue.front()] < car_reach_time_vet[right_queue.front()]){
                        next_car_arrive_bank = car_reach_time_vet[left_queue.front()];
                        next_car_arrive_side = LEFT;
                    }else if(car_reach_time_vet[left_queue.front()] > car_reach_time_vet[right_queue.front()]){
                        next_car_arrive_bank = car_reach_time_vet[right_queue.front()];
                        next_car_arrive_side = RIGHT;
                    }else{
                        next_car_arrive_bank = car_reach_time_vet[right_queue.front()];
                        next_car_arrive_side = where_is_ferry;
                    }
                }

            }


            if(next_car_arrive_bank > current_time){
                current_time = next_car_arrive_bank;
            }


            if(where_is_ferry != next_car_arrive_side){
                where_is_ferry = next_car_arrive_side;
                current_time += travel_time;
            }

            //load
            if(where_is_ferry == LEFT){
                if(car_reach_time_vet[left_queue.front()] <= current_time){

                    do{
                        ferry_queue.push(left_queue.front());
                        left_queue.pop();
                    }while(!left_queue.empty() && car_reach_time_vet[left_queue.front()] <= current_time && ferry_queue.size() < max_car);

                    current_time += travel_time;
                    where_is_ferry = RIGHT;
                }
            }else{
                if(car_reach_time_vet[right_queue.front()] <= current_time){

                    do{
                        ferry_queue.push(right_queue.front());
                        right_queue.pop();
                    }while(!right_queue.empty() && car_reach_time_vet[right_queue.front()] <= current_time && ferry_queue.size() < max_car);
                }

                current_time += travel_time;
                where_is_ferry = LEFT;
            }


        }


        //unload
        while(!ferry_queue.empty()){
            int car_id = ferry_queue.front();
            ferry_queue.pop();

            car_reach_time_vet[car_id] = current_time;

        }

        for(int time : car_reach_time_vet){
            cout << time << endl;
        }
        if(w != nCases-1)
            cout << endl;
    }
    return 0;
}