#include <string>
#include <iostream>
#include <map>
#include <regex>

using namespace std;

int main() {
    int nLines;
    map<string, int> mCountryLover;
    string country;

    scanf("%d\n", &nLines);

    for(int i = 0; i < nLines; ++i){
        getline(cin, country);

        regex reg("[[:s:]]");
        sregex_token_iterator iterator(country.cbegin(), country.cend(), reg, {-1});

        ++mCountryLover[*iterator];
    }

    for(auto it : mCountryLover){
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}