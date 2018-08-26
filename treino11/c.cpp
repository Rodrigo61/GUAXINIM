#include<bits/stdc++.h>

#define uint64 unsigned long long

typedef long long ll;
using namespace std;

uint64 mulmod(uint64 x, uint64 n, uint64 m)
{
	uint64 a = 0, b = x % m;
	for(; n > 0; n >>= 1)
	{
		if (n & 1)
		{
			a = (a + b) % m;
		}
		b = ( b << 1) % m;
		
	}
	
	return a %m;
}

uint64 powmod(uint64 x, uint64 n, uint64 m)
{
	uint64 a = 1, b =x;
	for (; n > 0; n >>= 1)
	{
		if (n & 1)
		{
			a = mulmod(a, b, m);
		}
		b = mulmod(b, b, m);
		
	}
	return a %m;
}

uint64 rand64u()
{
	return ((uint64)(rand() & 0xf) << 60) |
			((uint64)(rand() & 0x7fff) << 45) |
			((uint64)(rand() & 0x7fff) << 30) |
			((uint64)(rand() & 0x7fff) << 15) |
			((uint64)(rand() & 0x7fff));
	
}

uint64 gcd(uint64 a, uint64    b)
{
	while (b != 0)
	{
		uint64 t = b;
		b = a % b;
		a = t;
	}
	return a;
	
}

/*template<class Int>
std::vector<Int> prime_factorize(Int n)
{
	if (n <= 3)
	{
		vector<Int>(1, n);
	}
	
	vector<Int> res;
	for (Int i = 2; ; i++)
	{
		int p = 0, q = n / i, r = n - q * i;
		
		if (i > q || (i == q && r > 0))
		{
			break;
		}
		
		while (r == 0)
		{
			p++;
			n = q;
			q = n / i;
			r = n - q*i;
		}
		for (int j = 0; j < p ;j++)
		{
			res.push_back(i);
		}
	}
	if (n > 1)
	{
		res.push_back(n);
	}
	return res;
	
}*/

//~ template<class Int>
//~ vector<Int> get_divisors(Int n){
	//~ if (n <= 1)
	//~ {
		//~ return (n < 1) ? vector<Int>() : vetor<Int>(1,1);
		
	//~ }
	
	
	//~ vector<Int> res;
	//~ for (Int i = 1; i*i <= n; i++)
	//~ {
		//~ if (n % i == 0)
		//~ {
			//~ res.push_back(i);
			//~ if (i*i != n)
			//~ {
				//~ res.push_back(/i);	
			//~ }
			
		//~ }
		
			
	//~ }
//~ }

long long pollards_rho_brent(long long n)
{
	if (n % 2 ==0)
	{
		return 2;
	}
	
	uint64 y = rand64u() % (n - 1) + 1;
	uint64 c = rand64u() % (n - 1) + 1;
	uint64 m = rand64u() % (n - 1) + 1;
	uint64 g = 1, r = 1, q = 1, ys = 0, x = 0;
	
	for (r = 1; g == 1; r <<= 1)
	{
		x = y;
		for (int i = 0; i < r; ++i)
		{
			y = (mulmod(y, y, n) + c) %n;
		}
		for (long long k = 0; k < r && g == 1; k += m)
		{
			
			ys = y;
			long long lim = min(m, r - k);
			for (int j = 0; j < lim; j++)
			{
				y = (mulmod(y, y, n) + c) %n;
				q = mulmod(q, (x > y) ? (x - y) : (y - x), n);
			}
			g =gcd(q, n);
		}
		
	}
	
	if (g == n)
	{
		do
		{
			ys = (mulmod(ys, ys, n) + c) %n;
			g = gcd((x > ys) ? (x - ys) : (ys - x), n);
		} while (g <= 1);
	}

	return g;
	
}
	
	
bool is_prime(long long n)
{
	
	static const int np = 9, p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	for (int i = 0; i < np; i++)
	{
		if (n % p[i] == 0)
		{
			return n == p[i];
		}
	}
	if (n < p[np - 1])
	{
		return false;
	}
	
	uint64 t;
	int s = 0;
	for (t = n - 1; !(t & 1); t >>= 1)
	{
		s++;
	}
	
	for (int i = 0; i < np; i++)
	{
		uint64 r = powmod(p[i], t, n);
		if (r == 1)
		{
			continue;
		}
		
		bool ok = false;
		for (int j = 0; j < s && !ok; j++)
		{
			ok |= (r == (uint64)n - 1);
			r = mulmod(r, r, n);
		}
		
		if (!ok)
		{
			return false;	
		}
	}
	return true;	
}


map<ll, int> Mapa;

set<ll> potprim;

void factorize(ll n)
{
	long long cutoff = 1000000LL;
	while(n%2 == 0)
	{
		Mapa[2]++;
		n /= 2;
	}
	while(n%3 == 0)
	{
		Mapa[3]++;
		n /= 3;
	}
	for(ll i = 5, w = 4; i <= cutoff && i*i <= n; i += w)
	{
		for(; n % i == 0; n /= i)
		{
			Mapa[i]++;
		}
		w = 6-w;
	}
	for(long long p; n >cutoff && !is_prime(n); n /= p)
	{
		do
		{
			p = pollards_rho_brent(n);
		}while(p == n);
		Mapa[p]++;
	}
	if(n != 1)
	{
		Mapa[n]++;
	}
}

vector<pair<ll, int> > vet;

int dp[20001][1001];
int vis[20001][1001];

#define MOD 1000000007

int solve(int x, int y)
{
	if(x == vet.size())
		return y == 1;
	if(vis[x][y])
		return dp[x][y];
	vis[x][y] = 1;
	int r = 0;
	for(int i = 0; i <= vet[x].second; i++)
	{
		if(y%(i+1) == 0)
		{
			r = (r + solve(x+1, y/(i+1)))%MOD;
		}
	}
	return dp[x][y] = r % MOD;
}

main()
{
	int N, K;
	ll x;
	scanf("%d %d", &K, &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%lld", &x);
		factorize(x);
	}
	vet.assign(Mapa.begin(), Mapa.end());
	printf("%d\n", solve(0, K));
	return 0;
}





