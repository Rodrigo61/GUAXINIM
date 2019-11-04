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
    while (t--)
    {
        string str;
        cin >> str;

        char last = 'A';
        int c_sz = 0;
        vi working(255);

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != last)
            {
                if (c_sz & 1)
                    working[last] = 1;
                c_sz = 0;
            }
            c_sz++;
            last = str[i];
        }
        if (c_sz & 1)
            working[last] = 1;

        for (int i = 'a'; i <= 'z'; i++)
        {
            if (working[i])
                printf("%c", i);
        }
        printf("\n");
        
    }
    
}