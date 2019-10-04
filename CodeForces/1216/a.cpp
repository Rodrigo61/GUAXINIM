#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
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
    int n;
    string str;
    cin >> n >> str;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == str[i + 1])
        {
            ++count;
            str[i] = str[i] == 'a' ? 'b':'a';
        }
        ++i;
    }
    
    cout << count << endl;
    cout << str << endl;
}