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
    int t;
    scanf("%d", &t);

    for (int w = 0; w < t; w++)
    {
        int n, x;
        scanf("%d%d", &n, &x);
        vector<int> vals(n);
        ll total = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vals[i]);
            total += vals[i];
        }

        if (total % x != 0) {
            printf("%d\n", n);
            continue;
        }

        int res = -1;
        for (int i = 0; i < n; i++)
        {
            if (vals[i] % x != 0) {
                res = max(res, max(i, n - i - 1));
            }
        }

        printf("%d\n", res);
    }
    
}