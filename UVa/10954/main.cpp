#include <iostream>
#include <queue>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int number_count;

    cin >> number_count;
    while(number_count != 0){

        priority_queue<int> priority;

        for (int i = 0; i < number_count; ++i) {
            int number;

            cin >> number;

            priority.push(-1 * number);
        }

        int cost = 0;
        while(priority.size() > 2){
            int first = priority.top();
            priority.pop();
            int second = priority.top();
            priority.pop();

            cost += first + second;
            priority.push(first + second);
        }

        int first = priority.top();
        priority.pop();
        int second = priority.top();
        priority.pop();

        cost += first + second;

        cout << -1 * cost << endl;
        cin >> number_count;
    }
    return 0;
}