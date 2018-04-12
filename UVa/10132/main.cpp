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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string part;
    int n_cases;
    cin >> n_cases;
    cin.ignore();
    getline(cin, part);

    for (int w = 0; w < n_cases; ++w) {

        map<string, int> part_map;
        vector<string> part_vet;
        vector<string> part_vet_unique;
        part_vet.reserve(300);
        part_vet_unique.reserve(300);

        while(getline(cin, part)){

            if(part.empty()) break;

            deb("part = ", part);

            if(part_map.find(part) == part_map.end()){
                part_map[part] = 1;
            }else{
                part_map[part]++;
            }

            part_vet.push_back(part);
            part_vet_unique.push_back(part);
        }

        sort(all(part_vet_unique), [](string &s1, string &s2){
            if(s1.size() < s2.size()){
                return true;
            }
            if(s1.size() > s2.size()){
                return false;
            }

            return s1 < s2;

        });
        print_vector_debug(part_vet_unique);
        auto it = unique(all(part_vet_unique));
        part_vet_unique.erase(it, part_vet_unique.end());
        print_vector_debug(part_vet_unique);

        int min_sz = part_vet_unique[0].size();
        int max_sz = (*(part_vet_unique.end()-1)).size();

        deb("min_sz = ", min_sz);
        deb("max_sz = ", max_sz);

        for (int i = 0; i < part_vet_unique.size(); ++i) {
            if(part_vet_unique[i].size() > min_sz) break;

            for (int j = part_vet_unique.size()-1; j >= 0; --j) {
                if(part_vet_unique[j].size() < max_sz) break;

                string curr_pattern = part_vet_unique[i] + part_vet_unique[j];
                deb("curr_pattern = ", curr_pattern);
                map<string, int> part_map_cp = part_map;

                bool possible_pattern = true;
                for(auto &p : part_vet){
                    bool front_possible = true;
                    deb("p = ", p);
                    string rem_part;
                    /*FRONT*/
                    if(curr_pattern.substr(0, p.size()) != p){
                        deb("Aqui 0");
                        front_possible = false;
                        goto front_p1;
                    }
                    rem_part = curr_pattern.substr(p.size(), curr_pattern.size());
                    deb("rem_part = ", rem_part);

                    if(part_map_cp.find(rem_part) == part_map_cp.end()){
                        deb("aqui1");
                        front_possible = false;
                        goto front_p1;
                    }
                    if(part_map_cp[rem_part] == 0){
                        deb("aqui2");
                        front_possible = false;
                        goto front_p1;
                    }

                    part_map_cp[rem_part]--;

                    front_p1:
                    if(front_possible) continue;

                    /*BACK*/
                    if(curr_pattern.substr(curr_pattern.size() - p.size(), curr_pattern.size()) != p){
                        deb("Aqui 0");
                        possible_pattern = false;
                        break;
                    }
                    rem_part = curr_pattern.substr(0, curr_pattern.size()- p.size());
                    deb("rem_part = ", rem_part);

                    if(part_map_cp.find(rem_part) == part_map_cp.end()){
                        deb("aqui1");
                        possible_pattern = false;
                        break;
                    }
                    if(part_map_cp[rem_part] == 0){
                        deb("aqui2");
                        possible_pattern = false;
                        break;
                    }
                    part_map_cp[rem_part]--;
                }

                deb("end check");
                if(possible_pattern){
                    cout << curr_pattern << endl;
                    goto next_case;
                }

                curr_pattern = part_vet_unique[j]+part_vet_unique[i];
                deb("curr_pattern = ", curr_pattern);
                part_map_cp = part_map;

                possible_pattern = true;
                for(auto &p : part_vet){
                    bool front_possible = true;
                    deb("p = ", p);
                    string rem_part;
                    /*FRONT*/
                    if(curr_pattern.substr(0, p.size()) != p){
                        deb("Aqui 0");
                        front_possible = false;
                        goto front;
                    }
                    rem_part = curr_pattern.substr(p.size(), curr_pattern.size());
                    deb("rem_part = ", rem_part);

                    if(part_map_cp.find(rem_part) == part_map_cp.end()){
                        deb("aqui1");
                        front_possible = false;
                        goto front;
                    }
                    if(part_map_cp[rem_part] == 0){
                        deb("aqui2");
                        front_possible = false;
                        goto front;
                    }

                    part_map_cp[rem_part]--;

                    front:
                    if(front_possible) continue;

                    /*BACK*/
                    if(curr_pattern.substr(curr_pattern.size() - p.size(), curr_pattern.size()) != p){
                        deb("Aqui 0");
                        possible_pattern = false;
                        break;
                    }
                    rem_part = curr_pattern.substr(0, curr_pattern.size()- p.size());
                    deb("rem_part = ", rem_part);

                    if(part_map_cp.find(rem_part) == part_map_cp.end()){
                        deb("aqui1");
                        possible_pattern = false;
                        break;
                    }
                    if(part_map_cp[rem_part] == 0){
                        deb("aqui2");
                        possible_pattern = false;
                        break;
                    }
                    part_map_cp[rem_part]--;
                }

                deb("end check");
                if(possible_pattern){
                    cout << curr_pattern << endl;
                    goto next_case;
                }
            }
        }

        next_case:
        if(w != n_cases-1)
            cout << endl;
    }

    return 0;
}