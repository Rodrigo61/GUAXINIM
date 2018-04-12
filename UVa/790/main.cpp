using namespace std;
bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "

typedef pair<int,int> pii;
typedef vector<int> vi;


/// Debug Start
template<class T1> void deb(T1 e1)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << endl;
    }
}
template<class T1,class T2> void deb(T1 e1, T2 e2)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << endl;
    }
}
template<class T1,class T2,class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << endl;
    }
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1, T2 e2, T3 e3, T4 e4)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << endl;
    }
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << space << e5 << endl;
    }
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1, T2 e2, T3 e3, T4 e4 ,T5 e5, T6 e6)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << space << e5 << space << e6 << endl;
    }
}


template<typename T>
void print_vector_debug(const T& t) {

    if(debug) {
        cout << "[DEBUG] VECTOR:";
        for (auto i = t.cbegin(); i != t.cend(); ++i) {
            if ((i + 1) != t.cend()) {
                cout << *i << " ";
            } else {
                cout << *i << endl;
            }
        }
    }
}

template<typename T>
void print_array_debug(const T arr, int size){

    if(debug) {
        cout << "[DEBUG] VECTOR:";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << space;
        }
        cout << endl;
    }
}

template<typename T>
void print_2Darray_debug(const T arr, int rows, int cols){

    if(debug) {
        cout << "[DEBUG] Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << arr[i][j] << space;
            }
            cout << endl;
        }
        cout << endl;
    }
}

template<typename T>
void print_matrix_debug(const T& t) {
    if(debug) {
        cout << "[DEBUG] MATRIX:" << endl;
        for (auto i = t.cbegin(); i != t.cend(); ++i) {
            for(auto j = i->cbegin(); j != i->cend(); ++j){
                cout << *j << " ";
            }
            cout << endl;
        }
    }
}
//</editor-fold desc="GUAXINIM TEMPLATE">


int get_time(string &time){

    int pos = time.find(':');
    string hour = time.substr(0, pos);
    string min = time.substr(pos+1, time.size());

    return stoi(hour)*60 + stoi(min);
}


class Team{
private:
    int id;
    int solved_count;
    vi failed_sub;
    vi solved_problems;
    int acu_time;

public:

    Team(int id){
        this->id = id;
        solved_count = 0;
        failed_sub.resize(9,0);
        solved_problems.resize(9,0);
        acu_time = 0;
    }

    void submit(char problem_id, string &time, char status){

        int p_id = problem_id - 'A';
        int minutes = get_time(time);

        deb("p_id = ", p_id);
        deb("minutes = ", minutes);

        if(status == 'N'){
            failed_sub[p_id]++;
        }else{
            if(solved_problems[p_id] == 0){
                ++solved_count;
                acu_time += minutes + failed_sub[p_id]*20;
                solved_problems[p_id] = 1;
            }
        }
    }

    bool operator<(const Team& t2){
        if(this->solved_count < t2.solved_count) return true;
        if(this->solved_count > t2.solved_count) return false;

        if(this->acu_time < t2.acu_time) return true;
        if(this->acu_time >= t2.acu_time) return false;

    }

    void print(){
        if(id < 10){
            cout << "   " << id;
        }else{
            cout << "  " << id;
        }


        if(solved_count > 0){
            cout << "    " << solved_count << "       ";
            if(acu_time < 10){
                cout << "   " << acu_time;
            }else if(acu_time < 100){
                cout << "  " << acu_time;
            }else if(acu_time < 1000){
                cout << " " << acu_time;
            }else{
                cout << acu_time;
            }
        }

        cout << endl;
    }

    int get_id(){
        return id;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_cases;
    cin >> n_cases;

    for (int w = 0; w < n_cases; ++w) {

        int team_id;
        string time;
        char problem_id;
        char status;
        vi teams_visited(26, 0);

        vector<Team> vet_teams;
        vet_teams.reserve(26);
        for (int i = 0; i < 26; ++i) {
            Team t(i);
            vet_teams.push_back(t);
        }


            cin >> team_id >> problem_id >> time >> status;

            deb("team_id = ", team_id);
            deb("problem_id = ", problem_id);
            deb("time = ", time);
            deb("status = ", status);
            teams_visited[team_id] = 1;

            vet_teams[team_id].submit(problem_id, time, status);
            if(debug){
                vet_teams[team_id].print();
            }
        }

        sort(all(vet_teams));

        cout << "RANK TEAM PRO/SOLVED TIME"<< endl;
        bool first = true;
        Team *last_team;
        int last_rank = 0;
        int abs_rank = 0;
        int rank;
        for (int i = 25; i >= 0; --i) {
            if(teams_visited[vet_teams[i].get_id()]){

                ++abs_rank;
                if(first){
                    first = false;
                    rank = 1;
                }else if(vet_teams[i] < *last_team){
                    rank = abs_rank;
                }else{
                    rank = last_rank;
                }

                if(rank <= 9){
                    cout << "   " << rank << space;
                }else{
                    cout << "  " << rank << space;
                }

                vet_teams[i].print();
                last_team = &vet_teams[i];
                last_rank = rank;
            }
        }

    }
    return 0;
}