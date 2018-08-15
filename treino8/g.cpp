#include<bits/stdc++.h>
#define MAXM 500000
#define ll long long

using namespace std;

int isprime[MAXM+1];
vector<pair<int, int> > divisores[MAXM+1];

void gerar(int x)
{
	int mask = (1 << divisores[x].size()), d;
	if(x == 1)
		divisores[1].push_back({1, 0});
	for(int i = 0; i < mask; i++)
	{
		d = __builtin_popcount(i);
		if(d == 1)
			continue;
		ll ans = 1;
		int f = 0;
		for(int j = 0, k = 1; j < (int)divisores[x].size(); j++, k <<= 1)
		{
			if(k&i)
			{
				if(ans * divisores[x][j].first > MAXM)
					f = 1;
				else
					ans *= divisores[x][j].first;	
			}
		}
		if(!f)
			divisores[x].push_back({ans, d});
	}
}

void crivo()
{
	for(int i = 2; i <= MAXM; i += 2)
	{
		isprime[i] = 1;
		divisores[i].push_back({2, 1});
	}
	for(int i = 3; i <= MAXM; i += 2)
	{
		if(!isprime[i])
		{
			for(int j = i; j <= MAXM; j += i)
			{
				isprime[j] = 1;
				divisores[j].push_back({i, 1});
			}
		}
	}
	for(int j = 1; j <= MAXM; j++)
	{
		gerar(j);
	}
}

set<int> conjuntos[MAXM+1];
int vet[200001];
set<int> posicoes;

int main()
{
	crivo();
	ll total = 0, antes, depois;
	int N, M, x, y, c1 = 0;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		scanf("%d", &vet[i]);
	for(int t = 0; t < M; t++)
	{
		scanf("%d", &x);
		if(posicoes.count(x) > 0)
		{
			antes = depois = 0;
			y = vet[x];
			for(int i = 0; i < (int)divisores[y].size(); i++)
			{
				if(divisores[y][i].second&1)
					antes -= (conjuntos[divisores[y][i].first].size()*
					(conjuntos[divisores[y][i].first].size()-1LL))/2;
				else
					antes += (conjuntos[divisores[y][i].first].size()*
					(conjuntos[divisores[y][i].first].size()-1LL))/2;
				conjuntos[divisores[y][i].first].erase(x);
			}
			posicoes.erase(x);
			for(int i = 0; i < (int)divisores[y].size(); i++)
			{
				if(divisores[y][i].second&1)
					depois -= (conjuntos[divisores[y][i].first].size()*
					(conjuntos[divisores[y][i].first].size()-1LL))/2;
				else
					depois += (conjuntos[divisores[y][i].first].size()*
					(conjuntos[divisores[y][i].first].size()-1LL))/2;
			}
		}
		else
		{
			antes = depois = 0;
			y = vet[x];
			for(int i = 0; i < (int)divisores[y].size(); i++)
			{
				if(divisores[y][i].second&1)
					antes -= (conjuntos[divisores[y][i].first].size()*
					(conjuntos[divisores[y][i].first].size()-1LL))/2;
				else
					antes += (conjuntos[divisores[y][i].first].size()*
					(conjuntos[divisores[y][i].first].size()-1LL))/2;
				conjuntos[divisores[y][i].first].insert(x);
			}
			posicoes.insert(x);
			for(int i = 0; i < (int)divisores[y].size(); i++)
			{
				if(divisores[y][i].second&1)
					depois -= (conjuntos[divisores[y][i].first].size()*
					(conjuntos[divisores[y][i].first].size()-1LL))/2;
				else
					depois += (conjuntos[divisores[y][i].first].size()*
					(conjuntos[divisores[y][i].first].size()-1LL))/2;
			}
		}
		total += depois-antes;
		printf("%lld\n", total);
	}
	return 0;
}
