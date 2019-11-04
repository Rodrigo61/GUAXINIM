// https://open.kattis.com/problems/generalchineseremainder
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

ll crt(ll a, ll m, ll b, ll n)
{
    if (n > m)
        swap(a, b), swap(m, n);
    ll x, y, g = gcd<ll>(m, n, x, y);
    if((a - b) % g != 0)
        return -1;
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
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
        ll ans = crt(rem[0], mod[0], rem[1], mod[1]);
        if (ans != -1)
        {
            printf("%lld %lld\n", ans, lcm);
        }
        else
            printf("no solution\n");
    }
}