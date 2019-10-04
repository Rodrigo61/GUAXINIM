#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>

typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1e9 + 7;

vll primes;

bool is_prime(ll n)
{
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

void calc_primes(ll x)
{
    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (is_prime(i))
            {
                primes.pb(i);
            }

            if (x/i != i && is_prime(x/i))
                primes.pb(x/i);
        }
    }
}

ull mod_mul(ull a, ull b, ull M) {
	long long ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
	return ret + M * (ret < 0) - M * (ret >= (long long)M);
}
ull mod_pow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = mod_mul(b, b, mod), e /= 2)
		if (e & 1) ans = mod_mul(ans, b, mod);
	return ans;
}

int main()
{
    ll x, n;
    scanf("%lld%lld", &x, &n);

    calc_primes(x);

    ll res = 1;

    for (ll p : primes)
    {
        ll sent = n;
        ll curr = p;
        while (p <= sent)
        {
            db(sent);
            //if (p > sent) break;
            res = mod_mul(res, mod_pow(p, (sent/p), MOD), MOD);
            sent = sent/p;
        }
    }

    printf("%lld\n", res);
}