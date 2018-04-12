#include <iostream>
#include <cstring>

using namespace std;

int convertToInt(char c){
    if(c >= 0){
        return c;
    }
    return (abs(c) + 127);
}

void printPaid(int paid){
    int cents = paid % 100;
    int dollar = (paid - cents)/100;

    string cents_str ="";

    if(cents < 10){
        cents_str = "0";
    }

    cents_str += to_string(cents);

    cout << dollar << "." << cents_str << "$" << endl;

}

int main() {
    int nCases;


    scanf("%d\n", &nCases);

    for(int w = 0; w < nCases; ++w){
        int paid = 0;
        int valueMatrix[257];
        memset(valueMatrix, 0, sizeof(int)*257);


        int cCount;
        scanf("%d\n", &cCount);

        for(int i = 0; i < cCount; ++i){
            char c;
            int cValue;
            scanf("%c %d\n", &c, &cValue);

            valueMatrix[convertToInt(c)] = cValue;
        }

        int linesCount;
        scanf("%d\n", &linesCount);

        char charRead;
        scanf("%c", &charRead);
        while(linesCount > 0){
            paid += valueMatrix[convertToInt(charRead)];
            if(charRead == '\n'){
                --linesCount;
                if(linesCount == 0){
                    break;
                }
            }
            scanf("%c", &charRead);

        }
        printPaid(paid);


    }


    return 0;
}