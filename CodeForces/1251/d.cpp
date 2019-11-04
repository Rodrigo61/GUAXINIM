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
        ll n, s;
        scanf("%lld%lld", &n, &s);
        vector<pll> vals(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld%lld", &vals[i].fi, &vals[i].se);
        }
        
        ll up = s;
        ll lo = 0;
        ll best = 0;

        while (lo <= up)
        {
            ll mid = lo + (up - lo) / 2;

            ll right = 0;
            ll left = 0;
            for (auto p : vals)
            {
                if (p.fi >= mid)
                    ++right;
                if (p.se < mid)
                    ++left;
            }

            if (right <= (n+1)/2 && left <= n/2)
            {
                best = mid;
                mid = lo + 1;
            }
            else
                mid = up - 1;
        }
        
        printf("%lld\n", best);
    }
    
}