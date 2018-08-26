#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, int> Mapa;

set<ll> out, apag;
int op[100001];

int main()
{
	int N, tam, cnt = 0, sz = 0;
	vector<ll> apagar;
	ll x;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d", &op[i], &tam);
		for(int j = 0; j < tam; j++)
		{
			scanf("%lld", &x);
			if(op[i] == 2)
				out.insert(x);
			else
			{
				Mapa[x]++;
			}
		}
		if(op[i] == 1)
			cnt++;
	}
	if(cnt == 0)
		return !printf("%lld\n", 1000000000000000000LL-out.size());
	for(auto it: Mapa)
		if(it.second != cnt)
			apagar.push_back(it.first);
	for(int i = 0; i < (int)apagar.size(); i++)
			Mapa.erase(apagar[i]);
	for(auto it: out)
	{
		if(Mapa.count(it) > 0)
			sz++;
	}
	printf("%d\n", (int)Mapa.size() - sz);
	return 0;
}
