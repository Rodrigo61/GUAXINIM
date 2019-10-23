#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
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
    scanf("%d", &q);
    while (q--)
    {
        int n;
        scanf("%d", &n);
        vll vet;
        for (int i = 0; i < n; i++)
        {
            ll v;
            scanf("%lld", &v);
            vet.pb(v);
        }
        sort(all(vet));
        reverse(all(vet));

        ll a, x, b, y;
        scanf("%lld%lld", &x, &a);
        scanf("%lld%lld", &y, &b);
        ll k;
        scanf("%lld", &k);

        ll l = (a * b)/__gcd(a, b);

        ll up = n;
        ll lo = 0;
        ll best = -1;

        while (lo <= up)
        {
            ll mid = lo + (up - lo) / 2;
            ll total = 0;
            int it = 0;
            for (int i = 1; it < n && i <= mid; i++)
            {
                if (i % l == 0)
                {
                    ll p = vet[it];
                    it++;
                    total += ((x + y) * p)/100;
                }
            }

            ll bv, sv, bp, sp;
            if (x > y)
            {
                bv = a;
                bp = x;
                sv = b;
                sp = y;
            }
            else
            {
                sv = a;
                sp = x;
                bv = b;
                bp = y;
            }

            for (int i = 1; it < n && i <= mid; i++)
            {
                if (i % l == 0) continue;
                if (i % bv == 0)
                {
                    ll p = vet[it];
                    it++;
                    total += ((bp) * p)/100;
                }
            }
            for (int i = 1; it < n && i <= mid; i++)
            {
                if (i % l == 0) continue;
                if (i % sv == 0)
                {
                    ll p = vet[it];
                    it++;
                    total += ((sp) * p)/100;
                }
            }
            
            if (total >= k)
            {
                best = mid;
                up = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
            
        }
        
        printf("%lld\n", best);
        
    }
    
}