#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;


int main()
{
    int age;
    string rest;
    cin >> age >> rest;

    if (rest == "G") {
        printf("OK");
    } else if (rest == "PG") {
        if (age < 13) {
            printf("OK IF ACCOMPANIED");
        } else
            printf("OK");
    } else if (rest == "R-13") {
        if (age < 13) {
            printf("ACCESS DENIED");
        } else
            printf("OK");
        
    } else if (rest == "R-16") {
        if (age < 16) {
            printf("ACCESS DENIED");
        } else
            printf("OK");
    } else {
        if (age < 18) {
            printf("ACCESS DENIED");
        } else
            printf("OK");
    }
}