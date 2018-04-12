#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int frosh_number;

    cin >> frosh_number;
    while(frosh_number != 0){

        map<string, int> course_map;
        int most_popular_count = 0;


        for (int i = 0; i < frosh_number; ++i) {
            vector<int> course_vet(5);

            for (int j = 0; j < 5; ++j) {
                int course;
                cin >> course;

                course_vet[j] = course;
            }

            sort(course_vet.begin(), course_vet.end());

            string key = "";
            for(int &&course : course_vet){
                key += to_string(course);
            }


            int &course_count = course_map[key];
            course_count++;
            most_popular_count = max(most_popular_count, course_count);


        }

        int frosh_count_most_popular = 0;

        for(auto &i : course_map){
            if(i.second == most_popular_count){
                frosh_count_most_popular += most_popular_count;
            }
        }

        cout << frosh_count_most_popular << endl;

        cin >> frosh_number;
    }


    return 0;
}