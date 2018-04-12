#include <iostream>
#include <vector>
#include <list>

using namespace std;


int ctoidx(char c){
    return c - 'A';
}


class area{
public:
    vector<area*> vet_neighbors;
    bool sleeping;
    char data;

    area(){
        sleeping = false;
        vet_neighbors.resize(26);
    }

    void set_neighbor(char data, area *neighbor){
        vet_neighbors[ctoidx(data)] = neighbor;
    }

    bool will_wake(){
        int waked_neighbor = 0;
        for(auto it: vet_neighbors){
            if(it){
                if(!it->sleeping){
                    ++waked_neighbor;
                    if(waked_neighbor == 3){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};



int main() {

    ios::sync_with_stdio(false);

    bool end_program = false;
    while(!end_program){

        int n_slept_area;
        cin >> n_slept_area;

        int n_connections;
        cin >> n_connections;

        vector<area> vet_area(26);
        for (int i = 0; i < 26; ++i) {
            vet_area[i].data = i+'A';
        }

        char waked_id_1, waked_id_2, waked_id_3;
        cin >> waked_id_1 >> waked_id_2 >> waked_id_3;

        string known_area = "";
        for (int i = 0; i < n_connections; ++i) {
            char area_id_1, area_id_2;
            cin >> area_id_1 >> area_id_2;

            if(known_area.find(area_id_1) == string::npos){
                known_area += area_id_1;
            }
            if(known_area.find(area_id_2) == string::npos){
                known_area += area_id_2;
            }

            vet_area[ctoidx(area_id_1)].set_neighbor(area_id_2, &vet_area[ctoidx(area_id_2)]);
            vet_area[ctoidx(area_id_2)].set_neighbor(area_id_1, &vet_area[ctoidx(area_id_1)]);
            vet_area[ctoidx(area_id_1)].sleeping = true;
            vet_area[ctoidx(area_id_2)].sleeping = true;

        }

        //wake the three first
        vet_area[ctoidx(waked_id_1)].sleeping = false;
        if(known_area.find(waked_id_1) == string::npos){
            known_area += waked_id_1;
        }
        vet_area[ctoidx(waked_id_2)].sleeping = false;
        if(known_area.find(waked_id_2) == string::npos){
            known_area += waked_id_2;
        }
        vet_area[ctoidx(waked_id_3)].sleeping = false;
        if(known_area.find(waked_id_3) == string::npos){
            known_area += waked_id_3;
        }

        if(known_area.size() != n_slept_area){
            cout << "THIS BRAIN NEVER WAKES UP" << endl;
        }else{
            bool all_waked = true;
            for (int i = 0; i < 26; ++i) {
                if (vet_area[i].sleeping) {
                    all_waked = false;
                }
            }

            int current_time = 0;
            while(!all_waked){
                list<int> waked_in_row_idx;
                all_waked = true;
                bool some_area_waked = false;
                for (int i = 0; i < 26; ++i) {
                    if(vet_area[i].sleeping){
                        if(vet_area[i].will_wake()){
                            waked_in_row_idx.push_back(i);
                            some_area_waked = true;
                        }else{
                            all_waked = false;
                        }
                    }
                }
                ++current_time;

                for(auto idx : waked_in_row_idx){
                    vet_area[idx].sleeping = false;
                }

                if(!some_area_waked){
                    cout << "THIS BRAIN NEVER WAKES UP" << endl;
                    goto END_TEST;
                }
            }

            cout << "WAKE UP IN, " << current_time << ", YEARS" << endl;
        }


        END_TEST:
        cin.get();
        if(cin.peek() == EOF){
            end_program = true;
        }else{
            cin.get();
        }

    }


    return 0;
}