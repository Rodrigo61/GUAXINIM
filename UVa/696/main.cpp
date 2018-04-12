#include <iostream>

using namespace std;

int f(int x)
{
    if(x == 1) return 2;
    if(x == 2 || x == 3) return 4;
    return 0;
}

int main() {
    int line, column;

    cin >> line >> column;
    while(line != 0 || column != 0){
        int result;
        int maxNumber = max(line, column);
        int minNumber= min(line, column);

        if(minNumber == 1){
            result = maxNumber * minNumber;
        }else if(minNumber == 2){
            if(maxNumber <= 3){
                result = 4;
            }else{
                /*Sao feitos grupos em quadrados 2x2 preenchidos*/
                result = (maxNumber*minNumber)/2;
                result = int(result/4) * 4 + f(result%4);
            }
        }else{
            result = (((line*column)+1)/2);
        }

        printf("%d knights may be placed on a %d row %d column board.\n", result, line, column);

        cin >> line >> column;
    }

    return 0;
}