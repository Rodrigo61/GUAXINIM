#include <iostream>

using namespace std;

int main() {
    int numberCase;

    scanf("%d", &numberCase);

    for(int i = 1; i <= numberCase; ++i) {
        char c;
        int max = -1, velocity;

        do{
            scanf("%d%c", &velocity, &c);
            if (velocity > max) {
                max = velocity;
            }

        }while(c != '\n');


        printf("Case %d: %d\n", i, max);
    }

    return 0;
}