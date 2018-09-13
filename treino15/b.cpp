#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007LL

using namespace std;

ll modInverse(ll a, ll b)
{
	return a > 1LL ? b - ((modInverse(b%a, a) * b)/a) : 1LL;
}

ll inv(ll a)
{
	ll z = modInverse(a, MOD);
	if(z < 0)
		z += MOD;
	return z;
}

ll expbin(ll a, int e)
{
	ll ans = 1;
	for(int i = 1; i <= e; i <<= 1)
	{
		if(i&e)
			ans = (ans*a)%MOD;
		a = (a*a)%MOD;
	}
	return ans;
}

int main()
{
	int n, m, y, c;
	vector<int> primos;
	ll inc, exc = 0, tre = 0, val, sum;
	scanf("%d %d %d", &n, &m, &c);
	tre = val = expbin(c, n*n);
	inc = expbin(c, n*n*m)-val;
	y = m;
	for(int i = 2; i*i <= y; i++)
	{
		if(y % i == 0)
		{
			primos.push_back(i);
			while(y % i == 0)
				y /= i;
		}
	}
	if(y > 1 && y != m)
		primos.push_back(y);
	for(int i = 0; i < (int)primos.size(); i++)
	{
		exc = (exc + expbin(val, m/primos[i]) - val + MOD) % MOD;
		tre = (tre + ((expbin(val, m/primos[i]) - val)*inv(m/primos[i]))%MOD) % MOD;
	}
	sum = (((inc-exc)*inv(m) + tre)%MOD + MOD)%MOD;
	printf("%lld\n", sum);
	return 0;
}
