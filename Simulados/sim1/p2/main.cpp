#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n_cases;

    cin >> n_cases;
    bool spider_last_loser = true;
    for (int w = 0; w < n_cases; ++w) {
        int new_cycle;
        cin >> new_cycle;

        if(new_cycle % 2 == 0){
            spider_last_loser = !spider_last_loser;
        }

        if(spider_last_loser){
            cout << "2" << endl;
        }else{
            cout << "1" << endl;
        }

    }
    return 0;
}