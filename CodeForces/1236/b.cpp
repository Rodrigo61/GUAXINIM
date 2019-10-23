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

const ll mod = 1e9+7;

ll mod_mul(ll a, ll b)
{
    return ((a % mod) * (b % mod) ) % mod;
}


ll pow_mod(ll b, ll e)
{
    if (e == 1)
        return (b % mod);
    if (e == 0)
        return 1;
    
    if (e & 1)
    {
        ll ans = pow_mod(b, e/2);
        ans = mod_mul(ans, ans);
        ans = mod_mul(ans, b);
        return ans;
    }
    else
    {
        ll ans = pow_mod(b, e/2);
        ans = mod_mul(ans, ans);
        return ans;
    }
    
}

ll sub_mod(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod ) % mod;
}

int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll res = pow_mod(2, m);
    res = sub_mod(res, 1);
    res = pow_mod(res, n);
    printf("%lld\n", res);
}