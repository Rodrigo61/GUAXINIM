#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl;
#define ll long long
#define MOD 1000000007

ll x, k;
ll base[3];
ll C[3][3];
ll mat[3][3] = {{2, 0, 1}, {1, 0, 0}, {0, 0, 1}}, 
   res[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

ll mult(ll a, ll b)
{
	return ((a % MOD) * (b % MOD)) % MOD;
}

ll sub(ll a, ll b)
{
	return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
void multiply(ll A[3][3], ll B[3][3])
{
	int N = 3;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			C[i][j] = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k < N; k++)
			{
				C[i][j] += ((ll)A[i][k])*B[k][j];
				C[i][j] %= MOD;
			}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			A[i][j] = C[i][j] % MOD;
}

void power(ll e)
{
	db(e);
	for(ll i = 1; i <= e; i <<= 1)
	{
		if(i&e)
			multiply(res, mat);
		multiply(mat, mat);
	}
}

int main()
{
	scanf("%lld%lld", &x, &k);
	
	if (x == 0)
	{
		return !printf("0\n");
	}
	
	if (k == 0)
	{
		return !printf("%lld\n", mult(2, x));
	}
	if (k == 1)
	{
		return !printf("%lld\n", sub(mult(4,x),1));
	}
	
	
	power(k - 1);

	
	ll r = sub(mult(res[0][0],(sub(mult(4,x),1))),res[0][2]);
	printf("%lld\n", r);
	
	return 0;
}
