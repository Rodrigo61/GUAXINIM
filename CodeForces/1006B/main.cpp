#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    int nigga[n], nigga1[n], polycarp = 0;
    for(int i=0; i<n; i++){
        cin >> nigga[i];
        nigga1[i] = nigga[i];
    }
    sort(nigga1, nigga1+n);
    map<int, int>fuck;
    for(int i=n-1; i>=n-k; i--){
        polycarp += nigga1[i];
        fuck.insert(make_pair(nigga1[i], 1));
    }
    cout << polycarp << endl;
    int cnt = 0;
    for(int i=0; i<n; i++){
        cnt++;
        if(fuck[nigga[i]] == 1 and k >= 2){
            k--;
            cout << cnt << " ";
            cnt = 0;
        }
    }
    cout << cnt << endl;
}