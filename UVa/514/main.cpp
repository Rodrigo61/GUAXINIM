#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int couches_count;

    cin >> couches_count;

    while(couches_count != 0){

        vector<int> vet_couche_backup(couches_count);
        for (int i = 0, j = couches_count; i < couches_count; ++i, j--) {
            vet_couche_backup[i] = j;
        }


        while(true){

            vector<int> vet_couche;
            vet_couche = vet_couche_backup;

            vector<int> vet_reorganized(couches_count);
            for (int i = 0; i < couches_count; ++i
                    ) {
                cin >> vet_reorganized[i];
                if(vet_reorganized[i] == 0){
                    goto END_PERMUTATION;
                }
            }

            stack<int> rail_station;
            int reorganized_index = 0;
            while(reorganized_index != couches_count-1){

                if(rail_station.size() > 0 && rail_station.top() == vet_reorganized[reorganized_index]){

                    rail_station.pop();
                    ++reorganized_index;
                }else if(vet_couche.size() > 0){

                    while(vet_couche[vet_couche.size()-1] != vet_reorganized[reorganized_index]){
                        rail_station.push(vet_couche.back());
                        vet_couche.pop_back();
                        if(vet_couche.size() == 0){
                            break;
                        }
                    }

                    if(vet_couche[vet_couche.size()-1] == vet_reorganized[reorganized_index]){
                        rail_station.push(vet_couche.back());
                        vet_couche.pop_back();
                    }
                }else{
                    break;
                }

            }

            if(reorganized_index+1 == couches_count){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }

        }

        END_PERMUTATION:
        cout << endl;
        cin >> couches_count;
    }


    return 0;
}