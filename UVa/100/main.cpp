#include <iostream>

using namespace std;

int get_cycle(int i){
    int current_cycle = 1;

    while(i != 1){
        i = i%2==0? (i/2):(3*i + 1);
        ++current_cycle;
    }

    return current_cycle;
}

int main() {
    int num_1, num_2;

    while(scanf("%d%d", &num_1, &num_2) != EOF){
        int max_num = max(num_1, num_2);
        int min_num = min(num_1, num_2);

        int max_cycle = 0;

        for (int i = min_num; i <= max_num; ++i) {
            int cycle = get_cycle(i);

            max_cycle = max(max_cycle, cycle);
        }

        printf("%d %d %d\n", num_1, num_2, max_cycle);


    }
    return 0;
}