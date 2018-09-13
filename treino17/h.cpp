#include<bits/stdc++.h>
#define ll long long
#define MAXN 100001

using namespace std;

int N;
ll K;
int tree[MAXN];

void update(int i, int val)
{
	++i;
	while(i <= N)
	{
		tree[i] += val;
		i += (i&-i);
	}
}

int sum(int i)
{
	int s = 0;
	++i;
	while(i > 0)
	{
		s += tree[i];
		i -= (i&-i);
	}
	return s;
}

int vet[MAXN];
set<int> conjuntoX;
vector<int> vX;

int idX(int x)
{
	return lower_bound(vX.begin(), vX.end(), x)-vX.begin();
}

int main()
{
	ll inversoes = 0, val, ans = 0;
	scanf("%d %lld", &N, &K);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &vet[i]);
		conjuntoX.insert(vet[i]);
	}
	vX.assign(conjuntoX.begin(), conjuntoX.end());
	for(int i = 0; i < N; i++)
		vet[i] = idX(vet[i]);
	for(int l = 0, r = 0; r < N; r++)
	{
		inversoes += sum(N)-sum(vet[r]);
		update(vet[r], 1);
		//printf("%d %lld!!!\n", r, inversoes);
		while(inversoes >= K && l != r)
		{
			//printf("%lld %lld\n", inversoes, K);
			val = sum(vet[l]-1);
			//printf("%d %lld\n", l, val);
			if(inversoes-val < K)
				break;
			inversoes -= val;
			update(vet[l], -1);
			l++;
		}
		if(inversoes >= K)
		{
			//printf("%d %d %lld\n", l, r, inversoes);
			ans += l+1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
