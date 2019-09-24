/*
	A ideia aqui eh que para um numero limitado de pesos possiveis eh 
	possivel rodar uma versao gulosa do algoritmo da mochila.
	
	Suponha que voce tenha N itens e cada item tem peso 1 ou 2. Voce tem
	capacidade K e quer maximizar o valor da mochila. O algoritmo guloso
	entao se baseia em ordenar os itens por valor/peso e escolher os com
	o maior fator.
	Teremos dois casos, a soma gulosa teve peso igual a K. Nesse caso 
	temos a solucao otima, pois usamos toda capacidade escolhendo os 
	maiores valores. No outro caso, a soma tem peso igual a K - 1 (pois
	os pesos sao 1 ou 2), para essa situacao a solucao otima sera a gulosa
	ou entao trocando o item de peso 1 adicionado por ultimo (com o menor
	fator) pelo proximo item de peso 2 do algoritmo guloso.
*/
#include <bits/stdc++.h>

using namespace std;

#define pll pair<ll, ll>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define ll long long

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	vector<pll> vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld%lld", &vals[i].fi, &vals[i].se);
	}
	
	sort(all(vals), [](pll &a, pll &b)
	{
		return a.fi/(double)a.se > b.fi/(double)b.se;
	});
	
	ll res = 0;
	int k = 0;
	int i = 0;
	for (; i < (int)vals.size() && k < K - 1; i++)
	{
		res += vals[i].fi;
		k += vals[i].se;
	}
	
	if (k == K - 1)
	{
		ll res1 = res, res2 = res;
		
		//completa o greedy
		for (int j = i; j < (int)vals.size(); ++j)
		{
			if (vals[j].se == 1)
			{
				res1 += vals[j].fi;
				break;
			}
		}
		
		//troca ultimo de peso 1, por um de peso dois
		bool exchanged = false;
		for (int j = i; !exchanged && j < (int)vals.size(); ++j)
		{
			if (vals[j].se == 2)
			{
				for (int k = i - 1; !exchanged && k >= 0; k--)
				{
					if (vals[k].se == 1)
					{
						res2 -= vals[k].fi;
						res2 += vals[j].fi;
						exchanged = true;
					}
				}
			}
		}
		res = max(res1, res2);
	}
	
	printf("%lld\n", res);
}
