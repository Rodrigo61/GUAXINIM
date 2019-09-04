#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ulllong long
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
typedef unsigned long long ull;
typedef long double ld;

#define MAXN 112
#define trav(a, x) for(auto& a : x)

const ull MOD = (1LL<<31) - 1;
int N, K;
vi divs;
vi mask;
ull fat_dp[MAXN];
vi powered_factors;
int vis[200][MAXN][1123];
ull dp[200][MAXN][1123];
ull combs[MAXN][MAXN];

ull gcd(ull a, ull b, ull &x, ull &y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        x = 0, y = 1; 
        return b; 
    } 
  
    ull x1, y1; // To store results of recursive caull
    ull g = gcd(b%a, a, x1, y1); 
  
    // Update x and y using results of recursive 
    // caull
    x = y1 - (b/a) * x1; 
    y = x1; 
  
    return g; 
} 

ull modInverse(ull b, ull m) 
{ 
    ull x, y; // used in extended GCD algorithm 
    gcd(b, m, x, y); 
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 

// Function to compute a/b under modlo m 
ull div_mod(ull a, ull b) 
{ 
    a = a % MOD; 
    int inv = modInverse(b, MOD); 
    return (inv * a) % MOD;
} 

ull mult_mod(ull a, ull b)
{
	return (a * b) % MOD;
}

ull add(ull a, ull b)
{
	return (a + b) % MOD;
}

ull sub(ull a, ull b)
{
	return (a - b + MOD) % MOD;
}

ull fatorial(ull a)
{
	if (a <= 1) return 1;
	if (fat_dp[a] != 0)
		return fat_dp[a];
	return fat_dp[a] = mult_mod(a, fatorial(a - 1));
}


ull solve(int idx, int rest, int bitmask)
{
	db(idx);
	if (idx == (int)divs.size())
	{
		int fullmask = (1 << ((int)powered_factors.size())) - 1;
		db(fullmask);
		return (rest == 0 && bitmask == fullmask);
	}
	
	if (vis[idx][rest][bitmask])
	{
		return dp[idx][rest][bitmask];
	}
	vis[idx][rest][bitmask] = 1;
	
	ull res = solve(idx + 1, rest, bitmask);
	ull up = 1;
	ull down = 1;
	ull fat = 1;
	db(divs[idx]);
	for (int i = 1; i * divs[idx] <= rest; i++)
	{
		up = mult_mod(up, combs[rest - (i - 1) * divs[idx]][divs[idx]]);
		down = mult_mod(down, i);
		fat = mult_mod(fat, fatorial(divs[idx] - 1));
		db(idx);
		db(i);
		db(up);
		db(down);
		db(fat);
		ull fact = div_mod(up, down);
		db(fact);
		ull rec = mult_mod(fact, solve(idx + 1, rest - i * divs[idx], mask[idx] | bitmask));
		db(rec);
		res = add(res, rec);
	}
	
	return dp[idx][rest][bitmask] = res;
}

void calc_divs()
{
	for (int i = 1; i*i <= K; i++)
	{
		if (K % i == 0)
		{
			divs.pb(i);
			if (K/i != i)
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
			db(powered_factors[i]);
			if (d % powered_factors[i] == 0)
			{
				m |= 1 << i;
			}
		}
		mask.pb(m);
	}
}



ull mod_mul(ull a, ull b, ull M) {
	ull ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
	return ret + M * (ret < 0) - M * (ret >= (ull)M);
}

ull mod_pow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = mod_mul(b, b, mod), e /= 2)
		if (e & 1) ans = mod_mul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	trav(a, A) {   // ^ count trailing zeroes
		ull p = mod_pow(a, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = mod_mul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return (mod_mul(x, x, n) + 1) % n; };
	if (!(n & 1)) return 2;
	for (ull i = 2;; i++) {
		ull x = i, y = f(x), p;
		while ((p = __gcd(n + y - x, n)) == 1)
			x = f(x), y = f(f(y));
		if (p != n) return p;
	}
}
vector<ull> factorize(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
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
	
	calc_divs();
	calc_combs();
	auto v = factorize(K);
	int last = -1, acu;
	for (int i : v)
	{
		db(i);
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
	
	//~ for (auto d: divs)
		//~ printf("%d ", d);
	//~ printf("\n");	
	
	//~ for (auto d : powered_factors)
		//~ printf("%d ", d);
	//~ printf("\n");
	
	//~ for (auto p: mask)
	//~ {
		//~ printf("%d %d\n", p.fi, p.se);
	//~ }
	//~ printf("\n");	
	db("d1");
	printf("%lld\n", solve(0, N, 0));
	
}
