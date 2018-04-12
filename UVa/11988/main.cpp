#include <iostream>
#include <list>

using namespace std;

int main() {
    char c;

    while(scanf("%c", &c) != EOF){
        list<char> str;
        list<char> prefix;
        bool appendPrefix = false;

        while(c != '\n'){
            if(c == '['){
                appendPrefix = true;
                str.splice(str.begin(), prefix);
            }else if(c == ']'){
                appendPrefix = false;
                str.splice(str.begin(), prefix);
            }else{
                if(appendPrefix){
                    prefix.push_back(c);
                }else{
                    str.push_back(c);
                }
            }

            scanf("%c", &c);
        }

        str.splice(str.begin(), prefix);

        for(char c: str){
            cout << c;
        }
        cout << endl;

    }

    return 0;
}