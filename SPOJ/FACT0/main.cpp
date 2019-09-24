#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define lllong long
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;
 
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
 
int main()
{
	ll n;
	while (scanf("%lld", &n), n)
	{
		auto v = factorize(n);
		map<ll, ll> Mapa;
		for (ll i : v)
			Mapa[i]++;
		for (auto p : Mapa)
			printf("%lld^%lld ", p.fi, p.se);
		printf("\n");
	}
