#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

class Contestant{
public:
    int ID;
    int problemSolved = 0;
    int timePenality = 0;

};

int main() {
    int nCases;

    cin >> nCases;

    string line;
    getline(cin, line);
    getline(cin, line);

    for(int w = 0; w < nCases; ++w){
        int compProblCorrect[105][12];
        memset(compProblCorrect, 0, sizeof(int)*105*12);

        int compProblIncorrect[105][12];
        memset(compProblIncorrect, 0, sizeof(int)*105*12);

        vector<bool> submission(105);

        int part, probl, time;
        char flag;

        string line;
        getline(cin, line);

        while(!line.empty()){
            regex sep("[[:s:]]");
            sregex_token_iterator rToken(line.begin(), line.end(), sep, -1);

            part = stoi(rToken->str());
            probl = stoi((++rToken)->str());
            time = stoi((++rToken)->str());
            flag = (++rToken)->str()[0];                    ;

            submission[part] = true;

            if(compProblCorrect[part][probl] == 0){
                if(flag == 'C'){
                    compProblCorrect[part][probl] = time;
                }else if(flag == 'I'){
                    ++compProblIncorrect[part][probl];
                }
            }

            getline(cin, line);
        }


        vector<Contestant> rank;
        for(int i = 1; i <= 100; ++i){
            if(submission[i]){
                Contestant c;
                c.ID = i;
                for(int j = 1; j <= 9; ++j){
                    if(compProblCorrect[i][j] != 0){
                        c.problemSolved++;
                        c.timePenality += compProblCorrect[i][j];
                        c.timePenality += compProblIncorrect[i][j]*20;
                    }
                }

                rank.push_back(c);
            }
        }

        sort(rank.begin(), rank.end(), [](Contestant c1, Contestant c2){
            if(c1.problemSolved < c2.problemSolved){
                return true;
            }

            if(c1.problemSolved > c2.problemSolved){
                return false;
            }

            if(c1.timePenality > c2.timePenality){
                return true;
            }

            if(c1.timePenality < c2.timePenality){
                return false;
            }

            return c1.ID > c2.ID;

        });


        auto it = rank.end()-1;
        for(int i = 0; i < rank.size(); ++i){
            cout << it->ID << " " << it->problemSolved << " " << it->timePenality << endl;
            --it;
        }

        if(w != nCases -1)
        cout << endl;

    }


    return 0;
}