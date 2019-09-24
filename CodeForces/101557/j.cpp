#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define lllong long
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
typedef long double ld;

#define MAXN 112
#define trav(a, x) for(auto& a : x)

const ll MOD = (1LL<<31) - 1;
int N, K;
vi divs;
vi mask;
ll fat_dp[MAXN];
vi powered_factors;
int vis[MAXN][MAXN][1123];
ll dp[MAXN][MAXN][1123];
ll combs[MAXN][MAXN];

ll gcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

ll mod_inverse(ll a, ll m)
{
	ll x, y;
	assert(gcd(a, m, x, y) == 1);
	return (x % m + m) % m;
}

ll div_mod(ll a, ll b) 
{ 
    a = a % MOD; 
    ll inv = mod_inverse(b, MOD); 
    return (inv * a) % MOD;
} 

ll mult_mod(ll a, ll b)
{
	return (a * b) % MOD;
}

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}

ll sub(ll a, ll b)
{
	return (a - b + MOD) % MOD;
}

ll fatorial(ll a)
{
	if (a <= 1) return 1;
	if (fat_dp[a] != 0)
		return fat_dp[a];
	return fat_dp[a] = mult_mod(a, fatorial(a - 1));
}

ll solve(int idx, int rest, int bitmask)
{
	if (idx == (int)divs.size())
	{
		int fllmask = (1 << ((int)powered_factors.size())) - 1;
		return (rest == 0 && bitmask == fllmask);
	}
	
	if (vis[idx][rest][bitmask])
	{
		return dp[idx][rest][bitmask];
	}
	vis[idx][rest][bitmask] = 1;
	
	ll res = solve(idx + 1, rest, bitmask);
	ll up = 1;
	ll down = 1;
	ll fat = 1;
	for (int i = 1; rest - i * divs[idx] >= 0; i++)
	{
		up = mult_mod(up, combs[rest - (i - 1) * divs[idx]][divs[idx]]);
		down = mult_mod(down, i);
		fat = mult_mod(fat, fatorial(divs[idx] - 1));
		ll fact = mult_mod(div_mod(up, down), fat);
		ll rec = mult_mod(fact, solve(idx + 1, rest - i * divs[idx], mask[idx] | bitmask));
		res = add(res, rec);
	}
	
	return dp[idx][rest][bitmask] = res;
}

void calc_divs()
{
	for (int i = 1; i*i <= K && i < MAXN; i++)
	{
		if (K % i == 0)
		{
			if (i < MAXN)
				divs.pb(i);
			if (K/i != i && K/i < MAXN)
				divs.pb(K/i);
		}
	}
}

void calc_divs_masks()
{
	for (int d : divs)
	{
		int m = 0;
		for (int i = 0; i < (int)powered_factors.size(); i++)
		{
			if (d % powered_factors[i] == 0)
			{
				m |= 1 << i;
			}
		}
		mask.pb(m);
	}
}

ll mod_mul(ll a, ll b, ll M) {
	ll ret = a * b - M * (ll)(ld(a) * ld(b) / ld(M));
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ll mod_pow(ll b, ll e, ll mod) {
	ll ans = 1;
	for (; e; b = mod_mul(b, b, mod), e /= 2)
		if (e & 1) ans = mod_mul(ans, b, mod);
	return ans;
}

bool isPrime(ll n) {
	if (n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
	ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for(auto &a : A) {   // ^ count trailing zeroes
		ll p = mod_pow(a, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = mod_mul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ll pollard(ll n) {
	auto f = [n](ll x) { return (mod_mul(x, x, n) + 1) % n; };
	if (!(n & 1)) return 2;
	for (ll i = 2;; i++) {
		ll x = i, y = f(x), p;
		while ((p = __gcd(n + y - x, n)) == 1)
			x = f(x), y = f(f(y));
		if (p != n) return p;
	}
}
vector<ll> factorize(ll n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ll x = pollard(n);
	auto l = factorize(x), r = factorize(n / x);
	l.insert(l.end(), all(r));
	return l;
}

void calc_combs()
{
	for(int i = 0; i <= MAXN; i++)
    {
        combs[i][0] = 1;
    }
    for(int i = 1; i <= MAXN; i++)
    {
        for(int j = 1; j <= MAXN; j++)
        {
            combs[i][j] = (combs[i-1][j-1] + combs[i-1][j]) % MOD;
        }
    }
}

int main()
{
	scanf("%d%d", &N, &K);
	
	if (K == 1)
	{
		return !printf("1\n");
	}
	
	calc_divs();
	calc_combs();
	auto v = factorize(K);
	int last = -1, acu;
	for (int i : v)
	{
		if (i != last)
		{
			if (last != -1)
				powered_factors.pb(acu);
			acu = 1;
		}
		acu *= i;
		last = i;
	}
	if (last != -1)
		powered_factors.pb(acu);
		
		
	calc_divs_masks();
	
	printf("%lld\n", solve(0, N, 0));
	
}
