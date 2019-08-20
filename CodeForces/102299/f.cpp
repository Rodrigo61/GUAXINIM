#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned ll
#define fi first
 
ull mulmod(ull x, ull n, ull m)
{
	ull a = 0, b = x % m;
	for (; n > 0; n >>= 1)
	{
		if (n & 1)
			a = (a + b) % m;
		b = (b << 1) % m;
	}
	return a % m;
}
 
ull powmod(ull x, ull n, ull m)
{
	ull a = 1, b = x;
	for (; n > 0; n >>= 1)
	{
		if (n & 1)
			a = mulmod(a, b, m);
		b = mulmod(b, b, m);
	}
	return a % m;
}
 
ull rand64u()
{
	return  ((ull)(rand() & 0xf) <<60) |
			((ull)(rand() & 0x7fff) << 45) |
			((ull)(rand() & 0x7fff) << 30) |
			((ull)(rand() & 0x7fff) << 15) |
			((ull)(rand() & 0x7fff));
}
 
ull gcd(ull a, ull b)
{
	return b ? gcd(b, a%b) : a;
}
 
bool is_prime(ll n)
{
	static const int np = 9, p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	for (int i = 0; i < np; i++)
	{
		if(n % p[i] == 0)
			return n == p[i];
	}
	
	if (n < p[np - 1])
			return false;
	
	ull t;
	int s = 0;
	for (t = n - 1; !(t & 1); t >>= 1)
		s++;
		
	for (int i = 0; i < np; i++)
	{
		ull r = powmod(p[i], t, n);
		if (r == 1)
			continue;
		bool ok = false;
		for (int j = 0; j < s && !ok; j++)
		{
			ok |= (r == (ull)n - 1);
			r = mulmod(r, r, n);
		}
		
		if (!ok)
			return false;
	}
	return true;
}
 
ll pollards_rho(ll n)
{
	if (n % 2 == 0)
		return 2;
	
	ull y = rand64u() % (n - 1) + 1;
	ull c = rand64u() % (n - 1) + 1;
	ull m = rand64u() % (n - 1) + 1;
	ull g = 1, r = 1, q = 1, ys = 0, x = 0;
	
	for (r = 1; g == 1; r <<= 1)
	{
		x = y;
		for (ull i = 0; i < r; ++i)
			y = (mulmod(y, y, n) + c) % n;
		for (ll k = 0; k < r && g == 1; k += m)
		{
			ys = y;
			ll lim = min(m, r - k);
			for (int j = 0; j <  lim; j++)
			{
				y = (mulmod(y, y, n) + c) % n;
				q = mulmod(q, (x > y) ? (x - y) : (y - x), n);
			}
			g = gcd(q, n);
		}
	}
	if (g == n)
	{
		do
		{
			ys = (mulmod(ys,ys, n) + c ) % n;
			g = gcd((x > ys) ? (x - ys) : (ys - x), n);
		} while (g <= 1);	
	}
	return g;
}
 
map<ll, int> Mapa;
 
void factorize(ll n)
{
	ll cutoff = 1000000LL;
	while (n%2 == 0)
	{
		Mapa[2]++;
		n /= 2;
	}
	while (n%3 == 0)
	{
		Mapa[3]++;
		n /= 3;
	}
	for (ll i = 5, w = 4; i <= cutoff && i*i <= n; i += w)
	{
		for (; n % i == 0; n /= i)
			Mapa[i]++;
		w = 6 - w;
	}
	for (ll p; n > cutoff & !is_prime(n); n /= p)
	{
		do
		{
			p = pollards_rho(n);
		} while (p == n);
		Mapa[p]++;
	}
	if (n != 1)
		Mapa[n]++;
}
 
 
int main(void)
{
	ll a, b;
	cin >> a >> b;
	b /= __gcd(a, b);
	
	if (b == 1)
		cout << 2 << endl;
	else
	{
		ll ans = 1;
		factorize(b);
		for (auto p : Mapa)
			ans *= p.fi;
 
		cout << ans << endl;
	}
	
	return 0;
}
