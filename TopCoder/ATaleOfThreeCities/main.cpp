#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class ATaleOfThreeCities{
public:
    double connect(vector <int> ax, vector <int> ay, vector <int> bx, vector <int> by, vector <int> cx, vector <int> cy){
        double AB = INFINITY, AC = INFINITY, BC = INFINITY;

        for(int i = 0; i < ax.size(); ++i){

            for(int j = 0; j < bx.size(); ++j){
                double distance = getDistance(ax[i], ay[i], bx[j], by[j]);

                if(distance < AB){
                    AB = distance;
                }
            }
        }

        for(int i = 0; i < ax.size(); ++i) {
            for (int j = 0; j < cx.size(); ++j) {

                double distance = getDistance(ax[i], ay[i], cx[j], cy[j]);

                if (distance < AC) {
                    AC = distance;
                }
            }
        }

        for(int i = 0; i < bx.size(); ++i){
            for(int j = 0; j < cx.size(); ++j){
                double distance = getDistance(bx[i], by[i], cx[j], cy[j]);

                if(distance < BC){
                    BC = distance;
                }
            }
        }

        
        vector<double> vAux = {AB, AC, BC};
        return AB+AC+BC - max_element(vAux.begin(), vAux.end())[0];
    }


    double getDistance(int aXpos, int aYpos, int bXpos, int bYpos){
        return sqrt(pow(aXpos-bXpos, 2) + pow(aYpos-bYpos, 2));
    }
};


int main(){
    vector<int> ax = {0,0,0};
    vector<int> ay = {0,1,2};
    vector<int> bx = {2,3};
    vector<int> by = {1,1};
    vector<int> cx = {1,5};
    vector<int> cy = {3,28};

    ATaleOfThreeCities cls;

    cout << cls.connect(ax, ay, bx, by, cx, cy) << endl;
    return 0;
}