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
        int n;
        int odd = 0, even = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int v;
            scanf("%d", &v);
            if (v % 2 != i % 2) {
                if (v & 1) {
                    odd++;
                } else {
                    even++;
                }
            }
        }
        
        if (odd == even) {
            printf("%d\n", even);
        } else {
            printf("-1\n");
        }
    }
    
}