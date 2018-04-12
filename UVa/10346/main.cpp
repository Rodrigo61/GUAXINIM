#include <iostream>

using namespace std;

int main() {

    while(cin.peek() != EOF){
        int n_cigar;
        int n_butt;
        int total_cigar;

        cin >> n_cigar >> n_butt;
        total_cigar = n_cigar;

        while(n_cigar >= n_butt){
            n_cigar -= n_butt;
            n_cigar++;
            total_cigar++;
        }

        cout << total_cigar << endl;
        cin.get();

    }
    return 0;
}