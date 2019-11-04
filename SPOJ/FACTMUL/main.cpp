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
#define sz(x) (int)(x.size())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define MOD1 186583
#define MOD2 587117
#define MOD 109546051211

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

ll crt(ll a, ll m, ll b, ll n) {
    if (n > m) swap(a, b), swap(m, n);
    ll x, y, g = gcd<ll>(m, n, x, y);
    assert((a - b) % g == 0); // else no solution
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m*n/g : x;
}

int main()
{
    int n;
    scanf("%d", &n);
    ll fat1 = 1, fat2 = 1;
    ll res1 = 1, res2 = 1;;
    for (int i = 2; i <= n; i++)
    {
        fat1 = (fat1 * i) % MOD1;
        res1 = (res1 * fat1) % MOD1;

        fat2 = (fat2 * i) % MOD2;
        res2 = (res2 * fat2) % MOD2;
    }

    printf("%lld\n", crt(res1, MOD1, res2, MOD2));

}