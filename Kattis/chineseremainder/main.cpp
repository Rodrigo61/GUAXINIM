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

template<class T>
T gcd(T a, T b, T &x, T &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    T x1, y1;
    T d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll crt(ll a[], ll m[], int n)
{
    for(int i = 0; i < n; i++) 
        a[i] = (a[i] % m[i] + m[i]) % m[i];
    ll ans = a[0];
    ll lcm = m[0];
    for(int i = 1; i < n; i++)
    {
        ll x1, y;
        ll d = gcd<ll>(lcm, m[i], x1, y);
        if((a[i] - ans) % d != 0)
            return -1;
        ll new_lcm = lcm * m[i] / d;
        ans = ((ans + x1 * (a[i] - ans) / d % (m[i] / d) * lcm) % new_lcm + new_lcm) % new_lcm;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll rem[2], mod[2];
        scanf("%lld%lld%lld%lld", &rem[0], &mod[0], &rem[1], &mod[1]);
        ll lcm = (mod[0]*mod[1])/__gcd(mod[0], mod[1]);
        ll ans = crt(rem, mod, 2);
        if (ans != -1)
        {
            printf("%lld %lld\n", ans, lcm);
        }
        else
            printf("no solution\n");
    }
}