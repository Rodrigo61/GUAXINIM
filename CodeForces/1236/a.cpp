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
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        int ans = 0;
        while (b >= 1 && c >= 2)
        {
            b -= 1;
            c -= 2;
            ans += 3;
        }

        while (a >= 1 && b >= 2)
        {
            a -= 1;
            b -= 2;
            ans += 3;
        }
        
        printf("%d\n", ans);
    }
    
}