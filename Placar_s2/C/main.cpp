#include <iostream>

using namespace std;

int main() {

    int N;

    while(cin >> N, N != -1){

        int acu = 0;
        int fee;
        int visit_count = 0;
        for(int i = 0; i < N; ++i){
            cin >> fee;

            acu += fee;

            if(acu % 100 == 0){
                acu = 0;
                ++visit_count;
            }
        };

        cout << visit_count << endl;

    }
    return 0;
}