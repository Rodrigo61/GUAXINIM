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
#define sz(x) (int)(x.size())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
typedef long double ld;
typedef unsigned long long ull;

vector<ll> fact[51];
ll m[51];
ll a[51];


ull mod_mul(ull a, ull b, ull M)
{
	ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull mod_pow(ull b, ull e, ull mod)
{
	ull ans = 1;
	for (; e; b = mod_mul(b, b, mod), e /= 2)
		if (e & 1)
			ans = mod_mul(ans, b, mod);
	return ans;
}

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

template<class T>
T mod_inverse(T a, T m)
{
	T x, y;
	assert(gcd<ll>(a, m, x, y) == 1); // Or return something, if gcd is not 1 the inverse doesn't exist.
	return (x % m + m) % m;
}

ll crt(ll a, ll m, ll b, ll n)
{
    if (n > m)
        swap(a, b), swap(m, n);
    ll x, y, g = gcd<ll>(m, n, x, y);
    assert((a - b) % g == 0); // else no solution
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
}


ll crt_system(ll a[], ll m[], int n)
{
    for(int i = 0; i < n; i++) 
        a[i] = (a[i] % m[i] + m[i]) % m[i];
    ll ans = a[0];
    ll lcm = m[0];
    for(int i = 1; i < n; i++)
    {
        ans = crt(ans, lcm, a[i], m[i]);
        ll x, y;
        ll d = gcd<ll>(lcm, m[i], x, y);
        lcm = lcm * m[i] / d;
    }
    return ans;
}

bool isPrime(ull n)
{
    if (n < 2 || n % 6 % 4 != 1)
        return n - 2 < 2;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n - 1), d = n >> s;
    for (auto &a : A)
    { // ^ count trailing zeroes
        ull p = mod_pow(a, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = mod_mul(p, p, n);
        if (p != n - 1 && i != s)
            return 0;
    }
    return 1;
}

ull pollard(ull n)
{
	auto f = [n](ull x) { return (mod_mul(x, x, n) + 1) % n; };
	if (!(n & 1))
		return 2;
	for (ull i = 2;; i++)
	{
		ull x = i, y = f(x), p;
		while ((p = __gcd(n + y - x, n)) == 1)
			x = f(x), y = f(f(y));
		if (p != n)
			return p;
	}
}

vector<int> factorize(ull n)
{
	if (n == 1)
		return {};
	if (isPrime(n))
		return {(int)n};
	ull x = pollard(n);
	auto l = factorize(x), r = factorize(n / x);
	l.insert(l.end(), all(r));
	return l;
}

ll chooseModP(ll n, ll m, int p, vector<ll> &fact) {
	ll c = 1;
	while (n || m) {
		ll a = n % p, b = m % p;
		if (a < b) return 0;
		c = c * fact[a] % p * mod_inverse<ll>(fact[b], p) % p * mod_inverse<ll>(fact[a - b], p) % p;
		n /= p; m /= p;
	}
	return c;
}

void calc()
{
    for (int p = 2; p < 51; p++)
    {
        fact[p].resize(51);
        if (isPrime(p))
        {
            fact[p][0] = fact[p][1] = 1;
            for (int i = 2; i < 51; i++)
            {
                fact[p][i] = (fact[p][i-1] * (i % p)) % p;
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    calc();
    while (t--)
    {
        ll M, R, N;
        scanf("%lld%lld%lld", &N, &R, &M);
        auto factors = factorize(M);

        for (int i = 0; i < sz(factors); i++)
        {
            a[i] = chooseModP(N, R, factors[i], fact[factors[i]]);
            m[i] = factors[i];

        }

        printf("%lld\n", crt_system(a, m, sz(factors)));
    }
    
}