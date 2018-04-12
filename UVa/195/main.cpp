#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool compChar(char a, char b);

bool compStr(string a, string b){

    for(int i = 0; i < a.size(); ++i){
        if(compChar(a[i], b[i])){
            return true;
        }else if (compChar(b[i], a[i])){
            return false;
        }
    }

    return false;


}

bool compChar(char a, char b){

    if(toupper(a) == toupper(b)){
        return a < b;
    }

    a = toupper(a);
    b = toupper(b);

    return a < b;
}

int main() {
    int nCases;


    cin >> nCases;

    for(int w = 0; w < nCases; ++w){
        string word;
        set<string, bool(*)(string a, string b)> anagrams(&compStr);

        cin >> word;

        sort(word.begin(), word.end(), &compChar);

        do{
            anagrams.insert(word);
        }while(next_permutation(word.begin(), word.end(), &compChar));


        for(string s : anagrams){
            cout << s << endl;
        }


    }

    return 0;
}