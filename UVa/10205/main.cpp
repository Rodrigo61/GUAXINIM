#include <iostream>
#include <vector>
using namespace std;

string get_card_value(int rawValue){
    switch(rawValue){
        case 11:{
            return "Jack";
        }
        case 12:{
            return "Queen";
        }
        case 13:{
            return "King";
        }
        case 14:{
            return "Ace";
        }
    }

    return to_string(rawValue);
}

void doSuffle(vector<string>& deck, vector<int> suffle){
    vector<string> newDeck;

    for(int i = 0; i < 52; ++i){
        newDeck.push_back(deck[suffle[i] - 1]);
    }

    swap(deck, newDeck);
}

int main() {
    int numberCases;
    int suffleNumber;
    string suffleTypeUsed;

    cin >> numberCases;
    scanf(" ");

    for(int w = 0; w < numberCases; ++w){
        vector<string> deck(52);

        //init deck
        for(int j = 0; j< 13; ++j){
            deck[j] = get_card_value(j+2) + " of Clubs";
        }
        for(int j = 13; j< 26; ++j){
            deck[j] = get_card_value(j-11) + " of Diamonds";
        }
        for(int j = 26; j< 39; ++j){
            deck[j] = get_card_value(j-24) + " of Hearts";
        }
        for(int j = 39; j< 52; ++j){
            deck[j] = get_card_value(j-37) + " of Spades";
        }

        //read suffles
        cin >> suffleNumber;
        vector<vector<int>> knowSuffle(suffleNumber);
        for(int j = 0; j < suffleNumber; ++j){
            knowSuffle[j].reserve(52);
            for(int k = 0; k < 52; ++k){
                int value;
                cin >> value;
                knowSuffle[j].push_back(value);
            }
        }

        getline(cin, suffleTypeUsed);
        getline(cin, suffleTypeUsed);
        while(suffleTypeUsed != ""){
            doSuffle(deck, knowSuffle[stoi(suffleTypeUsed)-1]);
            getline(cin, suffleTypeUsed);
        }

        for(int i = 0; i < 52; ++i){
            cout << deck[i] << endl;
        }

        if(w != numberCases-1){
            cout << endl;
        }

    }
    return 0;
}