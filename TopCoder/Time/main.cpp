#include <iostream>
#define HOUR 3600
#define MINUTE 60
using namespace std;

class Time{
public:

    string whatTime(int seconds){
        int H, M, S;

        H = seconds / HOUR;
        seconds -= H*HOUR;

        M = seconds /  MINUTE;
        seconds -= M*MINUTE;

        S = seconds;


        return string(to_string(H)+':'+to_string(M)+":"+to_string(S));

    }
};

int main() {
    Time t;

    cout << "fim" << endl;
    return 0;
}