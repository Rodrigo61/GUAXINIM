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
    int q;
    cin >> q;
    while (q--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vi freq(255);
        for (char c: s1)
            freq[c]++;
        bool poss = false;
        for (char c : s2)
            if (freq[c])
            {
                poss = true;
                break;
            }
        if (poss)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    
}