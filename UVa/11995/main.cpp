#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int data_struct_size;

    while(scanf("%d", &data_struct_size) != EOF){
        stack<int> st;
        queue<int> qu;
        priority_queue<int> pr;

        int is_stack = 1;
        int is_queue = 1;
        int is_priority_queue = 1;

        for (int i = 0; i < data_struct_size; ++i) {
            int cmd, value;
            scanf("%d%d", &cmd, &value);

            if(cmd == 1){
                st.push(value);
                qu.push(value);
                pr.push(value);
            }else{
                int top_value;

                if(!st.empty()){
                    top_value = st.top();
                    st.pop();
                    if(top_value != value){
                        is_stack = false;
                    }
                }else{
                    is_stack = false;
                }

                if(!qu.empty()){
                    top_value = qu.front();
                    qu.pop();
                    if(top_value != value){
                        is_queue = false;
                    }
                }else{
                    is_queue = false;
                }

                if(!pr.empty()){
                    top_value = pr.top();
                    pr.pop();
                    if(top_value != value){
                        is_priority_queue = false;
                    }
                }else{
                    is_priority_queue = false;
                }

            }

        }

        int sum_possibles = is_stack + is_priority_queue + is_queue;

        if(sum_possibles > 1){
            printf("not sure\n");
        }else if(sum_possibles == 0){
            printf("impossible\n");
        }else{
            if(is_stack)
                printf("stack\n");
            if(is_queue)
                printf("queue\n");
            if(is_priority_queue)
                printf("priority queue\n");
        }


    }

    return 0;
}