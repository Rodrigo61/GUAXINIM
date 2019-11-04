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
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string num;
        cin >> num;
        vi odds, evens;
        for (char c : num)        
        {
            int v = c - '0';
            if (v & 1)
                odds.pb(v);
            else
                evens.pb(v);
        }

        auto it_o = odds.begin();
        auto it_e = evens.begin();

        while (it_o != odds.end() && it_e != evens.end())
        {
            if (*it_o < *it_e)
            {
                printf("%d", *it_o);
                ++it_o;
            }
            else
            {
                printf("%d", *it_e);
                ++it_e;
            }
        }

        while (it_o != odds.end())
        {
            printf("%d", *it_o);
            ++it_o;
        }

         while (it_e != evens.end())
        {
            printf("%d", *it_e);
            ++it_e;
        }
        printf("\n");
    }
}