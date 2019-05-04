#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 312345
#define ll long long
#define fi first
#define se second
#define pll pair<ll, ll>

int N, X;
ll vals[MAXN];
ll dp[MAXN][2][2][2];
int vis[MAXN][2][2][2];

ll solve(int it, int b, int a, int c)
{
	if (it == N)
	{
		return 0;
	}
	
	if (vis[it][b][a][c])
	{
		return dp[it][b][a][c];
	}
	vis[it][b][a][c] = 1;
	
	ll res = 0;
	if (!b)
	{
		res = max(vals[it], vals[it] * X); // unico a pegar
		res = max(res, solve(it + 1, 0, 0, 0)); // continuo sem pegar
		res = max(res, solve(it + 1, 1, 0, 0) + vals[it]); // comeco a pegar
		res = max(res, solve(it + 1, 1, 1, 0) + vals[it] * X); // comeco a pegar ativando
	}
	else
	{
		if (a)
		{
			res = max(res, vals[it] * X); // caso eu queira parar de pegar, esse eh meu ultimo
			res = max(res, solve(it + 1, 1, 1, 0) + vals[it] * X); // continuo pegando e ativo
			res = max(res, solve(it + 1, 1, 0, 1) + vals[it]); // continuo pegando mas desativo
		}
		else
		{
			res = max(res, vals[it]); // caso eu queira parar de pegar, esse eh meu ultimo
			if (!c)
			{
				res = max(res, solve(it + 1, 1, 1, 0) + vals[it] * X); // ativo o fator caso nunca desativei
			}
			res = max(res, solve(it + 1, 1, 0, c) + vals[it]); // continuo pegando com o fator desativado
		}
		
	}
	
	dp[it][b][a][c] = res; 
	return res;
}

int main()
{
	scanf("%d%d", &N, &X);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	
	printf("%lld\n", solve(0, 0, 0, 0));
	
	return 0;
}
