#include<bits/stdc++.h>
#define ll long long
using namespace std;

int vet[63];

int impossivel(int B, ll X)
{
	for(int i = 2; (i < B); i++)
	{
		if(X%i == 0)
		{
			while(X%i == 0)
			{
				X /= i;
			}
		}
	}
	return X != 1;
}

int B;
vector<int> divs;

ll val(vector<int>& v)
{
	ll ans = 0;
	for(int i = v.size()-1; i >= 0; i--)
		ans = B*ans+divs[v[i]];
	return ans;
}

int main()
{
	vector<int> v, v2;
	
	int k = 67;
	ll X, atual, ans = (((1LL << 62) - 1LL) + (1LL << 62));
	scanf("%d %lld", &B, &X);
	if(impossivel(B, X))
		return !printf("impossible\n");
	for(int i = 2; i < B; i++)
		if(X%i == 0)
			divs.push_back(i);
	queue< pair<ll, vector<int> > > fila;
	fila.push({X, {}});
	while(!fila.empty())
	{
		atual = fila.front().first;
		v = fila.front().second;
		//printf("%d\n", k);
		//printf("%lld\n", atual);
		//for(int i = 0; i < v.size(); i++)
		//	printf("%d\n", divs[i]);
		if(v.size() > k)
			break;
		if(atual == 1)
		{
			k = v.size();
			ans = min(ans, val(v));
		}
		fila.pop();
		if(!v.size())
		{
			for(int i = 0; i < (int)divs.size(); i++)
			{
				if(atual%divs[i] == 0)
				{
					fila.push({atual/divs[i], {i}});
				}
			}
		}
		else
		{
			for(int i = 0; i <= v.back(); i++)
			{
				if(atual%divs[i] == 0)
				{
					v2 = v;
					v2.push_back(i);
					fila.push({atual/divs[i], v2});
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
