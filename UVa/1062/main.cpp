#include <iostream>
#include <list>

using namespace std;

int main() {

    char letter;
    bool new_stack;
    int caso = 1;

    scanf("%c", &letter);

    while(letter != 'e'){

        list<char> stacks;
        do{
            new_stack = true;
            for(list<char>::iterator it = stacks.begin(); it != stacks.end(); ++it){
                if(*it >= letter){
                    *it = letter;
                    new_stack = false;
                    break;
                }
            }

            if(new_stack){
                stacks.push_back(letter);
            }

            scanf("%c", &letter);
        }while(letter != '\n');

        cout << "Case " << caso << ": " << stacks.size() << endl;
        scanf("%c", &letter);
        ++caso;
    }
    return 0;
}