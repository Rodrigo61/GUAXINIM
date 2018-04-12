#include <iostream>
#include <queue>
#include <stack>

#define UNLOAD_TIME 1
#define LOAD_TIME 1
#define MOVE_TIME 2

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int nCases;
    
    cin >> nCases;

    for (int w = 0; w < nCases; ++w) {
        int country_number;
        int stack_max_size;
        int queue_max_size;
        int queued_cargo_count = 0;

        cin >> country_number >> stack_max_size >> queue_max_size;


        vector<queue<int>> plataform_B_vet(country_number);

        for (int i = 0; i < country_number; ++i) {
            int queued_cargo_in_station;

            cin >> queued_cargo_in_station;
            for (int j = 0; j < queued_cargo_in_station; ++j) {
                int cargo;
                cin >> cargo;

                plataform_B_vet[i].push(cargo-1);
                ++queued_cargo_count;
            }
        }


        stack<int> carrier_cargo;
        int total_time = -1 * MOVE_TIME;
        for(int current_station = 0; (carrier_cargo.size() > 0 || queued_cargo_count > 0); current_station = (++current_station)%country_number){

            total_time += MOVE_TIME;

            //unload
            while(!carrier_cargo.empty()){
                int cargo = carrier_cargo.top();
                if(cargo == current_station){
                    carrier_cargo.pop();
                    total_time += UNLOAD_TIME;
                }else if(plataform_B_vet[current_station].size() < queue_max_size){
                    carrier_cargo.pop();
                    plataform_B_vet[current_station].push(cargo);
                    ++queued_cargo_count;
                    total_time += UNLOAD_TIME;
                }else{
                    break; // cant queue cargo
                }
            }

            //load
            while(!plataform_B_vet[current_station].empty() && carrier_cargo.size() < stack_max_size){
                carrier_cargo.push(plataform_B_vet[current_station].front());
                plataform_B_vet[current_station].pop();
                --queued_cargo_count;
                total_time += LOAD_TIME;
            }

        }

        cout << total_time << endl;
    }
    return 0;
}