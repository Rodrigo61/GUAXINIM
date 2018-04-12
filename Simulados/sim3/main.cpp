
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>


using namespace std;

int main() {

    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    vector<int> vet_index(n);
    vector<vector<int>> vet_list(n);

    for (int i = 0; i < n; ++i) {
        vet_index[i] = i;
        vet_list[i].push_back(i);
    }

    string cmd1;
    string cmd2;
    int num1;
    int num2;

    cin >> cmd1;
    while(cmd1.find("quit") == string::npos){
        cin >> num1 >> cmd2 >> num2;

        if(vet_index[num1] != vet_index[num2]){
            auto &in_v = vet_list[vet_index[num1]];
            auto &out_v = vet_list[vet_index[num2]];
            auto num1_idx = find(in_v.begin(), in_v.end(), num1);
            auto num2_idx = find(out_v.begin(), out_v.end(), num2);

            if(cmd1.find("move") != string::npos){
                if(cmd2.find("onto") != string::npos){
                    out_v.insert(num2_idx+1, num1);
                }else{
                    out_v.push_back(num1);
                }

                in_v.erase(num1_idx);
                vet_index[num1] = vet_index[num2];
            }else{
                if(cmd2.find("onto") != string::npos){
                    out_v.insert(num2_idx+1, num1_idx, in_v.end());
                }else{
                    out_v.insert(out_v.end(), num1_idx, in_v.end());
                }

                for (auto i = num1_idx; i < in_v.end(); ++i) {
                    vet_index[*i] = vet_index[num2];
                }
                in_v.erase(num1_idx, in_v.end());
            }


        }

        cin>> cmd1;
    }

    for (int i = 0; i < n; ++i) {
        cout << i << " :";
        for (int j = 0; j < vet_list[i].size(); ++j) {
            cout << " " << vet_list[i][j];
        }
        cout << endl;
    }



    return 0;
}