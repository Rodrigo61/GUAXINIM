#include <iostream>
#include <list>
using namespace std;

int cardValue(string card){
    if(string("23456789").find(card[0]) != string::npos){
        return card[0] - '0';
    }

    return 10;
}
int main()
{
    int caseNumber;

    scanf("%d", &caseNumber);

    for(int w = 0; w < caseNumber; ++w){

        list<string> firstPart, secondPart;
        for(int i = 0; i < 27; ++i){
            string card;
            cin >> card;
            firstPart.push_back(card);
        }

        for(int i = 0; i < 25; ++i){
            string card;
            cin >> card;
            secondPart.push_back(card);
        }

        int Y = 0;
        for(int i = 0; i < 3; ++i){
            int X = cardValue(firstPart.back());
            firstPart.pop_back();
            Y += X;

            for(int j = 0; j < 10 - X; ++j){
                firstPart.pop_back();
            }
        }

        firstPart.splice(firstPart.end(), secondPart);

        cout << "Case " << w+1 << ": " << *(next(firstPart.begin(), Y-1)) << endl;

    }
    return 0;
}