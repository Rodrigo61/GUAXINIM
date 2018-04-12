#include <iostream>
#include <regex>

using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    string line;

    getline(cin, line);

    while(!line.empty()){

        regex reg("[[:s:]]");
        sregex_token_iterator token_it(line.begin(), line.end(), reg, -1);

        stack<int> toys_stack;
        stack<int> size_nested_stack;

        auto end_it = sregex_token_iterator();
        bool is_nestead = true;
        while(token_it != end_it){
            int num = stoi(*token_it);

            if(num < 0){
                toys_stack.push(num);
                size_nested_stack.push(num);
            }else{
                if(toys_stack.empty() || num != abs(toys_stack.top())){
                    is_nestead = false;
                    break;
                }else{

                    size_nested_stack.pop();
                    toys_stack.pop();

                    if(!toys_stack.empty()){
                        int &top = size_nested_stack.top();
                        top += num;

                        if(top >= 0){
                            is_nestead = false;
                            break;
                        }
                    }


                }

            }


            ++token_it;
        }


        if(!toys_stack.empty()){
            is_nestead = false;
        }

        if(is_nestead){
            cout << ":-) Matrioshka!" << endl;
        }else{
            cout << ":-( Try again." << endl;
        }

        getline(cin, line);
    }


    return 0;
}