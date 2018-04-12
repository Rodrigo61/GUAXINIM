#include <iostream>
#include <stack>

using namespace std;

bool low_priority(char c1, char c2){
    int c1_val, c2_val;

    if(c1 == '*' || c1 == '/'){
        c1_val = 2;
    }else if(c1 == '+' || c1 == '-'){
        c1_val = 1;
    }else if(c1 == '('){
        c1_val = 0;
    }else{
        c1_val = 3;
    }

    if(c2 == '*' || c2 == '/'){
        c2_val = 2;
    }else if(c2 == '+' || c2 == '-'){
        c2_val = 1;
    }else if(c2 == '('){
        c2_val = 0;
    }else{
        c2_val = 3;
    }

    return c1_val < c2_val;

}

int main() {
    int nTests;

    scanf("%d\n\n", &nTests);

    for(int w = 0 ; w < nTests; ++w){

        string postfix_exp;
        stack<char> operator_stack;

        char c;
        scanf("%c", &c);
        while(c != '\n'){

            char space;
            scanf("%c", &space);

            if(isdigit(c)){
                postfix_exp += c;
            }else{
                if(!operator_stack.empty() && !low_priority(operator_stack.top(), c)){

                    if(c != '('){
                        do{
                            char top_operator = operator_stack.top();



                            operator_stack.pop();

                            if(top_operator == ')'){
                                top_operator = operator_stack.top();
                                operator_stack.pop();

                                while(top_operator != '('){
                                    postfix_exp += top_operator;
                                    top_operator = operator_stack.top();
                                    operator_stack.pop();
                                }
                            }else{
                                postfix_exp += top_operator;
                            }

                        }while(!operator_stack.empty() && !low_priority(operator_stack.top(), c));
                    }
                }


                operator_stack.push(c);

            }

            if(scanf("%c", &c) == EOF){
                break;
            }

        }

        while(!operator_stack.empty()){
            char top_operator = operator_stack.top();
            operator_stack.pop();

            if(top_operator == ')'){
                top_operator = operator_stack.top();
                operator_stack.pop();

                while(top_operator != '('){
                    postfix_exp += top_operator;
                    top_operator = operator_stack.top();
                    operator_stack.pop();
                }
            }else{
                postfix_exp += top_operator;
            }
        }

        printf("%s\n", postfix_exp.c_str());
        if(w != nTests-1)
            printf("\n");
    }
    return 0;
}